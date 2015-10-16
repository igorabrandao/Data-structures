#include "Stack.h"

template <class T>
Stack<T>::Stack()
{
	init();
}

template <class T>
Stack<T>::Stack( const Stack & rhs )
{
	iterator itr = begin();	/*!< Iterador auxiliar para percorrer a lista */
	while ( itr != end() )	/*!< Percorre a lista */ 
	{
		insert( itr.current->data );
		++( itr );
	}
}

template <class T>
Stack<T>::~Stack()
{
	clear();
	delete head;
	delete tail;
}


template <class T>
void
Stack<T>::init()
{
	theSize = 0;
	head = new Node();
	tail = new Node();
	head->next = tail;
	tail->prev = head;
}