#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <iostream>
#include <cstring>

#include "nagoom/connection.hpp"

using namespace nagoom;

Connection::Connection(const std::string& host, uint16_t port)
	: m_host(host),
	  m_port(port),
	  m_state(Disconnected)
{

}

bool Connection::establish()
{
	int result;
	struct hostent*    remote_host;
	struct sockaddr_in remote_addr;

	memset(&remote_addr, 0, sizeof(struct sockaddr_in));

	m_socket = socket(AF_INET, SOCK_STREAM, 0);

	if (m_socket < 0) {
		perror("unable to create socket");

		return false;
	}

	remote_host = gethostbyname(m_host.c_str());

	if (remote_host == nullptr) {
		perror("unable to translate remote host");

		return false;
	}

	remote_addr.sin_family = AF_INET;
	remote_addr.sin_port = htons(m_port);

	memcpy(&remote_addr.sin_addr, remote_host->h_addr, remote_host->h_length);

	result = connect(m_socket, (struct sockaddr*)&remote_addr, sizeof(struct sockaddr));

	if (result < 0) {
		perror("could not establish a connection");

		return false;
	}
	else
		return true;
}

void Connection::transmit(const Message& message)
{
	std::cout << "Transmitting message of type " << message.type() << std::endl;
}

bool Connection::established()
{
	return (m_state == Connection::Connected);
}
