#include <cstddef>
#include <sstream>
#include <iostream>
#include "byteorder.h"
#include "serializer/variant.hpp"
#include "serializer/container.hpp"

using namespace serializer;

Container::Container(const Protocol protocol)
	: m_protocol(protocol)
{
	uint16_t version = htobe16(static_cast<uint16_t>(m_protocol));
	uint8_t* pointer = reinterpret_cast<uint8_t*>(&version);

	// Magic header
	m_header[0] = '\xAC';
	m_header[1] = '\xED';

	// Protocol version
	m_header[2] = pointer[0];
	m_header[3] = pointer[1];
}

std::string Container::serialize() const
{
	size_t size;
	std::stringstream buffer;

	// Write the headers
	buffer.write(m_header, sizeof(m_header));

	// Calculate the total byte size
	for (const Variant* variant : m_variants)
		size += variant->byteSize();

	// If the total byte size is larger than the max value of a single
	// byte, write a BLOCKDATALONG type field followed by a short size field
	if (size > 255) {
		uint16_t sizeShort = htobe16(static_cast<uint16_t>(size));

		buffer.put('\x7A');
		buffer.write(reinterpret_cast<char*>(&sizeShort), sizeof(uint16_t));
	}
	else {
		uint8_t sizeByte = static_cast<uint8_t>(size);

		buffer.put('\x77');
		buffer.write(reinterpret_cast<char*>(&sizeByte), sizeof(uint8_t));
	}

	// Write the variadic objects
	for (const Variant* variant : m_variants)
	{
		switch (variant->type())
		{
			case Variant::String:
			{
				std::string value = variant->toString();
				uint16_t length = htobe16(static_cast<uint16_t>(value.length()));

				// Write the string length as a short
				buffer.write(reinterpret_cast<char*>(&length), sizeof(uint16_t));

				// Write the string contents
				buffer.write(value.c_str(), value.length());

				break;
			}

			case Variant::Integer:
			{
				uint32_t value = htobe32(static_cast<uint32_t>(variant->toInt()));

				buffer.write(reinterpret_cast<char*>(&value), sizeof(uint32_t));

				break;
			}

			case Variant::Byte:
			{
				uint8_t value = variant->toByte();

				buffer.write(reinterpret_cast<char*>(&value), sizeof(uint8_t));

				break;
			}
		}
	}

	return buffer.str();
}

Container::~Container()
{
	for (Variant* variant : m_variants)
		delete variant;
}

Container& Container::operator<<(const int value)
{
	Variant* variant = new Variant(Variant::Integer);
	variant->setValue(value);

	m_variants.push_back(variant);

	return *this;
}

Container& Container::operator<<(const uint8_t value)
{
	Variant* variant = new Variant(Variant::Byte);
	variant->setValue(value);

	m_variants.push_back(variant);

	return *this;
}

Container& Container::operator<<(const std::string& value)
{
	Variant* variant = new Variant(Variant::String);
	variant->setValue(value);

	m_variants.push_back(variant);

	return *this;
}

