#include <cstddef>
#include "byteorder.h"
#include "serializer/container.hpp"

using namespace serializer;

Container::Container(const Protocol protocol)
	: m_protocol(protocol), m_count(1)
{
	uint16_t version = htobe16(static_cast<uint16_t>(m_protocol));
	uint8_t* pointer;

	// Magic header
	m_buffer.push_back('\xAC');
	m_buffer.push_back('\xED');

	// Protocol version
	push(reinterpret_cast<uint8_t*>(&version), sizeof(uint16_t));

	// Block data
	m_buffer.push_back('\x77');
}

void Container::push(uint8_t* pointer, size_t size)
{
	ptrdiff_t diff = (pointer + size) - pointer;
	m_count += diff;

	m_buffer.insert(end(m_buffer), pointer, pointer + size);
}

Container& Container::operator<<(const std::string& string)
{
	uint16_t length = htobe16(string.length());

	push(reinterpret_cast<uint8_t*>(&length), sizeof(uint16_t));

	for (char character : string) {
		m_buffer.push_back(character);
	}
}

Container& Container::operator<<(const int32_t value)
{
	int32_t converted = htobe32(value);

	push(reinterpret_cast<uint8_t*>(&converted), sizeof(uint32_t));
}
