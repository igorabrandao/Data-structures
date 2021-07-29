/*! \brief drive.cpp.
 *
 *  Program to test the GenericTree class.
*/
#include <iostream>
#include "GenericTree.h"

using namespace std;

/**
 * Main method
 */
int main()
{
    // GenericTree initial size
    int iSize = 10;
    string phrase = "generic-tree";

    /* ---------------------------- [ Test GenericTree class ] ---------------------------- */

    // GenericTree class instance with int
    GenericTree<int> intGenericTree(100);
    GenericTree<int> intInputNode;

    // GenericTree class instance with string
    GenericTree<char> stringGenericTree('@');
    GenericTree<char> stringEmptyTree;

    // Add some nodes to the tree
    for (auto i = 0; i < iSize; i++)
    {
        intGenericTree.push(intGenericTree.Root(), i);
    }

    for (char &c : phrase)
    {
        stringGenericTree.push(stringGenericTree.Root(), c);
    }

    /* ============================================================================== */

    /* -------------------------- [ Test print operation ] -------------------------- */

    cout << "<<< Testing the print operation:" << endl;
    cout << endl;

    cout << "intGenericTree " << endl;
    intGenericTree.print(intGenericTree.Root());
    cout << endl;

    cout << "stringGenericTree " << endl;
    stringGenericTree.print(stringGenericTree.Root());
    cout << endl;

    cout << "stringEmptyTree " << endl;
    stringEmptyTree.print(stringEmptyTree.Root());
    cout << endl;

    /* ============================================================================== */

    /* ============================================================================== */

    /* ------------------ [ Test recursive take input operation ] ------------------- */

    cout << "<<< Testing the recursive take input operation:" << endl;
    cout << endl;

    cout << "intInputNode before input" << endl;
    intInputNode.print(intInputNode.Root());
    cout << endl;

    intInputNode.setRoot(intInputNode.takeInputRecursive());

    cout << "intInputNode after input" << endl;
    intInputNode.print(intInputNode.Root());
    cout << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}