//
// Created by tangb on 2024-10-07.
//

#include "singlyLinkedList.h"

/*
----------------------- <FUNCTION OVERVIEW> -----------------------
Prototype:
Name:
Purpose:
Arguments:
Running Time:
  Explanation:
Cost function:
  Explanation:
Function Description:
Example:
---------------------- </FUNCTION OVERVIEW> -----------------------
*/

/*
----------------------- <FUNCTION OVERVIEW> -----------------------
Prototype: void SinglyLinkedList::Clear()
Name: Clear
Purpose: used for clearing the list manually without destructor
Arguments: None
Running Time: O(n)
  Explanation: For loop looping through the linked list
Cost function: 3n + 2
  Explanation: 3n : recurses through 3 commands n times.
               2  : 2 other commands
Function Description:
  a temp variable is used to recurse through the list such that we
  can do the process of
  HEAD MOVES ON TO THE NEXT THING IN THE LL
  DELETE THE PREVIOUS THING IN THE HEAD
  REPEAT UNTIL HEAD IS NULLPTR

Example:
  say we have a linked list:
    1 -> 2 -> 3 -> 4
  and we want to delete it. Since each of the elements are dynamically
  allocated, we must free each one individually.

  At iteration 0, our pointers will look something like this:
   head           tail
    v              v
    1 -> 2 -> 3 -> 4 -> nullptr
    ^
   temp
  then we can realize that if we delete the head WITHOUT the temp, we are left
  with a hanging pointer, as we have no way to access the 2. Thus, we move it
  to the two, and delete the 1 using the temp.

        head      tail
         v         v
    1 -> 2 -> 3 -> 4 -> nullptr
    ^
   temp

   Now we may safely delete temp with access to the rest of the linked list.

---------------------- </FUNCTION OVERVIEW> -----------------------
*/

void SinglyLinkedList::Clear(){
  const Node* temp = head;
  while(temp != nullptr){
    head = head->next;
    delete temp;
    temp = head;
  }
  head = nullptr;
}

/*
----------------------- <FUNCTION OVERVIEW> -----------------------
Prototype: SinglyLinkedList::SinglyLinkedList()
Name: Default Constructor
Purpose: used for initialization with no arguments
Arguments: None
Running Time: O(1)
  Explanation: one command
Cost function: 1
  Explanation: one command
Function Description: Literally just sets the head to nullptr
---------------------- </FUNCTION OVERVIEW> -----------------------
*/

SinglyLinkedList::SinglyLinkedList(){
  head = nullptr;
  tail = nullptr;
}

/*
----------------------- <FUNCTION OVERVIEW> -----------------------
Prototype: SinglyLinkedList::SinglyLinkedList(const int data)
Name: Constructor
Purpose: used for initialization with one argument
Arguments: const int data : initializes the head to have a value
Running Time: O(1)
  Explanation: One command
Cost function: 1
  Explanation: One command
Function Description: Dynamically allocates the head to a value
Example:
  if we send 1 to this constructor, our head will initialize to a
  dynamic Node with a next value of nullptr

  1 -> nullptr
---------------------- </FUNCTION OVERVIEW> -----------------------
*/

SinglyLinkedList::SinglyLinkedList(const int data){
  head = new Node(data);
  tail = head;
}

/*
----------------------- <FUNCTION OVERVIEW> -----------------------
Prototype: SinglyLinkedList::~SinglyLinkedList()
Name: Destructor
Purpose: When the linked list goes out of scope, this is called to free dynamically allocated memory
Arguments: None
Running Time: O(n)
  Explanation: calls Clear, which is O(n). Refer to Function Overview of Clear
Cost function: 3n+2
  Explanation: refer to Function Overview of Clear
Function Description: calls clear, which frees all dynamically allocated memory
---------------------- </FUNCTION OVERVIEW> -----------------------
*/
SinglyLinkedList::~SinglyLinkedList() { Clear() }


/*
*DEEP COPY DEFN: changes to the initial linked list will not change the copied linked list
----------------------- <FUNCTION OVERVIEW> -----------------------
Prototype: SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other)
Name: copy constructor
Purpose: creates a DEEP COPY* of the passed linked list (other)
Arguments: SinglyLinkedList& other : copy things from this
Running Time: O(n)
  Explanation: iterates through the linked list
Cost function: 4n + 1
  Explanation: 4 commands happen in the loop, one happens outside the loop
Function Description: Deep copies a passed linked list. Implements the use
  of the tail, which may not be tested. If the tail is not implemented, you can
  use temp nodes to iterate and copy like in Assignment 1.
---------------------- </FUNCTION OVERVIEW> -----------------------
*/
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

/*
*DEEP COPY DEFN: changes to the initial linked list will not change the copied linked list
----------------------- <FUNCTION OVERVIEW> -----------------------
Prototype: SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList& other)
Name: overloaded assignment operator
Purpose: creates a DEEP COPY* of the passed linked list (other)
Arguments: SinglyLinkedList& other : copy things from this
Running Time: O(n)
  Explanation: iterates through the linked list
Cost function: (3n + 3) + (3n + 2) = 6n + 5
  Explanation: 3 commands happen in the loop, 3 happen outside the loop. + Clear cost function
Function Description: Deep copies a passed linked list. Does NOT implement the use
  of the tail. Usually if the tail is provided, you would use it, but I didn't for the sake
  of doing it without the tail.
---------------------- </FUNCTION OVERVIEW> -----------------------
*/
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
  
  return *this;
}

/*
----------------------- <FUNCTION OVERVIEW> -----------------------
Prototype: void SinglyLinkedList::Print() const
Name: Print()
Purpose: prints out a linked list
Arguments: None
Running Time: O(n)
  Explanation: iterates through linked list
Cost function: 2n + 2
  Explanation: 2 commands inside loop and 2 outside loop
Function Description: prints out a linked list
---------------------- </FUNCTION OVERVIEW> -----------------------
*/
void SinglyLinkedList::Print() const {
  const Node* temp = head;
  while(temp != nullptr){
    std::cout << temp->data;
    if(temp->next != nullptr) std::cout << " -> ";
  }
  std::cout << std::endl;
}

/*
----------------------- <FUNCTION OVERVIEW> -----------------------
Prototype: bool SinglyLinkedList::IsEmpty() const
Name: IsEmpty
Purpose: returns true iff the linked list is empty
Arguments: none
Running Time: O(1)
  Explanation: one command
Cost function: 1
  Explanation: one command
Function Description: refer to purpose
---------------------- </FUNCTION OVERVIEW> -----------------------
*/
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