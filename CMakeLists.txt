cmake_minimum_required(VERSION 3.10)
project(voiceRecognition)

set(CMAKE_CXX_STANDARD 17)

add_executable(voiceRecognition main.cpp Signal.cpp Signal.h)