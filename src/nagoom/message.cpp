#include "nagoom/message.hpp"

using namespace nagoom;

Message::Message(Message::Type type)
	: m_type(type),
	  m_buffer()
{
	
}

std::string& Message::append(const std::string& string)
{
	return m_buffer.append(string);
}
