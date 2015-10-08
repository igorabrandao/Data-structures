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

	// Print the elements
	st.print();
	st.top();

	// Remove 1 element
	st.pop();
	st.print();
	st.top();

	// Remove another element
	st.pop();
	st.print();
	st.top();

	// Remove another element
	st.pop();
	st.print();
	st.top();

    // Remove all data
	st.makeEmpty();
	st.print();
	st.top();

	/* ========================================================================= */

	return 0;
}