#include "byteorder.h"
#include "nagoom/message.hpp"

using namespace nagoom;

Message::Message()
	: m_buffer()
{
	
}

std::string Message::encode() const
{
	return std::string();
}

// for (int i = 0; i < finalbytes.length; i++)
// {
// 	int tmp7_6 = i;
// 	byte[] tmp7_5 = finalbytes;
//  tmp7_5[tmp7_6] = (byte)(tmp7_5[tmp7_6] ^ key[((encodeKey + i) % key.length)]);
// }return finalbytes;
// std::string Message::encode() const
// {
// 	uint16_t header[2];
// 	uint16_t packet_key;

// 	packet_key = rand() * strlen(ciphers);

// 	header[0] = static_cast<uint16_t>(m_buffer.length());
// 	header[1] = packet_key;

// 	std::string data(m_buffer);
// 	std::stringstream buffer;

// 	for (int i = 0; i < m_buffer.length(); i++)
// 	{
// 		data[i] = (m_buffer[i] ^ ciphers[(packet_key + i) % strlen(ciphers)]);
// 	}

// 	buffer << header[0] << header[1] << data;

// 	return buffer.str();
// }
