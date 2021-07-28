// ***************************************************
// ** Implements the functions from Queue class
// ***************************************************
#include "QueueLL.h"

// ***************************************************
// ** Functions
// ***************************************************

/**
 * Class constructor
 */
template <typename T>
QueueLL<T>::QueueLL()
{
	// Set the strack basic attributes
	this->iSize = 0;
	this->currIndex = 0;

	// Initialize the queue
	this->data = new LinkedList<T>();
}

/**
 * Returns the size of the queue
 * 
 * time complexity: O(1)
 */
template <typename T>
int QueueLL<T>::size() const
{
	return this->currIndex;
}

/**
 * Function to check whether or not the queue is empty
 * 
 * time complexity: O(1)
 */
template <typename T>
bool QueueLL<T>::isEmpty() const
{
	return (this->size() == 0 ? true : false);
}

/**
 * Function to check whether or not the queue is empty
 * 
 * time complexity: O(1)
 */
template <typename T>
bool QueueLL<T>::isFull() const
{
	return (this->currIndex == iSize ? true : false);
}

/**
 * Method to add elements into the queue
 * 
 * time complexity: O(1)
 */
template <typename T>
void QueueLL<T>::push(T data_)
{
	// Add the new value to the queue
	this->data->push_back(data_);

	// Update the index
	this->currIndex++;
}

/**
 * Method to remove elements from the queue following FIFO
 * 
 * time complexity: O(1)
 */
template <typename T>
void QueueLL<T>::pop()
{
	// Check if the queue is empty
	if (this->isEmpty())
	{
		cout << "<< Queue is Empty! >>" << endl; // queue underflow
	}
	else
	{
		// Remove the first value from the queue
		this->data->pop_front();

		// Update the index
		this->currIndex--;
	}
}

/**
 * Function to retrieve the first element from the queue
 * 
 * time complexity: O(1)
 */
template <typename T>
T QueueLL<T>::front() const
{
	// Check if the queue is empty
	if (this->isEmpty())
	{
		cout << "<< Queue is Empty! >>" << endl;
		return T();
	}
	else
	{
		// Return the first element from the queue
		return this->data->Head()->Next()->Data();
	}
}

/**
 * Method to print the queue
 * 
 * time complexity: O(n) by n elements
 * in other words, O(n)/n = O(1) per element
 */
template <typename T>
void QueueLL<T>::print(bool showLength_, string queueName_) const
{
	this->data->print(true, queueName_);
}

/**
 * Function to reverse the queue
 * 
 * time complexity: O(n)
 * space complexity: O(n)
 */
template <typename T>
void QueueLL<T>::reverse()
{
	// Create a temp list
	LinkedList<T> *temp = new LinkedList<T>();

	while (!this->isEmpty())
	{
		temp->push_front(this->front());
		this->pop();
	}

	// Copy the new list
	this->data = temp;
}

// ***************************************************
// ** Overload operators
// ***************************************************