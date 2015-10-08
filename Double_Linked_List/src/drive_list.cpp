#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	// Declarando a lista.
	List<int> myList;
	myList.print();
	cout << "O tamanho da lista eh : " << myList.size() << endl;
	cout << "A lista esta vazia ? Sim se size == 0 e nao caso size != 0" << endl;
	if(myList.empty())
		cout << ">>> SIM, esta vazia!!!" << endl;
	else
		cout << ">>> NAO, tem elementos!!!" << endl;	
	myList.push_back(1);
	myList.print();
	myList.push_back(2);
	myList.print();
	myList.push_back(3);
	myList.print();
	cout << ">>> push_front(0)" << endl;
	myList.push_front(0);
	myList.print();
	cout << ">>> push_front(-1)" << endl;
	myList.push_front(-1);
	myList.print();
	cout << "Hello world" << endl;
	cout << "O tamanho da lista eh : " << myList.size() << endl;
	return EXIT_SUCCESS;
}
