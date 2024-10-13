cmake_minimum_required(VERSION 3.29)
project(mt1_Study_Guide)

set(CMAKE_CXX_STANDARD 17)

add_executable(mt1_Study_Guide main.cpp
        LinkedLists/singlyLinkedList.cpp
        LinkedLists/doublyLinkedList.cpp
        Queues/deque.cpp
        Queues/queue.cpp
        Stacks/stack_linkedList.cpp)
