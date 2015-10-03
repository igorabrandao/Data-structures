#include "DictionaryAL.h"

typedef int Key;

DictionaryAL::DictionaryAL( int _MaxSz )
: mi_Length( 0 )
, mi_Capacity( _MaxSz )
, mpt_Data( nullptr )
{
    /* We not accept negatives values */
	if( _MaxSz < 0 )
	{
		throw std::invalid_argument("[ArrayList()]: Tamanho de lista invalido!");
	}
	else
	{
		mpt_Data = new NodeAl[ _MaxSz ];
	}
}

int
DictionaryAL::_search( Key _x ) const
{
	int i = 0;

	for ( /* Empty */ ; i < mi_Length ; ++i )
	{
		if( mpt_Data[ i ].id == _x )
			return i;
	}
	/** Return the mi_length */
	return i;
}


bool
DictionaryAL::pop( Key _x, Data & _s )
{
	bool bResult;
	/*! Performs private search searching for the index */
	int wanted = _search( _x );
	/* Se o elemento não for encontrado returna falso*/
	if( wanted == mi_Length )
		bResult = false;
	else
	{
		/* Se a chave do indice for igual a chave passada por parametro */
		if( mpt_Data[ wanted ].id == _x )
		{
			/* S recebe o conteudo do indice informado*/
			_s = mpt_Data[ wanted ].info;
			/* 
			 * Faz o shift dos elementos da direita para a esquerda 
			 * começando do indice do elemento removido 
			 */
			for( auto i( wanted ) ; i < mi_Length - 1; ++i )
			{
				mpt_Data[ i ].info = mpt_Data[ i + 1 ].info;
			}
			/* Decrementa o tamanho lógico do dicionario */
			mi_Length--;
			/* Retorna verdadeiro */
			bResult = true;
		}
		else
			bResult = false;
	}
	return bResult;
}


bool
DictionaryAL::search( Key _x, Data & _s ) const
{
	bool bResult;
	/*! Performs private search searching for the index */
	int wanted = _search( _x );

	/* Se o elemento nao for encontrado retorna falso */
	if( wanted == mi_Length )
		bResult = false;
	else
	{
		/* Se a chave do indice encontrado for igual a chave passada por parametro */
		if( mpt_Data[ wanted ].id == _x )
		{
			/* _s recebe o conteudo do indice encontrado */
			_s = mpt_Data[ wanted ].info;
			/* Retorna verdadeiro*/
			bResult = true;
		}
		else
			bResult = false;
	}
	return bResult;
}


/*! @brief insert an element on the list
 *  @param _newint a integer thats represents the new int to be inserted
 * 	@paran _newInfo a parameter thars represents the new info to be inserted in the node*/
bool
DictionaryAL::push( Key _newKey, Data _newInfo )
{
	/* Se ainda existe vaga no dicionario*/
	if( mi_Length < mi_Capacity )
	{
		/* 
		 * Se a chave ainda nao existe no dicionario
		 * ( Nao pode haver chaves repetidas )
		 */
		if( _search( _newKey ) == mi_Length )
		{
			/* Insere a chave e o conteudo no fim do dicionario */
			mpt_Data[ mi_Length ].id 	= _newKey;
			mpt_Data[ mi_Length ].info 	= _newInfo;
			/* Incrementa o tamanho logico do dicionario*/
			mi_Length++;
			return true;
		}
		else
		{
			std::invalid_argument("[DictionaryAL::insert] key allready exists!!!");
		}
	}
	else
	{
		throw std::overflow_error("Memory List if Full!!!");
	}
	return false;
}


/*!
 *	@brief recovery the index of the minor key of the list.
 * 	@return the index of the minor key.
 */
Key
DictionaryAL::min() const
{
	Key minKey = mpt_Data[0].id;				/*!< the atual minor key is the first key */
	/*! If the list is not empty*/
	if ( mi_Length > 0 )
	{
		
		for ( auto i(1) ; i < mi_Length ; ++i )
		{
			if(mpt_Data[i].id < minKey )
			{
				minKey = mpt_Data[i].id;
			}
		}
	}
	else
	{
		throw std::length_error("Lista vazia ");
	}
	/* Retorna a menor chave */
	return minKey;
}



Key
DictionaryAL::max() const
{
	/* A primeira chave fica sendo a maior chave temporariamente */
	Key maxKey 	= mpt_Data[0].id;
	/*! If the list is not empty*/
	if ( mi_Length > 0 )
	{
		/* Percorre a partir da segunda chave */
		for ( auto i(1) ; i < mi_Length ; ++i )
		{
			/* Testa se a chave eh maior */
			if(mpt_Data[i].id > maxKey )
			{
				/* Atualiza o maxKey */
				maxKey 	= mpt_Data[ i ].id;
			}
		}
	}
	else
	{
		throw std::length_error("Lista vazia ");
	}
	/* Retorna a maior chave */
	return maxKey;
}



bool
DictionaryAL::successor( Key _x, Key & _y ) const
{
	bool bResult;
	/* Recebe o index de _x e mi_Length _x não esteja na lista */
	int wanted = _search( _x );

	/* caso a lista seja vazia ou chave não tem sucessora */
	if( wanted == mi_Length || wanted == mi_Length - 1 )
	{
		bResult = false;
		throw std::out_of_range("Numero não possui successor!!!");
	}
	else
	{
		if( mpt_Data[ wanted ].id == _x )
		{
			/* _y recebe a chave sucessora */
			_y = mpt_Data[ wanted + 1 ].id;
			bResult = true;
		}
		else
			bResult = false;
	}
	return bResult;
}


bool
DictionaryAL::predecessor( Key _x, Key & _y ) const
{
	bool bResult;
	/* Recebe o index de _x e mi_Length _x não esteja na lista */
	int wanted = _search( _x );

	/* Se a chave não esta na lista ou eh a primeira */
	if( wanted == mi_Length || wanted == 0 )
	{
		bResult = false;
		throw std::out_of_range("Numero não possui predecessor!!!");
	}
	else
	{
		if( mpt_Data[ wanted ].id == _x )
		{
			/* _y recebe a chave predecessora */
			_y = mpt_Data[ wanted - 1 ].id;
			bResult = true;
		}
		else
			bResult = false;
	}
	return bResult;
}
