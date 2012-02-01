#ifndef __CLIENT_HPP
#define __CLIENT_HPP

#include <string>

#include "nagoom/message.hpp"
#include "nagoom/connection.hpp"

namespace nagoom
{

class Client
{
public:
	Client(const std::string& name, const std::string& pass);

	bool connect();
	void send(const Message& message);

	const std::string& name()
	{
		return m_name;
	}

	const std::string& pass()
	{
		return m_pass;
	}
	
private:
	std::string m_name;
	std::string m_pass;
	Connection m_connection;		
};

}

#endif
