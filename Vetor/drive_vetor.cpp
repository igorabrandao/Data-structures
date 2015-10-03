#include <iostream>
#include <cmath>
#include <limits>
#include <cstring>

#include "vetor.h"

// Descomente os defines abaixo se optar por implementar sobrecarga de operador.
//#define OPERATOR_EQUAL      // sobrecarga operator==(),  a == b
//#define OPERATOR_ASSIGN     // sobrecarga operator=(),   a = b
//#define OPERATOR_ASSIGN_AT  // sobrecarda operator[](),  a[0] = 3

using namespace MeuVetor;

int main()
{
    float fTotalScore = 0.f;
    bool vbSuccess = true;
    cout << "\n>>>>> Iniciando bateria de testes, nota inicial eh: " << fTotalScore << endl << endl;

    // ============================================================================
    // T01: testando segundo construtor que recebe um vetor
    // ------------------------------------------------------------------------
    {
        cout << "=======================================================\n";
        cout << ">>>> [T01] Testando: construtor (sz, v[]) \n";
        int aiDummyArr[] = { 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
        int iDummySz = sizeof( aiDummyArr ) / sizeof( int );
        //%
        Vetor v1( iDummySz, aiDummyArr );
        //%
        //cout << ">> v1: " << v1 << endl;
        // Get object's data and make sure it's the same passed as argument.
        const int *p = v1.data();
        for( int i(0) ; i<v1.size() ; ++i )
        {
            if ( p[i] != aiDummyArr[i] )
            {
                vbSuccess = false;
                break;
            }
        }
        
        fTotalScore +=  ( vbSuccess ) ? 10.f : 0.f;

        if ( vbSuccess )
            cout << ">>>> [T01] status: bem sucedido!\n";
        else
            cout << ">>>> [T01] status: FALHOU!\n";

        cout << ">>>> Nota atual: " << fTotalScore << endl << endl << endl;
        // Prepare for next test.
        vbSuccess = true;
    }

    // ============================================================================
    // T02: testando operator de igualdade, operator==()
    // ------------------------------------------------------------------------
    {
        cout << "=======================================================\n";
        cout << ">>>> [T02] Testando: comparacao operator()== ou equal() \n";
        Vetor v1( 5 , -1 ); // Vetor de 5 elementos, todos com valor -1: vetor original.
        Vetor v2( 5 , -1 ); // Vetor de 5 elementos, todos com valor -1: igual vetor iriginal.
        Vetor v3( 5 , -2 ); // Vetor de 5 elementos, todos com valor -2: mesmo tamanho, elementos diferentes.
        Vetor v4( 10, -1 ); // Vetor de 10 elementos, todos com valor -1: > que vetor original.
        Vetor v5( 4 , -1 ); // Vetor de 4 elementos, todos com valor -1: < que vetor original.
        cout << ">> v1: " << v1 << endl;
        cout << ">> v2: " << v2 << endl;
        cout << ">> v3: " << v3 << endl;
        cout << ">> v4: " << v4 << endl;
        cout << ">> v5: " << v5 << endl;

        //%
#ifdef OPERATOR_EQUAL
        cout << ">> v1 == v2?: ";
        if ( !( v1 == v2 ) )
            vbSuccess = false;
        cout << ( v1 == v2 ) << endl;

        cout << ">> v1 == v3?: ";
        if ( v1 == v3 )
            vbSuccess = false;
        cout << ( v1 == v3 ) << endl;

        cout << ">> v1 == v4?: ";
        if ( v1 == v4 )
            vbSuccess = false;
        cout << ( v1 == v4 ) << endl;

        cout << ">> v1 == v5?: ";
        if ( v1 == v5 )
            vbSuccess = false;
        cout << ( v1 == v5 ) << endl;
#else
        cout << ">> v1 == v2?: ";
        if ( ! v1.isEqual(v2) )
            vbSuccess = false;
        cout << v1.isEqual(v2) << endl;

        cout << ">> v1 == v3?: ";
        if ( v1.isEqual(v3) )
            vbSuccess = false;
        cout << v1.isEqual(v3) << endl;

        cout << ">> v1 == v4?: ";
        if ( v1.isEqual(v4) )
            vbSuccess = false;
        cout << v1.isEqual(v4)  << endl;

        cout << ">> v1 == v5?: ";
        if ( v1.isEqual(v5) )
            vbSuccess = false;
        cout << v1.isEqual(v5)  << endl;
#endif
        //%
        fTotalScore +=  ( vbSuccess ) ? 5.f : 0.f;

        // Report results
        if ( vbSuccess )
            cout << "\n>>>> [T02] status: bem sucedido!\n";
        else
            cout << "\n>>>> [T02] status: FALHOU!\n";

        cout << ">>>> Nota atual: " << fTotalScore << endl << endl << endl;
        // Prepare for next test.
        vbSuccess = true;
    }

    // ============================================================================
    // T03: testando operator de atribuicao, operator=()
    // ------------------------------------------------------------------------
    {
        cout << "=======================================================\n";
        cout << ">>>> [T03] Testando: comparacao operator=() ou assign() \n";
        Vetor v1( 5 , -1 ); // Vetor de 5 elementos, todos com valor -1.
        Vetor v2( 10, -2 ); // Vetor de 10 elementos, todos com valor -2.
        Vetor v3( 4 , -3 ); // Vetor de 4 elementos, todos com valor -3.
        cout << ">> v1: " << v1 << endl;
        cout << ">> v2: " << v2 << endl;
        cout << ">> v3: " << v3 << endl;

        cout << ">> v3 = v1\n";
        cout << ">> v2 = v1\n";
        //%
#ifdef OPERATOR_ASSIGN
        v2 = v1;
        v3 = v1;
#else
        v2.assign( v1 );
        v3.assign( v1 );
#endif
        //%
        cout << ">> v1: " << v1 << endl;
        cout << ">> v2: " << v2 << endl;
        cout << ">> v3: " << v3 << endl;

        const int *p2 = v2.data();
        if ( v1.size() != v2.size() )
            vbSuccess = false;
        for( int i(0) ; i<v2.size() ; ++i )
            if ( p2[i] != -1 )
                vbSuccess = false;

        v3 = v1;
        const int *p3 = v3.data();
        if ( v1.size() != v3.size() )
            vbSuccess = false;
        for( int i(0) ; i<v3.size() ; ++i )
            if ( p3[i] != -1 )
                vbSuccess = false;

        fTotalScore +=  ( vbSuccess ) ? 15.f : 0.f;

        // Report results
        if ( vbSuccess )
            cout << "\n>>>> [T03] status: bem sucedido!\n";
        else
            cout << "\n>>>> [T03] status: FALHOU!\n";

        cout << ">>>> Nota atual: " << fTotalScore << endl << endl << endl;
        // Prepare for next test.
        vbSuccess = true;
    }

    // ============================================================================
    // T04: testando operator de atribuicao, operator[]()/assingAt()/at()
    // ------------------------------------------------------------------------
    {
        cout << "=======================================================\n";
        cout << ">>>> [T04] Testando operator de atribuicao, operator[]()/assingAt()/at() \n";
        Vetor v1( 5, -1 ); // Vetor de 5 elementos, todos com valor -1.
        cout << ">> v1: " << v1 << endl;

        cout << ">> v1[2] = 5\n";
#ifdef OPERATOR_ASSIGN_AT
        v1[2] = 5;
#else
        //v1.assignAt( 2 ) = 5;
        v1.assignAt( 2,5 );
#endif
        const int *p1 = v1.data();
        if ( p1[2] != 5 )
            vbSuccess = false;
        cout << ">> v1: " << v1 << endl;


        cout << "\n>> int x = v1[2];\n";
#ifdef OPERATOR_ASSIGN_AT
        int x = v1[2];
#else
        int x = v1.at( 2 );
#endif
        if ( x != 5 )
            vbSuccess = false;
        cout << ">> x: " << x << endl;

        fTotalScore +=  ( vbSuccess ) ? 5.f : 0.f;

        // Report results
        if ( vbSuccess )
            cout << "\n>>>> [T04] status: bem sucedido!\n";
        else
            cout << "\n>>>> [T04] status: FALHOU!\n";

        cout << ">>>> Nota atual: " << fTotalScore << endl << endl << endl;
        // Prepare for next test.
        vbSuccess = true;
    }



    // ============================================================================
    // T05: testando swap().
    // ------------------------------------------------------------------------
    {
        cout << "=======================================================\n";
        cout << ">>>> [T05] Testando: metodo swap(). \n";
        Vetor v1( 5 , 1 ); // Vetor de 5 elementos, todos com valor 1.
        Vetor v2( 10, 2 ); // Vetor de 10 elementos, todos com valor 2.
        Vetor v3( 10, 3 ); // Vetor de 10 elementos, todos com valor 3.
        Vetor v4( 5 , 4 ); // Vetor de 5 elementos, todos com valor 4.
        
        //%
        cout << ">> v1: " << v1 << endl;
        cout << ">> v2: " << v2 << endl;
        cout << ">> v1.swap(v2) => v1: ";
        v1.swap( v2 ); 
        cout << v1 << endl;
        const int *p1 = v1.data();
        for( int i(0) ; i<v1.size() ; ++i )
        {
            if ( p1[i] != 2 )
            {
                vbSuccess = false;
                break;
            }
        }
        // Reduce score.
        fTotalScore +=  ( vbSuccess ) ? 5.f : 0.f;

        cout << ">> v3: " << v3 << endl;
        cout << ">> v4: " << v4 << endl;
        cout << ">> v3.swap(v4) => v3: ";
        v3.swap( v4 );
        cout << v3 << endl;
        int aiExpectedResult[] = { 4, 4, 4, 4, 4, 3, 3, 3, 3, 3 };
        const int *p3 = v3.data();
        for( int i(0) ; i<v3.size() ; ++i )
        {
            if ( p3[i] != aiExpectedResult[i] )
            {
                vbSuccess = false;
                break;
            }
        }
        // Reduce score.
        fTotalScore +=  ( vbSuccess ) ? 5.f : 0.f;
        //%

        // Report results
        if ( vbSuccess )
            cout << "\n>>>> [T05] status: bem sucedido!\n";
        else
            cout << "\n>>>> [T05] status: FALHOU!\n";

        cout << ">>>> Nota atual: " << fTotalScore << endl << endl << endl;
        // Prepare for next test.
        vbSuccess = true;
    }

    // ============================================================================
    // T06: testando average().
    // ------------------------------------------------------------------------
    {
        cout << "=======================================================\n";
        cout << ">>>> [T06] Testando: metodo average(). \n";
        int n(10);
        Vetor v1( n, 1 ); // Vetor de 10 elementos, todos com valor 1.
        v1.fillN(); // Agora vetor tem 10 elementos, preenchidos de 1 a 10.
        
        //%
        cout << ">> v1: " << v1 << endl;
        cout << ">> media dos elementos de v1, v1.average(): ";
        float fAvg = v1.average( ); 
        cout << fAvg << endl;
        float fExpectedAvg = ( n*(n+1) / 2.f ) / n ;
        cout << ">> media esperada: " << fExpectedAvg << endl;
        if ( fAvg != fExpectedAvg )
            vbSuccess = false;
        //%
        
        // Reduce score.
        fTotalScore +=  ( vbSuccess ) ? 5.f : 0.f;

        // Report results
        if ( vbSuccess )
            cout << "\n>>>> [T06] status: bem sucedido!\n";
        else
            cout << "\n>>>> [T06] status: FALHOU!\n";

        cout << ">>>> Nota atual: " << fTotalScore << endl << endl << endl;
        // Prepare for next test.
        vbSuccess = true;
    }

    // ============================================================================
    // T07: testando reverse().
    // ------------------------------------------------------------------------
    {
        cout << "=======================================================\n";
        cout << ">>>> [T07] Testando: metodo reverse(). \n";
        
        //%
        int n(11);
        Vetor v1( n, 1 ); // Vetor de 10 elementos, todos com valor 1.
        v1.fillN(); // Agora vetor tem 10 elementos, preenchidos de 1 a 10.
        const int *p1 = v1.data(); // Pointer to data inside object.
        // Let us copy the orignal data to a temporary array.
        int a1[ v1.size() ];
        std::memcpy( reinterpret_cast< int * >( a1 ),     // Source
                     reinterpret_cast<const int *>( p1 ), // Destination
                     sizeof(int) * v1.size() );           // number of bytes to copy
        cout << ">> v1: " << v1 << endl;
        v1.reverse();
        cout << ">> v1.reverse(); ";
        cout << ">> New v1: " << v1 << endl;

        for( int i(0) ; i<v1.size() ; ++i )
        {
            if ( a1[i] != p1[v1.size()-i-1] )
            {
                vbSuccess = false;
                break;
            }
        }

        //%
        
        // Reduce score.
        fTotalScore +=  ( vbSuccess ) ? 5.f : 0.f;

        // Report results
        if ( vbSuccess )
            cout << "\n>>>> [T07] status: bem sucedido!\n";
        else
            cout << "\n>>>> [T07] status: FALHOU!\n";

        cout << ">>>> Nota atual: " << fTotalScore << endl << endl << endl;
        // Prepare for next test.
        vbSuccess = true;
    }

    // ============================================================================
    // T08: testando resize().
    // ------------------------------------------------------------------------
    {
        cout << "=======================================================\n";
        cout << ">>>> [T08] Testando: metodo resize(). \n";
        
        //%
        int n(5);
        Vetor v1( n, 1 ); // Vetor de 5 elementos, todos com valor 1.
        v1.fillN(); // Agora vetor tem 5 elementos, preenchidos de 1 a 10.
        cout << ">> v1: " << v1 << endl;
        int n2(8);
        v1.resize(n2);
        cout << ">> v1.resize("<<n2<<");\n";
        cout << ">> v1: " << v1 << endl;
        int aiExpectedResult[] = { 1, 2, 3, 4, 5, 0, 0, 0 };
        const int *p1 = v1.data();
        for( int i(0) ; i<v1.size() ; ++i )
        {
            if ( p1[i] != aiExpectedResult[i] )
            {
                vbSuccess = false;
                break;
            }
        }

        int n3(3);
        v1.resize(n3);
        cout << ">> v1.resize("<<n3<<");\n";
        cout << ">> v1: " << v1 << endl;
        int aiExpectedResult2[] = { 1, 2, 3 };
        const int *p2 = v1.data();
        for( int i(0) ; i<v1.size() ; ++i )
        {
            if ( p2[i] != aiExpectedResult2[i] )
            {
                vbSuccess = false;
                break;
            }
        }
        //%
        
        // Reduce score.
        fTotalScore +=  ( vbSuccess ) ? 15.f : 0.f;

        // Report results
        if ( vbSuccess )
            cout << "\n>>>> [T08] status: bem sucedido!\n";
        else
            cout << "\n>>>> [T08] status: FALHOU!\n";

        cout << ">>>> Nota atual: " << fTotalScore << endl << endl << endl;
        // Prepare for next test.
        vbSuccess = true;
    }

    // ============================================================================
    // T09: testando fill(size, vetor[]).
    // ------------------------------------------------------------------------
    {
        cout << "=======================================================\n";
        cout << ">>>> [T09] Testando: metodo fill( size, vetor[] ). \n";
        
        //%
        int n(5);
        Vetor v1( n, 1 ); // Vetor de 5 elementos, todos com valor 1.
        v1.fillN(); // Agora vetor tem 5 elementos, preenchidos de 1 a 10.
        cout << ">> v1: " << v1 << endl;
        int aiNewVals[] = { 2, 1, 4, 5, 3, 10, 8, 6, 9, 7 };
        cout << ">> v1.fill( 5, V ), onde V = {2, 1, 4, 5, 3, 10, 8, 6, 9, 7}\n";
        v1.fill( 5, aiNewVals );
        cout << ">> New v1: " << v1 << endl;
        const int *p1 = v1.data();
        for( int i(0) ; i<v1.size() ; ++i )
        {
            if ( p1[i] != aiNewVals[i] )
            {
                vbSuccess = false;
                break;
            }
        }

        int n2(10);
        Vetor v2( n2, 1 ); // Vetor de 10 elementos, todos com valor 1.
        v2.fillN(); // Agora vetor tem 10 elementos, preenchidos de 1 a 10.
        cout << "\n>> v2: " << v2 << endl;
        cout << ">> v2.fill( 10, V ), onde V = {2, 1, 4, 5, 3, 10, 8, 6, 9, 7}\n";
        v2.fill( 10, aiNewVals );
        cout << ">> New v2: " << v2 << endl;
        const int *p2 = v2.data();
        for( int i(0) ; i<v2.size() ; ++i )
        {
            if ( p2[i] != aiNewVals[i] )
            {
                vbSuccess = false;
                break;
            }
        }
        //%
        
        // Reduce score.
        fTotalScore +=  ( vbSuccess ) ? 10.f : 0.f;

        // Report results
        if ( vbSuccess )
            cout << "\n>>>> [T09] status: bem sucedido!\n";
        else
            cout << "\n>>>> [T09] status: FALHOU!\n";

        cout << ">>>> Nota atual: " << fTotalScore << endl << endl << endl;
        // Prepare for next test.
        vbSuccess = true;
    }

    // ============================================================================
    // T10: testando unique().
    // ------------------------------------------------------------------------
    {
        cout << "=======================================================\n";
        cout << ">>>> [T10] Testando: metodo unique(). \n";
        
        //%
        int aiDummyArr[] = { 2, 1, 1, 1, 1, 2, 3, 3, 2, 2, 3 };
        int iDummySz = sizeof( aiDummyArr ) / sizeof( int );
        Vetor v1( iDummySz, aiDummyArr );
        cout << ">> v1: " << v1 << endl;
        cout << ">> v1.unique();\n";
        v1.unique();
        cout << ">> New v1: " << v1 << endl;
        const int *p1 = v1.data();
        int aiExpected[] = {2,1,3};
        for( int i(0) ; i<v1.size() ; ++i )
        {
            if ( p1[i] != aiExpected[i] )
            {
                vbSuccess = false;
                break;
            }
        }
        //%
        
        // Reduce score.
        fTotalScore +=  ( vbSuccess ) ? 15.f : 0.f;

        // Report results
        if ( vbSuccess )
            cout << "\n>>>> [T10] status: bem sucedido!\n";
        else
            cout << "\n>>>> [T10] status: FALHOU!\n";

        cout << ">>>> Nota atual: " << fTotalScore << endl << endl << endl;
        // Prepare for next test.
        vbSuccess = true;
    }

    // ============================================================================
    // T11: testando sort().
    // ------------------------------------------------------------------------
    {
        cout << "=======================================================\n";
        cout << ">>>> [T11] Testando: metodo sort(). \n";
        
        //%
        Vetor v1( 20 ); // Vetor de 20 elementos, todos com valor 0.
        v1.fillNShuffle(); // Agora vetor tem 20 elementos, preenchidos de 1 a 20.
        cout << ">> v1: " << v1 << endl;
        cout << ">> v1.sort();\n";
        v1.sort();
        cout << ">> New v1: " << v1 << endl;
        const int *p1 = v1.data();
        for( int i(0) ; i<v1.size() ; ++i )
        {
            if ( p1[i] != i+1 )
            {
                vbSuccess = false;
                break;
            }
        }
        //%
        
        // Reduce score.
        fTotalScore +=  ( vbSuccess ) ? 5.f : 0.f;

        // Report results
        if ( vbSuccess )
            cout << "\n>>>> [T11] status: bem sucedido!\n";
        else
            cout << "\n>>>> [T11] status: FALHOU!\n";

        cout << ">>>> Nota atual: " << fTotalScore << endl << endl << endl;
        // Prepare for next test.
        vbSuccess = true;
    }

    cout << "\n >>>> Normal existing!\n";

    return EXIT_SUCCESS;
}
