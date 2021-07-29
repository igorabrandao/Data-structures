// ***************************************************
// ** Implements the functions from GenericTree class
// ***************************************************
#include "GenericTree.h"

// ***************************************************
// ** Functions
// ***************************************************

/**
 * Class constructor
 */
template <typename T>
GenericTree<T>::GenericTree()
{
	// Initialize the list basic attributes
	this->root = new TreeNode<T>();
	this->setTreeSize(0);
}

/**
 * Class constructor overload
 */
template <typename T>
GenericTree<T>::GenericTree(T data_)
{
	// Initialize the list basic attributes
	this->root = new TreeNode<T>(data_);
	this->setTreeSize(0);
}

/**
 * Class destructor
 */
template <typename T>
GenericTree<T>::~GenericTree()
{
	// TODO
}

/**
 * Copy constructor (deep copy)
 * 
 * time complexity: O(n)
 */
template <typename T>
GenericTree<T>::GenericTree(const GenericTree &obj_)
{
	// TODO
}

/**
 * Method to add a node to a given node of the tree
 * 
 * time complexity O(1)
 */
template <typename T>
void GenericTree<T>::push(TreeNode<T> *node_, T data_)
{
	// Create the new node with the given data
	TreeNode<T> *newNode = new TreeNode<T>(data_);

	// Add the new node to the children list of the given node
	node_->Children()->push(newNode);

	// Update the tree size
	this->setTreeSize(this->treeSize++);
}

/**
 * Method to add a child to a given node
 * 
 * time complexity O(1)
 */
template <typename T>
void GenericTree<T>::pushChild(TreeNode<T> *parentNode_, TreeNode<T> *childNode_)
{
	// Connect the child node with its parent
	parentNode_->Children()->push(childNode_);

	// Update the tree size
	this->setTreeSize(this->treeSize++);
}

/**
 * Method to print the tree
 * 
 * time complexity O(n)
 * space complexity O(n)
 */
template <typename T>
void GenericTree<T>::print(TreeNode<T> *root_) const
{
	// Handle edge case
	if (root_ == nullptr)
	{
		cout << "<Empty tree>" << endl;
		return;
	}

	// Print the current tree node value
	cout << root_->Data() << ": ";

	// Loop over the current node children
	for (auto i = 0; i < root_->Children()->size(); i++)
	{
		cout << root_->Children()->getAt(i)->Data() << " ";
	}
	cout << endl;

	for (auto i = 0; i < root_->Children()->size(); i++)
	{
		this->print(root_->Children()->getAt(i));
	}
}

/**
 * Method to fill the tree recursively
 */
template <typename T>
TreeNode<T> *GenericTree<T>::takeInputRecursive()
{
	// Receive the tree node data from the user input
	T rootData;
	cout << "Enter the node data: ";
	cin >> rootData;

	// Set the root node with the given data
	TreeNode<T> *root = new TreeNode<T>(rootData);

	// Receive the number of children for the current node
	int nChildren;
	cout << "Enter num of children of " << rootData << ": ";
	cin >> nChildren;

	// Loop over the node children
	for (auto i = 0; i < nChildren; i++)
	{
		// Create the child node and input it with children nodes
		TreeNode<T> *childNode = this->takeInputRecursive();

		// Input the current root node children
		this->pushChild(root, childNode);
	}

	return root;
}

// ***************************************************
// ** Overload operators
// ***************************************************