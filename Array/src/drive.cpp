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

    cout << "Initial values:" << endl;

    for (size_t i = 0; i < 5; i++)
    {
        // Add some values
        intArray.add(10);
        stringArray.add("Hello!");

        // Print the values
        cout << intArray.get(i) << endl;
        cout << stringArray.get(i) << endl;
    }

    cout << endl;

    /* ============================================================================== */

    /* ------------------------ [ Test the Array deep copy ] ------------------------ */

    /**
     * Now, let's create another integer array
     * and assign the values from original array to the new one
     */
    Array<int> intArray2 = intArray;

    cout << "New array with copied values:" << endl;

    // Print the new int array values
    for (int i = 0; i < intArray2.size(); i++)
    {
        cout << intArray2.get(i) << " ";
    }

    cout << endl;

    /* ============================================================================== */

    return 0;
}