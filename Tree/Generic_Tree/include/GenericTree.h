/*!
	<PRE>
	SOURCE FILE : GenericTree.h
	DESCRIPTION.: GenericTree class - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Data Structures Project.

	tail UPDATE.: July 28th, 2021.
	</pre>
*/
#ifndef GENERIC_TREE_H_
#define GENERIC_TREE_H_

#include <iostream>
#include <string>
#include "../../../Array/include/Array.h"
#include "../../../Queue/LinkedList/include/QueueLL.h"

using namespace std;

/**
 * TreeNode template class
 */
template <class T>
class TreeNode
{
private:
    T data;
    Array<TreeNode<T> *> *children;

public:
    // ***************************************************
    // ** Methods
    // ***************************************************
    // Class constructor
    TreeNode() { this->children = new Array<TreeNode<T> *>(); };

    // Class constructor overload
    TreeNode(T data_) : data(data_) { this->children = new Array<TreeNode<T> *>(); };

    // Class destructor
    ~TreeNode()
    {
        // Delete the nodes with a recursive postOrder traversal
        for (auto i = 0; i < this->Children()->size(); i++)
            delete this->Children()->getAt(i);
    };

    // Adds the given node as children of the current node
    inline void setChildren(TreeNode *treeNode_) { this->children = treeNode_; };

    // Return pointer of the children node
    inline Array<TreeNode<T> *> *Children() { return this->children; };

    // Returns data of the current node
    inline T Data() { return this->data; };
};

/**
 * GenericTree template class
 */
template <class T>
class GenericTree
{
private:
    // ***************************************************
    // ** Attributes
    // ***************************************************
    TreeNode<T> *root; // The root of the list
    int treeSize = 0;  // The number of nodes in the tree

public:
    // ***************************************************
    // ** Getters and setters
    // ***************************************************
    inline void setTreeSize(int size_) { this->treeSize = size_; };
    inline int getTreeSize() { return this->treeSize; };
    inline TreeNode<T> *Root() { return this->root; };
    void setRoot(TreeNode<T> *root_)
    {
        this->root = root_;
        this->treeSize++;
    };

    // ***************************************************
    // ** Functions
    // ***************************************************
    GenericTree();                                           // Class constructor
    GenericTree(T data_);                                    // Class constructor overload
    ~GenericTree();                                          // Class Destructor
    GenericTree(const GenericTree &obj_);                    // Copy constructor
    void push(TreeNode<T> *, T data_);                       // Method to add a node to a given node of the tree
    void pushChild(TreeNode<T> *, TreeNode<T> *);            // Method to add a child to a given node
    void print(TreeNode<T> *root_) const;                    // Method to print the tree
    void printLevelWise(TreeNode<T> *root_) const;           // Method to print the tree level wise
    void preOrder(TreeNode<T> *root_) const;                 // Method to print the tree in pre order traversal
    void postOrder(TreeNode<T> *root_) const;                // Method to print the tree in post order traversal
    TreeNode<T> *takeInputRecursive();                       // Function to fill the tree recursively
    TreeNode<T> *takeInputLevelWise();                       // Function to fill the tree level wise
    int countNodes(TreeNode<T> *root_) const;                // Function to count the number of tree nodes
    int countLeafNodes(TreeNode<T> *root_) const;            // Function to count the number of tree leaf nodes
    int height(TreeNode<T> *root_) const;                    // Function to count the tree height
    void printNodesLevelK(TreeNode<T> *root_, int k_) const; // Method to print the tree nodes at K depth level
    void deleteTree(TreeNode<T> *root_);                     // Method to delete the tree

    // ***************************************************
    // ** Overload operators
    // ***************************************************
};

#include "GenericTree.inl"
#endif

/* --------------------- [ End of the GenericTree.h rooter ] ------------------- */
/* ============================================================================ */