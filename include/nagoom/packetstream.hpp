#ifndef __PACKET_STREAM_HPP
#define __PACKET_STREAM_HPP

#include <string>
#include <vector>

namespace nagoom
{
	
class PacketStream
{
public:
	PacketStream();

	void append(const uint8_t* buffer, const size_t size);

	PacketStream& operator<<(uint16_t value);
	PacketStream& operator<<(const std::string& value);

private:
	std::vector<uint8_t> m_buffer;
};

}

#endif
