/*!
	<PRE>
	SOURCE FILE : HashMap.h
	DESCRIPTION.: HashMap class - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: August/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Data Structures Project.

	tail UPDATE.: August 05th, 2021.
	</pre>
*/
#ifndef QUEUELL_H_
#define QUEUELL_H_

#include <iostream>
#include <string>

using namespace std;

/**
 * HashMap node template class
 */
template <class T>
class MapNode
{
private:
public:
    // ***************************************************
    // ** Attributes
    // ***************************************************
    string key;       // The node key
    T value;          // The node value
    MapNode<T> *next; // The Linked List structure to holds the QueueLL data

    // ***************************************************
    // ** Functions
    // ***************************************************
    MapNode(string key_, T value_)
    {
        this->key = key_;
        this->value = value_;
    };
    ~MapNode() { delete next; };
};

/**
 * HashMap template class
 */
template <class T>
class HashMap
{
private:
    // ***************************************************
    // ** Attributes
    // ***************************************************
    MapNode<T> **buckets; // Bucket array
    int numBuckets;       // Bucket array size
    int count;            // Number of entries

    int hashFunction(string key_) const; // Function to generate a index according to the key

public:
    // ***************************************************
    // ** Functions
    // ***************************************************
    HashMap();                          // Class constructor
    ~HashMap();                         // Class Destructor
    int size() const;                   // Function to return the bucket array size
    T getValue(string key_) const;      // Function to get the value by its key
    void insert(string key_, T value_); // Method to insert a <K, V> pair into the map
    void remove(string key_);           // Method to remove a pair from the map

    // ***************************************************
    // ** Overload operators
    // ***************************************************
};

#include "HashMap.inl"
#endif

/* --------------------- [ End of the HashMap.h header ] ------------------- */
/* ============================================================================ */