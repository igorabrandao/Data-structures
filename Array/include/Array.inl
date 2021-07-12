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
	// Define the Array initial attributes
	this->mSize = size_;
	this->nrOfEl = 0;

	// Allocate the necessary memory to it
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
 * Copy constructor (deep copy)
 */
template <typename T>
Array<T>::Array(const Array &obj_)
{
	// Get the original array size
	int size = obj_.size();

	// Allocate the necessary memory to the new array
	this->arr = new T[size];

	for (int i = 0; i < size; i++)
	{
		// Copy each element from the origin array
		this->arr[i] = obj_.arr[i];
	}

	// Update the number of elements
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
T &Array<T>::getAt(int index_) const
{
	if (index_ < 0 || index_ >= this->nrOfEl)
		throw std::out_of_range("<< Index out of range exception! >>");

	return this->arr[index_];
}

template <typename T>
void Array<T>::expand(int newSize_)
{
	int szToExpand = newSize_;

	// If the new size wasn't informed, just double the Array
	if (szToExpand == 0)
		szToExpand *= 2;

	// Create a temp Array and allocate the necessary memory to it
	this->arr = new T[size];

	for (auto i = 0; i < this->nrOfEl; i++)
	{
		// Copy each element from the origin array
		temp[i] = new T(*this->arr[i]);
	}
}

/**
 * Function to print the array
 */
template <typename T>
void Array<T>::print(string arrayName_) const
{
	if (arrayName_.compare("") != 0)
		cout << arrayName_ << ": [ ";
	else
		cout << "[ ";

	// Print the new int array values
	for (int i = 0; i < this->size(); i++)
	{
		cout << this->getAt(i) << " ";
	}

	cout << "]" << endl;
}

// ***************************************************
// ** Overload operators
// ***************************************************

/**
 * Overload of the operator=
 * 
 * Implemented to support the following:
 * 
 * array1 = array2 = array3; cascading assignment
 * array1 = array1; self-assignment
 * (array1 = array2) = array3; odd but valid
 */
template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs)
{
	// Verify if it's a self-assignment
	if (this != &rhs)
	{
		// Free the memory of the current Array
		delete[] arr;

		// Perform the deep copy of the rhs
		int size = rhs.size();
		this->arr = new T[size];

		for (int i = 0; i < size; i++)
		{
			// Copy each element from the origin array
			this->arr[i] = rhs.arr[i];
		}

		// Update the number of elements
		this->nrOfEl = size;
	}

	// Return a reference for Array for cascading assignment
	return (*this);
}

/**
 * Overload of the operator[]
 */
template <typename T>
T &Array<T>::operator[](int index_)
{
	return this->getAt(index_);
}

template <typename T>
const T &Array<T>::operator[](int index_) const
{
	return this->getAt(index_);
}