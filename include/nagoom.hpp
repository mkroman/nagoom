#ifndef __NAGOOM_HPP
#define __NAGOOM_HPP

#define _NAGOOM_REVISION "cd944bd0"

#include "nagoom/client.hpp"
#include "nagoom/message.hpp"
#include "nagoom/connection.hpp"

#define debug(string) \
	std::cout << " \e[0;1mDebug\e[0;0m  " << string << std::endl;

#define error(string) \
	std::cout << " \e[1;31mError\e[0;0m  " << string << std::endl;

#endif
