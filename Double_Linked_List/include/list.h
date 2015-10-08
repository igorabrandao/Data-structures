#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

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
		const_iterator() : current( nullptr ) { /* Empty */ };
		
		// Retorna objeto armazenado na posicao atual .
		// Para const_iterator , este metodo eh um accessor que retorna
		// uma referencia constante . Logo este operador so pode
		// aparecer do lado direito de uma atribuicao ou em comparacoes.
		const Object & operator*() const
		{
			/* Returns the data of the node */
			return ( current->data );
		}

		// Pre-incremento : ++it
		const_iterator & operator++()
		{
			current = current->next; 	/*!< This node receives the next node */
			return (*this);				/*!< Return the next node */
		}

		// Pos-incremento : it++
		const_iterator operator++( int )
		{
			const_iterator old = *this;	/*!< This node receiver the next node */
			++( *this ); 				/*!< Updates the next node */
			return old;					/*!< Return this node */
		}
		
		// Pre-decremento : --it
		const_iterator & operator--()
		{
			current = current->mp_Prev;	/*!< This node receives the previus node */
			return ( *this ); 			/*!< Return this node */
		}

		// Pos-decremento : it--
		const_iterator operator--( int )
		{
			const_iterator old = *this;	/*!< This node receives the previus node */
			--( *this ); 				/*!< Updates the previus node */
			return old; 				/*!< Return this node */
		}

		/*! @return true if the atual node is equal to right hand side node */
		bool operator==( const const_iterator & rhs ) const
		{
			return current == rhs.current;
		}

		/*! @return true if the atual node is diferent to right hand side node */
		bool operator!=( const const_iterator & rhs ) const
		{
			return !( *this == rhs );
		}

	/*!
	 *	Protect section
	 */	
	protected :
		/*! Declarado como protected para ser acessivel pela classe 'iterator' */
		Node *current;
		// Construtor protegido que recebe um noh para ser apontado
		// Utilizado dentro da classe ‘List ’ apenas e nao pelo codigo cliente .
		const_iterator( Node* p )
		{
			/* Assings the current node. */
			current = p;
		};

		// Necessario p/ permitir acesso de 'List' aos campos desta classe.
		friend class List<Object>;
	};

	// inheritance : IS-A relation
	class iterator : public const_iterator 
	{ 	
	public :
		// Construtor p´ublico do iterator que invoca construtor da classe base .
		iterator( ) : const_iterator::current( nullptr ) { /* Empty */ }
		
		/*!
		 *	Retorna objeto armazenado na posicao apontada por ‘current’.
		 * 	For iterator , tem duas versoes , uma accessor que permite sua
		 * 	utilizacao do apenas do lado direito de uma atribuicao ou em
		 * 	comparacoes.
		 */
		const Object & operator*() const
		{
			/*! Retorna os dados do noh */
			return ( *this );
		}

		// Esta versao mutator eh usada do lado esquerdo de atribuicoes.
		Object & operator*()
		{
			/*! Retorna os dados do noh */
			return ( *this );
		}
		
		// prefixo
		iterator & operator++()
		{
			this->current = this->current->next;
			return ( *this );
		}

		// posfix
		iterator operator++( int )
		{
			iterator old = *this;	// este noh recebe o proximo noh
			++( *this ); 			// Atualiza o proximo noh (next node)
			return old; 			// retorna this noh
		}
		
		// prefixo
		iterator & operator--()
		{
			this->current = this->current->prev;	/*!< This node receive the previus node */
			return ( *this );			/*!< Return the previus nodde */
		}

		// posfix
		iterator operator--( int )
		{
			iterator old = *this;
			--( *this );
			return old;
		}

	protected :
		
		/*!
		 *	Construtor protegido que espera uma posi¸c~ao para apontar .
		 *	E invocado principalmente dentro da classe ‘List ’, mas
		 * 	nao pelo cliente ( que nao tem acesso a este metodo ).
		*/
		iterator( Node *p )
		{
			this->current = p; /*! Atribui o noh atual */
		}

		// Necessario p/ permitir acesso de ‘List’ aos campos desta classe.
		friend class List<Object>;
	};

	// Metodos basico que todas as classes deveriam oferecer
	
	/*! Constructor */
	List()
	{
		cout << "estou dentro do constructor da lista" << endl;
		init(); /*! Initialize the list */
	}

	/*! Desconstructor*/
	~List()
	{
		clear();	/*! Clean all itens of the list */
		delete head;	/*! Desalocates the head pointer */
		delete tail; 	/*! Desalocates the tail pointer */
	}

	/*! Copy constructor */
	List( const List & rhs )
	{
		iterator itr = begin(); /*!< Iterador auxiliar para percorrer a lista */
		while( itr != end() )	/*!< Percorre a lista */ 
		{
			insert( itr.current->data );
			++( itr );
		}
	}

	/**
	 *	Clona a lista. 
	 * 	@param rhs A lista que sera atribuido o clone
	 */
	const List & operator=( const List & rhs )
	{
		clear(); 			/*!< Desaloca todos os itens da lista */
		new List( rhs ); 	/*!< Clona a lista */
	}

	/*!
	 *	Metodos especificos da classe!!!
	 */

	/*! @return the first node (with stored value) of the list */
	iterator begin()	// Versao mutator
	{ 
		return iterator( head->next ); 
	}

	/*! @return the first node (with stored value) of the list */
	const_iterator begin() const // Versao accessor
	{ 
		return iterator( head->next ); 
	}

	/*! @return the last node of the list */
	iterator end() 	/*!< Versao mutator */
	{ 
		return iterator( tail ); 
	}

	/*! @return the last node of the list */
	const_iterator end() const /*!< Versao accessor */
	{ 
		return iterator( tail ); 
	}
	

	/*! Return number of elements currently in the list */
	int size() const 
	{	
		return theSize; 
	}

	/*! @return true if the list is empty */
	bool empty() const 
	{ 
		return ( size() == 0 ); 
	}

	void print()
	{
		iterator itr = begin();
		cout << "Lista = [ ";
		while( itr != end() )
		{
			cout << itr.current->data << " ";
			itr++;
		}
		cout << "]" << endl;
	} 		
	
	// Apaga todos os nos da fila , tornando-a vazia
	void clear()
	{
		erase( begin(), end() );
	}					

	Object & front()	/*!< Versao mutator */
	{ 
		return *begin(); 
	}

	/*! @return the value of the first node of the list */
	const Object & front() const /*!< Versao accessor */
	{ 
		return *begin(); 
	}
	
	/*! @return the value of the last node of the list */
	Object & back() /*!< Versao mutator */
	{
		return ( *( --end() ) );
	}

	/*! @return the value of the last node of the list */
	const Object & back() const /*!< Versao accessor */
	{
		return ( *( --end() ) );
	}

	/*! Adiciona um novo noh no começo da fila */
	void push_front( const Object & obj )
	{
		insert( begin(), obj );
	}

	/*! Adiciona um novo noh no final da fila */
	void push_back( const Object & obj )
	{
		insert( end(), obj );
	}

	/*! Remove o primeiro noh da lista */
	void pop_front()
	{
		erase( begin() );
	}

	void pop_back()
	{
		erase( --end() );
	}
	
	/*!
	 *	Insere um novo noh na lista.
	 *	@param itr um noh da lista
	 * 	@param obj Valor no novo noh
	 * 	@return O novo noh
	 */
	iterator insert( iterator itr , const Object & obj )
	{
		Node *newNode = new Node( obj, itr.current->prev, itr.current );
		itr.current->prev->next = newNode;
		itr.current->prev = newNode;
		theSize++;
		
		return newNode;
	}

	/**
	 * 	Remove  o noh itr da lista
	 * 	@param itr Um noh da lista
	 * 	@return O noh removido.
	 */
	iterator erase( iterator itr )	
	{
		Node* pAuxNode = itr.current->next;	// Aloca um noh auxiliar
		itr.current->prev->next = itr.current->next;	// Atribui o proximo noh para o proximo noh do noh anterior.
		itr.current->next->prev = itr.current->prev; 	// Atribui o noh anterior ao noh anterior do proximo noh.
		delete itr.current;	// Desaloca o noh
		--theSize; 			// Decrementa o tamanho da lista.
		return pAuxNode; 	// Retorna o noh removido
	}


	/**
	 * Remove os nohs entre o range passado como parametro
	 * @param start O primeiro noh a ser removido
	 * @param end O último noh a ser removido
	 * @return O proximo noh do ultimo noh removido
	 */
	iterator erase( iterator start , iterator end )
	{
		iterator itr = start; 	/*!< Iterador auxiliar para percorrer o range da lista */
		while ( itr != end ) 	/*!< Percorre o range da lista */
		{
			itr = erase( itr );	/*!< Atribui o proximo noh retornado da funcao e remove o noh */
		}
		return itr; 			/*!< Retorna o proximo noh do ultimo noh removido */
	}

	/*!
	 *	Retorna o noh encontrado na lista
	 * 	@param obj O valor do noh a ser procurado
	 * 	@return O noh encontrado.
	 */
	const_iterator find( const Object & obj ) const
	{
		const_iterator citr = find(obj);
		return citr;
	}

	/*!
	 *	Retorna o noh encontrado na lista
	 * 	@param obj O valor do noh a ser procurado
	 * 	@return O noh encontrado.
	 */
	iterator find( const Object & obj )
	{
		iterator itr = begin(); // atribui o noh inicial da lista ao iterador auxiliar
		while ( itr != end() ) // Percorre o intervalo da lista
		{
			if ( *( itr ) == obj )  // Se o valor no noh eh igual ao objeto obj.
				break; // Finaliza a busca
		
			++( itr ); // Atribui o noh next ao iterador auxiliar
		}
		return itr; // Retorna o noh encontrado na lista
	}

private :
	int theSize;	/*!< The size of the list */
	Node *head;		/*!< pointer for the head node (first node of the list) */
	Node *tail;		/*!< pointer for the tail node (last node of the list) */

	/*! Inicializa campos para representar lista vazia */
	void init()
	{
		theSize = 0;		/*! Atribui o tamanho como sendo 0 */
		head = new Node();	/*! Aloca o noh head */
		tail = new Node(); 	/*! Aloca o noh cauda */
		head->next = tail; 	/*! Liga o no head ao noh tail */
		tail->prev = head;	/*! Liga o no tail ao noh head */
	};
}; 	// Classe List

//#include "list.inl"
#endif	// LIST_H