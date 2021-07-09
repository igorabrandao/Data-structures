#include <iostream>
#include <string>
#include "MemoryCell.h"

using namespace std;

/**
 * Program to test the MemoryCell template class
 */
int main()
{
    MemoryCell<int> m1;
    MemoryCell<string> m2("hello");
    MemoryCell<float> m3;
    MemoryCell<double> m4(2.1);

    m1.write(37);
    m2.write(m2.read() + " world!");
    m3.write(1.8f);
    m4.write(m4.read() * 2);

    cout << m1.read() << endl
         << m2.read() << endl
         << m3.read() << endl
         << m4.read() << endl;

    return 0;
}