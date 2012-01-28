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

	m_buffer.insert(end(m_buffer), reinterpret_cast<const uint8_t*>(&result), sizeof(result));

	return *this;
}
