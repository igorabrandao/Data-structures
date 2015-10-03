/*!
	<PRE>
	SOURCE FILE : DictionaryAL.h
	DESCRIPTION.: Simple Dictionary with Array List class - with implementation.
	AUTHOR......: Selan R. dos Santos
	CONTRIBUTOR.: Igor A. Brandão
	LOCATION....: IMD/UFRN.
	SATARTED ON.: 
	CHANGES.....: Functions implemented.

	TO COMPILE..: Use makefile.
	OBS.........: Part of the LP1 Project.

	LAST UPDATE.: September 28th, 2015.
	</pre>
*/

#ifndef DICTIONARYAL_H
#define DICTIONARYAL_H

#include <stdexcept>
#include <string>
#include <iostream>

/*! LifeScreen template class */
class DictionaryAL
{
	/*!
     * Protected section
    */
	protected:

		/*! Alias to key and data type */
		typedef int Key;
		typedef std::string Data;

		/*! Struct that represents the information pair: <int, information> */
		struct NodeAl
		{
			Key id;		/*!< The key is a simple integer */
			Data info;	/*!< The information is a string */
		};

		static const int SIZE=50;		/*!< Defaut size list */
		int mi_Length;					/*!< Current lenght list */
		int mi_Capacity;				/*!< Maximun size list 	*/
		NodeAl *mpt_Data;				/*!< Storage area: Vector dynamically allocated */

		int _search( Key _x ) const;	/*!< Search helper method; */

	/*!
     * Public section
    */
	public:

		DictionaryAL( int _MaxSz = SIZE );					/*!< Constructor */
		virtual ~DictionaryAL() { delete [] mpt_Data;  };	/*!< Virtual Destructor */

		/*!	Functions */
		bool pop( Key _x, Data & _s ); 			    		/*!< @brief Remove an element of the list */
		bool search( Key _x, Data & _s ) const;				/*!< @brief Search for an element of the list */
		bool push( Key _newKey, Data _newInfo );	    	/*!< @brief insert an element on the list */

		Key min() const;									/*!< Retrieves the minor int of the dictionary */
		Key max() const;									/*!< Recovers the biggest int of the dictionary */

		bool successor( Key _x, Key & _y ) const;			/*!< Recovers in _y the successor int to _x, if any (true) */
		bool predecessor( Key _x, Key & _y ) const;			/*!< Recovering in the _x _x int predecessor, if any (true) */

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