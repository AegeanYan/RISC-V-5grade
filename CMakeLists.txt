cmake_minimum_required(VERSION 3.14)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(code
        ALU.cpp
        ALU.h
        Memory.cpp
        main.cpp
        Memory.h
        Registor.cpp
        Registor.h
        simulator.cpp
        simulator.h
        )
