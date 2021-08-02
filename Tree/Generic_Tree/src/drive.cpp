/*! \brief drive.cpp.
 *
 *  Program to test the GenericTree class.
*/
#include <iostream>
#include "GenericTree.h"

using namespace std;

/**
 * Method to fill a tree
 */
template <typename T>
void fillTree(GenericTree<T> *tree_)
{
    // Create the root node
    TreeNode<T> *filleTreeRoot = new TreeNode<T>(1);

    // Fill manually the tree
    tree_->setRoot(filleTreeRoot); // root (1st level)
    tree_->push(tree_->Root(), 2); // 2nd level
    tree_->push(tree_->Root(), 3);
    tree_->push(tree_->Root(), 4);
    tree_->push(tree_->Root()->Children()->getAt(0), 5); // 3rd level
    tree_->push(tree_->Root()->Children()->getAt(0), 6);
    tree_->push(tree_->Root()->Children()->getAt(1), 7);
    tree_->push(tree_->Root()->Children()->getAt(2), 8);
    tree_->push(tree_->Root()->Children()->getAt(2)->Children()->getAt(0), 9); // 4th level
}

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
    GenericTree<int> intFilledTree;

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

    // Pre-fill the tree
    fillTree(&intFilledTree);

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

    /* ------------------ [ Test recursive take input operation ] ------------------- */

    cout << "<<< Testing the recursive take input operation:" << endl;
    cout << endl;

    cout << "intInputNode before input" << endl;
    intInputNode.print(intInputNode.Root());
    cout << endl;

    //intInputNode.setRoot(intInputNode.takeInputRecursive());
    //intInputNode.setRoot(intInputNode.takeInputLevelWise());

    cout << "intInputNode after input" << endl;
    //intInputNode.print(intInputNode.Root());
    intInputNode.printLevelWise(intInputNode.Root());
    cout << endl;

    /* ============================================================================== */

    intFilledTree.printLevelWise(intFilledTree.Root());

    /* ----------------------- [ Test nodes count operation ] ----------------------- */

    cout << "<<< Testing the nodes count operation:" << endl;
    cout << endl;

    cout << "intFilledTree nodes count (treeSize): " << intFilledTree.getTreeSize() << endl;
    cout << "intFilledTree nodes count (nodes count): " << intFilledTree.countNodes(intFilledTree.Root()) << endl;
    cout << endl;

    /* ============================================================================== */

    /* ----------------------- [ Test tree height operation ] ----------------------- */

    cout << "<<< Testing the tree height operation:" << endl;
    cout << endl;

    cout << "intFilledTree height: " << intFilledTree.height(intFilledTree.Root()) << endl;
    cout << endl;

    /* ============================================================================== */

    /* --------------------- [ Test printNodesLevelK operation ] -------------------- */

    cout << "<<< Testing the printNodesLevelK operation:" << endl;
    cout << endl;

    int depthLevel = 0;
    cout << "intFilledTree nodes at level " << depthLevel << ": " << endl;
    intFilledTree.printNodesLevelK(intFilledTree.Root(), depthLevel);
    cout << endl;

    depthLevel = 1;
    cout << "intFilledTree nodes at level " << depthLevel << ": " << endl;
    intFilledTree.printNodesLevelK(intFilledTree.Root(), depthLevel);
    cout << endl;

    depthLevel = 2;
    cout << "intFilledTree nodes at level " << depthLevel << ": " << endl;
    intFilledTree.printNodesLevelK(intFilledTree.Root(), depthLevel);
    cout << endl;

    depthLevel = 3;
    cout << "intFilledTree nodes at level " << depthLevel << ": " << endl;
    intFilledTree.printNodesLevelK(intFilledTree.Root(), depthLevel);
    cout << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}