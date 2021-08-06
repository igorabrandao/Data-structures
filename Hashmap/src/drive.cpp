/*! \brief drive.cpp.
 *
 *  Program to test the Hashmap class.
*/
#include <iostream>
#include "HashMap.h"

using namespace std;

/**
 * Main method
 */
int main()
{
    // Hashmap initial size
    int iSize = 10;
    string phrase = "queue";

    /* ---------------------------- [ Test Hashmap class ] ---------------------------- */

    // Hashmap class instance with int
    HashMap<int> intHashmap;

    cout << "<<< Testing the Hashmap initialization:" << endl;

    // Add some values
    for (auto i = 0; i < iSize; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        intHashmap.insert(key, value);
    }

    // Print the hashmap
    cout << "intHashmap size: " << intHashmap.size() << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}