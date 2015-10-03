#include <iostream>

typedef int Datatype;

struct Node
{
	Datatype data;
	Node * next;
};

void PrintList( Node * _original )
{
	Node * tmp(_original);

	std::cout << "[ ";
	while( tmp != nullptr )
	{
		std::cout << tmp->data << " "; 
		tmp = tmp->next;
	}
	std::cout << "]\n";
}

void push_back( Node * _original, Datatype data_ )
{

}

Node * clone ( Node * _original )
{
	// AIL (cabeça) da lista clonada
	Node * headClone(nullptr);

	// Ponteiro temporário usado para percorrer a lista original
	Node * ptr(_original);

	// Ponteiro que aponta sempre para o final da lista
	Node * tail(nullptr);

	// Ponteiro para receber o novo nó
	Node * newNode(nullptr);

	// Laço para percorrer a lista original
	while ( ptr != nullptr )
	{
		// Se entrar no laço, ao menos 1 nó será clonado
		tail = new Node;
		tail->data = ptr->data;	/*!< Copia o dado do nó atual */
		tail->next = nullptr;

		/*! Testa se é a primeira inserção */
		if ( headClone == nullptr )
		{
			headClone = tail;
			//tail = newNode;
		}
		// Copia os demais nós (a partir da segunda)
		else
		{
			tail->next = newNode; 	/*!< Conecta o novo nó a lista clone */
			//tail = tail->next;		/*!< Avança tail (invariante do laço); tail++ */
		}
		tail = newNode;		/*!< Tail sempre aponta para o novo nó */

		ptr = ptr->next;	/*!< Avança para o próximo nó da lista */
	}

	return headClone;
}

int main ()
{
	// Aloca a cabeça da lista original
	Node * head( nullptr );

	// Adiciona elementos a lista original
	push_back(head, 1);
	push_back(head, 2);
	push_back(head, 3);
	push_back(head, 4);

	// Imprime a lista original
	std::cout << ">>> Lista original: ";
	PrintList(head);

	Node * novaLista;
	novaLista = head;

	// Clone da lista
	novaLista = clone(head);

	// Imprime a nova lista
	std::cout << ">>> Lista clonada: ";
	PrintList(novaLista);

	push_back(novaLista, 5);

	// Imprime a nova lista
	std::cout << ">>> Lista clonada apos insercao: ";
	PrintList(novaLista);

	std::cout << ">>> Lista original (apos insercao no clone): ";
	PrintList(head);
}