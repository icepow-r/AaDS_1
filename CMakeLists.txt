cmake_minimum_required(VERSION 3.10)
project(ShuntingYard)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(shunting_yard
    src/main.cpp
    src/DoublyLinkedList.h
    src/DynamicArray.h
    src/Stack.h
    src/ShuntingYard.h
    src/ShuntingYard.cpp
)

target_include_directories(shunting_yard PRIVATE src)
