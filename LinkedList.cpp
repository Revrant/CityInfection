/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 03 City Infection
Date Last Modified: 02/13/2017
File Summary: Holds all functions for creating the linked list
------------------------------------------*/
#include "LinkedList.h"

//*********************************************************************
//
//     CONSTRUCTOR
//
//*********************************************************************
template <typename T>
LinkedList<T>::LinkedList()
{
        m_front = nullptr;
        m_length = 0;
}

//*********************************************************************
//
//     DESTRUCTOR
//
//*********************************************************************

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* temp = m_front;
    while(temp != nullptr)
    {
        Node<T>* next = temp->getNext();
        delete temp;
        temp = next;
    }
}

//*********************************************************************
//
//     IS EMPTY
//
//*********************************************************************

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return(m_front == nullptr);
}

//*********************************************************************
//
//     GET LENGTH
//
//*********************************************************************

template <typename T>
int LinkedList<T>::getLength() const
{
    return(m_length);
}

//*********************************************************************
//
//     POSITION OF
//
//*********************************************************************

template <typename T>
int LinkedList<T>::positionOf(T value) const
{
    int position = 0;
    Node<T>* temp = m_front;
    while(temp != nullptr)
    {
        position++;
        if(temp->getItem()==value)
        {
            return (position);
        }
        else
        {
          temp = temp->getNext();
        }
    }
    return(0);
}

//*********************************************************************
//
//     ADD BACK
//
//*********************************************************************

template <typename T>
void LinkedList<T>::addBack(T value)
{
    Node<T>* temp = m_front;
    if(temp == nullptr)
    {
      addFront(value);
    }
    else
    {
        Node<T>* newNode = new Node<T>(value);

        while(temp->getNext()!=nullptr)
        {
          temp = temp->getNext();
        }
        temp->setNext(newNode);
        m_length++;
    }
}

//*********************************************************************
//
//     ADD FRONT
//
//*********************************************************************

template <typename T>
void LinkedList<T>::addFront(T value)
{
    Node<T>* oldFront = m_front;
    Node<T>* newFront = new Node<T>(value);
    newFront->setNext(oldFront);
    m_front = newFront;
    m_length++;
}

//*********************************************************************
//
//     INSERT
//
//*********************************************************************

template <typename T>
bool LinkedList<T>::insert(int position, T value)
{
    if(position < 1 || position > m_length + 1)
        {
          return(false);
        }
    else
    {
        if(position == 1)
        {
            addFront(value);
            return(true);
        }
        if(position == m_length + 1)
        {
            addBack(value);
            return(true);
        }
        Node<T>* temp = m_front;
        int tempPos = 2;

        while(position > tempPos)
        {
            temp = temp->getNext();
            tempPos++;
        }
        Node<T>* newNode = new Node<T>(value);
        newNode->setNext(temp->getNext());
        temp->setNext(newNode);
        m_length++;
        return(true);
    }
}

//*********************************************************************
//
//     REMOVE BACK
//
//*********************************************************************

template <typename T>
bool LinkedList<T>::removeBack()
{
    if(m_front == nullptr)
    {
        return(false);
    }

    Node<T>* temp = m_front->getNext();
    Node<T>* prev = m_front;

    while(temp->getNext() != nullptr)
    {
        temp = temp->getNext();
        prev = prev->getNext();
    }

    prev->setNext(nullptr);

    delete temp;
    m_length--;

    return(true);
}

//*********************************************************************
//
//     REMOVE FRONT
//
//*********************************************************************

template <typename T>
bool LinkedList<T>::removeFront()
{
    if(m_front == nullptr)
    {
      return false;
    }

    Node<T>* oldFront = m_front;
    Node<T>* newFront = m_front->getNext();
    m_front = newFront;

    delete oldFront;
    m_length--;
    return(true);
}

//*********************************************************************
//
//     REMOVE AT
//
//*********************************************************************

template <typename T>
bool LinkedList<T>::removeAt(int position)
{
    if(position < 1 || position > m_length)
    {
      return(false);
    }

    if(position == 1)
    {
      return(removeFront());
    }

    if(position == m_length)
    {
      return(removeBack());
    }

    Node<T>* temp = m_front->getNext();
    Node<T>* prev = m_front;


    int tempPos = 2;
    while(position > tempPos)
    {
        temp = temp->getNext();
        prev = prev->getNext();
	      tempPos++;
    }
    prev->setNext(temp->getNext());
    delete temp;
    m_length--;

    return(true);
}

//*********************************************************************
//
//     SET ENTRY
//
//*********************************************************************

template <typename T>
void LinkedList<T>::setEntry(int position, T value)
{
    if(position < 1 || position > m_length)
    {
      return;
    }
    else
    {
        Node<T>* temp = m_front;

        int tempPos = 1;
        while(tempPos < position)
        {
            temp = temp->getNext();
            tempPos++;
        }
        temp->setValue(value);
    }
}

//*********************************************************************
//
//     GET ENTRY
//
//*********************************************************************

template <typename T>
T LinkedList<T>::getEntry(int position) const
{
    if(position < 1 || position > m_length)
      {
        throw std::invalid_argument("ERROR: Invalid position");
      }
    else
    {
        Node<T>* temp = m_front;

        int tempPos = 1;
        while(tempPos < position)
        {
            temp = temp->getNext();
            tempPos++;
        }
        return(temp->getValue());
    }
}













//SPACE
