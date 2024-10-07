//
// Created by tangb on 2024-10-07.
//

#pragma once

class sll_Node { // Singly Linked List node
  public:
    sll_Node* next;

    sll_Node();    // Default ctor
    sll_Node(int); // Constructor for an int arg provided
    ~sll_Node();

    sll_Node(const sll_Node& other);
    sll_Node& operator=(const sll_Node& other);

    void Print();
    bool IsEmpty();
    bool InsertAtBeginning();
    bool InsertAtEnd();
    bool InsertAtIndex(int index);

    int getSize();
    int removeAtBeginning();
    int removeAtEnd();
    int removeAtIndex(int index);

    bool Swap(int index1, int index2);

  private:
    int data;
    sll_Node* head;
};