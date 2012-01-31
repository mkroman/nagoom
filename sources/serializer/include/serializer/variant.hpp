#ifndef __SERIALIZER_VARIANT_HPP
#define __SERIALIZER_VARIANT_HPP

#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <string>

namespace serializer
{

class Variant
{
public:
	enum VariantType
	{
		Null,
		Byte,
		String,
		Integer
	};
	
	Variant();
	Variant(VariantType type);

	const Variant& operator=(int rhs);
	const Variant& operator=(uint8_t rhs);
	const Variant& operator=(const char* rhs);
	const Variant& operator=(const std::string& rhs);

	~Variant();

	bool empty() const;

	VariantType type() const
	{
		return m_type;
	}

	size_t length() const
	{
		if (m_type == String)
			return m_length;
		else
			return -1;
	}

	size_t byteSize() const
	{
		switch (m_type)
		{
			case Byte:
				return (sizeof(uint8_t));
				break;

			case Null:
				return 0;
				break;
			
			case String:
				return (sizeof(uint16_t) + sizeof(char) * length());
				break;

			case Integer:
				return (sizeof(uint16_t));
				break;
		}
	}

	int toInt() const;
	std::string toString() const;

private:
	void clear()
	{
		m_intValue = 0;
		m_charPointerValue = nullptr;
		m_byteValue = 0;
	}

	VariantType m_type;

	union {
		int m_intValue;
		char* m_charPointerValue;
		uint8_t m_byteValue;
	};

	size_t m_length;
};

}

#endif
