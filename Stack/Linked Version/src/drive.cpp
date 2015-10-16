#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack<int> stk;
	stk.push(5);
	stk.push(4);
	stk.push(3);
	stk.push(2);
	stk.push(1);
	stk.print();

	cout << "Push OK! agora vou testar o pop()" << endl;
	stk.pop();
	cout << "Vou imprimir depois de dar o pop()" << endl;
	stk.print();
	cout << "Pop ok!!! agora vou testar o front()" << endl;
	cout << "O elemento do topo eh: " << stk.top() << endl;
	cout << "print novamente" << endl;
	stk.print();
	return 0;
}