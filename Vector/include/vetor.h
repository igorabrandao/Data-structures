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

    const int DEFAULT_SIZE = 10;
    const int DEFAULT_FILL_VAL = 0;


    class Vetor {

        // methods
        public:
            explicit Vetor( int _iSz = DEFAULT_SIZE, int _iFillVal = DEFAULT_FILL_VAL );     // Default size = 100, filling value = 0.

            ~Vetor( );                  // Destructor.

            Vetor( const Vetor &src );  // Copy constructor.

            void fill( int val );

            void fillN();

            void fillNShuffle();

            int size( void ) const { return miSize; }

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

            explicit Vetor( int _iSz, int * _piVals );     // Default size = 100, filling value = 0.

            int& operator[]( int _idx );
            const int operator[]( int _idx ) const;
            const Vetor& operator=( const Vetor& _rhs );
            bool operator==( const Vetor& _rhs ) const;
            bool operator!=( const Vetor& _rhs ) const;

            int at( int _idx ) const;  // int x = a.at( 2 ); // out_of_bounds
            int& assignAt( int _idx ); // a.assignAt( 2 ) = 3;  equi a[2] = 3
            void assignAt( int _idx, int _iNewVal ); // a.assignAt( 2, 3 );  equiv a[2] = 3;

            void assign( const Vetor& _rhs ); // a.assign( b );

            bool isEqual( const Vetor& _rhs ) const; // if ( a.equal( b ) )


            int front( void ) const;
            int back( void ) const;
            int min( void ) const;
            int max( void ) const;
            
            float average( void ) const;
            void reverse( void );

            void resize( int );

            void fill( int size, int newVals[] );

            int unique( void ); // returns new size.

            void sort( void );

            // Binary methods

            void swap( Vetor& _rhs );

            // Members
        private:
            int miSize;
            int *mpiData;
    };
}
#endif
