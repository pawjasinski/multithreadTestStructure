CMAKE_MINIMUM_REQUIRED(VERSION "3.10")

PROJECT(ZadanieStruktura)

set(CMAKE_CXX_STANDARD 11)

set(
    HEADERS
    ${PROJECT_SOURCE_DIR}/include/baseClass.h
    ${PROJECT_SOURCE_DIR}/include/client
    ${PROJECT_SOURCE_DIR}/include/packet.h
    ${PROJECT_SOURCE_DIR}/include/recipient.h
    ${PROJECT_SOURCE_DIR}/include/server.h
    ${PROJECT_SOURCE_DIR}/include/trafficmonitor.h
    )
set(
    SOURCES
    ${PROJECT_SOURCE_DIR}/src/client.cpp
    ${PROJECT_SOURCE_DIR}/src/recipient.cpp
    ${PROJECT_SOURCE_DIR}/src/server.cpp
    ${PROJECT_SOURCE_DIR}/src/trafficmonitor.cpp
    )

ADD_SUBDIRECTORY(src)