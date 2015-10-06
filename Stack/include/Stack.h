/*!
	<PRE>
	SOURCE FILE : Stack.h
	DESCRIPTION.: Stack class - with implementation.
	AUTHOR......: Igor A. Brandão and Leandro F. Silva
	LOCATION....: IMD/UFRN.
	SATARTED ON.: September/2005
	CHANGES.....: Functions implemented.

	TO COMPILE..: Use makefile.
	OBS.........: Part of the LP1/EDB Project.

	LAST UPDATE.: September 29th, 2015.
	LAST UPDATE.: October 6th, 2015.
	</pre>
*/

#ifndef Stack_H_
#define Stack_H_

// ******************PUBLIC OPERATIONS*********************
// void push( x )     	--> Insert x
// T pop( )          	--> Remove and return most recently inserted item
// T top( )          	--> Return most recently inserted item
// bool isEmpty( )    	--> Return true if empty; else false
// bool isFull( )    	--> Return true if full; else false
// void makeEmpty( )  	--> Remove all items
// void print( )  		--> Print the stack elements
// ***********************ERRORS****************************
// std::underflow_error thrown if needed.

/*! LifeScreen template class */
template <class T>
class Stack
{
	/*!
     * Public section
    */
	public:

		/*! Functions */
        Stack();   			/*!< Constructor */
        Stack( int sz_ );   /*!< Constructor overload */
        ~Stack();  			/*!< Destructor */

		/*! Basic members */
		void push( const T & _x );
		const T & pop( );
		const T & top();

		bool isEmpty( ) { return (iTop == -1); }
		bool isFull( ) { return (iTop + 1 == iSz); }
		void makeEmpty( );
		void print( );

	/*!
     * Private section
    */
	private:

		/*! Attributes */
		int iSz;	/*!< Stack size */
		int iTop;	/*!< The top of stack */
		T* items;	/*!< A pointer to stack items */

		/*! Disable copy constructor */
		Stack( const Stack & ){ /* empty */ }
};

#include "Stack.inl"
#endif

/* --------------------- [ End of the Stack.h header ] ------------------- */
/* ========================================================================= */