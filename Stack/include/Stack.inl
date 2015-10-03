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
		/*! Erro message */
		std::cout << "<< Stack is Full! >>" << std::endl;
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
		/*! Erro message */
		std::cout << "<< Stack is Empty! >>" << std::endl;
		exit(1);
	}

	/*! Remove the element */
	return items[iTop--];
}

/********************************************//**
* Returns a reference to the top element 
* in the stack.
***********************************************/
/*template <typename T>
const T &
Stack<T>::top() const
{

}*/

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
	std::cout << "<< [ " << std::endl;

	/*! Check while stack is empty */
	for ( int i = 0; i < iSz; ++i )
	{
		items[i];
	}

	std::cout << " ] >> " << std::endl;
}