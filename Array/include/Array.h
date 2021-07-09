/*!
	<PRE>
	SOURCE FILE : Array.h
	DESCRIPTION.: Array class - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Data Structures Project.

	tail UPDATE.: Octuber 16th, 2015.
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

    // Max size
    int mSize = 0;

    // Current size
    int nrOfEl = 0;

    // The actual array
    T *arr;

public:
    // ***************************************************
    // ** Functions
    // ***************************************************

    // Class constructor
    Array(int size_ = 5);

    // Class Destructor
    ~Array();

    // Copy constructor
    Array(const Array &obj_);

    // Function to return the array size
    int size() const;

    // Function to add an element into the array
    void add(const T &obj_);

    // Function to get an element by its position
    T &get(int index);

    // ***************************************************
    // ** Overload operators
    // ***************************************************
    Array& operator=(const Array& rhs);
};

#include "Array.inl"
#endif

/* --------------------- [ End of the Array.h header ] ------------------- */
/* ========================================================================= */