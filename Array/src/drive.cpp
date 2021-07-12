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
    // Array initial size
    int iSize = 10;

    /* ---------------------------- [ Test Array class ] ---------------------------- */

    // Array class instance with int
    Array<int> intArray(iSize);

    // Array class instance with string
    Array<std::string> stringArray(iSize);

    cout << "<<< Testing the Array initialization:" << endl;

    // Add some values
    for (auto i = 0; i < iSize; i++)
    {
        intArray.add(i);
        stringArray.add("Hello!");
    }

    // Print the values
    intArray.print("intArray");
    stringArray.print("stringArray");
    cout << endl;

    /* ============================================================================== */

    /* ------------------------ [ Test the Array deep copy ] ------------------------ */

    /**
     * Now, let's create another integer array
     * and assign the values from original array to the new one
     */
    Array<int> intArray2 = intArray;

    cout << "<<< Testing the copy constructor:" << endl;
    intArray2.print("intArray2");
    cout << endl;

    /* ============================================================================== */

    /* ------------------------ [ Test the Array operator = ] ----------------------- */

    // Create more Arrays
    Array<int> intArray3;
    Array<int> intArray4;
    Array<int> intArray5;

    // Assign the original Array to the new one
    intArray3 = intArray;

    cout << "<<< Testing the operator=:" << endl;
    intArray3.print("intArray3");
    cout << endl;

    // Assign the original Array to multiple ones
    intArray4 = intArray5 = intArray;

    cout << "<<< Testing the operator= with cascading:" << endl;
    intArray4.print("intArray4");

    intArray5.print("intArray5");
    cout << endl;

    /* ============================================================================== */

    /* ------------------------ [ Test the Array operator [] ] ---------------------- */

    cout << "<<< Testing the operator[]:" << endl;
    cout << "intArray[0]: " << intArray[0] << endl;
    cout << "intArray[5]: " << intArray[5] << endl;
    cout << "intArray[9]: " << intArray[9] << endl;
    //cout << "intArray[10]: " << intArray[10] << endl;
    //cout << "intArray[-1]: " << intArray[-1] << endl;
    cout << endl;

    /* ============================================================================== */

    /* ------------------------- [ Test the expand operation ] ---------------------- */

    cout << "<<< Expanding the intArray:" << endl;
    int nSize = 50;
    intArray.expand(nSize);

    // Fill the new Array positions
    for (auto i = iSize; i < nSize; i++)
    {
        intArray[i] = i;
    }

    intArray.print("intArray");
    cout << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}