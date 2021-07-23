// ***************************************************
// ** Implements the functions from Stack class
// ***************************************************
#include "Stack.h"

// ***************************************************
// ** Functions
// ***************************************************

/**
 * Class constructor
 */
template <typename T>
Stack<T>::Stack(int size_)
{
	// Initialize the stack basic attributes
}

/**
 * Class destructor
 */
template <typename T>
Stack<T>::~Stack()
{
	// Delete the array data
	delete[] this->data;
}

// ***************************************************
// ** Overload operators
// ***************************************************