#include <cstring>
#include <sstream>
#include <iostream>

#include "nagoom.hpp"
#include "nagoom/message.hpp"

using namespace nagoom;

Message::Message()
{
	
}

std::string Message::encode(uint16_t key) const
{
	size_t ciphersLength = strlen(ciphers);
	std::string data = m_container.serialize();

	for (int i = 0; i < data.length(); i++)
	{
		data[i] = (data[i] ^ ciphers[(key + i) % ciphersLength]);
	}

	return data;
}

std::string Message::decode(uint16_t key) const
{
	size_t ciphersLength = strlen(ciphers);
	std::string data = m_container.serialize();

	for (int i = 0; i < data.length(); i++)
	{
		data[i] = (data[i] ^ ciphers[(key + i) % ciphersLength]);
	}

	return data;
}

std::string Message::toString() const
{
	return m_container.serialize();	
}
