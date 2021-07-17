/*!
	<PRE>
	SOURCE FILE : LinkedList.h
	DESCRIPTION.: LinkedList class - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Data Structures Project.

	tail UPDATE.: July 15th, 2021.
	</pre>
*/
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>
#include <string>

using namespace std;

/**
 * Node template class
 */
template <class T>
class Node
{
private:
    T data;
    Node<T> *next;

public:
    // ***************************************************
    // ** Methods
    // ***************************************************
    // Class constructor
    Node() : next(nullptr){};

    // Class constructor overload
    Node(T data_) : data(data_), next(nullptr){};

    // Adds the given node as next of the current node
    inline void setNext(Node *node) { this->next = node; };

    // Return pointer of the next node
    inline Node *Next() { return this->next; };

    // Returns data of the current node
    inline T Data() { return this->data; };
};

/**
 * LinkedList template class
 */
template <class T>
class LinkedList
{
private:
    // ***************************************************
    // ** Attributes
    // ***************************************************
    int listSize = 0; // The list size
    Node<T> *head;    // The head of the list
    Node<T> *tail;    // The tail of the list

public:
    // ***************************************************
    // ** Functions
    // ***************************************************
    LinkedList();                                // Class constructor
    ~LinkedList();                               // Class Destructor
    LinkedList(const LinkedList &obj_);          // Copy constructor
    void push_front(T data_);                    // Function to add a value to the front of the list
    void push_back(T data_);                     // Function to add a value to the back of the list
    void pop_front();                            // Function to remove the first value of the list
    void pop_back();                             // Function to remove the last value of the list
    void print(bool, string llName_ = "") const; // Function to print the linked list
    int length() const;                          // Function to return the number of elements in the list

    // ***************************************************
    // ** Overload operators
    // ***************************************************
};

#include "LinkedList.inl"
#endif

/* --------------------- [ End of the LinkedList.h header ] ------------------- */
/* ============================================================================ */