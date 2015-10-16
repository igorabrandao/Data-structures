/*! \brief Stack.inl.
 *
 *  Implements the functions from Stack class.
*/
#include "Stack.h"

/********************************************//**
* constructor
***********************************************/
template <typename T>
Stack<T>::Stack()
{
    /* Empty */
}

/********************************************//**
* constructor overload
***********************************************/
template <typename T>
Stack<T>::Stack( int sz_ )
{
	/*! Initial settings */
    iSz = sz_;
	iTop = -1;

	/*! Allocate the stack itself */
	items = new T[iSz];
}

/********************************************//**
* destructor
***********************************************/
template <typename T>
Stack<T>::~Stack()
{
	/*! Delete the elements */
    delete [] items;
}

/********************************************//**
* Inserts a new element at the top of the stack, 
* above its current top element. The content of 
* this new element is initialized to a copy of val.
***********************************************/
template <typename T>
void
Stack<T>::push( const T & x_ )
{
	/*! Check if the stack is full */
	if ( isFull() )
	{
		/*! Error message */
		throw std::overflow_error("<< Stack is Full! >>");
		exit(1);
	}

	/*! Insert a new element */
	items[++iTop] = x_;
}

/********************************************//**
* Removes the element on top of the stack, 
* effectively reducing its size by one.
***********************************************/
template <typename T>
const T &
Stack<T>::pop()
{
	/*! Check if the stack is empty */
	if ( isEmpty() )
	{
		/*! Error message */
		throw std::underflow_error("<< Stack is Empty! >>");
		exit(1);
	}

	/*! Remove the element */
	return items[iTop--];
}

/********************************************//**
* Return most recently inserted item.
***********************************************/
template <typename T>
const T &
Stack<T>::top()
{
	/*! Check if the stack is empty */
	if ( isEmpty() )
	{
		/*! Error message */
		throw std::underflow_error("<< Stack is Empty! >>");
		exit(1);
	}

	//std::cout << "<< " << items[iTop] << " >>" << std::endl;

	/*! Return the element */
	return items[iTop];
}


/********************************************//**
* Check if the stack is empty.
* Returns true to empty or false if not.
***********************************************/
template <typename T>
void
Stack<T>::makeEmpty()
{
	/*! Check while stack is empty */
	while ( !isEmpty() )
	{
		/*! Remove all elements */
		pop();
	}
}

/********************************************//**
* Print the stack
***********************************************/
template <typename T>
void
Stack<T>::print()
{
	std::cout << "<< [ ";

	/*! Check while stack is empty */
	for ( int i = 0; i <= iTop; ++i )
	{
		if ( i == (iTop) )
			std::cout << items[i];
		else
			std::cout << items[i] << ", ";
	}

	std::cout << " ] >> " << std::endl;
}