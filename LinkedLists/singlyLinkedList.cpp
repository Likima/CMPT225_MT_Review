//
// Created by tangb on 2024-10-07.
//

#include "singlyLinkedList.h"

void SinglyLinkedList::Clear(){
  const Node* temp = head;
  while(temp != nullptr){
    head = head->next;
    delete temp;
    temp = head;
  }
  head = nullptr;
}

SinglyLinkedList::SinglyLinkedList(){
  this->head = nullptr;
}

SinglyLinkedList::SinglyLinkedList(const int data){
  head->data = data;
  this->head = nullptr;
}

SinglyLinkedList::~SinglyLinkedList() { Clear() }

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other) {
  if (other.head == nullptr) {
    head = nullptr;
    return;
  }

  const Node *temp = other.head;

  while (temp != nullptr) {
    Node *newNode = new Node(temp->data);

    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    temp = temp->next;
  }
}

SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList& other){
  if (this == &other) return *this; // Handle self-assignment
  
  Clear();
  
  if (other.head) {
    head = new Node(other.head->data);
    Node* current = head;
    const Node* otherCurrent = other.head->next;
    
    while(otherCurrent != nullptr){
      current->next = new Node(otherCurrent->data);
      current = current->next;
      otherCurrent = otherCurrent->next;
    }
  }
  
  return *this
}

void SinglyLinkedList::Print() const {
  const Node* temp = head;
  while(temp != nullptr){
    std::cout << temp->data;
    if(temp->next != nullptr) std::cout << " -> ";
  }
  std::cout << std::endl;
}

bool SinglyLinkedList::IsEmpty() const {
  return head == nullptr;
}

bool SinglyLinkedList::InsertAtBeginning(const int num){
  Node* newNode = new Node(num);
  newNode->next = head;
  head = newNode;

  return head != nullptr; // return the success
}

bool SinglyLinkedList::InsertAtEnd(const int num){
  Node* newNode = new Node(num);
  tail->next = newNode;
  tail = newNode;

  return newNode != nullptr;
}

bool SinglyLinkedList::InsertAtIndex(int index, const int num){
  if ( index == 0 ) return InsertAtBeginning(num);
  else if ( index == getSize()-1 ) return InsertAtEnd(num);

  Node* newNode = new Node(num);
  Node* current = head;

  for(int i = 0; i < index; i++) current = current->next;

  newNode->next = current->next;
  current->next = newNode;

  return newNode != nullptr;
}

int SinglyLinkedList::getSize() const {
  const Node* temp = head;
  int size = 0;
  while(temp != nullptr) {
    temp = temp->next;
    size++;
  }
  return size;
}

int SinglyLinkedList::removeAtBeginning(){
  const int returnValue = head->data;
  const Node* temp = head;
  if(head == nullptr) return 0;
  head = head->next;
  delete temp;
  return returnValue;
}

int SinglyLinkedList::removeAtEnd(){
  const int returnValue = tail->data;
  delete tail;
  tail = head;
  for(int i = 0; i < getSize() - 1; i++) tail = tail->next;
  return returnValue;
}

int SinglyLinkedList::removeAtIndex(int index){
  if ( index == 0 ) return removeAtBeginning();
  else if ( index == getSize() - 1 ) return removeAtEnd();

  Node* temp = head;
  for(int i = 0; i < index - 1; i++) temp = temp->next;

  Node* delNode = temp->next;
  const int returnValue = delNode->data;
  temp->next = delNode->next;
  delete delNode;

  return returnValue;
}

bool SinglyLinkedList::Swap(int index1, int index2){
  if ( index1 == index2 ) return true;

  const int indexOneValue = removeAtIndex(index1);
  const int indexTwoValue = removeAtIndex(index2);

  indexOneValue > indexTwoValue ?
    (InsertAtIndex(index2, indexTwoValue),
    InsertAtIndex(index1, indexOneValue))
   :
    (InsertAtIndex(index2, indexTwoValue),
    InsertAtIndex(index1, indexOneValue));

  return false;
}