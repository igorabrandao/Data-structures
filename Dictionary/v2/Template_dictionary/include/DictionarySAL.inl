#include "DictionarySAL.h"

template <typename Key, typename Data, typename KeyComparator>
int 
DictionarySAL<Key, Data, KeyComparator>::_search( Key _x ) const
{
	int mid; 							// Variavel usada para definir o meio da lista.
	int left = 0;
	int right = this->mi_Length - 1; 			// recebe o ultimo elemento da lista.

	/* Enquanto a esquerda for menor ou igual a direita */
	while( left <= right ) 				
	{
		/* Atualiza o index do meio da lista */
		mid = ( left + right ) / 2;
		/* Testa se a chave esta no meio da lista */		
		if(_x == this->mpt_Data[ mid ].id )   // Se o id foi encontrato na lista.
        {	
        	/* Retorna o index da chave */
        	return mid;
		}

		if( _x < this->mpt_Data[ mid ].id ) 	// verifica se a chave eh menor do que o id do mid.
		{
			if( mid == 0 ) 				// se mid for igual a zero entгo ela deve ser retornada.
				return mid;
			else
			{
				/* Verifica se a chave procurada eh maior do que o dado armazenado logo a esquerda na lista, nesse caso a chave eh o proprio mid. */
				if( _x > this->mpt_Data[mid-1].id )
					return mid;
			}
		}

		if( this->mpt_Data[mid].id > _x )		// Verifica se a o meio da lista eh maior do que a chave passada por parametro.*/
			right = mid - 1; 				// Caso verdadeiro o top serб o indice mid - 1.
		else
			left = mid + 1; 				// Caso falso a inf serб o mid + 1.
	}

	return this->mi_Length;					// retorna o tamanho da lista se nгo entrar o while.
}


template <typename Key, typename Data, typename KeyComparator>
bool 
DictionarySAL<Key, Data, KeyComparator>::pop( Key _x , Data & _s)
{
	bool bResult;
	/*! Performs private search searching for the index */
	int wanted = _search( _x );
	if( wanted == this->mi_Length )
		bResult = false;
	else
	{
		if( this->mpt_Data[ wanted ].id == _x )
		{
			_s = this->mpt_Data[ wanted ].info;
			for( auto i( wanted ) ; i < this->mi_Length - 1; ++i )
			{
				this->mpt_Data[ i ].id 		= this->mpt_Data[ i + 1 ].id;
				this->mpt_Data[ i ].info 	= this->mpt_Data[ i + 1 ].info;
			}
			this->mi_Length--;
			bResult = true;
		}
		else
			bResult = false;
	}
	return bResult;
}


template <typename Key, typename Data, typename KeyComparator>
bool
DictionarySAL<Key, Data, KeyComparator>::search( Key _x, Data & _s ) const
{
	int left = 0;
	int right = this->mi_Length - 1;
	int mid;
	while( left <= right )
	{
		mid = (left + right) / 2;
		if( this->mpt_Data[ mid ].id == _x )
		{
			_s = this->mpt_Data[ mid ].info;
			return true;
		}

		if( _x > this->mpt_Data[ mid ].id )
			left = mid + 1;
		else
			right = mid - 1;
	}

	return false;	
}


template <typename Key, typename Data, typename KeyComparator>
bool 
DictionarySAL<Key, Data, KeyComparator>::push( Key _newKey, Data _newInfo )
{
	int aux = _search( _newKey );

	if( this->mi_Length != this->mi_Capacity ) 	// Se a lista ainda nгo esta cheia.
	{
		if( this->mpt_Data[ aux ].id != _newKey ) 		// Se aux for diferente da novaId
		{
			if( aux != this->mi_Length )	// Se aux for diferente do tamanho da lista
			{
				for( int i = this->mi_Length - 1; i >= aux; --i ) 								// percorre toda a lista
					std::swap( this->mpt_Data[ i ], this->mpt_Data[ i + 1 ] );	// Faz a troca ultimo elemento com o penultimo depois do penultimo com o ante penultimo e assim consecutivamente.

			}
			this->mpt_Data[ aux ].id 	= _newKey; 		// Insere a novaID
			this->mpt_Data[ aux ].info 	= _newInfo;	// Insere a nova informaзгo
			this->mi_Length++; 						// Incrementa o tamanho da lista
			return true;
		}
		else 	// Caso a chave ja exista.
			std::cout << "Operacao nao realizada,chave ja existente" << std::endl;
	}
	else 		// Caso a lista esteja cheia.
		std::cout << "Operacao nao realizada, a lista esta cheia" << std::endl;

	return false;
}


template <typename Key, typename Data, typename KeyComparator>
Key
DictionarySAL<Key, Data, KeyComparator>::min() const 
{
	if ( this->mi_Length > 0 )
    {
        return this->mpt_Data[0].id;
    }
    else
        std::cout << "lista vazia!!!" << std::endl;

    return -1;
}


template <typename Key, typename Data, typename KeyComparator>
Key
DictionarySAL<Key, Data, KeyComparator>::max() const 
{
	if(this->mi_Length > 0)
    {
        return this->mpt_Data[ this->mi_Length - 1].id;
    }
    else
        std::cout << "lista vazia!!!" << std::endl;

    return -1;
}

template <typename Key, typename Data, typename KeyComparator>
bool
DictionarySAL<Key, Data, KeyComparator>::successor( Key _x , Key & _y ) const
{
	bool bResult;
    int aux = _search(_x);

    /* se ele existir na lista e tiver sucessor */
    if( _x == this->mpt_Data[ aux ].id && aux < this->mi_Length - 1)
    {
        _y = this->mpt_Data[ aux + 1 ].id;
        bResult = true;
    }
    else
    {
        std::cout << "Este indice não possui sucessor ou indice não existe!\n";
        _y = -1;
        bResult = false;
    }
    return bResult;
}

template <typename Key, typename Data, typename KeyComparator>
bool
DictionarySAL<Key, Data, KeyComparator>::predecessor( Key _x , Key & _y ) const
{
	bool bResult;
    int aux = _search(_x);
    /* se ele existir na lista e tiver sucessor */
    if( _x == this->mpt_Data[ aux ].id && aux > 0)
    {
        _y = this->mpt_Data[ aux - 1 ].id;
        bResult = true;
    }
    else
    {
        std::cout << "Este indice não possui predecessor ou indice não existe!\n";
        _y = -1;
        bResult = false;
    }
    return bResult;
}