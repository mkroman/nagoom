#include <cstdint>
#include <cstring>
#include <iostream>
#include "serializer.hpp"
#include "serializer/file.hpp"

using namespace serializer;

File::File(const std::string& path)
	: m_stream(path, std::fstream::in | std::fstream::out)
{
	char buffer[2];
	uint16_t protocol_version;

	if (m_stream.good()) {
		m_stream.read(buffer, 2);

		if (memcmp(buffer, "\xAC\xED", 2) != 0) {
			perror("Input file does not contain serialized java objects");
		}
		else {
			m_stream.read(buffer, 2);

			protocol_version = (buffer[1] | static_cast<uint16_t>(buffer[0]) << 8);

			if (protocol_version != 5) {
				perror("Unsupported protocol specification");
			}
			else {
				m_protocol = Protocol::V5;
			}
		}
	}
	else {
		perror("Failed to open input stream");
	}
}
