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
		Short,
		String,
		Integer
	};
	
	Variant();
	Variant(VariantType type);

	const Variant& operator=(int rhs);
	const Variant& operator=(uint8_t rhs);
	const Variant& operator=(uint16_t rhs);
	const Variant& operator=(const char* rhs);
	const Variant& operator=(const std::string& rhs);

	~Variant();

	const Variant& setValue(int value)
	{
		return operator=(value);
	}

	const Variant& setValue(uint8_t value)
	{
		return operator=(value);
	}

	const Variant& setValue(uint16_t value)
	{
		return operator=(value);
	}

	const Variant& setValue(const char* value)
	{
		return operator=(value);
	}

	const Variant& setValue(const std::string& value)
	{
		return operator=(value);
	}

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

			case Short:
				return (sizeof(uint16_t));
				break;

			case Integer:
				return (sizeof(uint32_t));
				break;
		}
	}

	int toInt() const;
	uint8_t toByte() const;
	uint16_t toShort() const;
	std::string toString() const;

private:
	void clear()
	{
		m_intValue = 0;
		m_charPointerValue = nullptr;
		m_byteValue = 0;
		m_shortValue = 0;
	}

	VariantType m_type;

	union {
		int m_intValue;
		char* m_charPointerValue;
		uint8_t m_byteValue;
		uint16_t m_shortValue;
	};

	size_t m_length;
};

}

#endif
