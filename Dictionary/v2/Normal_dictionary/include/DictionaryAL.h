#ifndef DICTIONARYAL_H
#define DICTIONARYAL_H

/**********************************************//**
* @brief Dictionary Class
* @author Leandro Antonio Feliciano da Silva
* @Version 1.0
* @date 24 set 2015
**************************************************/

#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

/* Preparando para template*/
typedef int Key;		// Alias para Chave
typedef string Data;	// Alias para o dado

class DictionaryAL
{
protected:
	

	/*! Structure of the node representing the pair: <int, information> */
	struct NodeAl
	{
		int id;				/*!< The int is a simple integer */
		std::string info;	/*!< The information is a string */
	};

	static const int SIZE=50;		/*!< Defaut size of the list 	*/
	int mi_Length;					/*!< Current lenght of the list */
	int mi_Capacity;				/*!< Maximun size of the list 	*/
	NodeAl *mpt_Data;				/*!< Storage Area: Vector dynamically allocated */

	int _search( Key _x ) const;	/*!< Search helper method;		*/

public:
	/*! Constructor */
	DictionaryAL( int _MaxSz = SIZE );
	/*! Virtual Destructor */
	virtual ~DictionaryAL() { delete [] mpt_Data;  };

	bool pop( Key _x, Data & _s ); 			    /*!< @brief Remove an element of the list */
	bool search( Key _x, Data & _s ) const;		/*!< @brief Search for an element of the list */
	bool push( Key _newKey, Data _newInfo );	    /*!< @brief insert an element on the list */
	Key min() const;		/*!< Retrieves the minor keu of the dictionary */
	Key max() const;		/*!< Recovers the biggest Key of the dictionary */
	/*!	Recovers in _y the successor int to _x, if any (true) */
	bool successor( Key _x, Key & _y ) const;
	/*! Recovering in the _x _x int predecessor, if any (true) */
	bool predecessor( Key _x, Key & _y ) const;

	/*! Sends back to the output stream an ascii representation for the list */
	inline friend
	std::ostream & operator<<(std::ostream& _os, const DictionaryAL& _oList )
	{
		_os << " [ ";
		for ( int i(0) ; i < _oList.mi_Length ; ++i )
			_os << "{id: " << _oList.mpt_Data[ i ].id << ", info: " << _oList.mpt_Data[ i ].info << "}  ";

		_os << "]";
		return _os;
	}
};

#endif