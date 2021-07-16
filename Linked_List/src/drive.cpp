/*! \brief drive.cpp.
 *
 *  Program to test the LinkedList class.
*/
#include <iostream>
#include "LinkedList.h"

using namespace std;

/**
 * Main method
 */
int main()
{
    // LinkedList initial size
    int iSize = 10;
    string phrase = "linked->list";

    /* ---------------------------- [ Test LinkedList class ] ---------------------------- */

    // LinkedList class instance with int
    LinkedList<int> intLinkedList;

    // LinkedList class instance with string
    LinkedList<char> stringLinkedList;

    cout << "<<< Testing the LinkedList initialization:" << endl;

    // Add some values
    for (auto i = 0; i < iSize; i++)
    {
        intLinkedList.push_back(i);
    }

    for(char& c : phrase) {
        stringLinkedList.push_back(c);
    }
    
    // Print the values
    intLinkedList.print("intLinkedList");
    stringLinkedList.print("stringLinkedList");
    cout << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}