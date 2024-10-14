//
// Created by tangb on 2024-10-07.
//

#pragma once

#include "../LinkedLists/singlyLinkedList.h"

class Stack {
public:
    Stack();               // Constructor
    ~Stack();              // Destructor
    Stack(const Stack& other);

    void push(int data) const;             // Push an element onto the stack
    void print() const;
    int pop();                      // Pop the top element off the stack
    [[nodiscard]] int top() const;                 // Get the top element
    [[nodiscard]] bool isEmpty() const;            // Check if the stack is empty
    [[nodiscard]] int getSize() const;             // Get the current size of the stack

private:
    SinglyLinkedList* ll{};
};
