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
    int mSize;

    // Current size
    int nrOfEl;

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

    // Function to return the array size
    int size() const;

    // Function to add an element into the array
    void add(const T &obj_);

    // Function to get an element by its position
    T &get(int index);

    // ***************************************************
    // ** Overload operators
    // ***************************************************
};

#include "Array.inl"
#endif

/* --------------------- [ End of the Array.h header ] ------------------- */
/* ========================================================================= */