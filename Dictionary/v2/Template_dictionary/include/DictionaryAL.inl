#include "DictionaryAL.h"

template < typename Key, typename Data, typename KeyComparator>
DictionaryAL< Key, Data, KeyComparator >::DictionaryAL( int _MaxSz )
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



template < typename Key, typename Data, typename KeyComparator>
int
DictionaryAL< Key, Data, KeyComparator >::_search( Key _x ) const
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


template < typename Key, typename Data, typename KeyComparator>
bool
DictionaryAL< Key, Data, KeyComparator >::pop( Key _x, Data & _s )
{
	bool bResult;
	/*! Performs private search searching for the index */
	int wanted = _search( _x );
	/*! Caso o elemento não esteja na lista */
	if( wanted == mi_Length )
	{
        _s = "Elemento nao encontrado";
		bResult = false;
	}
	else
	{
		/*! Se a chave _x for igual a chave do index wanted */
		if( mpt_Data[ wanted ].id == _x )
		{
			/* _s recebe o conteudo do info do index wanted */
			_s = mpt_Data[ wanted ].info;
			/* Faz o shift dos elementos a partir do index wanted da direita para a esquerda */
			for( auto i( wanted ) ; i < mi_Length - 1; ++i )
			{
				mpt_Data[ i ].info = mpt_Data[ i + 1 ].info;
			}
			/* Decrementa o tamanho logico da lista */
			mi_Length--;
			bResult = true;
		}
		else
		{
            _s = "Elemento nao encontrado";
			bResult = false;
        }
	}

	return bResult;
}



template < typename Key, typename Data, typename KeyComparator>
bool
DictionaryAL< Key, Data, KeyComparator >::search( Key _x, Data & _s ) const
{
	bool bResult;
	/*! Performs private search searching for the index */
	int wanted = _search( _x );

	/* Caso o elemento nao esteja na lista */
	if( wanted == mi_Length )
    {
        _s = "Elemento não encontrado";
		bResult = false;
	}
	else
	{
		if( mpt_Data[ wanted ].id == _x )
		{
			/* _s recebe o dado armazenado no index wanted */
			_s = mpt_Data[ wanted ].info;
			bResult = true;
		}
		else
		{
            _s = "Elemento não encontrado";
			bResult = false;
        }
	}

	return bResult;
}


/*! @brief insert an element on the list
 *  @param _newint a integer thats represents the new int to be inserted
 * 	@paran _newInfo a parameter thars represents the new info to be inserted in the node*/
template < typename Key, typename Data, typename KeyComparator>
bool
DictionaryAL< Key, Data, KeyComparator >::push( Key _newKey, Data _newInfo )
{
	if( mi_Length < mi_Capacity )
	{
		if( _search( _newKey ) == mi_Length )
		{
			mpt_Data[ mi_Length ].id 	= _newKey;
			mpt_Data[ mi_Length ].info 	= _newInfo;
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
template < typename Key, typename Data, typename KeyComparator >
Key
DictionaryAL< Key, Data, KeyComparator >::min( KeyComparator _keyComparator ) const
{
    Key minKey = mpt_Data[0].id;				/*!< the atual minor key is the first key */
	/*! If the list is not empty*/
	if ( mi_Length > 0 )
	{
        for ( auto i(1) ; i < mi_Length ; ++i )
		{
			if( _keyComparator( mpt_Data[ i ].id, minKey ) )
			{
				/* Atualiza a menor chave */
				minKey = mpt_Data[i].id;
			}
		}
	}
	else
	{
		throw std::length_error("Lista vazia ");
	}
	return minKey;
}


template < typename Key, typename Data, typename KeyComparator>
Key
DictionaryAL< Key, Data, KeyComparator >::max( KeyComparator _keyComparator ) const
{
    Key maxKey = mpt_Data[0].id;

	if ( mi_Length > 0 )
	{
        for ( auto i(1) ; i < mi_Length ; ++i )
		{
			if( !_keyComparator( mpt_Data[i].id, maxKey ) )
			{
				/* Atualiza a maior chave */
                maxKey 	= mpt_Data[ i ].id;
			}
		}
	}
	else
	{
		throw std::length_error("Lista vazia ");
	}
	return maxKey;
}


template < typename Key, typename Data, typename KeyComparator>
bool
DictionaryAL< Key, Data, KeyComparator >::successor( Key _x, Key & _y ) const
{
	bool bResult;
	int wanted = _search( _x );

	if( wanted == mi_Length || wanted == mi_Length - 1 )
	{
		bResult = false;
		throw std::out_of_range("Numero não possui successor!!!");
	}
	else
	{
		if( mpt_Data[ wanted ].id == _x )
		{
			_y = mpt_Data[ wanted + 1 ].id;
		}
		else
			bResult = false;
	}
	return bResult;
}



template < typename Key, typename Data, typename KeyComparator>
bool
DictionaryAL< Key, Data, KeyComparator >::predecessor( Key _x, Key & _y ) const
{
	bool bResult;

	int wanted = _search( _x );

	if( wanted == mi_Length || wanted == 0 )
	{
		bResult = false;
		throw std::out_of_range("Numero não possui predecessor!!!");
	}
	else
	{
		if( mpt_Data[ wanted ].id == _x )
		{
			_y = mpt_Data[ wanted - 1 ].id;
		}
		else
			bResult = false;
	}
	return bResult;
}
