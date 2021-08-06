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
 * time complexity: O(l) where l is the key size
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
 * Method to perform the rehash operation
 * 
 * time complexity: O(n)
 */
template <typename T>
void HashMap<T>::rehash()
{
	// Create a copy of the current buckets
	MapNode<T> **temp = this->buckets;

	int oldBucketSize = this->numBuckets;
	int newBucketSize = (2 * this->numBuckets);

	// Double the bucket size
	this->buckets = new MapNode<T> *[newBucketSize];

	// Initialize the new doubled bucket array to remove garbage
	for (auto i = 0; i < newBucketSize; i++)
		this->buckets[i] = nullptr;

	// Reinitialize the map attributes
	this->count = 0;
	this->numBuckets = oldBucketSize;

	// Loop over the original bucket array
	for (auto i = 0; i < oldBucketSize; i++)
	{
		// Point to the LL head of the current item
		MapNode<T> *head = temp[i];

		// Loop over the linked list
		while (head != nullptr)
		{
			// Get the current node <key, value> pair
			string currKey = head->key;
			T currValue = head->value;

			// Insert the current <key, value> pair into the new bucket array
			this->insert(currKey, currValue);

			// Goto the next node
			head = head->next;
		}
	}

	// Delete the temp bucket array
	for (auto i = 0; i < oldBucketSize; i++)
		delete temp[i];

	delete[] temp;
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
	// Get the unique index
	int bucketIndex = this->hashFunction(key_);

	// Point to the bucket list item LL head
	MapNode<T> *head = this->buckets[bucketIndex];

	// Loop over the linked list
	while (head != nullptr)
	{
		// Check if it exists a node with the given key
		if (head->key == key_)
			return head->value;

		// Goto the next node
		head = head->next;
	}

	// Given key is not present
	return T();
}

/**
 * Method to insert a <K, V> pair into the map
 * 
 * time complexity: O(n) + O(l) = O(n)
 * in case we have a bad hashFunction and all values goes to the same
 * index. So traversing the LL will take O(n)
 * However, since we have a good hashFunction O(n) will never happen, so
 * the average case will be O(n/b), where n is the number of <key, value> pairs
 * and b is the bucket array size. n/b stands for the map Load Factor.
 * A good Load Factor is around 0.7
 * In other words, since we have O(n/b) and n/b <= 0.7, the real time complexity
 * is O(1)
 * 
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

	// Calculates the current load factor
	double currLoadFactor = (1.0 * this->count / this->numBuckets);

	if (currLoadFactor > this->loadFactor)
		this->rehash();
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