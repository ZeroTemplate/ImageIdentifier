cmake_minimum_required(VERSION 3.3)
project(ImageIdentifier)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    ImageIdentifier/fileBMP.cpp
    ImageIdentifier/fileBMP.hpp
    ImageIdentifier/fileJPG.cpp
    ImageIdentifier/fileJPG.hpp
    ImageIdentifier/imageFile.h
    ImageIdentifier/main.cpp)

add_executable(ImageIdentifier ${SOURCE_FILES})