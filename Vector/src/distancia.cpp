#include <iostream>
#include <cmath>
#include <limits>

#include "vetor.h"

#define EPSILON 0.00001

using namespace MeuVetor;

/**
 * Calcula a distância Euclideana entre dois objetos passados como argumento.
 * @param a Primeiro vetor para o cálculo de distância.
 * @param b Segundo vetor para o cálculo de distância.
 * @return A distância Euclideana calculada.
 *
 */
float euclideanDist( const Vetor& a, const Vetor& b )
{
    long lAcum(0l);

    if ( a.size() != b.size() )
        throw std::length_error( "[euclideanDist()] vectors do not match in size." );

    for( int i(0) ; i<a.size() ; ++i )
    {
        lAcum += (b[i]-a[i])*(b[i]-a[i]);
    }

    return sqrt( lAcum );
}

/**
 * Calcula a distância Manhattan entre dois objetos passados como argumento.
 * @param a Primeiro vetor para o cálculo de distância.
 * @param b Segundo vetor para o cálculo de distância.
 * @return A distância Manhattan calculada.
 *
 */
float manhattanDist( const Vetor& a, const Vetor& b )
{
    int iAcum(0);

    if ( a.size() != b.size() )
        throw std::length_error( "[euclideanDist()] vectors do not match in size." );

    for( int i(0) ; i<a.size() ; ++i )
    {
        iAcum += std::abs( a[i] - b[i] );
    }

    return static_cast<float>( iAcum );
}

/**
 * Identifica e retorna o índice do elemento em uma coleção mais "próximo"
 * de um elemento alvo, de acordo com uma dada função de distância.
 * Tanto a coleção (e seu tamanho) quanto o alvo são passados como argumento.
 * Além destas duas informações, a função recebe um ponteiro para uma função
 * que calcula o tipo de disância desejada.
 * @param V Coleção de objetos na forma de um arranjo unidimensional.
 * @param iSz Tamanho da coleçaão de objetos.
 * @param Target Objeto-alvo que desejamos achar a menor distância para algum objeto na coleção.
 * @param distFunc Ponteiro para função que calcula a disância entre dois objetos fornecidos.
 * @return O índe do elemento mais "próximo" (de acordo com a função de distância fornecida) ao alvo dentro da coleção.
 *
 */
// Standard linear search.
template < typename Obj >
int searchSmallestDistance( Obj V[], int iSz, const Obj &Target, float (* distFunc)( const Obj& o1, const Obj& o2 ) )
{
    float fDist = distFunc( V[0], Target ); // Assume first distance found is the (temporary) smallest.
    int iIdxMin(0); // Index of the element with smallest distance to target.

    // Run through the array looking for the element in collection with smallest distance to target.
    for ( int i(1); i < iSz; ++i ) // Start from 2nd.
    { 
        float fTempDist = distFunc( V[ i ], Target );
        if ( fTempDist < fDist  ) // Is this smaller than the minimum found so far?
        {
            iIdxMin = i; // Update index of this object.
            fDist = fTempDist; // Update smallest distance found so far.
        }
    }
    return iIdxMin;
}


int main()
{
    float fTotalScore = 0.f;
    bool vbSuccess = false;

    // ===============================================================================
    // Preparing bag of vetors.
    Vetor aoBag[ ] = { Vetor(5, 2), Vetor(5, 6), Vetor(5, -2), Vetor(5, 12), Vetor(5, 10), Vetor(5, -7), Vetor(5, 0) };
    int iBagSz ( sizeof( aoBag ) / sizeof( Vetor ) );
    cout << ">>>> Bag elements are: \n";
    for( int i(0) ; i<iBagSz ; ++i )
        cout << "Bag[" << i << "]: " << aoBag[i] << endl;
    cout << ">>>> Size of bag is: " << iBagSz << endl << endl;

    // This is our target (try the others).
    //Vetor oTarget( 5, 7 );
    Vetor oTarget( 5, 1 );
    //Vetor oTarget( 5, 100 );
    //Vetor oTarget( 5, -3 );
    cout << ">>>> Target element is: " << oTarget << endl << endl;



    // ===============================================================================
    // Looking for smallest Euclidean distance 
    int iIdxTargetE = searchSmallestDistance( aoBag, iBagSz, oTarget, euclideanDist );

    // Determine Euclidean distance found.
    float fDist = euclideanDist( oTarget, // alvo
                                 aoBag[ iIdxTargetE ] ); // colecao

    cout << ">>>> [Euclidean] Closest element to Target" << oTarget << " is Bag[" << iIdxTargetE << "]: " << aoBag[ iIdxTargetE ] << endl;
    cout << ">>>> The distance is " << fDist << endl << endl;

    // Reduce score.
    const float fExpectedDistE = 2.23607f; // Distancia correta. 
    vbSuccess = ( std::fabs( fDist - fExpectedDistE ) < EPSILON );
    fTotalScore +=  ( vbSuccess ) ? 10.f : 0.f;

    // Report results
    if ( vbSuccess )
        cout << "\n>>>> [D01] status: bem sucedido!\n";
    else
        cout << "\n>>>> [D01] status: FALHOU!\n";

    cout << ">>>> Nota atual: " << fTotalScore << endl << endl << endl;



    // ===============================================================================
    // Looking for smallest Manhattan distance 
    int iIdxTargetM = searchSmallestDistance( aoBag, iBagSz, oTarget, manhattanDist );

    // Calcular distancia
    fDist = manhattanDist( oTarget, //alvo
                           aoBag[ iIdxTargetE ] ); // colecao

    cout << ">>>> [Manhattan] Closest element to Target" << oTarget << " is Bag[" << iIdxTargetM << "]: " << aoBag[ iIdxTargetM ] << endl;
    cout << ">>>> The distance is " << fDist << endl << endl;

    // Adjust score.
    const float fExpectedDistM = 5.f; // Distancia correta. 
    vbSuccess = ( std::fabs( fDist - fExpectedDistM ) < EPSILON );
    fTotalScore +=  ( vbSuccess ) ? 10.f : 0.f;

    // Report results
    if ( vbSuccess )
        cout << "\n>>>> [D02] status: bem sucedido!\n";
    else
        cout << "\n>>>> [D02] status: FALHOU!\n";

    cout << ">>>> Nota atual: " << fTotalScore << endl << endl << endl;



    // ===============================================================================

    cout << "\n >>>> Normal existing!\n";

    return 1;
}
