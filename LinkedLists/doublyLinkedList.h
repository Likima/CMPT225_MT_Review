//
// Created by tangb on 2024-10-07.
//

#pragma once

class doublyLinkedList {
    public:
        doublyLinkedList();                // Constructor
        ~doublyLinkedList();               // Destructor

        void insertAtHead(int data);       // Insert node at the beginning
        void insertAtTail(int data);       // Insert node at the end
        void insertAtPosition(int data, int position); // Insert node at a specific position
        void deleteAtHead();               // Delete node from the beginning
        void deleteAtTail();               // Delete node from the end
        void deleteAtPosition(int position); // Delete node at a specific position
        int search(int data);              // Search for a node with the given data
        bool isEmpty() const;              // Check if the list is empty
        int getSize() const;               // Get the size of the list

    private:
        struct Node {
            int data;
            Node* prev;
            Node* next;
        };

        Node* head;
        Node* tail;
        int size;                          // Track the size of the list
};


