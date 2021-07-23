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
    Stack<int> intStack(iSize);

    // Stack class instance with string
    Stack<char> stringStack(iSize);

    cout << "<<< Testing the Stack initialization:" << endl;

    // Add some values
    for (auto i = 0; i < iSize; i++)
    {
        intStack.push(i);
    }

    intStack.pop();
    intStack.pop();

    for (char &c : phrase)
    {
        stringStack.push(c);
    }

    stringStack.pop();
    stringStack.push('!');

    // Print the stacks
    intStack.print(true, "intStack");
    stringStack.print(true, "stringStack");
    cout << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}