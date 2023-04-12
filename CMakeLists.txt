cmake_minimum_required(VERSION 3.22)
project(DoublyLinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(DoublyLinkedList main.cpp Sources/DoublyLinkedList.cpp Headers/DoublyLinkedList.h Sources/DoublyLinkedListMenu.cpp Headers/DoublyLinkedListMenu.h)
