/*! \brief drive.cpp.
 *
 *  Program to test the Queue class.
*/
#include <iostream>
#include "Queue.h"

using namespace std;

/**
 * Main method
 */
int main()
{
    // Queue initial size
    int iSize = 10;
    string phrase = "queue";

    /* ---------------------------- [ Test Queue class ] ---------------------------- */

    // Queue class instance with int
    Queue<int> intQueue;

    // Queue class instance with string
    Queue<char> stringQueue;

    cout << "<<< Testing the Queue initialization:" << endl;

    // Add some values
    for (auto i = 0; i < iSize; i++)
    {
        intQueue.push(i);
    }

    for (char &c : phrase)
    {
        stringQueue.push(c);
    }

    // Print the stacks
    intQueue.print(true, "intQueue");
    stringQueue.print(true, "stringQueue");

    /* ============================================================================== */

    /* --------------------------- [ Test pop operation ] --------------------------- */

    cout << "<<< Testing the pop & push operations:" << endl;
    cout << endl;

    cout << "<<< intQueue: pop(), pop(), pop(), push(99)" << endl;
    intQueue.pop();
    intQueue.pop();
    intQueue.pop();
    intQueue.push(99);
    intQueue.print(true, "intQueue");
    cout << endl;

    cout << "<<< stringQueue: pop(), pop(), push('!'), pop(), push('X')" << endl;
    stringQueue.pop();
    stringQueue.pop();
    stringQueue.push('!');
    stringQueue.pop();
    stringQueue.push('X');
    stringQueue.print(true, "stringQueue");
    cout << endl;

    /* ============================================================================== */

    /* --------------------------- [ Test front operation ] --------------------------- */

    cout << "<<< Testing the front operations:" << endl;

    // Print the stacks front
    cout << "intQueue front: " << intQueue.front() << endl;
    cout << "stringQueue front: " << stringQueue.front() << endl;
    cout << endl;

    cout << "pop()" << endl;
    intQueue.pop();
    stringQueue.pop();

    cout << "intQueue front: " << intQueue.front() << endl;
    
    cout << "stringQueue front: " << stringQueue.front() << endl;
    cout << endl;

    cout << "pop()" << endl;
    intQueue.pop();
    stringQueue.pop();

    cout << "intQueue front: " << intQueue.front() << endl;
    cout << "stringQueue front: " << stringQueue.front() << endl;
    cout << endl;

    cout << "stringQueue pop()" << endl;
    
    stringQueue.pop();
    stringQueue.pop();
    stringQueue.pop();

    cout << endl;

    cout << "intQueue front: " << intQueue.front() << endl;
    cout << "stringQueue front: " << stringQueue.front() << endl;

    intQueue.print(true, "intQueue");
    stringQueue.print(true, "stringQueue");

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}