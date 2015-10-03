#ifndef DICTIONARYSAL_H
#define DICTIONARYSAL_H

#include "DictionaryAL.h"

class DictionarySAL : public DictionaryAL // : public DictionaryAl
{
    public:
        bool pop( Key _x , Data & );
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

#endif // DICTIONARYSAL_H