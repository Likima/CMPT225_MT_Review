//
// Created by tangb on 2024-10-07.
//

#pragma once

#include "../LinkedLists/singlyLinkedList.h"

class Stack {
public:
    Stack();               // Constructor
    ~Stack();              // Destructor

    void push(int data);             // Push an element onto the stack
    void pop();                      // Pop the top element off the stack
    int top() const;                 // Get the top element
    bool isEmpty() const;            // Check if the stack is empty
    int getSize() const;             // Get the current size of the stack

private:
    sll_Node* head;
};
