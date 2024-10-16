//
// Created by tangb on 2024-10-07.
//

#ifndef DEQUE_H
#define DEQUE_H

#include "../LinkedLists/doublyLinkedList.h"

class Deque {
public:
    Deque();                           // Constructor
    ~Deque();                          // Destructor

    void insertFront(int data);        // Insert element at the front
    void insertBack(int data);         // Insert element at the back
    void deleteFront();                // Delete element from the front
    void deleteBack();                 // Delete element from the back
    [[nodiscard]] int getFront() const;              // Get the front element
    [[nodiscard]] int getBack() const;               // Get the back element
    [[nodiscard]] bool isEmpty() const;              // Check if the deque is empty
    [[nodiscard]] int getSize() const;               // Get the size of the deque
    void clear();                      // Clear all elements from the deque

private:
    doublyLinkedList* head;
    doublyLinkedList* tail;
    int size;                          // Track the size of the deque
};

#endif //DEQUE_H
