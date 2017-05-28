/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 03 City Infection
Date Last Modified: 02/6/2017
File Summary: Node header file
------------------------------------------*/
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
  T m_value;
  Node<T>* m_next;
public:
  Node(T value);
  T getValue();
  void setNext(Node* next);
  void setValue(T value);
  Node<T>* getNext();
};
#include "Node.cpp"
#endif
