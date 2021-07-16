/*!
	<PRE>
	SOURCE FILE : LinkedList.h
	DESCRIPTION.: LinkedList class - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Data Structures Project.

	tail UPDATE.: July 12th, 2021.
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
public:
    T data;
    Node *next;

    // Class constructor
    Node(T data_)
    {
        data = data_;
        next = NULL;
    }
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
    Node *head;       // The head of the list

public:
    // ***************************************************
    // ** Functions
    // ***************************************************
    LinkedList();                          // Class constructor
    ~LinkedList();                         // Class Destructor
    LinkedList(const LinkedList &obj_);    // Copy constructor
    void push_back(T data_);               // Function to add a value to the back of the list
    void push(T data_);                    // Function to add a value to the front of the list
    void pop();                            // Function to remove the first value of the list
    void pop_back();                       // Function to remove the last value of the list
    void print(string llName_ = "") const; // Function to print the linked list

    // ***************************************************
    // ** Overload operators
    // ***************************************************
};

#include "LinkedList.inl"
#endif

/* --------------------- [ End of the LinkedList.h header ] ------------------- */
/* ============================================================================ */