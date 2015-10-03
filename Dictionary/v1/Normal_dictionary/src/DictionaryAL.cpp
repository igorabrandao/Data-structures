/*! \brief DictionaryAL.cpp.
 *
 *  Implements the DictionaryAL functions.
*/
#include "DictionaryAL.h"

/********************************************//**
* constructor
***********************************************/
DictionaryAL::DictionaryAL( int _MaxSz )
: mi_Length( 0 )
, mi_Capacity( _MaxSz )
, mpt_Data( nullptr )
{
    /*! Check negative values */
	if ( _MaxSz < 0 )
		throw std::invalid_argument("[ArrayList()]: The list size is invalid!");
	else
		mpt_Data = new NodeAl[ _MaxSz ]; /*!< Allocate the new node */
}

/********************************************//**
* Search helper method
***********************************************/
int
DictionaryAL::_search( int _x ) const
{
	int i = 0;

	for ( /* Empty */; i < mi_Length; ++i )
	{
		if( mpt_Data[ i ].id == _x )
			return i;
	}

	/*! Return the current lenght list */
	return i;
}

/********************************************//**
* Remove an element of the list
***********************************************/
bool
DictionaryAL::pop( int _x, std::string & _s )
{
	/*! Auxiliary variables */
	bool bResult;

	/*! Performs a search referred to the index */
	int match = _search( _x );

	/*! Check if the match is inside the current lenght list */
	if( match == mi_Length )
		bResult = false;
	else
	{
		if( mpt_Data[ match ].id == _x )
		{
			_s = mpt_Data[ match ].info;

			for( auto i( match ) ; i < mi_Length - 1; ++i )
			{
				mpt_Data[ i ].info = mpt_Data[ i + 1 ].info;
			}

			mi_Length--;
			bResult = true;
		}
		else
			bResult = false;
	}

	return bResult;
}


bool
DictionaryAL::search( int _x, std::string & _s ) const
{
	bool bResult;
	/*! Performs private search searching for the index */
	int match = _search( _x );

	if( match == mi_Length )
		bResult = false;
	else
	{
		if( mpt_Data[ match ].id == _x )
		{
			_s = mpt_Data[ match ].info;
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
DictionaryAL::push( int _newKey, std::string _newInfo )
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
int
DictionaryAL::min() const
{
	/*! If the list is not empty*/
	if ( mi_Length > 0 )
	{
		int minKey = mpt_Data[0].id;				/*!< the atual minor key is the first key */
		int indexKey = 0;							/*!< the atual index is the index of the first element */
		for ( auto i(1) ; i < mi_Length ; ++i )
		{
			if(mpt_Data[i].id < minKey )
			{
				minKey = mpt_Data[i].id;
				indexKey = i;
			}
		}
		return indexKey;
	}
	else
	{
		throw std::length_error("Lista vazia ");
	}
	return -1;
}


int
DictionaryAL::max() const
{
	if ( mi_Length > 0 )
	{
		int maxKey 		= mpt_Data[0].id;
		int indexKey	= 0;

		for ( auto i(1) ; i < mi_Length ; ++i )
		{
			if(mpt_Data[i].id > maxKey )
			{
				maxKey 		= mpt_Data[ i ].id;
				indexKey	= i;
			}
		}
		return indexKey;
	}
	else
	{
		throw std::length_error("Lista vazia ");
	}
	return -1;
}


bool
DictionaryAL::successor( int _x, int & _y ) const
{
	bool bResult;
	int match = _search( _x );

	if( match == mi_Length || match == mi_Length - 1 )
	{
		bResult = false;
		throw std::out_of_range("Numero não possui successor!!!");
	}
	else
	{
		if( mpt_Data[ match ].id == _x )
		{
			_y = mpt_Data[ match + 1 ].id;
		}
		else
			bResult = false;
	}
	return bResult;
}


bool
DictionaryAL::predecessor( int _x, int & _y ) const
{
	bool bResult;

	int match = _search( _x );

	if( match == mi_Length || match == 0 )
	{
		bResult = false;
		throw std::out_of_range("Numero não possui predecessor!!!");
	}
	else
	{
		if( mpt_Data[ match ].id == _x )
		{
			_y = mpt_Data[ match - 1 ].id;
		}
		else
			bResult = false;
	}
	return bResult;
}
