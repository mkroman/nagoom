#ifndef __SERIALIZER_CONTAINER_HPP
#define __SERIALIZER_CONTAINER_HPP

#include <string>
#include <vector>
#include <cstdint>

#include "serializer.hpp"
#include "serializer/variant.hpp"

namespace serializer
{
	
class Container
{
public:
	Container(const Protocol protocol = Protocol::V5);
	~Container();

	Container& operator<<(const int value);
	Container& operator<<(const uint8_t value);
	Container& operator<<(const uint16_t value);
	Container& operator<<(const std::string& value);

	std::string serialize() const;

	size_t byteSize() const;

private:
	char m_header[4];
	Protocol m_protocol;
	std::vector<Variant*> m_variants;
};

}

#endif
