//
// Created by tangb on 2024-10-07.
//

#include "singlyLinkedList.h"

sll_Node::sll_Node(){
  this->head = nullptr;
}

sll_Node::sll_Node(int data){
  this->data = data;
  this->head = nullptr;
}

sll_Node::~sll_Node(){
  sll_Node* temp = head;
  while(temp != nullptr){
    head = head->next;
    delete temp;
    temp = head;
  }
  head = nullptr;
}

sll_Node::sll_Node(const sll_Node& other){

}

sll_Node& sll_Node::operator=(const sll_Node& other){

}

void sll_Node::Print(){

}

bool sll_Node::IsEmpty(){

}

bool sll_Node::InsertAtBeginning(){

}

bool sll_Node::InsertAtEnd(){

}

bool sll_Node::InsertAtIndex(int index){

}

int sll_Node::getSize(){

}

int sll_Node::removeAtBeginning(){

}

int sll_Node::removeAtEnd(){

}

int sll_Node::removeAtIndex(int index){

}

bool sll_Node::Swap(int index1, int index2){
  return false;
}