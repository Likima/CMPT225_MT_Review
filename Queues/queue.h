//
// Created by tangb on 2024-10-07.
//

#ifndef QUEUE_H
#define QUEUE_H

#include "../LinkedLists/singlyLinkedList.h"

class queue {
public:
    explicit queue(int capacity);       // Constructor with specified capacity
    ~queue();                  // Destructor

    void enqueue(int data);            // Add an element to the end of the queue
    void dequeue();                    // Remove an element from the front of the queue
    [[nodiscard]] int front() const;                 // Get the front element
    [[nodiscard]] int back() const;                  // Get the back element
    [[nodiscard]] bool isEmpty() const;              // Check if the queue is empty
    [[nodiscard]] int getSize() const;               // Get the current size of the queue
    [[nodiscard]] int getCapacity() const;           // Get the capacity of the queue

private:
    SinglyLinkedList* list;
    int size;                          // Current size of the queue
};



#endif //QUEUE_H
