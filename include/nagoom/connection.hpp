#ifndef __CONNECTION_HPP
#define __CONNECTION_HPP

#include <string>

namespace nagoom
{

enum ConnectionState
{
	Connected,
	Connecting,
	Disconnected
};

class Connection
{
public:
	Connection(const std::string& host, uint16_t port);

	bool establish();
	bool established();

private:
	std::string m_host;
	uint16_t m_port;

	int m_socket;
	ConnectionState m_state;
};

}

#endif
