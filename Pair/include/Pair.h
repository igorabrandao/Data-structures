/*!
	<PRE>
	SOURCE FILE : Pair.h
	DESCRIPTION.: Pair class - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Data Structures Project.

	tail UPDATE.: July 25th, 2021.
	</pre>
*/
#ifndef PAIR_H_
#define PAIR_H_

#include <iostream>

using namespace std;

/**
 * Pair template class
 */
template <class T, class V>
class Pair
{
private:
    // ***************************************************
    // ** Attributes
    // ***************************************************
    T x; // x attribute
    V y; // y attribute

public:
    // ***************************************************
    // ** Functions
    // ***************************************************
    Pair()
    {
        this->x = T();
        this->y = V();
    };
    Pair(T x_, V y_)
    {
        this->setX(x_);
        this->setY(y_);
    };                                       // Class constructor overload
    ~Pair(){};                               // Class Destructor
    void setX(T data_) { this->x = data_; }; // Set the x attribute
    T getX() { return this->x; };            // Return the x attribute
    void setY(V data_) { this->y = data_; }; // Set the y attribute
    V getY() { return this->y; };            // Return the y attribute

    // ***************************************************
    // ** Overload operators
    // ***************************************************
};

#endif

/* --------------------- [ End of the Pair.h header ] ------------------- */
/* ========================================================================= */