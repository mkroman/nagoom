#ifndef __NAGOOM_HPP
#define __NAGOOM_HPP

#define _NAGOOM_REVISION "2c6b25b43c3a10b369367ec704a5ddccdc750e8d"

#include "nagoom/client.hpp"
#include "nagoom/message.hpp"
#include "nagoom/connection.hpp"

#define debug(string) \
	std::cout << " \e[0;1mDebug\e[0;0m  " << string << endl;

#define error(string) \
	std::cout << " \e[1;31mError\e[0;0m  " << string << endl;

#endif
