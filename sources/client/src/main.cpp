#include <iostream>
#include <cstring>
#include <climits>
#include <fstream>

#include "nagoom.hpp"
#include "serializer/variant.hpp"
#include "serializer/container.hpp"

void printCipherText();

using namespace std;
using namespace serializer;

int main(int argc, char** argv)
{
	cout << endl << " \e[0;1mNagoom\e[0;0m (revision " << _NAGOOM_REVISION << ")" << endl;
	cout << " Copyright (c) \e[1mdrizz\e[0m <drizz@hush.ai>" << endl << endl;

	debug("\e[1;33mCiphers:\e[0m");
	printCipherText();

	cout << endl;

	debug("Instantiating client …");

	nagoom::Client* client = new nagoom::Client("test", "test");

	std::string input = "\xf0\x06\xe7\x21\x4f\xa6\xb3\xd1\xba\x92\x44\x8b\x22\xbc\x64\x85\xb6\x22\xa7\xcd\x27\x92\x9e\x78\x7a\xde\x68\x24\x10\xf6\xb5\x74\xdb\x73\x7c\xf3\xea\x8b\x6b\xb9\x86\xbe\x15\xba\x1e\x3a\x6e\x45\xb3\x92\xa6\x51\x15\x2b\x46\xfd\x29\x99\xc7\x75\x5e\x70\xbf\xd5\x17\x15\xf9\x0d\x31\xe1\x48\xbc\xc0\xe7\xa0\x2d\x1e\xab\xc6\x34\x11\x48\x18\x3a\x94\x93\x50\x7c\x7a\x8d\x01\x34\x61\xd6\x2a\xb8\x39\xda\xbd\x76\x3d\x85\x93";

	for (int i = 0; i < input.length(); i++)
	{
		input[i] = (input[i] ^ nagoom::ciphers[(50 + i) % 100]);
	}

	std::cout << input << std::endl;

	// debug("Establishing connection …");

	// if (client->connect()) {
	// 	debug("Connection established, sending handshake …");

	// 	nagoom::Message loginMessage;

	// 	loginMessage << nagoom::Message::N_LOGINMESSAGE;
	// 	loginMessage << client->name();
	// 	loginMessage << client->pass();

	// 	client->send(loginMessage);
	// }

	return 0;
}

void printCipherText()
{
	int i, r = 0;
	int ciphersPerRow = 25;
	char buffer[2];
	string output;

	for (i = 0; i < strlen(nagoom::ciphers); i++)
	{
		sprintf(buffer, "%0.2X", (unsigned char)nagoom::ciphers[i]);

		output.append(buffer);

		if (++r == ciphersPerRow)
		{
			debug(output);
			output.clear();

			r = 0;
		}
	}
}
