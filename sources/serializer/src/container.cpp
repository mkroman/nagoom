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
	std::stringstream buffer;

	// Write the headers
	buffer.write(m_header, sizeof(m_header));

	// Write the variadic objects
	for (const Variant& variant : m_variants)
	{
		switch (variant.type())
		{
			case Variant::String:
			{
				std::cout << "hejs " << variant.toString() << " dejs" << std::endl;

				//buffer.write(value.c_str(), value.length());
				break;
			}
		}
	}

	return buffer.str();
}

Container::~Container()
{
	
}

Container& Container::operator<<(const std::string& value)
{
	Variant* variant = new Variant;
	*variant = value;

	//m_variants.insert(end(m_variants), variant);
	m_variants.push_back(*variant);

	// uint16_t length = htobe16(string.length());

	// push(reinterpret_cast<uint8_t*>(&length), sizeof(uint16_t));

	// for (char character : string) {
	// 	m_buffer.push_back(character);
	// }
	return *this;
}

Container& Container::operator<<(const int value)
{
	// int32_t converted = htobe32(value);

	// push(reinterpret_cast<uint8_t*>(&converted), sizeof(uint32_t));
	return *this;
}
