cmake_minimum_required(VERSION 3.24)
project(LIBRARY_MANAGEMENT_SYSTEM)

set(CMAKE_CXX_STANDARD 17)

#add_executable(LIBRARY_MANAGEMENT_SYSTEM main.cpp)

add_executable(LIBRARY_MANAGEMENT_SYSTEM main.cpp sqlite/sqlite3.h sqlite/sqlite3.c)

