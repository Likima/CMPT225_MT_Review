//
// Created by Brandon Tang on 2024-10-07.
//

/*
-----------------FILE OVERVIEW-----------------
A stack is a FILO Datatype. Think of a physical
stack, when we put something onto the stack it
is on the top, and when we take something off
the stack, we take it off the top.

This file defines the basic functionalities
of a stack. These are push, pop, constructors
isEmpty, etc.

This stack uses a linked list to implement the
functions.
----------------/FILE OVERVIEW-----------------
 */

#include "stack_linkedList.h"
#include <string>

void printIntInBox(const int data) {
 const int datasize = data % 10; // gets the size of the number
 const std::string s(datasize, '0');
 const std::string m(datasize/2, ' ');

 std::cout << s << std::endl;
 std::cout << "|" << s << data << s << "|" << std::endl;
 std::cout << s << std::endl;
}

Stack::Stack() = default;             // Constructor

Stack::Stack(const Stack& other) { this->ll = other.ll; }

Stack::~Stack() { ll->Clear(); }             // Destructor

void Stack::print() const {
 const Node* temp = ll->getHead();
 while (temp != nullptr) {
  printIntInBox(temp->data);
  temp = temp->next;
 }
}

void Stack::push(const int data) const {
 const Node* newNode = new Node(data);
 const Node* temp = ll->getHead();

 if (temp == nullptr) {
  temp = newNode;
  return;
 }
 while (temp->next != nullptr) {
  temp = temp->next;
 }
 temp->next = newNode;
}          // Push an element onto the stack

int Stack::pop() {
 return(ll->removeAtBeginning());
}          // Pop the top element off the stack
int Stack::top() const {
 return(ll->getHead()->data);
}          // Get the top element
bool Stack::isEmpty() const {
 return(ll->getSize() == 0);
}         // Check if the stack is empty
int Stack::getSize() const {
 return(ll->getSize());
}          // Get the current size of the stack
