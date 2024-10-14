//
// Created by tangb on 2024-10-07.
//

#pragma once

#include <iostream>

class Node {
  public:
    int data;
    mutable const Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList { // Singly Linked List node
  public:
    Node* next;

    SinglyLinkedList();    // Default ctor
    SinglyLinkedList(int); // Constructor for an int arg provided
    ~SinglyLinkedList();

    SinglyLinkedList(const SinglyLinkedList& other);
    SinglyLinkedList& operator=(const SinglyLinkedList& other);

    void Print() const;
    void Clear();

    bool IsEmpty() const;

    bool InsertAtBeginning(int num);
    bool InsertAtEnd(int num);
    bool InsertAtIndex(int index, int num);

    int getSize() const;
    int removeAtBeginning();
    int removeAtEnd();
    int removeAtIndex(int index);

    bool Swap(int index1, int index2);
    [[nodiscard]] Node* getHead() const { return head; }

  private:
    Node* head = nullptr;
    Node* tail = nullptr;
};