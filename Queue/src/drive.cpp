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
    Queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.print();
    //std::cout << " << " << q.front() << " >> " << std::endl;
    std::cout << " << " << q.back() << " >> " << std::endl;
    /*
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.front();
    */

	/* ========================================================================= */

	return 0;
}