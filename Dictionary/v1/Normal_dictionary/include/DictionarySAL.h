#ifndef DICTIONARYSAL_H
#define DICTIONARYSAL_H

#include "DictionaryAL.h"

class DictionarySAL : public DictionaryAL // : public DictionaryAl
{
    public:
        bool pop( int _x , std::string & );
        bool search( int _x, std::string & _s ) const;
        bool push( int _newKey, std::string _newInfo );	    /*!< @brief insert an element on the list */
        int min() const; // Recupera a menor chave do dicionario
        int max() const; // Recupera a maior chave do dicionario
        // Recupera em _y a chave sucessora a _x , se existir ( true ).
        bool successor( int _x , int & _y ) const;
        // Recupera em _y a chave antecessora a _x , se existir ( true ).
        bool predecessor( int _x , int & _y ) const;

    private:
        int _search( int _x ) const; // Metodo de busca auxiliar .
};

#endif // DICTIONARYSAL_H