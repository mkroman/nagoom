#include <sstream>
#include "serializer/variant.hpp"

using namespace serializer;

Variant::Variant()
	: m_type(Variant::Null)
{
	
}

Variant::Variant(VariantType type)
	: m_type(type)
{
	
}

const Variant& Variant::operator=(int rhs)
{
	if (m_type != Variant::Integer)
		clear();

	m_type = Variant::Integer;
	m_intValue = rhs;
		
	return *this;
}

const Variant& Variant::operator=(uint8_t rhs)
{
	if (m_type != Variant::Byte)
		clear();

	m_type = Variant::Byte;
	m_byteValue = rhs;
}

const Variant& Variant::operator=(uint16_t rhs)
{
	if (m_type != Variant::Short)
		clear();

	m_type = Variant::Short;
	m_shortValue = rhs;
}

const Variant& Variant::operator=(const char* rhs)
{
	if (m_type != Variant::String)
		clear();

	m_type = Variant::String;
	m_length = strlen(rhs);
	m_charPointerValue = strdup(rhs);

	return *this;
}

const Variant& Variant::operator=(const std::string& rhs)
{
	if (m_type != Variant::String)
		clear();

	m_type = Variant::String;
	m_length = rhs.length();

	char* buffer = static_cast<char*>(malloc(m_length + 1));

	if (buffer != nullptr) {
		strncpy(buffer, rhs.c_str(), m_length + 1);

		m_charPointerValue = buffer;
	}

	return *this;
}

uint8_t Variant::toByte() const
{
	switch (m_type)
	{
		case Variant::String:
		case Variant::Null:
			return 0;
			break;

		case Variant::Byte:
			return m_byteValue;
			break;
	}
}

uint16_t Variant::toShort() const
{
	switch (m_type)
	{
		case Variant::Byte:
			return static_cast<uint16_t>(m_byteValue);
			break;

		case Variant::Integer:
			return static_cast<uint16_t>(m_intValue);
			break;

		case Variant::Short:
			return m_shortValue;
			break;

		default:
			return 0;
	}
}

int Variant::toInt() const
{
	switch (m_type)
	{
		case Variant::String:
		case Variant::Null:
			return 0;
			break;
		
		case Variant::Integer:
			return m_intValue;
			break;
		
		case Variant::Byte:
			return static_cast<int>(m_byteValue);
			break;
	}
}

std::string Variant::toString() const
{
	switch (m_type)
	{
		case Variant::String:
		{
			if (m_charPointerValue != nullptr)
			{
				return std::string(m_charPointerValue, m_length);
			}
			else
				return std::string("<nullstr>");

			break;
		}

		case Variant::Integer:
		{
			std::stringstream stream;
			stream << m_intValue;

			return stream.str();
			break;
		}

		case Variant::Short:
		{
			std::stringstream stream;
			stream << m_shortValue;

			return stream.str();
			break;
		}
		
		case Variant::Byte:
			char buffer[4];
			sprintf(buffer, "%#0.2x", m_byteValue);
			return std::string(buffer);
			break;
		
		case Variant::Null:
			return std::string("<null>");
			break;

		default:
			return std::string("<unknown>");
	}
}


Variant::~Variant()
{
	if (m_type == Variant::String && m_charPointerValue != nullptr)
		free(m_charPointerValue);

	clear();
}
