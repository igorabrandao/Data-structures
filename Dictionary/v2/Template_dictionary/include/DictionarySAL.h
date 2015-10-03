#ifndef DICTIORARYSAL_H
#define DICTIORARYSAL_H

#include "DictionaryAL.h"

template <typename Key, typename Data, typename KeyComparator>
class DictionarySAL : public DictionaryAL < Key, Data, KeyComparator > // : public DictionaryAl
{
    public:
    	DictionarySAL( int _MaxSz ) : 
    		DictionaryAL< Key, Data, KeyComparator>( _MaxSz ){/* Empty */};
        
        bool pop( Key _x , Data & _s);
        bool search( Key _x, Data & _s ) const;
        bool push( Key _newKey, Data _newInfo );	    /*!< @brief insert an element on the list */
        Key min() const; // Recupera a menor chave do dicionario
        Key max() const; // Recupera a maior chave do dicionario
        // Recupera em _y a chave sucessora a _x , se existir ( true ).
        bool successor( Key _x , Key & _y ) const;
        // Recupera em _y a chave antecessora a _x , se existir ( true ).
        bool predecessor( Key _x , Key & _y ) const;

    private:
        int _search( Key _x ) const; // Metodo de busca auxiliar .
};

#include "DictionarySAL.inl"

#endif // DICTIORARYSAL_H