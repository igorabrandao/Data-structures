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
    /* Inicializa n */
    float n = 0; 

    /* Somatorio do produto notável */
    for (int i = 0; i < a.size(); i++) 
        n += (a[i] - b[i])*(a[i] - b[i]);
    
    /* Retorna a raiz de N */ 
    return sqrt(n);
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
    /* Inicializa n */
    float n = 0;
    
    /* somatorio do modulo de pi(a[i]) - qi(b[i]) */
    for (int i = 0; i < a.size(); i++) 
        n += fabs( (a[i] - b[i]) );
    
    return n;
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
    // TODO

    // STUB, o codigo abaixo deve ser substituido pelo codigo apropriado.
    return 0.f;
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


    cout << "\n >>>> Normal existing!\n";

    return 1;
}