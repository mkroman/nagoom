#include "byteorder.h"
#include "nagoom/packetstream.hpp"

using namespace nagoom;

PacketStream::PacketStream()
	: m_buffer(nullptr)
{
	
}

PacketStream& PacketStream::operator<<(uint16_t value)
{
	uint16_t result = htobe16(value);

	append(reinterpret_cast<uint8_t*>(&result), sizeof(result));

	return *this;
}

void PacketStream::append(const uint8_t* buffer, const size_t size)
{
	m_buffer->insert(m_buffer->end(), buffer, buffer + size);
}
