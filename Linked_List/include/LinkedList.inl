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
	// Initialize the list basic attributes
	this->head = new Node<T>();
	this->tail = new Node<T>();
	this->listSize = 0;
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

	// Initialize the list basic attributes
	this->head = new Node<T>();
	this->tail = new Node<T>();

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

	// Set-up the copy list tail
	this->tail = temp;
}

/**
 * Function to add a value to the front of the list
 * 
 * time complexity = O(n)
 */
template <typename T>
void LinkedList<T>::push_front(T data_)
{
	// Create a new node
	Node<T> *newNode = new Node<T>(data_);

	if (this->head == nullptr)
	{
		// Handle first node push
		this->head = newNode;
		this->tail = newNode;
	}
	else
	{
		/**
		 * Set Next of Node to Head of the current list
		 * (Node)->(Current List)
		 */
		newNode->setNext(this->head);

		// Set the Head pointer to the new node
		this->head = newNode;
	}

	// Update the list size
	this->listSize = this->length();
}

/**
 * Function to add a value to the back of the list
 * 
 * time complexity = O(n)
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
		this->tail = newNode;
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
		 * Set newNode as the next of the last node (tail)
		 */
		currNode->setNext(newNode);

		// Assign the last element to the list tail
		this->tail = currNode->Next();
	}

	// Update the list size
	this->listSize = this->length();
}

/**
 * Function to remove the first value of the list
 */
template <typename T>
void LinkedList<T>::pop_front()
{
	// Check if the list has any elements
	if (this->head->Next() == nullptr)
	{
		// Delete the list head & tail
		delete this->head;
		delete this->tail;

		cout << "<< pop_front(): List already empty! >>" << endl;
	}
	else
	{
		// Create a pointer to the list head
		Node<T> *node = this->head;

		// Assign the head to the second element
		this->head = this->head->Next();

		// Delete the first element
		delete node;

		// Update the list size
		this->listSize = this->length();
	}
}

/**
 * Function to remove the last value of the list
 */
template <typename T>
void LinkedList<T>::pop_back()
{
	if (this->head->Next() == nullptr)
	{
		// Delete the list head & tail
		delete this->head;
		delete this->tail;

		cout << "<< pop_back(): List already empty! >>" << endl;
	}
	else
	{
		Node<T> *secondLast = this->head;

		// Find the second last node
		while (secondLast->Next()->Next() != nullptr)
		{
			secondLast = secondLast->Next();
		}

		// Delete last node and second last becomes the last
		delete secondLast->Next();

		// Change next of second last node
		secondLast->setNext(nullptr);

		// Assign the last element to the tail
		this->tail = secondLast;
	}

	// Update the list size
	this->listSize = this->length();
}

/**
 * Function to print the linked list
 */
template <typename T>
void LinkedList<T>::print(bool showLength_, string listName_) const
{
	// Create a pointer to the list head
	Node<T> *tmp = this->head;

	if (listName_.compare("") != 0)
		if (showLength_)
			cout << listName_ << "(" << this->length() << "): [ ";
		else
			cout << listName_ << ": [ ";
	else if (showLength_)
		cout << this->length() << ": [ ";
	else
		cout << "[ ";

	// Loop over the list until it reachs the tail
	while (tmp != nullptr)
	{
		if (tmp == this->head && tmp == this->tail)
			std::cout << tmp->Data() << "(H)(T) -> ";
		else if (tmp == this->head)
			std::cout << "(H) -> ";
		else if (tmp == this->tail)
			std::cout << tmp->Data() << "(T) -> ";
		else
			std::cout << tmp->Data() << " -> ";

		tmp = tmp->Next();
	}

	std::cout << "NULL ]\n";
}

/**
 * Function to return the number of elements in the list
 * 
 * time complexity = O(n)
 */
template <typename T>
int LinkedList<T>::length() const
{
	int size = 0;

	// Create a pointer to first element of the list
	Node<T> *tmp = this->head->Next();

	// Loop over the list until it reachs the tail
	while (tmp != nullptr)
	{
		tmp = tmp->Next();
		size++;
	}

	return size;
}

/**
 * Function to return the ith element from the list
 */
template <typename T>
Node<T> *LinkedList<T>::getElemByIndex(int index_) const
{
	// First of all check the validity of the index
	if (index_ < 0 || index_ > (this->listSize - 1))
	{
		cout << "<< Index out of range! >>" << endl;
		return nullptr;
	}
	else
	{
		// Start the search from the first node, not from the head pointer
		Node<T> *currNode = this->head->Next();

		/**
		 * Iterate through the end of the list
		 */
		for (auto i = 0; i < index_; i++)
		{
			// Goto the next node
			currNode = currNode->Next();
		}

		return currNode;
	}

	cout << "<< Element not found! >>" << endl;
	return nullptr;
}

// ***************************************************
// ** Overload operators
// ***************************************************