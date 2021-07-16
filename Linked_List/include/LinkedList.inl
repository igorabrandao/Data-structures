// ***************************************************
// ** Implements the functions from LinkedList class
// ***************************************************
#include "LinkedList.h"

// ***************************************************
// ** Functions
// ***************************************************

/**
 * Class constructor
 */
template <typename T>
LinkedList<T>::LinkedList()
{
	// Initialize the list head
	this->head = new Node(nullptr);
}

/**
 * Class destructor
 */
template <typename T>
LinkedList<T>::~LinkedList()
{
	// Delete the LinkedList pointer
	delete[] this->head;

	// TODO: needs to delete all nodes
}

/**
 * Copy constructor (deep copy)
 */
template <typename T>
LinkedList<T>::LinkedList(const LinkedList &obj_)
{
	// TODO
}

/**
 * Function to add a value to the back of the list
 */
template <typename T>
void LinkedList<T>::push_back(T data_)
{
	// TODO
}

/**
 * Function to add a value to the front of the list
 */
template <typename T>
void LinkedList<T>::push(T data_)
{
	// Create the new node
	Node newNode = new Node(data_);

	// Link the current first value with the new one
	newNode->next = this->head;

	// Link the head to the new value
	this->head->next = newNode;
}

/**
 * Function to remove the last node of the list
 */
template <typename T>
void LinkedList<T>::pop()
{
	// Check if the list has any elements
	if (this->head != nullptr)
	{
		// Create a pointer to the list head
		Node *node = this->head;

		// Assign the head to the second element
		this->head = this->head->next;

		// Delete the first element
		delete node;
	}
}

/**
 * Function to print the linked list
 */
template <typename T>
void LinkedList<T>::print(string listName_) const
{
	// TODO
}

// ***************************************************
// ** Overload operators
// ***************************************************