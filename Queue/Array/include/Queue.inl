// ***************************************************
// ** Implements the functions from Queue class
// ***************************************************
#include "Queue.h"

// ***************************************************
// ** Functions
// ***************************************************

/**
 * Class constructor
 */
template <typename T>
Queue<T>::Queue()
{
	// Set the strack basic attributes
	this->iSize = 0;
	this->currIndex = 0;

	// Initialize the queue
	this->data = new Array<T>(this->iSize);
}

/**
 * Returns the size of the queue
 */
template <typename T>
int Queue<T>::size() const
{
	return this->currIndex;
}

/**
 * Function to check whether or not the queue is empty
 */
template <typename T>
bool Queue<T>::isEmpty() const
{
	return (this->size() == 0 ? true : false);
}

/**
 * Function to check whether or not the queue is empty
 */
template <typename T>
bool Queue<T>::isFull() const
{
	return (this->currIndex == iSize ? true : false);
}

/**
 * Method to add elements into the queue
 */
template <typename T>
void Queue<T>::push(T data_)
{
	// Check if the queue is full
	if (this->isFull())
	{
		// Expand the array size to fit the new queue data
		this->iSize = (this->iSize == 0 ? 1 : this->iSize * 2);
		this->data->expand(this->iSize);
	}

	// Add the new value to the queue
	this->data->add(data_);

	// Update the index
	this->currIndex++;
}

/**
 * Method to remove elements from the queue following FIFO
 */
template <typename T>
void Queue<T>::pop()
{
	// Check if the queue is empty
	if (this->isEmpty())
	{
		cout << "<< Queue is Empty! >>" << endl; // queue underflow
	}
	else
	{
		// Remove the value from the queue
		this->data->remove(0);

		// Update the index
		this->currIndex--;
	}
}

/**
 * Function to retrieve the first element from the queue
 */
template <typename T>
T Queue<T>::front() const
{
	// Check if the queue is empty
	if (this->isEmpty())
	{
		cout << "<< Queue is Empty! >>" << endl;
		return T();
	}
	else
	{
		// Return the last element from the queue
		return this->data->getAt(0);
	}
}

/**
 * Method to print the queue
 */
template <typename T>
void Queue<T>::print(bool showLength_, string queueName_) const
{
	this->data->print(queueName_);

	if (showLength_)
		cout << "size: " << this->size() << endl;

	cout << endl;
}

// ***************************************************
// ** Overload operators
// ***************************************************