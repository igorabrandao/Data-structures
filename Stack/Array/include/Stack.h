/*!
	<PRE>
	SOURCE FILE : Stack.h
	DESCRIPTION.: Stack class based on custom Array - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Data Structures Project.

	tail UPDATE.: July 23th, 2021.
	</pre>
*/
#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include "../../Array/include/Array.h"

using namespace std;

/**
 * Stack template class
 */
template <class T>
class Stack
{
private:
    // ***************************************************
    // ** Attributes
    // ***************************************************
    Array<T> *data; // The Array structure to holds the Stack data
    int currIndex;  // Holds the current position on the stack

    // ***************************************************
    // ** Methods
    // ***************************************************
    inline Stack(const Stack &){/* empty */}; // Disable copy constructor

public:
    // ***************************************************
    // ** Functions
    // ***************************************************
    Stack(int size_ = 5); // Class constructor
    ~Stack();             // Class Destructor
    void push(T data_);   // Method to add elements into the stack
    void pop();           // Method to remove elements from the stack following LIFO
    T top() const;        // Function to retrieve the last element from the stack
    int size() const;     // Returns the size of the stack
    bool isEmpty() const; // Function to check whether or not the stack is empty

    // ***************************************************
    // ** Overload operators
    // ***************************************************
};

#include "Stack.inl"
#endif

/* --------------------- [ End of the Stack.h header ] ------------------- */
/* ============================================================================ */