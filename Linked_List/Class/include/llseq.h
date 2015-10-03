/**
 * Definition of a class that implements a list based on array.
 * This is a template class, where we need to specify the type
 * of key (unique) and the type of information we need to store
 * in the list.
 * 
 * Author: Selan Santos
 * Date: March 25th, 2015
 * */

#ifndef _LLSEQ_H_
#define _LLSEQ_H_

#include <stdexcept>
#include <string>

class LLSeq
{
    typedef Chave int;
    typedef Informacao std::string;
    protected:
        struct NoLLSeq {    // Estrutura do noh de um lista seq.
            Chave id;       // A chave eh um inteiro nesta TAD.
            Informacao info;// A informacao tambem eh inteiro.
        };

        static const int SIZE=50; // Tamanho maximo da lista.
        int mi_Length;            // Comprimento atual da lista.
        int mi_Capacity;          // Capacidade maxima de armazenamento.
        NoLLSeq *mpt_Data;        // Area de armazenamento: vetor estatico.

        int buscaAux( Chave _x ) const; // Metodo de busca.

    public:
        LLSeq ( int _MaxSz = SIZE );
        ~LLSeq ();
        bool busca( Chave _x, Informacao & ) const;             // Busca publica.
        bool remocao( Chave _x, Informacao & );                 // Remove da lista.
        bool insercao( Chave _novaId, Informacao _novaInfo );   // Pure virtual
};

#endif
