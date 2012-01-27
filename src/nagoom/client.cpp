#include "nagoom/client.hpp"

using namespace nagoom;

Client::Client(const std::string& name, const std::string& pass)
	: m_name(name),
	  m_pass(pass),
	  m_connection("95.211.129.162", 34005)
{

}

bool Client::connect()
{
	if (!m_connection.established()) {
		return m_connection.establish();
	}
	else {
		return false;
	}
}
