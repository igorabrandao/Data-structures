// ***************************************************
// ** Implements the functions from HashMap class
// ***************************************************
#include "HashMap.h"

// ***************************************************
// ** Functions
// ***************************************************

/**
 * Class constructor
 */
template <typename T>
HashMap<T>::HashMap()
{
	// Set the strack basic attributes
	this->count = 0;
	this->numBuckets = 0;

	// Initialize the bucket array
	this->buckets = new MapNode<T> *[this->numBuckets];

	for (auto i = 0; i < this->numBuckets; i++)
		this->buckets[i] = nullptr;
}

/**
 * Class destructor
 */
template <typename T>
HashMap<T>::~HashMap()
{
	// Destroy the bucket array items linked list
	for (auto i = 0; i < this->numBuckets; i++)
		delete this->buckets[i];

	// Destroy the bucket array itself
	delete[] this->buckets;
}

/**
 * Function to generate a index according to the key
 * 
 * time complexity: O(1)
 * space complexity: O(1)
 */
template <typename T>
int HashMap<T>::hashFunction(string key_) const
{
	int hashCode = 0;
	int base = 1;
	int prime = 37; // Can be any prime number, the bigger the best

	// Loop the key in rever order
	for (auto i = key_.size() - 1; i >= 0; i--)
	{
		hashCode += key_[i] * base;
		base = base * p;

		// Compress to avoid out of index
		hashCode = hashCode % this->numBuckets;
		base = base % this->numBuckets;
	}

	// Return the hashCode compressed according to the bucket array size
	return hashCode % this->numBuckets;
}

/**
 * Function to return the bucket array size
 * 
 * time complexity: O(1)
 * space complexity: O(1)
 */
template <typename T>
int HashMap<T>::size() const
{
	// Return the number of <K, V> pairs on the map
	return this->count;
}

/**
 * Function to get the value by its key
 * 
 * time complexity: O(1)
 * space complexity: O(1)
 */
template <typename T>
T HashMap<T>::getValue(string key_) const
{
}

/**
 * Method to insert a <K, V> pair into the map
 * 
 * time complexity: O(1)
 * space complexity: O(1)
 */
template <typename T>
void HashMap<T>::insert(string key_, T value_)
{
	// Get the unique index
	int bucketIndex = this->hashFunction(key_);

	// Point to the bucket list item LL head
	MapNode<T> *head = this->buckets[bucketIndex];

	// Loop over the linked list
	while (head != nullptr)
	{
		// Check if it already exists a node with the same key
		if (head->key == key_)
		{
			head->value = value_;
			return;
		}

		// Goto the next node
		head = head->next;
	}

	// Insert the new node at the head of the Linked List
	MapNode<T> *node = new MapNode<T>(key_, value_);
	node->next = this->buckets[bucketIndex];
	this->buckets[bucketIndex] = node;

	// Update the number of <key, value> pairs inside the map
	this->count++;
}

/**
 * Method to remove a pair from the map
 * 
 * time complexity: O(1)
 * space complexity: O(1)
 */
template <typename T>
T HashMap<T>::remove(string key_)
{
	// Get the unique index
	int bucketIndex = this->hashFunction(key_);

	// Point to the bucket list item LL head
	MapNode<T> *head = this->buckets[bucketIndex];
	MapNode<T> *prev = nullptr;
	T value;

	// Loop over the linked list
	while (head != nullptr)
	{
		// Check if it already exists a node with the same key
		if (head->key == key_)
		{
			// Check if the key is on the LL head
			if (prev == nullptr)
			{
				// Unlink the head node
				this->buckets[bucketIndex] = head->next;
			}
			else
			{
				// Unlink the node
				prev->next = head->next;
			}

			// Store the node value before deleting it
			value = head->value;

			// Isolate the node to be deleted, since the destructor is recursive
			head->next = nullptr;

			// Now delete the node without destroying the rest of the LL
			delete head;

			// Update the number of <key, value> pairs inside the map
			this->count--;

			return value;
		}

		// Goto the next node
		prev = head;
		head = head->next;
	}

	// Given key is not present
	return T();
}

// ***************************************************
// ** Overload operators
// ***************************************************