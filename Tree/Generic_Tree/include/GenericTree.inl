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
	this->treeSize++;
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
	this->treeSize++;
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
 * Method to print the tree level wise
 * 
 * time complexity O(n)
 * space complexity O(n)
 */
template <typename T>
void GenericTree<T>::printLevelWise(TreeNode<T> *root_) const
{
	// Create a queue to store the nodes ref
	QueueLL<TreeNode<T> *> q;
	q.push(root_);

	while (!q.isEmpty())
	{
		// Store the front node from the queue and remove it
		TreeNode<T> *frontNode = q.front();
		q.pop();

		// Print the front node
		cout << frontNode->Data() << ": ";

		for (auto i = 0; i < frontNode->Children()->size(); i++)
		{
			TreeNode<T> *childNode = frontNode->Children()->getAt(i);

			// Add the child node to the stack
			q.push(childNode);

			// Print the current child node
			cout << childNode->Data() << " ";
		}

		cout << endl;
	}
}

/**
 * Method to print the tree in pre order traversal
 * 
 * time complexity O(n)
 * space complexity O(n)
 */
template <typename T>
void GenericTree<T>::preOrder(TreeNode<T> *root_) const
{
	// Handle edge case
	if (root_ == nullptr)
	{
		cout << "<Empty tree>" << endl;
		return;
	}

	// Print the current tree node value
	cout << root_->Data() << " ";

	// Loop over the current node children
	for (auto i = 0; i < root_->Children()->size(); i++)
		this->preOrder(root_->Children()->getAt(i));
}

/**
 * Method to print the tree in post order traversal
 * 
 * time complexity O(n)
 * space complexity O(n)
 */
template <typename T>
void GenericTree<T>::postOrder(TreeNode<T> *root_) const
{
	// Handle edge case
	if (root_ == nullptr)
	{
		cout << "<Empty tree>" << endl;
		return;
	}

	// Loop over the current node children
	for (auto i = 0; i < root_->Children()->size(); i++)
		this->postOrder(root_->Children()->getAt(i));

	// Print the current tree node value
	cout << root_->Data() << " ";
}

/**
 * Function to fill the tree recursively
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

/**
 * Function to fill the tree level wise
 */
template <typename T>
TreeNode<T> *GenericTree<T>::takeInputLevelWise()
{
	// Receive the tree node data from the user input
	T rootData;
	cout << "Enter the root data: ";
	cin >> rootData;

	// Set the root node with the given data
	TreeNode<T> *root = new TreeNode<T>(rootData);

	// Add the root node to the tree size
	this->treeSize++;

	// Create a queue to store the nodes ref
	QueueLL<TreeNode<T> *> q;
	q.push(root);

	while (!q.isEmpty())
	{
		// Store the front node from the queue and remove it
		TreeNode<T> *frontNode = q.front();
		q.pop();

		// Receive the number of children for the current node
		int nChildren;
		cout << "Enter num of children of " << frontNode->Data() << ": ";
		cin >> nChildren;

		for (auto i = 1; i <= nChildren; i++)
		{
			// Receive the current child input
			T childData;
			cout << "Enter the " << i << "th child of " << frontNode->Data() << ": ";
			cin >> childData;

			/**
			 * Now perform 3 operations:
			 * 1) create de node
			 * 2) push it to the queue
			 * 3) connect it with the parent
			 */
			TreeNode<T> *childNode = new TreeNode<T>(childData);
			q.push(childNode);
			frontNode->Children()->push(childNode);

			// Update the tree size
			this->treeSize++;
		}
	}

	return root;
}

/**
 * Function to count the number of tree nodes
 */
template <typename T>
int GenericTree<T>::countNodes(TreeNode<T> *root_) const
{
	// Test the edge case
	if (root_ == nullptr)
		return 0;

	int count = 1;

	// Loop over the root children nodes
	for (auto i = 0; i < root_->Children()->size(); i++)
	{
		// Count the current child children nodes recursively
		count += this->countNodes(root_->Children()->getAt(i));
	}

	return count;
}

/**
 * Function to count the number of tree leaf nodes
 */
template <typename T>
int GenericTree<T>::countLeafNodes(TreeNode<T> *root_) const
{
	// Test the edge case
	if (root_ == nullptr)
		return 0;

	// Test the base case
	if (root_->Children()->size() == 0)
		return 1;

	int count = 0;

	// Loop over the root children nodes
	for (auto i = 0; i < root_->Children()->size(); i++)
	{
		// Count the current child children leaf nodes recursively
		count += this->countLeafNodes(root_->Children()->getAt(i));
	}

	return count;
}

/**
 * Function to count the tree height
 */
template <typename T>
int GenericTree<T>::height(TreeNode<T> *root_) const
{
	// Test the edge case
	if (root_ == nullptr)
		return 0;

	int maxHeight = 0;

	// Loop over the root children nodes
	for (auto i = 0; i < root_->Children()->size(); i++)
	{
		// Count the subtree height recursively and Update the maxHeight
		maxHeight = max(maxHeight, this->height(root_->Children()->getAt(i)));
	}

	return maxHeight + 1;
}

/**
 * Method to print the tree nodes at K depth level
 */
template <typename T>
void GenericTree<T>::printNodesLevelK(TreeNode<T> *root_, int k_) const
{
	// Test the edge case
	if (root_ == nullptr)
		return;

	// Base case (we reach the desired depth level of the tree)
	if (k_ == 0)
	{
		cout << root_->Data() << " ";
		return;
	}

	// Traverse the tree recursively
	for (auto i = 0; i < root_->Children()->size(); i++)
	{
		printNodesLevelK(root_->Children()->getAt(i), (k_ - 1));
	}
}

/**
 * Method to delete the tree
 * 
 * time complexity O(n)
 * space complexity O(n)
 */
template <typename T>
void GenericTree<T>::deleteTree(TreeNode<T> *root_)
{
	// Handle edge case
	if (root_ == nullptr)
		return;

	// Loop over the current node children
	for (auto i = 0; i < root_->Children()->size(); i++)
		deleteTree(root_->Children()->getAt(i));

	// Delete the current node
	delete root_;
}

// ***************************************************
// ** Overload operators
// ***************************************************