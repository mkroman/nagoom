#include <cstring>
#include <sstream>
#include <iostream>

#include "nagoom.hpp"
#include "nagoom/message.hpp"

using namespace nagoom;

Message::Message()
	: m_buffer()
{
	
}

std::string Message::encode() const
{
	uint16_t header[2];
	uint16_t packet_key;

	packet_key = rand() % strlen(ciphers);

	header[0] = static_cast<uint16_t>(m_buffer.size());
	header[1] = packet_key;

	std::string data(m_buffer.begin(), m_buffer.end());
	std::stringstream buffer;

	debug("packet_key: " << packet_key);
	debug("body size: " << header[0]);

	for (int i = 0; i < m_buffer.size(); i++)
	{
		data[i] = (m_buffer[i] ^ ciphers[(packet_key + i) % strlen(ciphers)]);

		debug("Encrypting: " << m_buffer[i] << " -> " << data[i]);
	}

	buffer << header[0] << header[1] << data;

	return buffer.str();
}
