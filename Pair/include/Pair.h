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
template <class T1, class T2>
class Pair
{
private:
    // ***************************************************
    // ** Attributes
    // ***************************************************
    T1 x; // x attribute
    T2 y; // y attribute

public:
    // ***************************************************
    // ** Functions
    // ***************************************************
    Pair()
    {
        this->x = T1();
        this->y = T2();
    };
    Pair(T1 x_, T2 y_)
    {
        this->setX(x_);
        this->setY(y_);
    };                                        // Class constructor overload
    ~Pair(){};                                // Class Destructor
    void setX(T1 data_) { this->x = data_; }; // Set the x attribute
    T1 getX() { return this->x; };            // Return the x attribute
    void setY(T2 data_) { this->y = data_; }; // Set the y attribute
    T2 getY() { return this->y; };            // Return the y attribute

    // ***************************************************
    // ** Overload operators
    // ***************************************************
};

#endif

/* --------------------- [ End of the Pair.h header ] ------------------- */
/* ========================================================================= */