/*! \brief drive.cpp.
 *
 *  Program to test the Queue class.
*/
#include <iostream>
#include "Queue.h"

using namespace std;

/*! Main method */
int main()
{
	/* --------------------- [ Test Queue class with chars ] ------------------- */

	/*! Queue class instance with int */
    Queue<char> q;

    q.push('a');
    q.push('b');
    q.push('c');
    q.print();

    /*
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.front();
    */

	/* ========================================================================= */

	return 0;
}