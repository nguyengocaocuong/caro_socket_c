cmake_minimum_required(VERSION 3.17)
project(Client C)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_C_STANDARD 99)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(SOURCE_FILES main.c)
file(GLOB SOURCES "views/src/*.c" "exchange/src/*.c")


add_executable(SOURCE_FILES ${SOURCES})
add_executable(Client ${SOURCE_FILES} ${SOURCES})
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(views/include exchange/include exchange/constant)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})
target_link_libraries(Client ${GTK3_LIBRARIES})
target_link_libraries(Client Threads::Threads)

