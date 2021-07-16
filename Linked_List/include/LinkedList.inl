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
	this->head = new Node<T>();
}

/**
 * Class destructor
 */
template <typename T>
LinkedList<T>::~LinkedList()
{
	// Create a pointer to the list head
	Node<T> *currNode = this->head;
	Node<T> *nextNode;

	// Loop over the list until it reachs the tail
	while (currNode != nullptr)
	{
		nextNode = currNode->Next();
		delete currNode;
		currNode = nextNode;
	}
}

/**
 * Copy constructor (deep copy)
 */
template <typename T>
LinkedList<T>::LinkedList(const LinkedList &obj_)
{
	// Temp pointer to loop over the original list
	Node<T> *temp = obj_.head;

	// Initialize the list head
	this->head = new Node<T>();

	// Iterate through the end of the list
	while (temp && temp->Next())
	{
		/**
		 * Set the copied node as next of last node
		 * (Current List)->(Node)
		 */
		this->push_back(temp->Next()->Data());

		// Go to the next node of the original list
		temp = temp->Next();
	}
}

/**
 * Function to add a value to the front of the list
 */
template <typename T>
void LinkedList<T>::push_front(T data_)
{
	// Create a new node
	Node<T> *newNode = new Node<T>(data_);

	/**
	 * Set Next of Node to Head of the current list
	 * (Node)->(Current List)
	 */
	newNode->setNext(this->head);

	// Set the Head pointer to the new node
	this->head = newNode;

	// Update the list size
	this->listSize++;
}

/**
 * Function to add a value to the back of the list
 */
template <typename T>
void LinkedList<T>::push_back(T data_)
{
	// Create the new node
	Node<T> *newNode = new Node<T>(data_);

	// List is empty so new node is a head
	if (this->head->Next() == nullptr)
	{
		this->head->setNext(newNode);
	}
	else
	{
		Node<T> *currNode = this->head;

		/**
		 * Iterate through the end of the list and set new node as next
		 * of last node
		 * (Current List)->(Node)
		 */
		while (currNode && currNode->Next())
		{
			currNode = currNode->Next();
		}

		/**
		 * At this point curr is the last node
		 * Set newNode as the next of the last node
		 */
		currNode->setNext(newNode);
	}

	// Update the list size
	this->listSize++;
}

/**
 * Function to remove the last node of the list
 */
template <typename T>
void LinkedList<T>::pop_front()
{
	// Check if the list has any elements
	if (this->head != nullptr)
	{
		// Create a pointer to the list head
		Node<T> *node = this->head;

		// Assign the head to the second element
		this->head = this->head->Next();

		// Delete the first element
		delete node;

		// Update the list size
		this->listSize--;
	}
}

/**
 * Function to print the linked list
 */
template <typename T>
void LinkedList<T>::print(string listName_) const
{
	// Create a pointer to the list head
	Node<T> *tmp = this->head;

	if (listName_.compare("") != 0)
		cout << listName_ << ": [ ";
	else
		cout << "[ ";

	// Loop over the list until it reachs the tail
	while (tmp != nullptr)
	{
		std::cout << tmp->Data() << " -> ";
		tmp = tmp->Next();
	}

	std::cout << "NULL ]\n";
}

// ***************************************************
// ** Overload operators
// ***************************************************