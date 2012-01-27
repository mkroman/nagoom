#ifndef __CONNECTION_HPP
#define __CONNECTION_HPP

#include <string>

#include "nagoom/message.hpp"

namespace nagoom
{

class Connection
{
public:
	enum State
	{
		Connected,
		Connecting,
		Disconnected
	};

	Connection(const std::string& host, uint16_t port);

	bool establish();
	bool established();

	void transmit(const Message& message);

	const std::string& host()
	{
		return m_host;
	}

	uint16_t port()
	{
		return m_port;
	}

private:
	std::string m_host;
	uint16_t m_port;

	int m_socket;
	State m_state;
};

}

#endif
