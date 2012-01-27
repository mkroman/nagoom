#include "nagoom/connection.hpp"

using namespace nagoom;

Connection::Connection(const std::string& host, uint16_t port)
	: m_host(host),
	  m_port(port)
{
	
}

bool Connection::establish()
{
	// …
}

bool Connection::established()
{
	return (m_state == Connected);
}
