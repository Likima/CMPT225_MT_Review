//
// Created by tangb on 2024-10-07.
//

#include "queue.h"

queue::queue(int capacity): size(0) {}       // Constructor with specified capacity
queue::~queue() { list->Clear(); }                  // Destructor

void queue::enqueue(const int data) {
    list->InsertAtEnd(data);
    size++;
}// Add an element to the end of the queue

void queue::dequeue() {
    if (list->IsEmpty()) return;
    list->removeAtBeginning();
    size--;
}                    // Remove an element from the front of the queue
int queue::front() const {
    return list->getHead()->data;
}
// Get the front element
int queue::back() const {
    return list->getTail()->data;
}                  // Get the back element
bool queue::isEmpty() const {
    return size == 0;
}              // Check if the queue is empty

int queue::getSize() const {
    return size();
}               // Get the current size of the queue
