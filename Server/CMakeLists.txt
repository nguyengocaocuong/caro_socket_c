cmake_minimum_required(VERSION 3.17)
project(Server C)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_C_STANDARD 99)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(MAIN main.c)
include_directories(constant include)
file(GLOB SOURCES "src/*.c")
add_executable(Server ${SOURCES} ${MAIN})
target_link_libraries(Server Threads::Threads)

