#include <iostream>

#include "nagoom.hpp"

using namespace std;

int main(int argc, char** argv)
{
	nagoom::Client* client = new nagoom::Client("test", "test");

	if (client->connect()) {
		cout << "Client connected" << endl;
	}

	return 0;
}
