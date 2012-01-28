#ifndef __PACKET_STREAM_HPP
#define __PACKET_STREAM_HPP

#include <vector>

namespace nagoom
{
	
class PacketStream
{
public:
	PacketStream();

	void append(const uint8_t bytes);

	PacketStream& operator<<(uint16_t value);

private:
	std::vector<uint8_t> m_buffer;
};

}

#endif
