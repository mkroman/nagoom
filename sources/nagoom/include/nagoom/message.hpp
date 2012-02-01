#ifndef __MESSAGE_HPP
#define __MESSAGE_HPP

#include <string>
#include <vector>

#include "serializer.hpp"

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

// public static final short N_LOGINMESSAGE = 1001;
// public static final short N_ROOMLOAD = 1002;
// public static final short N_LOGINLOAD = 1003;
// public static final short N_NEWAVATARINROOM = 1004;
// public static final short N_MOVEAVATAR = 1005;
// public static final short N_AVATARLEAVE = 1006;
// public static final short N_NEWMESSAGE = 1007;
// public static final short N_COINUPDATE = 1008;
// public static final short N_SEATLOCKMESSAGE = 1009;
// public static final short N_ROOMLISTUPDATE = 1010;
// public static final short N_ROOMCHANGE = 1011;
// public static final short N_AWAYSTATUS = 1012;
// public static final short N_CLOTHESUPDATE = 1013;
// public static final short N_ERRORNOTIFICATION = 1014;
// public static final short N_WARDROBEUPDATE = 1015;
// public static final short N_UPDATELOOKS = 1016;
// public static final short N_NEWWHISPERMESSAGE = 1017;
// public static final short N_REQUESTMESSAGE = 1018;
// public static final short N_ITEMSUPDATE = 1019;
// public static final short N_ITEMPANELUPDATE = 1020;
// public static final short N_ITEMPLACEMENT = 1021;
// public static final short N_TRADEREQUEST = 1022;
// public static final short N_APARTMENTKICK = 1023;
// public static final short N_ADMINKICK = 1024;
// public static final short N_KICKEDOUT = 9007;

class Message
{
public:
	static const uint16_t N_LOGINMESSAGE = 1001;
	static const uint16_t N_ROOMLOAD = 1002;
	static const uint16_t N_LOGINLOAD = 1003;
	static const uint16_t N_NEWAVATARINROOM = 1004;
	static const uint16_t N_MOVEAVATAR = 1005;
	static const uint16_t N_AVATARLEAVE = 1006;
	static const uint16_t N_NEWMESSAGE = 1007;
	static const uint16_t N_COINUPDATE = 1008;
	static const uint16_t N_SEATLOCKMESSAGE = 1009;
	static const uint16_t N_ROOMLISTUPDATE = 1010;
	static const uint16_t N_ROOMCHANGE = 1011;
	static const uint16_t N_AWAYSTATUS = 1012;
	static const uint16_t N_CLOTHESUPDATE = 1013;
	static const uint16_t N_ERRORNOTIFICATION = 1014;
	static const uint16_t N_WARDROBEUPDATE = 1015;
	static const uint16_t N_UPDATELOOKS = 1016;
	static const uint16_t N_NEWWHISPERMESSAGE = 1017;
	static const uint16_t N_REQUESTMESSAGE = 1018;
	static const uint16_t N_ITEMSUPDATE = 1019;
	static const uint16_t N_ITEMPANELUPDATE = 1020;
	static const uint16_t N_ITEMPLACEMENT = 1021;
	static const uint16_t N_TRADEREQUEST = 1022;
	static const uint16_t N_APARTMENTKICK = 1023;
	static const uint16_t N_ADMINKICK = 1024;
	static const uint16_t N_KICKEDOUT = 9007;

	Message();

	const Message& operator<<(int value)
	{
		m_container << value;

		return *this;
	}

	const Message& operator<<(uint8_t value)
	{
		m_container << value;

		return *this;
	}

	const Message& operator<<(uint16_t value)
	{
		m_container << value;

		return *this;
	}

	const Message& operator<<(const char* value)
	{
		m_container << value;

		return *this;
	}

	const Message& operator<<(const std::string& value)
	{
		m_container << value;

		return *this;
	}
	
 	std::string encode(uint16_t key) const;
 	std::string decode(uint16_t key) const;

 	std::string toString() const;

private:
	serializer::Container m_container;
};

}

#endif
