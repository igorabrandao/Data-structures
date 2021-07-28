/*!
	<PRE>
	SOURCE FILE : Array.h
	DESCRIPTION.: Array class - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Data Structures Project.

	tail UPDATE.: July 12th, 2021.
	</pre>
*/
#ifndef Array_H_
#define Array_H_

#include <iostream>
#include <string>

using namespace std;

/**
 * Array template class
 */
template <class T>
class Array
{
private:
    // ***************************************************
    // ** Attributes
    // ***************************************************
    int mSize = 0;  // Max size
    int nrOfEl = 0; // Current size
    T *arr;         // The actual array

public:
    // ***************************************************
    // ** Functions
    // ***************************************************
    Array(int size_ = 5);                     // Class constructor
    ~Array();                                 // Class Destructor
    Array(const Array &obj_);                 // Copy constructor
    int size() const;                         // Function to return the array size
    void push(const T &obj_);                 // Method to add an element and expand the the array if it's necessary
    void add(const T &obj_);                  // Method to add an element into the array
    void addAt(int index_, const T &obj_);    // Method to add an element into a give position the array
    void remove(int index_);                  // Method to remove an element from the array
    T &getAt(int index_) const;               // Function to get an element by its position
    void expand(int newSize_ = 0);            // Method to expand the array N positions
    void print(string arrayName_ = "") const; // Method to print the array

    // ***************************************************
    // ** Overload operators
    // ***************************************************
    Array &operator=(const Array &rhs);
    T &operator[](int index_);
    const T &operator[](int index_) const;
};

#include "Array.inl"
#endif

/* --------------------- [ End of the Array.h header ] ------------------- */
/* ========================================================================= */