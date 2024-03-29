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
    string phrase2 = "hello-world!";

    /* ---------------------------- [ Test LinkedList class ] ---------------------------- */

    // LinkedList class instance with int
    LinkedList<int> intLinkedList;
    LinkedList<int> intLinkedListReverse;
    LinkedList<int> intLinkedListMini;
    LinkedList<int> intLinkedListEmpty;
    LinkedList<int> list1;
    LinkedList<int> list2;

    // LinkedList class instance with string
    LinkedList<char> stringLinkedList;
    LinkedList<char> stringLinkedListReverse;
    LinkedList<char> stringLinkedListNew;

    cout << "<<< Testing the LinkedList initialization:" << endl;

    // Add some values
    for (auto i = 0; i < iSize; i++)
    {
        intLinkedList.push_back(i);
        intLinkedListReverse.push_front(i);
    }

    for (auto i = 0; i < iSize; i++)
    {
        list1.push_back(i);
    }

    for (auto i = 0; i < iSize; i++)
    {
        list2.push_back(i * 2);
    }

    for (char &c : phrase)
    {
        stringLinkedList.push_back(c);
        stringLinkedListReverse.push_front(c);
    }

    for (char &c : phrase2)
    {
        stringLinkedListNew.push_back(c);
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

    /*--------------- [ Test the Linked List searchValue operation ] --------------- */

    cout << "<<< Testing the searchValue operation:" << endl;

    intLinkedList.print(false, "intLinkedList");
    cout << "2 is at position: " << intLinkedList.searchValue(2) << endl;
    cout << endl;

    intLinkedListEmpty.print(false, "intLinkedListEmpty");
    cout << "100 is at position: " << intLinkedListEmpty.searchValue(100) << endl;
    cout << "0 is at position: " << intLinkedListEmpty.searchValue(0) << endl;
    cout << endl;

    intLinkedListCopy.print(false, "intLinkedListCopy");
    cout << "5 is at position: " << intLinkedListCopy.searchValue(5) << endl;
    cout << endl;

    stringLinkedListCopy.print(false, "stringLinkedListCopy");
    cout << "k is at position: " << stringLinkedListCopy.searchValue('k') << endl;
    cout << "K is at position: " << stringLinkedListCopy.searchValue('K') << endl;
    cout << "t is at position: " << stringLinkedListCopy.searchValue('t') << endl;
    cout << "z is at position: " << stringLinkedListCopy.searchValue('z') << endl;
    cout << "- is at position: " << stringLinkedListCopy.searchValue('-') << endl;
    cout << "d is at position: " << stringLinkedListCopy.searchValue('d') << endl;
    cout << "' ' is at position: " << stringLinkedListCopy.searchValue(' ') << endl;
    cout << "l is at position: " << stringLinkedListCopy.recursiveSearchValue(stringLinkedListCopy.Head(), 'l') << endl;
    cout << "s is at position: " << stringLinkedListCopy.recursiveSearchValue(stringLinkedListCopy.Head(), 's') << endl;
    cout << "i is at position: " << stringLinkedListCopy.recursiveSearchValue(stringLinkedListCopy.Head(), 'i') << endl;
    cout << endl;

    /* ============================================================================== */

    /*----------------- [ Test the Linked List midpoint operations ] ---------------- */

    cout << "<<< Testing the midpoint operation:" << endl;

    intLinkedList.print(false, "intLinkedList");
    cout << "Midpoint: " << intLinkedList.midpointData() << endl;
    cout << endl;

    intLinkedListCopy.print(false, "intLinkedListCopy");
    cout << "Midpoint: " << intLinkedListCopy.midpointData() << endl;
    cout << endl;

    stringLinkedListCopy.print(false, "stringLinkedListCopy");
    cout << "Midpoint: " << stringLinkedListCopy.midpointData() << endl;
    cout << endl;

    intLinkedListEmpty.print(false, "intLinkedListEmpty");
    cout << "Midpoint: " << intLinkedListEmpty.midpointData() << endl;
    cout << endl;

    cout << endl;

    /* ============================================================================== */

    /*------------------ [ Test the Linked List reverse operation ] ----------------- */

    cout << "<<< Testing the reverse operation:" << endl;

    intLinkedList.print(false, "intLinkedList");
    intLinkedList.reverse();
    intLinkedList.print(false, "reverse: ");
    cout << endl;

    intLinkedListCopy.print(false, "intLinkedListCopy");
    intLinkedListCopy.reverse();
    intLinkedListCopy.print(false, "reverse: ");
    cout << endl;

    stringLinkedListCopy.print(false, "stringLinkedListCopy");
    stringLinkedListCopy.reverse();
    stringLinkedListCopy.print(false, "reverse: ");
    cout << endl;

    intLinkedListEmpty.print(false, "intLinkedListEmpty");
    intLinkedListEmpty.reverse();
    intLinkedListEmpty.print(false, "reverse: ");
    cout << endl;

    cout << endl;

    /* ============================================================================== */

    /*----------- [ Test the Linked List deleteIthNodeFromEnd operation ] ---------- */

    cout << "<<< Testing the deleteIthNodeFromEnd operation:" << endl;

    stringLinkedListNew.print(true, "stringLinkedListNew");
    stringLinkedListNew.deleteIthNodeFromEnd(5);
    /*stringLinkedListNew.deleteIthNodeFromEnd(-1);
    stringLinkedListNew.deleteIthNodeFromEnd(10);
    stringLinkedListNew.deleteIthNodeFromEnd(3);*/
    //stringLinkedListNew.deleteIthNodeFromEnd(stringLinkedListNew.length() - 1);
    stringLinkedListNew.print(true, "stringLinkedListNew");
    cout << endl;

    /* ============================================================================== */

    /*------------------- [ Test the Linked List merge operation ] ------------------ */

    cout << "<<< Testing the merge operation:" << endl;

    // Perform the merging
    LinkedList<int> mergedList;

    list1.print(true, "list1");
    list2.print(true, "list2");

    //mergedList.merge(list1.Head(), list2.Head());

    mergedList.print(true, "mergedList");
    cout << endl;

    /* ============================================================================== */

    /*---------------------- [ Josephus Circle implementation ] --------------------- */

    cout << "<<< Josephus Circle implementation using linked list:" << endl;

    /**
     * There are n people standing in a circle waiting to be executed. The counting out 
     * begins at some point in the circle and proceeds around the circle in a fixed direction. 
     * In each step, a certain number of people are skipped and the next person is executed. 
     * The elimination proceeds around the circle (which is becoming smaller and smaller as 
     * the executed people are removed), until only the last person remains, who is given 
     * freedom. Given the total number of persons n and a number k which indicates that k-1 
     * persons are skipped and k-th person is killed in circle. The task is to choose the place 
     * in the initial circle so that you are the last one remaining and so survive. 
     * (0 based indexing) .
     * 
     * Examples : 
     * Input :  Length of circle : n = 4
     *          Count to choose next : k = 2
     * Output : 0
     * 
     * Input :  n = 5
     *          k = 3
     * Output : 3
     * 
     * Input :  n = 6
     *          k = 4
     * Output : 4
     */
    LinkedList<int> josephus;
    int n = 6;
    int k = 4;

    cout << "n: " << n << endl;
    cout << "k: " << k << endl;

    // Add n people to the circle
    for (auto i = 0; i < n; i++)
    {
        josephus.push_back(i);
    }

    // Convert the single LL into a circular LL
    josephus.Tail()->setNext(josephus.Head()->Next());

    // Point to the first element of the list
    auto currPerson = josephus.Head()->Next();

    // Kill people until the last stand
    while (josephus.listSize != 1)
    {
        // Traverse the list k times
        for (auto i = 1; i < k; i++)
        {
            currPerson = currPerson->Next();
        }

        auto personToKill = currPerson->Next();
        currPerson->setNext(personToKill->Next());

        // Kill the selected person and restart the counting
        delete personToKill;
        josephus.listSize--;
    }

    cout << "<<< last man standing: " << currPerson->Next()->Data() << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}