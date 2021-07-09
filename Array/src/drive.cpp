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

    cout << "<<< Testing the Array initialization:" << endl;

    // Add some values
    for (size_t i = 0; i < 5; i++)
    {
        intArray.add(i);
        stringArray.add("Hello!");
    }

    // Print the values
    cout << "intArray: [ ";

    for (auto i = 0; i < intArray.size(); i++)
    {
        cout << intArray.get(i) << " ";
    }

    cout << "]" << endl;

    cout << "stringArray: [ ";

    for (auto i = 0; i < stringArray.size(); i++)
    {
        cout << stringArray.get(i) << " ";
    }

    cout << "]" << endl
         << endl;

    /* ============================================================================== */

    /* ------------------------ [ Test the Array deep copy ] ------------------------ */

    /**
     * Now, let's create another integer array
     * and assign the values from original array to the new one
     */
    Array<int> intArray2 = intArray;

    cout << "<<< Testing the copy constructor:" << endl;

    cout << "intArray2: [ ";

    // Print the new int array values
    for (int i = 0; i < intArray2.size(); i++)
    {
        cout << intArray2.get(i) << " ";
    }

    cout << "]" << endl
         << endl;

    /* ============================================================================== */

    /* ============================================================================== */

    /* ------------------------ [ Test the Array operator = ] ----------------------- */

    // Create one more Array
    Array<int> intArray3;
    
    // Assign the original Array to the new one
    intArray3 = intArray;

    cout << "<<< Testing the operator=:" << endl;

    cout << "intArray3: [ ";

    // Print the new int array values
    for (int i = 0; i < intArray3.size(); i++)
    {
        cout << intArray3.get(i) << " ";
    }

    cout << "]" << endl
         << endl;

    /* ============================================================================== */

    return 0;
}