/*! \brief drive.cpp.
 *
 *  Program to test the LinkedList class.
*/
#include <iostream>
#include "Stack.h"

using namespace std;

/**
 * Main method
 */
int main()
{
    // LinkedList initial size
    int iSize = 10;
    string phrase = "stack";

    /* ---------------------------- [ Test Stack class ] ---------------------------- */

    // Stack class instance with int
    Stack<int> intStack;

    // Stack class instance with string
    Stack<char> stringStack;

    cout << "<<< Testing the Stack initialization:" << endl;

    // Add some values
    for (auto i = 0; i < iSize; i++)
    {
        intStack.push(i);
    }

    for (char &c : phrase)
    {
        stringStack.push(c);
    }

    // Print the stacks
    intStack.print(true, "intStack");
    stringStack.print(true, "stringStack");

    /* ============================================================================== */

    /* --------------------------- [ Test pop operation ] --------------------------- */

    cout << "<<< Testing the pop & push operations:" << endl;
    cout << endl;

    cout << "<<< intStack: pop(), pop(), pop(), push(99)" << endl;
    intStack.pop();
    intStack.pop();
    intStack.pop();
    intStack.push(99);
    intStack.print(true, "intStack");
    cout << endl;

    cout << "<<< stringStack: pop(), pop(), push('!'), pop(), push('X')" << endl;
    stringStack.pop();
    stringStack.pop();
    stringStack.push('!');
    stringStack.pop();
    stringStack.push('X');
    stringStack.print(true, "stringStack");
    cout << endl;

    /* ============================================================================== */

    /* --------------------------- [ Test top operation ] --------------------------- */

    cout << "<<< Testing the top operations:" << endl;

    // Print the stacks top
    cout << "intStack top: " << intStack.top() << endl;
    cout << "stringStack top: " << stringStack.top() << endl;
    cout << endl;

    cout << "pop()" << endl;
    intStack.pop();
    stringStack.pop();

    cout << "intStack top: " << intStack.top() << endl;
    cout << "stringStack top: " << stringStack.top() << endl;
    cout << endl;

    cout << "pop()" << endl;
    intStack.pop();
    stringStack.pop();

    cout << "intStack top: " << intStack.top() << endl;
    cout << "stringStack top: " << stringStack.top() << endl;
    cout << endl;

    cout << "pop()" << endl;
    
    stringStack.pop();
    stringStack.pop();
    stringStack.pop();

    cout << "intStack top: " << intStack.top() << endl;
    cout << "stringStack top: " << stringStack.top() << endl;
    cout << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}