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
    cout << "intLinkedList 1st: " << intLinkedList.getElemByIndex(0)->Data() << endl;
    cout << "intLinkedList 2nd: " << intLinkedList.getElemByIndex(1)->Data() << endl;
    cout << "intLinkedList last: " << intLinkedList.getElemByIndex(intLinkedList.length() - 1)->Data() << endl;
    cout << "intLinkedList 10th: " << intLinkedList.getElemByIndex(9) << endl;
    cout << "intLinkedList -1th: " << intLinkedList.getElemByIndex(-1) << endl;

    cout << "stringLinkedListCopy 5th: " << stringLinkedListCopy.getElemValueByIndex(4) << endl;
    cout << "stringLinkedListCopy 7th: " << stringLinkedListCopy.getElemValueByIndex(6) << endl;
    cout << "stringLinkedListCopy last: " << stringLinkedListCopy.getElemValueByIndex(stringLinkedListCopy.length() - 1) << endl;

    cout << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}