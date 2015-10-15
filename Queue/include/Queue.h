/*!
	<PRE>
	SOURCE FILE : Queue.h
	DESCRIPTION.: Queue class - with implementation.
	AUTHOR......: Igor A. Brandão and Leandro F. Silva
	LOCATION....: IMD/UFRN.
	SATARTED ON.: October/2015
	CHANGES.....: Functions implemented.

	TO COMPILE..: Use makefile.
	OBS.........: Part of the LP1/EDB Project.

	tail UPDATE.: September 29th, 2015.
	tail UPDATE.: October 6th, 2015.
	tail UPDATE.: October 14th, 2015.
	</pre>
*/

#ifndef Queue_H_
#define Queue_H_

#include <iostream>
#include <cassert>
#include <stdexcept>

// ******************PUBLIC OPERATIONS*********************
// void push( x )     	--> Insert x
// void pop( )          --> Remove the head element
// void front( )        --> Return the head element
// void back( )         --> Return the tail element
// bool empty( )    	--> Return true if empty; else false
// void makeEmpty( )  	--> Remove all items
// void print( )  		--> Print the Queue elements
// int size( )  		--> Return the number of elements

// ***********************ERRORS****************************
// std::underflow_error thrown if needed.
// std::overflow_error thrown if needed.

/*! Template node */
template <typename T>
struct Node
{
    T data;
    Node* next;
    Node(T d, Node* n = NULL): data(d), next(n){}
};

/*! Queue template class */
template <class T>
class Queue
{
	/*!
     * Private section
    */
    private:

    	/*! Attributes */
        Node<T> * head;		/*!< Pointer to head element */
        Node<T> * tail;		/*!< Pointer to tail element */
        int iSz;			/*!< Queue size */

    /*!
     * Public section
    */
    public:

        /*! Functions */
        Queue();   			/*!< Constructor */
        ~Queue();  			/*!< Destructor */

    	/*! Basic members */
        void push( const T & _x );
        void pop();

        const T & front();
        const T & back();

        bool empty();
		void makeEmpty();
		void print();
};

#include "Queue.inl"
#endif

/* --------------------- [ End of the Queue.h header ] ------------------- */
/* ========================================================================= */