/*!
	<PRE>
	SOURCE FILE : QueueLL.h
	DESCRIPTION.: QueueLL class based on custom Linked List - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Data Structures Project.

	tail UPDATE.: July 27th, 2021.
	</pre>
*/
#ifndef QUEUELL_H_
#define QUEUELL_H_

#include <iostream>
#include <string>
#include "../../../Linked_List/include/LinkedList.h"

using namespace std;

/**
 * QueueLL template class
 */
template <class T>
class QueueLL
{
private:
    // ***************************************************
    // ** Attributes
    // ***************************************************
    LinkedList<T> *data; // The Linked List structure to holds the QueueLL data
    int iSize;           // QueueLL max size
    int currIndex;       // Holds the current position on the queue

    inline QueueLL(const QueueLL &){/* empty */}; // Disable copy constructor

public:
    // ***************************************************
    // ** Functions
    // ***************************************************
    QueueLL();                                      // Class constructor
    inline ~QueueLL(){/* empty */};                 // Class Destructor
    int size() const;                               // Returns the size of the queue
    bool isEmpty() const;                           // Function to check whether or not the queue is empty
    bool isFull() const;                            // Function to check whether or not the queue is empty
    void push(T data_);                             // Method to add elements into the queue
    void pop();                                     // Method to remove elements from the queue following FIFO
    T front() const;                                // Function to retrieve the first element from the queue
    void print(bool, string queueName_ = "") const; // Method to print the queue
    void reverse();                                 // Method to reverse the queue

    // ***************************************************
    // ** Overload operators
    // ***************************************************
};

#include "QueueLL.inl"
#endif

/* --------------------- [ End of the QueueLL.h header ] ------------------- */
/* ============================================================================ */