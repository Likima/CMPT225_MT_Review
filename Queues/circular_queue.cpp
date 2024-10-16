//
// Created by tangb on 2024-10-14.
//

#include "circular_queue.h"

#include <cstdio>
#include <iostream>
#include <ostream>
#include <bits/range_access.h>

circular_queue::circular_queue(const int s): front_idx(0), rear_idx(0), size(0), capacity(s) {
    c = new int[capacity];
};
circular_queue::~circular_queue() { delete[] c; }

circular_queue::circular_queue(const circular_queue& other) {
    c = other.c;
    capacity = other.capacity;
    size = other.size;
    front_idx = other.front_idx;
    rear_idx = other.rear_idx;
}

void circular_queue::enqueue(const int value) {
    if (is_full()) {
        std::cout<<"Queue is full"<<std::endl;
        return;
    }
    c[rear_idx] = value;
    rear_idx = (rear_idx + 1) % capacity;
    size++;
}

int circular_queue::dequeue() {
    if (is_empty()) {
        std::cout<<"Queue is empty"<<std::endl;
        return -1;
    }
    front_idx = (front_idx + 1) % capacity;
    size--;
    return c[(front_idx - 1) % capacity];
}

bool circular_queue::is_empty() const {
    return size == 0;
}

bool circular_queue::is_full() const {
    return size == capacity;
}