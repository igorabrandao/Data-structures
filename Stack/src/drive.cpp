/*! \brief drive.cpp.
 *
 *  Program to test the Stack class.
*/
#include <iostream>
#include "Stack.h"

using namespace std;

/*! Main method */
int main()
{
	/* --------------------- [ Test Stack class with chars ] ------------------- */

	/*! Stack class instance with chars */
	Stack<char> st(10);

    // Insert the letters 'A' - 'J'
	for ( int i = 65; i < 75; i++ )
		st.push(i);

	st.print();

    // Remove all the data
	st.makeEmpty();

	/* ========================================================================= */

	return 0;
}