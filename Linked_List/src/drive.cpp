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
    LinkedList<int> intLinkedListMini;
    LinkedList<int> intLinkedListEmpty;

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

    intLinkedListMini.push_back(123);

    // Print the values
    intLinkedList.print(true, "intLinkedList");
    intLinkedListReverse.print(true, "intLinkedListReverse");
    intLinkedListMini.print(true, "intLinkedListMini");
    intLinkedListEmpty.print(true, "intLinkedListEmpty");
    stringLinkedList.print(true, "stringLinkedList");
    stringLinkedListReverse.print(true, "stringLinkedListReverse");
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
    intLinkedListCopy.print(true, "intLinkedListCopy");
    stringLinkedListCopy.print(true, "stringLinkedListCopy");
    cout << endl;

    /* ============================================================================== */

    /*------------------- [ Test the Linked List pop operations ] ------------------- */

    cout << "<<< Testing the pop operations:" << endl;

    // Get the previous list and remove some elements to see what happen
    intLinkedList.pop_front();
    intLinkedList.pop_back();
    intLinkedList.pop_back();
    intLinkedList.pop_back();
    intLinkedList.pop_front();

    stringLinkedList.pop_front();
    stringLinkedList.pop_front();
    stringLinkedList.pop_front();
    stringLinkedList.pop_front();
    stringLinkedList.pop_front();
    stringLinkedList.pop_back();
    stringLinkedList.pop_back();

    intLinkedListEmpty.pop_back();
    intLinkedListEmpty.pop_front();

    intLinkedList.print(true, "intLinkedList");
    stringLinkedList.print(true, "stringLinkedList");
    intLinkedListEmpty.print(true, "intLinkedListEmpty");
    cout << endl;

    /* ============================================================================== */

    /* ============================================================================== */

    /*----------------- [ Test the Linked List search operations ] ------------------ */

    cout << "<<< Testing the search operations:" << endl;

    // Get the previous list and search for elements
    cout << "intLinkedList(0): " << intLinkedList.getIthNode(0)->Data() << endl;
    cout << "intLinkedList(1): " << intLinkedList.getIthNode(1)->Data() << endl;
    cout << "intLinkedList(last): " << intLinkedList.getIthNode(intLinkedList.length() - 1)->Data() << endl;
    cout << "intLinkedList(9): " << intLinkedList.getIthNode(9) << endl;
    cout << "intLinkedList(-1): " << intLinkedList.getIthNode(-1) << endl;

    cout << "stringLinkedListCopy(4): " << stringLinkedListCopy.getIthNodeValue(4) << endl;
    cout << "stringLinkedListCopy(6): " << stringLinkedListCopy.getIthNodeValue(6) << endl;
    cout << "stringLinkedListCopy(last): " << stringLinkedListCopy.getIthNodeValue(stringLinkedListCopy.length() - 1) << endl;

    cout << endl;

    /* ============================================================================== */

    /*-------------- [ Test the Linked List insertIthNode operations ] -------------- */

    cout << "<<< Testing the insertIthNode operations:" << endl;

    stringLinkedListCopy.print(true, "stringLinkedListCopy");

    stringLinkedListCopy.insertIthNode('@', 0); // the same of push_front
    stringLinkedListCopy.insertIthNode('X', 3);
    stringLinkedListCopy.insertIthNode('Y', 6);
    stringLinkedListCopy.insertIthNode('Z', (stringLinkedListCopy.length())); // the same of push_back

    stringLinkedListCopy.print(true, "stringLinkedListCopy");

    cout << endl;

    /* ============================================================================== */

    /*-------------- [ Test the Linked List deleteIthNode operations ] -------------- */

    cout << "<<< Testing the deleteIthNode operations:" << endl;

    stringLinkedListCopy.deleteIthNode(0);
    stringLinkedListCopy.deleteIthNode(2);
    stringLinkedListCopy.deleteIthNode(4);
    stringLinkedListCopy.deleteIthNode((stringLinkedListCopy.length() - 1));
    stringLinkedListCopy.deleteIthNode((stringLinkedListCopy.length()));
    stringLinkedListCopy.deleteIthNode(-1);
    stringLinkedListCopy.print(true, "stringLinkedListCopy");

    cout << endl;

    /* ============================================================================== */

    /*------------------ [ Test the Linked List recursive length ] ------------------ */

    cout << "<<< Testing the recursive length:" << endl;

    cout << "intLinkedList: " << intLinkedList.recursiveLength(intLinkedList.Head()) << endl;
    cout << "intLinkedListEmpty: " << intLinkedListEmpty.recursiveLength(intLinkedListEmpty.Head()) << endl;
    cout << "intLinkedListCopy: " << intLinkedListCopy.recursiveLength(intLinkedListCopy.Head()) << endl;
    cout << "stringLinkedListCopy: " << stringLinkedListCopy.recursiveLength(stringLinkedListCopy.Head()) << endl;

    cout << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}