cmake_minimum_required(VERSION 3.12)
project(RC4)

set(CMAKE_CXX_STANDARD 11)

add_executable(RC4 main.cpp Rc4.cpp Rc4.h)