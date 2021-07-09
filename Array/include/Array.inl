// ***************************************************
// ** Implements the functions from Array class
// ***************************************************
#include "Array.h"

// ***************************************************
// ** Functions
// ***************************************************

/**
 * Class constructor
 */
template <typename T>
Array<T>::Array(int size_)
{
	this->mSize = size_;
	this->nrOfEl = 0;
	this->arr = new T[this->mSize];
}

/**
 * Class destructor
 */
template <typename T>
Array<T>::~Array()
{
	// Delete the Array pointer
	delete[] this->arr;
}

/**
 * Copy constructor
 */
template <typename T>
Array<T>::Array(const Array &obj_)
{
	// Get the origin array size
	int size = obj_.size();

	// Allocate the necessary memory into the new array
	this->arr = new T[size];

	for (int i = 0; i < size; i++)
	{
		// Copy each element from the origin array
		this->arr[i] = obj_.arr[i];
	}

	// Increment the number of elements
	this->nrOfEl = size;
}

/**
 * Function to return the array size
 */
template <typename T>
int Array<T>::size() const
{
	return this->nrOfEl;
}

/**
 * Function to add an element into the array
 */
template <typename T>
void Array<T>::add(const T &obj_)
{
	if (this->nrOfEl < this->mSize)
		this->arr[this->nrOfEl++] = obj_;
	else
		cout << "<<< Array is full!" << endl;
}

/**
 * Function to get an element by its position
 */
template <typename T>
T &Array<T>::get(int index)
{
	if (index < 0 || index >= this->nrOfEl)
		throw "Bad index!";

	return this->arr[index];
}

// ***************************************************
// ** Overload operators
// ***************************************************