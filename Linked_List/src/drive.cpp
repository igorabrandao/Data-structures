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
    string phrase = "linked-list";

    /* ---------------------------- [ Test LinkedList class ] ---------------------------- */

    // LinkedList class instance with int
    LinkedList<int> intLinkedList;
    LinkedList<int> intLinkedListReverse;

    // LinkedList class instance with string
    LinkedList<char> stringLinkedList;
    LinkedList<char> stringLinkedListReverse;

    cout << "<<< Testing the LinkedList initialization:" << endl;

    // Add some values
    for (auto i = 0; i < iSize; i++)
    {
        intLinkedList.push_back(i);
        intLinkedListReverse.push_front(i);
    }

    for (char &c : phrase)
    {
        stringLinkedList.push_back(c);
        stringLinkedListReverse.push_front(c);
    }

    // Print the values
    intLinkedList.print("intLinkedList");
    intLinkedListReverse.print("intLinkedListReverse");
    stringLinkedList.print("stringLinkedList");
    stringLinkedListReverse.print("stringLinkedListReverse");
    cout << endl;

    /* ============================================================================== */

    /* --------------------- [ Test the Linked List deep copy ] --------------------- */

    /**
     * Now, let's create another integer & char linked lists
     * and assign the values from original linked list to the new one
     */
    LinkedList<int> intLinkedListCopy = intLinkedList;
    LinkedList<char> stringLinkedListCopy = stringLinkedList;

    cout << "<<< Testing the copy constructor:" << endl;
    intLinkedListCopy.print("intLinkedListCopy");
    stringLinkedListCopy.print("stringLinkedListCopy");
    cout << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}