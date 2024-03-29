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
Stack<T>::Stack()
{
	// Set the strack basic attributes
	this->iSize = 0;
	this->currIndex = 0;

	// Initialize the stack
	this->data = new Array<T>(this->iSize);
}

/**
 * Returns the size of the stack
 */
template <typename T>
int Stack<T>::size() const
{
	return this->currIndex;
}

/**
 * Function to check whether or not the stack is empty
 */
template <typename T>
bool Stack<T>::isEmpty() const
{
	return (this->currIndex == 0 ? true : false);
}

/**
 * Function to check whether or not the stack is empty
 */
template <typename T>
bool Stack<T>::isFull() const
{
	return (this->currIndex == iSize ? true : false);
}

/**
 * Method to add elements into the stack
 */
template <typename T>
void Stack<T>::push(T data_)
{
	// Check if the stack is full
	if (this->isFull())
	{
		// Expand the array size to fit the new stack data
		this->iSize = (this->iSize == 0 ? 1 : this->iSize * 2);
		this->data->expand(this->iSize);
	}
	
	// Add the new value to the stack
	this->data->add(data_);

	// Update the index
	this->currIndex++;
}

/**
 * Method to remove elements from the stack following LIFO
 */
template <typename T>
void Stack<T>::pop()
{
	// Check if the stack is empty
	if (this->isEmpty())
		cout << "<< Stack is Empty! >>" << endl; // stack underflow
	else
	{
		// Remove the value from the stack
		this->data->remove(this->currIndex - 1);

		// Update the index
		this->currIndex--;
	}
}

/**
 * Function to retrieve the last element from the stack
 */
template <typename T>
T Stack<T>::top() const
{
	// Check if the stack is empty
	if (this->isEmpty())
	{
		cout << "<< Stack is Empty! >>" << endl;
		return T();
	}
	else
	{
		// Return the last element from the stack
		return this->data->getAt(this->currIndex - 1);
	}
}

/**
 * Method to print the stack
 */
template <typename T>
void Stack<T>::print(bool showLength_, string stackName_) const
{
	this->data->print(stackName_);

	if (showLength_)
		cout << "size: " << this->size() << endl;

	cout << endl;
}

// ***************************************************
// ** Overload operators
// ***************************************************