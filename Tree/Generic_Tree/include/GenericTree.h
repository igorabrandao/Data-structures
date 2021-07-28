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

    // ***************************************************
    // ** Functions
    // ***************************************************
    GenericTree();                        // Class constructor
    GenericTree(T data_);                 // Class constructor overload
    ~GenericTree();                       // Class Destructor
    GenericTree(const GenericTree &obj_); // Copy constructor
    void push(TreeNode<T> *, T data_);    // Method to add a node to a given node of the tree
    void print(TreeNode<T> *root_) const; // Method to print the tree

    // ***************************************************
    // ** Overload operators
    // ***************************************************
};

#include "GenericTree.inl"
#endif

/* --------------------- [ End of the GenericTree.h rooter ] ------------------- */
/* ============================================================================ */