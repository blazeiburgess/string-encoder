cmake_minimum_required(VERSION 3.25)
project(string-encoder)

set(CMAKE_CXX_STANDARD 17)

add_executable(string-encoder main.cpp app.cpp app.h codecs/html.cpp codecs/html.h codecs/url.cpp codecs/url.h constants/country.h
        codecs/generic.h
        codecs/generic.cpp)
