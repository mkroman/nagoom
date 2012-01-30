#ifndef __SERIALIZER_FILE_HPP
#define __SERIALIZER_FILE_HPP

#include <string>
#include <fstream>
#include "serializer.hpp"

namespace serializer
{
	
class File
{
public:
	File(const std::string& path);

	const Protocol protocol() const
	{
		return m_protocol;
	}
	
private:
	std::fstream m_stream;
	Protocol m_protocol;
};

}

#endif
