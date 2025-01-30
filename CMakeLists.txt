cmake_minimum_required(VERSION 3.10)
project(ThriftCalculator)

find_package(Threads REQUIRED)

set(THRIFT_GEN_DIR ${CMAKE_SOURCE_DIR}/gen-cpp)
set(THRIFT_INCLUDE_DIR /usr/local/include/thrift)
set(THRIFT_LIB thrift)

include_directories(${THRIFT_GEN_DIR} ${THRIFT_INCLUDE_DIR})
link_directories(/usr/local/lib)

add_executable(server src/Calculator_server.cpp ${THRIFT_GEN_DIR}/Calculator.cpp ${THRIFT_GEN_DIR}/calculator_types.cpp)
add_executable(client src/Calculator_client.cpp ${THRIFT_GEN_DIR}/Calculator.cpp ${THRIFT_GEN_DIR}/calculator_types.cpp)

target_link_libraries(server ${THRIFT_LIB} Threads::Threads)
target_link_libraries(client ${THRIFT_LIB} Threads::Threads)

