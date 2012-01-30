#include <iostream>
#include <cstring>
#include <climits>
#include <fstream>

#include "nagoom.hpp"
#include "serializer/container.hpp"

void printCipherText();

using namespace std;

int main(int argc, char** argv)
{
	cout << endl << " \e[0;1mNagoom\e[0;0m (revision " << _NAGOOM_REVISION << ")" << endl;
	cout << " Copyright (c) \e[1mdrizz\e[0m <drizz@hush.ai>" << endl << endl;

	debug("\e[1;33mCiphers:\e[0m");
	printCipherText();

	cout << endl;

	debug("Debugging serializer container …");

	serializer::Container container;

	container << 200;
	container << "abc";

	std::string test;


	container.dump(test);

	std::ofstream fil("/home/mk/out.bin");
	fil.write(test.c_str(), test.length());
	fil.close();

	// debug("Instantiating client …");

	// nagoom::Client* client = new nagoom::Client("test", "test");

	// debug("Establishing connection …");

	// if (client->connect()) {
	// 	debug("Connection established, sending handshake …");
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
