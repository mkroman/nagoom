#include "byteorder.h"
#include "nagoom/packetstream.hpp"

using namespace nagoom;

PacketStream::PacketStream()
	: m_buffer()
{
	
}

PacketStream& PacketStream::operator<<(uint16_t value)
{
	uint16_t result = htobe16(value);

	append(reinterpret_cast<const uint8_t*>(&result), sizeof(result));

	return *this;
}

PacketStream& PacketStream::operator<<(const std::string& value)
{
	char* buffer = const_cast<char*>(value.c_str());

	append(reinterpret_cast<uint8_t*>(buffer), value.length());

	return *this;
}

void PacketStream::append(const uint8_t* buffer, const size_t size)
{
	m_buffer.insert(end(m_buffer), buffer, buffer + size);
}
