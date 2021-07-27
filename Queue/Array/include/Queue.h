/*!
	<PRE>
	SOURCE FILE : Queue.h
	DESCRIPTION.: Queue class based on custom Array - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Data Structures Project.

	tail UPDATE.: July 27th, 2021.
	</pre>
*/
#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <string>
#include "../../../Array/include/Array.h"

using namespace std;

/**
 * Queue template class
 */
template <class T>
class Queue
{
private:
    // ***************************************************
    // ** Attributes
    // ***************************************************
    Array<T> *data; // The Array structure to holds the Queue data
    int iSize;      // Queue max size
    int currIndex;  // Holds the current position on the queue

    inline Queue(const Queue &){/* empty */}; // Disable copy constructor

public:
    // ***************************************************
    // ** Functions
    // ***************************************************
    Queue();                                        // Class constructor
    inline ~Queue(){/* empty */};                   // Class Destructor
    int size() const;                               // Returns the size of the queue
    bool isEmpty() const;                           // Function to check whether or not the queue is empty
    bool isFull() const;                            // Function to check whether or not the queue is empty
    void push(T data_);                             // Method to add elements into the queue
    void pop();                                     // Method to remove elements from the queue following FIFO
    T front() const;                                // Function to retrieve the first element from the queue
    void print(bool, string queueName_ = "") const; // Method to print the queue

    // ***************************************************
    // ** Overload operators
    // ***************************************************
};

#include "Queue.inl"
#endif

/* --------------------- [ End of the Queue.h header ] ------------------- */
/* ============================================================================ */