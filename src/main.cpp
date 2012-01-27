#include <iostream>
#include <cstring>
#include <climits>
#include <fstream>

#include "nagoom.hpp"

using namespace std;

int main(int argc, char** argv)
{
	nagoom::Client* client = new nagoom::Client("test", "test");

	cout << " \e[0;1mNagoom\e[0;0m (revision " << _NAGOOM_REVISION << ")" << endl;
	cout << " Copyright (c) \e[1mdrizz\e[0m <drizz@hush.ai>" << endl << endl;
	// cout << " Built " << __DATE__ << endl << endl;

	std::string cipherText;

	char buffer[2];
	for (int i = 0; i < strlen(nagoom::ciphers); i++) {
		sprintf(buffer, "%X", (unsigned char)nagoom::ciphers[i]);

		cipherText.append(buffer);
	}

	debug("\e[1;33mCiphers:\e[0m " << cipherText);

	return 0;
}
