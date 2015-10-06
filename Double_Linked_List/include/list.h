#ifndef LIST_H
#define LIST_H

template <typename Object>
class List 
{
private :
	/*! 
	 *	O noh basico da lista duplamente encadeada. Aninhada dentro de
	 *	List , a estrutura ‘Node’ ´e publica ( dentro de List ) , mas eh ainda
	 *	assim eh encapsulada para cliente pois eh declarada na categoria
	 *	‘private’ em List .
	 */
	struct Node
	{ 
		Object data; // Campo de dados
		Node *prev; // Apontador para o pr´oximo n´o
		Node *next; // Apontador para o n´o anterior
		
		// Construtor inline com varios parametros default
		Node( const Object& d = Object( ), Node* p = nullptr , Node* n = nullptr )
		: data( d )
		, prev( p )
		, next( n ) 
		{ /* Empty */ } 
	};

public :
	// Classes iteradores .
	class const_iterator 
	{	 
	public :
		// Construtor publico
		const_iterator();
		// Retorna objeto armazenado na posicao atual .
		// Para const_iterator , este metodo eh um accessor que retorna
		// uma referencia constante . Logo este operador so pode
		// aparecer do lado direito de uma atribuicao ou em comparacoes.
		const Object & operator*() const;
		// Pre-incremento : ++it
		const_iterator & operator++();
		// Pos-incremento : it++
		const_iterator operator++( int );
		// Pre-decremento : --it
		const_iterator & operator--()
		// Pos-decremento : it--
		const_iterator operator--( int )
		bool operator==( const const_iterator & rhs ) const ;
		bool operator!=( const const_iterator & rhs ) const ;

	protected :
		// Declarado como protected para ser acessivel pela classe ‘iterator’
		Node *current;
		// Construtor protegido que recebe um n´o para ser apontado .
		// Utilizado dentro da classe ‘List ’ apenas e n~ao pelo c´odigo cliente .
		const_iterator( Node* p );
		// Necess´ario p/ permitir acesso de ‘List ’ aos campos desta classe .
		friend class List<Object>;
	};

	// inheritance : IS-A relation
	class iterator : public const_iterator 
	{ 	
	public :
		// Construtor p´ublico do iterator que invoca construtor da classe base .
		iterator( ) { /* Empty */ }
		
		/*!
		 *	Retorna objeto armazenado na posicao apontada por ‘current’.
		 * 	For iterator , tem duas versoes , uma accessor que permite sua
		 * 	utilizacao do apenas do lado direito de uma atribuicao ou em
		 * 	comparacoes.
		 */
		const Object & operator*() const ;
		// Esta versao mutator eh usada do lado esquerdo de atribuicoes.
		Object & operator*();
		
		// prefixo
		iterator & operator++();
		// posfix
		iterator operator++( int );
		// prefixo
		iterator & operator--();
		// posfix
		iterator operator--( int );

	protected :
		
		/*!
		 *	Construtor protegido que espera uma posi¸c~ao para apontar .
		 *	E invocado principalmente dentro da classe ‘List ’, mas
		 * 	nao pelo cliente ( que nao tem acesso a este metodo ).
		*/
		iterator( Node *p );

		// Necessario p/ permitir acesso de ‘List’ aos campos desta classe.
		friend class List <Object >;
	};

	// Metodos basico que todas as classes deveriam oferecer
	List();
	~List();
	List( const List & rhs );
	const List & operator=( const List & rhs );

	// Metodos especificos da classe
	iterator begin(); 				// Versao mutator
	const_iterator begin() const; 	// Versao accessor
	iterator end(); 				// Versao mutator
	const_iterator end() const; 	// Versao accessor
	int size() const; 				// Retorna tamanho da lista
	bool empty() const; 			// Retorna true se vazia , falso caso contrario
	void clear(); 					// Apaga todos os nos da fila , tornando-a vazia
	Object & front() { return *begin( ); }
	const Object & front() const;
	Object & back();
	const Object & back() const;
	void push_front( const Object & x ) { insert( begin( ), x ); }
	void push_back( const Object & x );
	void pop_front();
	void pop_back( );
	iterator insert( iterator itr , const Object & x );
	iterator erase( iterator itr );	// remove no apontado por itr
	iterator erase( iterator start , iterator end );
	const_iterator find( const Object & x ) const;
	iterator find( const Object & x );

private :
	int theSize;
	Node *head;
	Node *tail;

	// Inicializa campos para representar lista vazia
	void init();
}; 	// Classe List

#include "list.inl"
#endif	// LIST_H