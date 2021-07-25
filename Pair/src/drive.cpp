/*! \brief drive.cpp.
 *
 *  Program to test the Pair class.
*/
#include <iostream>
#include <string>
#include "Pair.h"

using namespace std;

/**
 * Main method
 */
int main()
{
    /* ---------------------------- [ Test Pair class ] ---------------------------- */

    cout << "<<< Testing the Pair initialization:" << endl;

    // Pair class instance with int
    Pair<int, int> intPair(1, 2);

    // Pair class instance with string
    Pair<std::string, std::string> stringPair;
    stringPair.setX("Hello");
    stringPair.setY("World!");

    // Pair class instance with pair of float
    Pair<float, float> tempFloat(1.44, 3.55);
    Pair<float, Pair<float, float>> floatTriple;
    floatTriple.setX(0.33);
    floatTriple.setY(tempFloat);

    // Print the pairs
    cout << "intPair: <" << intPair.getX() << ", " << intPair.getY() << ">" << endl;
    cout << "stringPair: <" << stringPair.getX() << ", " << stringPair.getY() << ">" << endl;
    cout << "floatTriple: <" << floatTriple.getX() << ", " << floatTriple.getY().getX() << ", " << floatTriple.getY().getY() << ">" << endl;
    cout << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}