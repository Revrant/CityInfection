/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 03 City Infection
Date Last Modified: 02/13/2017
File Summary: Linked List header file
------------------------------------------*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

template <typename T>
class LinkedList
{
private:
  Node<T>* m_front;
  int m_length;
public:
  /**
    * @pre - none
    * @post - Constructs linked list
    * @return - nothing
    **/
  LinkedList();
  /**
    * @pre - Linked list
    * @post - Destructs linked lists
    * @return - nothing
    **/
  ~LinkedList();
  /**
    * @pre - Requires linked list
    * @post - looks at Node
    * @return - T value
    **/
  Node<T>* getNode(int index);
  /**
    * @pre - Linked List
    * @post - Adds value to front of node
    * @return - void
    **/
  void addFront(T value);
  /**
    * @pre - None
    * @post - None
    * @return - Bool
    **/
  bool isEmpty() const;
  /**
    * @pre - Linked List
    * @post - Nothing
    * @return - length of linked list
    **/
  int getLength() const;
  /**
    * @pre - LinkedList
    * @post - Nothing
    * @return - Position of Node
    **/
  int positionOf(T value) const;
  /**
    * @pre - Linked List
    * @post - adds node to back of List
    * @return - void
    **/
  void addBack(T value);
  /**
    * @pre - Linked List
    * @post - inserts node into list
    * @return - Bool
    **/
  bool insert(int position, T value);
  /**
    * @pre - Linked List
    * @post - Removes Node from back of list
    * @return - bool
    **/
  bool removeBack();
  /**
    * @pre - Linked List
    * @post - removes Node from front of List
    * @return - bool
    **/
  bool removeFront();
  /**
    * @pre - Linked List
    * @post - Removes specific Node fron list
    * @return - bool
    **/
  bool removeAt(int position);
  /**
    * @pre - Linked List
    * @post - Sets T value in Node
    * @return - void
    **/
  void setEntry(int position, T value);
  /**
    * @pre - Linked List
    * @post - Nothing
    * @return - T value
    **/
  T getEntry(int position) const;
};
#include "LinkedList.cpp"
#endif
