#include <iostream>
#include "nagoom/client.hpp"

using namespace nagoom;

Client::Client(const std::string& name, const std::string& pass)
	: m_name(name),
	  m_pass(pass),
	  m_connection("95.211.129.162", 34005)
{
	srand(time(NULL));
}

bool Client::connect()
{
	if (!m_connection.established() && m_connection.establish()) {
		Message loginMessage;

		loginMessage << (uint16_t)1001;
		loginMessage << std::string("kongsonant");
		loginMessage << std::string("kongsonant");

		m_connection.transmit(loginMessage);
	}
	else {
		return false;
	}
}
