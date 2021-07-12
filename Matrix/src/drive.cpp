/*! \brief drive.cpp.
 *
 *  Program to test the Matrix class.
*/
#include <iostream>
#include <string>
#include "Matrix.h"

using namespace std;

/**
 * Program to test the Matrix template class
 */
int main()
{
    // Matrix initial size
    int iRows = 2;
    int iCols = 5;

    /* ---------------------------- [ Test Matrix class ] ---------------------------- */

    // Matrix class instance with int
    Matrix<int> intMatrix(iRows, iCols);

    cout << "<<< Testing the Matrix initialization:" << endl;

    // Add some values
    for (auto i = 0; i < iRows; i++)
    {
        for (auto j = 0; j < iCols; j++)
        {
            intMatrix.add(i, j, (i * iCols + j));
        }
    }

    // Print the values
    intMatrix.print("intMatrix");
    cout << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}