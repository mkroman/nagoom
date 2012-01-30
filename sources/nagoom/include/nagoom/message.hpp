#ifndef __MESSAGE_HPP
#define __MESSAGE_HPP

#include <string>
#include <vector>

#include "byteorder.h"

namespace nagoom
{

static const char ciphers[] = "\x88\x3d\x74\x45\x21\xd3\x67\xec\xaa\x17\x3b\x02\x39"
							  "\x79\x82\x08\xf2\x99\xd1\x6a\x4a\xbc\xc0\x9f\xd0\x2e"
							  "\xf7\xdf\xc6\x3e\x7a\x27\x76\x5d\xe7\xfc\x3e\x1d\x14"
							  "\xf9\x75\x34\x6b\xbd\x45\xd6\x5e\xa9\xd2\x18\x5c\xeb"
							  "\xe7\x24\x3c\xd4\xb3\xde\xd0\xf3\x32\xea\x0c\xd0\x05"
							  "\xeb\xd1\x0c\xf4\xa5\x48\xe0\xea\x10\x37\xe9\x7b\x10"
							  "\x70\x2c\xe7\x76\xdb\x72\x2f\xf3\xef\xfd\x0a\xd5\xf3"
							  "\xdb\x6d\xc8\x1e\x2a\x04\x24\xc5\xf3";

class Message
{
public:
	Message();

 	std::string encode() const;

 	inline Message& operator<<(int16_t value)
 	{
 		uint16_t converted = htobe16(value);

 		append(reinterpret_cast<uint8_t*>(&converted), sizeof(converted));

 		return *this;
 	}

 	inline Message& operator<<(const std::string& value)
 	{
 		char* buffer = const_cast<char*>(value.c_str());

 		append(reinterpret_cast<uint8_t*>(buffer), value.length());

 		return *this;
 	}

protected:
	inline void append(const uint8_t* buffer, const size_t size)
	{
		m_buffer.insert(end(m_buffer), buffer, buffer + size);
	}

private:
	std::vector<uint8_t> m_buffer;
};

}

#endif
