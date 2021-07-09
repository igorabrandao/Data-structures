/*! \brief drive.cpp.
 *
 *  Program to test the Array class.
*/
#include <iostream>
#include <string>
#include "Array.h"

using namespace std;

/**
 * Main method
 */
int main()
{
	/* ---------------------------- [ Test Array class ] ---------------------------- */

    // Array class instance with int
    Array<int> intArray;

    // Array class instance with string
    Array<std::string> stringArray;

    // Add some values
    for (size_t i = 0; i < 5; i++)
    {
        intArray.add(10);
        stringArray.add("Hello!");
    }

    // Print the values
    for (size_t i = 0; i < 5; i++)
    {
        cout << intArray.get(i) << endl;
        cout << stringArray.get(i) << endl;
    }

	/* ========================================================================= */

	return 0;
}