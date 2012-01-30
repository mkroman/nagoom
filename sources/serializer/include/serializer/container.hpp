#ifndef __SERIALIZER_CONTAINER_HPP
#define __SERIALIZER_CONTAINER_HPP

#include <string>
#include <vector>
#include <cstdint>
#include "serializer.hpp"

namespace serializer
{
	
class Container
{
public:
	Container(const Protocol protocol = Protocol::V5);

	const std::vector<uint8_t>& buffer()
	{
		return m_buffer;
	}

	Container& operator<<(const int32_t value);
	Container& operator<<(const std::string& string);

	void dump(std::string& output)
	{
		m_buffer.insert(m_buffer.begin() + 5, m_count);

		for (uint8_t& byte : m_buffer) {
			output.push_back(byte);
		}
	}

protected:
	void push(uint8_t* pointer, size_t size = 1);

private:
	uint8_t m_count;
	Protocol m_protocol;
	std::vector<uint8_t> m_buffer;
};

}

#endif
