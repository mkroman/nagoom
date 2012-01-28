PROJECT(Nagoom)

SET(CMAKE_BUILD_TYPE Debug)

IF(CMAKE_COMPILER_IS_GNUCXX)
	SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=gnu++0x)
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

INCLUDE_DIRECTORIES(include)

EXEC_PROGRAM(git ARGS "rev-parse HEAD" OUTPUT_VARIABLE REVISION)
CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/include/nagoom.hpp.in ${CMAKE_SOURCE_DIR}/include/nagoom.hpp ESCAPE_QUOTES)

SET(NAGOOM_SOURCES
	src/main.cpp
	src/nagoom/client.cpp
	src/nagoom/message.cpp
	src/nagoom/connection.cpp
	src/nagoom/packetstream.cpp
)

ADD_EXECUTABLE(nagoom ${NAGOOM_SOURCES})

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
