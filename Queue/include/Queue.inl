/*! \brief Queue.inl.
 *
 *  Implements the functions from Queue class.
*/
#include "Queue.h"

/********************************************//**
* constructor
***********************************************/
template <typename T>
Queue<T>::Queue()
{
	/*! Initialize the pointers */
    head = NULL;
    tail = NULL;
    iSz = 0;
}

/********************************************//**
* destructor
***********************************************/
template <typename T>
Queue<T>::~Queue()
{
	/*! If it is already empty don't do anything. */
    if ( empty() )
        return;

    /*! Clear de queue */
    makeEmpty();
}

/********************************************//**
* Inserts a new element at the back of the Queue.
***********************************************/
template <typename T>
void
Queue<T>::push( const T & x_  )
{
	/*! Check if the queue is empty */
	if ( head == NULL )
	{
		/*! Create the head element and update the pointer */
		head = new Node<T>(x_);
		tail = head;
	}
	else
	{
		/*! Create a new element and update the pointer */
		tail->next = new Node<T>(x_);
		tail = tail->next;
	}

	/*! Update the queue size */
	iSz++;
}

/********************************************//**
* Removes the head element from queue.
***********************************************/
template <typename T>
void
Queue<T>::pop()
{
	/*! Check if the queue is empty */
	if ( head == NULL )
	{
		/*! Error message */
		throw std::underflow_error("<< Queue is Empty! >>");
		exit(1);
	}

	/*! Remove the element */
    Node<T> * temp = head;
    head = head->next;
    delete temp;

    /*! Update the queue size */
    iSz--;
}

/********************************************//**
* Return the head inserted item.
***********************************************/
template <typename T>
const T &
Queue<T>::front()
{
	/*! Check if the queue's head is empty */
	if ( head == NULL )
	{
		/*! Error message */
		throw std::underflow_error("<< Head is Empty! >>");
		exit(1);
	}

	/*! Return the head item */
	return head->data;
}

/********************************************//**
* Return most recently inserted item.
***********************************************/
template <typename T>
const T &
Queue<T>::back()
{
	/*! Check if the queue's tail is empty */
	if ( tail == NULL )
	{
		/*! Error message */
		throw std::underflow_error("<< Tail is Empty! >>");
		exit(1);
	}

	/*! Return the tail item */
	return tail->data;
}

/********************************************//**
* Check if the Queue is empty.
* Returns true to empty or false if not.
***********************************************/
template <typename T>
bool
Queue<T>::empty()
{
	/*! Check if the queue is empty */
	return (iSz == 0);
}

/********************************************//**
* Print the queue
***********************************************/
template <typename T>
void
Queue<T>::makeEmpty()
{
	Node<T> *tmp;

    /*! Delete all elements until its empty */
    while ( !empty() )
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

/********************************************//**
* Print the queue
***********************************************/
template <typename T>
void
Queue<T>::print()
{
	std::cout << "<< [ ";

	/*! Check while queue is empty */
	while ( !empty() )
	{
		std::cout << front() << " ";
		pop();
	}

	std::cout << "] >> " << std::endl;
}