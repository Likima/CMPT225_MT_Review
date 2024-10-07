//
// Created by tangb on 2024-10-07.
//

#ifndef QUEUE_H
#define QUEUE_H



class queue {
    queue(int capacity);       // Constructor with specified capacity
    ~queue();                  // Destructor

    void enqueue(int data);            // Add an element to the end of the queue
    void dequeue();                    // Remove an element from the front of the queue
    int front() const;                 // Get the front element
    int back() const;                  // Get the back element
    bool isEmpty() const;              // Check if the queue is empty
    bool isFull() const;               // Check if the queue is full
    int getSize() const;               // Get the current size of the queue
    int getCapacity() const;           // Get the capacity of the queue

private:
    int* arr;                          // Array to hold queue elements
    int capacity;                      // Maximum capacity of the queue
    int frontIndex;                    // Index of the front element
    int backIndex;                     // Index of the back element
    int size;                          // Current size of the queue
};



#endif //QUEUE_H
