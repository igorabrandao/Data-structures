#ifndef _VETOR_H_
#define _VETOR_H_

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <random>
#include <algorithm>
#include <iterator>
#include <array>

using namespace std;

namespace MeuVetor {
    template < typename T >
    class Vetor {
        public:
            /* Class constructor
                *@param: _iSz => array length
                *@param: _iFillVal => default value to fill
            */
            explicit Vetor( T _iSz = T(), T _iFillVal = T() );

            /* Class destructor */
            ~Vetor();

            /* Constructor override (copy)
                * Vetor a(b) equal to a.Vetor(b)
            */
            Vetor( const Vetor &_oSrc );

            //! Preenche o vetor com o mesmo valor passado como argumento.
            /*! @param _iVal Valor para preenchimento do vetor.
             */
            void fill( int _iVal );

            //! Preenche o vetor com inteiros de 1 ateh N (numero de elementos do vetor).
            void fillN( void );

            //! Preenche o vetor com inteiros de 1 ateh N (numero de elementos do vetor) e depois faz uma permutacao de seus elementos.
            void fillNShuffle( void );

            //! Retorna o numero de elementos no vetor.
            /*! @return Numero de elementos armazenados no vetor.
             */
            int size( void ) const { return miSize; }

            //! Retorna um ponteiro constante para os dados do Vetor. Usado apenas para depuração.
            /*! @return Ponteiro constante para os dados (mpStorage).
             */
            const int* data() const
            { return mpiData; }

            // FRIEND METHODS
        public:

            //! Sobrecarga do operador <<, que faz com que seja impresso o ret&acirc;ngulo na forma: [ x, y, Width, Height ]
            /*! @param _os Output stream, normalmente o <CODE>cout</code>.
             *  @param _CRec O ret&acirc;ngulo a ser impresso na tela.
             *  @return A pr&oacute;pria <CODE>os</code> recebida como par&acirc;metros (para permitir encadeamento).
             */
            inline friend std::ostream &operator<< (std::ostream& _os, const Vetor& _CVetor)
            {
                _os << "[ ";
                for( int i(0) ; i<_CVetor.miSize ; ++i )
                    _os << _CVetor.mpiData[i] << "  ";
                _os << "]";
                return _os;
            }




        // =========================================================================    
        // METODOS PARA IMPLEMENTAR.
        // TODO

            explicit Vetor( int _iSz, int * _piVals );


            const int operator[]( int _idx ) const;
            // OU
            int at( int _idx ) const;  // int x = a.at( 2 );


            int& operator[]( int _idx );
            // OU
            void assignAt( int _idx, int _iNewVal ); // a.assignAt( 2, 3 );  equiv a[2] = 3;


            const Vetor& operator=( const Vetor& _rhs );
            // OU
            void assign( const Vetor& _rhs ); // a.assign( b );


            bool operator==( const Vetor& _rhs ) const;
            // OU
            bool isEqual( const Vetor& _rhs ) const; // if ( a.equal( b ) )

            int min( void ) const;
            int max( void ) const;
           
            float average( void ) const;

            void reverse( void );

            void resize( int _iNewSz );

            void fill( int size, int newVals[] );

            int unique( void ); // returns new size.

            int compara(int _a, int _b);

            void sort( void );

            void swap( Vetor& _rhs );

        // FIM DA LISTA DE METODOS PARA IMPLEMENTAR.
        // =========================================================================    
        private:
            int miSize;
            int *mpiData;
    };
}
#endif
// ==============================[ Fim vetor.h ]============================== //