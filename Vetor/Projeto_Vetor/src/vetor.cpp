#include "vetor.h"

using namespace std;

namespace MeuVetor {

    Vetor::Vetor( int _iSz, int _iFillVal ) : 
        miSize( _iSz ),
        mpiData( new int[ miSize ] )
    {
        if ( _iSz <= 0 )
            throw std::invalid_argument( "[Vetor::Vetor(int,int)]: Size of Vetor is invalid!" );

        // Initialize with filling value provided.
        for ( int i(0) ; i<miSize ; i++ )
            mpiData[ i ] = _iFillVal; // 
    }

    Vetor::~Vetor()
    {
        delete [ ] mpiData;
    }

    // Copy constructor
    Vetor::Vetor( const Vetor &rhs ) :
        miSize( rhs.miSize ), 
        mpiData( new int[ rhs.miSize ] )
    {
        // copiar elementos da fonte original
        for ( int i(0) ; i<miSize ; ++i )
            this->mpiData[ i ] = rhs.mpiData[ i ];
    }

    void
    Vetor::fill( int val )
    {
        for( int i(0); i<miSize; ++i  )
            mpiData[ i ] = val;
    }

    void
    Vetor::fillN( void )
    {
        for( int i(0); i<miSize; ++i  )
            mpiData[ i ] = i+1;
    }

    void
    Vetor::fillNShuffle( void )
    {
        // Fill Vetor with { 1, 2, 3... N }.
        fillN();

        // Shuffle data
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(mpiData, mpiData + miSize, g);
    }


    // ================================================================================
    //TODO Começa aqui. Implemente os métodos da classe abaixo.

    //! Segundo construtor que recebe um arranjo para inicializar o objeto.
    /*! Cria um Vetor com o tamanho especificado e o preenche com os valores fornecidos
     *  por meio de um arranjo passado como argumento.
     *  Lembre-se que no construtor precisamos alocar nova memória para armazenar os
     *  elementos fornecidos.
     *  Se o tamanho do arranjo for negativo, proceda como no construtor principal
     *  e lançe uma exceção 'invalid_argument()'.
     *  @param _iSz Tamanho do arranjo passado como argumento.
     *  @param _piVals Ponteiro para um arranjo com os dados para preencher o objeto Vetor.
     *  
     *  Exemplo:
     *  int vet[] = { 5, 4, 3, 2, 1 };
     *  Vetor a( 5, vet )
     *  'a' será criado com 5 posições, sendo a:[ mpiData = { 5, 4, 3, 2, 1 }, miSize = 5 ].
     */
    Vetor::Vetor( int _iSz, int * _piVals ) : 
        miSize( _iSz ),
        mpiData( new int[ miSize ] )
    {
        if ( _iSz <= 0 )
            throw std::invalid_argument( "[Vetor::Vetor(int,int)]: Size of Vetor is invalid!" );

        // Initialize with filling value provided.
        for ( int i(0) ; i < miSize ; i++ )
            mpiData[i] = _piVals[i]; // 
    }

    //! Modifica o conteudo do vetor em uma posicao especificada.
    /*! Modifica o conteudo do vetor em uma posicao especificada.
     *  Você deve ter o cuidado de garantir que o indice eh válido, ou seja, corresponde
     *  a uma posicao válida dentro do objeto Vetor.
     *
     *  Se o índice for inválido você pode lançar uma exeção assim:
     *  throw std::out_of_range( "Index provided out of valid range!" );
     *
     *  @param _idx Localização do elemento requisitado.
     *  @param _iNewVal Novo valor a ser atribuido na posicao solicitada.
     *  
     *
     *  A forma de uso eh do tipo:
     *  a.assignAt( 0, 3 ); // Atribui o valor 3 na posição zero do Vetor 'a'.
     *  a[0] = 3; 
     */
    void 
    Vetor::assignAt( int _idx, int _iNewVal )
    {
        if ( _idx < 0 ||  _idx > miSize )
            throw std::out_of_range( "Index provided out of valid range!" );

        mpiData[_idx] = _iNewVal;
    }
    // Alternativamente, implemente o metodo abaixo no lugar do de cima.
    int&
    Vetor::operator[]( int _idx )
    {
        if ( _idx < 0 ||  _idx > miSize )
            throw std::out_of_range( "Index provided out of valid range!" );

        return mpiData[_idx];
    }

    //! Retorna o conteudo do vetor em uma posicao especificada.
    /*! Recupera o conteudo do vetor em uma posicao especificada.
     *  Você deve ter o cuidado de garantir que o indice eh válido, ou seja, corresponde
     *  a uma posicao válida dentro do objeto Vetor.
     *
     *  Se o índice for inválido você pode lançar uma exeção assim:
     *  throw std::out_of_range( "Index provided out of valid range!" );
     *
     *  @param _idx Localização do elemento requisitado
     *  @return Retorna o valor do vetor na posição requisitada.
     *
     *  A forma de uso eh do tipo:
     *  int x = a.at( 0 ); // recupera o valor na posição zero do Vetor 'a'.
     *  ou
     *  int x = a[0];
     */
    int
    Vetor::at( int _idx ) const
    {
        if ( _idx < 0 ||  _idx > miSize )
            throw std::out_of_range( "Index provided out of valid range!" );

        return mpiData[_idx];
    }
    // Alternativamente, implemente o metodo abaixo no lugar do de cima.
    const int
    Vetor::operator[]( int _idx ) const
    {
        if ( _idx < 0 ||  _idx > miSize )
            throw std::out_of_range( "Index provided out of valid range!" );

        return mpiData[_idx];
    }

    //! Verifica se um vetor eh idêntico a outro.
    /*! Verifica se o vetor do lado esquerdo da comparação é igual ao vetor do lado direito da comparação.
     *  Se forem iguais, retorna verdadeiro, caso contrário retorna falso.
     *  @param _rhs Objeto Vetor do lado direito da comparação.
     *  @return true se os vetores forem iguais ou false, caso contrário.
     *
     *  Para um vetor ser considero idêntico ele deve possuir o mesmo tamanho e os mesmos elementos.
     *
     *  A forma de uso eh do tipo:
     *  if ( a.isEqual( b ) )  // Verifica se Vetor 'a' é igual ao Vetor 'b'.
     *  OU
     *  if ( a == b ) 
     */
    bool Vetor::isEqual( const Vetor& _rhs ) const
    {
        // Verifica se os vetores possuem o mesmo tamanho
        if ( this->miSize != _rhs.miSize )
            return false;
        else
        {
            // Verificação elemento a elemento
            for ( int i(0) ; i < this->miSize ; i++ )
                if ( this->mpiData[i] != _rhs.mpiData[i] ) return false;       
        }

        return true;
    }
    // Alternativamente, implemente o metodo abaixo no lugar do de cima.
    bool
    Vetor::operator==( const Vetor& _rhs ) const
    {
        // Verifica se os vetores possuem o mesmo tamanho
        if ( this->miSize != _rhs.miSize )
            return false;
        else
        {
            // Verificação elemento a elemento
            for ( int i(0) ; i < this->miSize ; i++ )
                if ( this->mpiData[i] != _rhs.mpiData[i] ) return false;       
        }

        return true;
    }

    //! Atribui um vetor a outro.
    /*! Atribui um vetor a outro, alterando seu tamanho se necessário.
     *  Um cuidado especial deve ser tomado para evitar vazamento de memória.
     *  Se o vetor do lado direito da atribuição possuir o mesmo tamanho do vetor que recebe (lado esquerdo),
     *  não é necessário desalocar/alocar nova memória.
     *  Caso contrário, você deve modificar o tamanho da área de armazenamento do vetor adequadamente.
     *  
     *  @param _rhs Objeto Vetor do lado direito da atribuição.
     *  @return Retorna o próprio objeto modificado ou *this. // só para sobrecarga.
     *
     *  A forma de uso eh do tipo:
     *  a.assign( b ); // Atribui o conteúdo de 'b' para 'a', modificando o tamanho de 'a' se necessário.
     *  OU
     *  a = b;
     */
    void
    Vetor::assign( const Vetor& _rhs ) // a.assign( b );
    {
        // Teste para evitar auto-atribuição, como a = a.
        if ( this != &_rhs )
        {
            // Verifica se os vetores possuem o mesmo tamanho
            if ( this->miSize != _rhs.miSize )
            {
                // Realoca o vetor de acordo com _rhs
                this->miSize = _rhs.miSize;
                this->mpiData = new int[ _rhs.miSize ];
            }

            // Atribui os valores para mpiData
            for ( int i(0) ; i < this->miSize ; i++ )
                this->mpiData[i] = _rhs.mpiData[i];
        }
    }
    // Alternativamente, implemente o metodo abaixo no lugar do de cima.
    const Vetor&
    Vetor::operator=( const Vetor& _rhs )
    {
        // Teste para evitar auto-atribuição, como a = a.
        if ( this != &_rhs )
        {
            // Verifica se os vetores possuem o mesmo tamanho
            if ( this->miSize != _rhs.miSize )
            {
                // Realoca o vetor de acordo com _rhs
                this->miSize = _rhs.miSize;
                this->mpiData = new int[ _rhs.miSize ];
            }

            // Atribui os valores para mpiData
            for ( int i(0) ; i < this->miSize ; i++ )
                this->mpiData[i] = _rhs.mpiData[i];
        }

        return *this;
    }

    //! Retorna o menor elemento de um vetor.
    /*! Retorna o menor elemento armazenado no vetor.
     *  @return O valor do menor elemento encontrado.
     */
    int
    Vetor::min( void ) const
    {
        // TODO

        // STUB, o codigo abaixo deve ser substituido pelo codigo apropriado.
        return 0;
    }

    //! Retorna o maior elemento de um vetor.
    /*! Retorna o maior elemento armazenado no vetor.
     *  @return O valor do maior elemento encontrado.
     */
    int
    Vetor::max( void ) const
    {
        // TODO

        // STUB, o codigo abaixo deve ser substituido pelo codigo apropriado.
        return 0;
    }

    //! Troca os elementos de dois vetores.
    /*! O método troca os elementos de dois vetores envolvidos na operação.
     *  Se os vetores forem de tamanhos diferentes, a troca deve ser realizada até o
     *  tamanho do menor vetor.
     *
     *  @param _rhs Objeto Vetor que será alvo da troca.
     *
     *  Exemplo:
     *  a = { 4, 5, 6, 7, 1, 2, 8 }, b = { 10, 20, 30 };
     *  Após a.swap( b ), fica
     *  a = { 10, 20, 30, 7, 1, 2, 8 }, b = { 4, 5, 6 };
     */
    void
    Vetor::swap( Vetor & _rhs )
    {
        int length = 0;

        // Verifica se os vetores possuem o mesmo tamanho
        if ( this->miSize > _rhs.miSize )
            length = _rhs.miSize;
        else
            length = this->miSize;

        // Swap the elements
        for ( int i(0) ; i < length; i++ )
            std::swap(this->mpiData[i], _rhs.mpiData[i]);
    }

    //! Retorna a média dos elementos presentes no vetor.
    /*! Retorna a média aritmética simples dos elementos presentes no vetor.
     *  @return A média dos elementos armazenados no vetor.
     *
     *  Exemplo de uso:
     *  cout << "A media eh: " << a.average() << endl;
     */
    float
    Vetor::average( void ) const
    {
        float avg = 0.f;

        // Sum the elements
        for ( int i(0) ; i < this->miSize; i++ )
            avg += this->mpiData[i];

        return (avg/this->miSize);
    }

    //! Reverte a ordem dos elementos em um vetor.
    /*! Retorna a ordem interna dos elementos armazenados no vetor.
     *  
     *  Exemplo:
     *  Se a = { 5, 4, 3, 2, 1 }
     *  a.reverse() implica em a = { 1, 2, 3, 4, 5 }.
     */
    void
    Vetor::reverse( void )
    {
        int idx_last = (this->miSize - 1);

        // Reverse the vector
        for ( int i(0) ; i < (this->miSize)/2; i++ )
        {
            std::swap(this->mpiData[i], this->mpiData[idx_last]);
            idx_last--;
        }
    }

    //! Altera o tamanho do vetor, mantendo os elementos originais até o novo tamanho.
    /*! Modifica o tamanho original do vetor para o novo tamanho informado.
     *  Se o novo tamanho for MENOR do que o anterior, o método mantém apenas
     *  os elementos que cabem no novo tamanho.
     *  Se o novo tamanho for MAIOR do que o anterior, o método preserva todos
     *  os elementos originais e preencher o restante com zeros.
     *
     *  @param _iNewSz O novo tamanho do vetor.
     *
     *  Cuidado especial deve ser tomado para evitar vazamento de memória.
     *  Você também deve ve/rificar que o tamanho informado é válido, ou seja, maior do que zero.
     *
     *  Se o tamanho for inválido você pode lançar a seguinte exceção assim:
     *  throw std::invalid_argument( "Novo tamanho de vetor invalido!" );
     *  
     *
     *  Exemplo:
     *  Suponha a = [ mpiData = { 1, 2, 3, 4, 5 }, miSize = 5 ]
     *  a.resize( 8 );
     *  O vetor ficaria a = [ mpiData = { 1, 2, 3, 4, 5, 0, 0, 0 }, miSize = 8 ]
     *
     *  E se fizermos a.resize( 3 );
     *  O vetor ficaria a = [ mpiData = { 1, 2, 3 }, miSize = 3 ]
     */
    void
    Vetor::resize( int _iNewSz )
    {
        // Verifica se o novo tamnho do vetor é válido
        if ( _iNewSz <= 0 )
            throw std::invalid_argument( "Novo tamanho de vetor invalido!" );

        // Instância um ponteiro com o novo valor
        int * ptrAux = new int[ _iNewSz ];

        // Preenche com 0's
        for ( auto i(0); i < _iNewSz ; ++i )
            ptrAux[ i ] = 0;

        // Preenche o ponteiro com as infos
        for ( auto j(0); j < this->miSize && j < _iNewSz; ++j )
            ptrAux[ j ] = mpiData[ j ];

        // Desacolca a memória
        delete [] mpiData;
        mpiData = ptrAux;
        miSize = _iNewSz;
    }

    //! Preencher o Vetor com os elementos fornecidos via arranjo.
    /*! Modifica o Vetor original alterando seu tamanho (se necessário)
     *  de maneira que seus novos elementos sejam os fornecidos via arranjo.
     *  Cuidado especial deve ser tomado para evitar vazamento de memória
     *  se for necessário fazer ajuste da área de armazenamento.
     *
     *  Você também deve varificar que o tamanho informado é válido, ou seja, maior do que zero.
     *  Se o tamanho for inválido você pode lançar uma exeção assim:
     *  throw std::invalid_argument( "Novo tamanho de vetor invalido!" );
     *
     *  @param _Sz O tamanho do arranjo e o novo tamanho do Vetor.
     *  @param _aiNewVals Arranjo contendo os novos valores para o Vetor.
     *
     *  Exemplo:
     *  Vetor a ( 10 ); // Cria um vetor com 10 zeros. a = [ mpiData = {0,0,0,0,0,0,0,0,0,0}, miSize = 10 ]
     *  int arr[] = { 5, 6, 4, 0, 2 };
     *  a.fill ( 5, arr ) faria
     *  a = [ mpiData = { 5, 6, 4, 0, 2 }, miSize = 5 ]
     */
    void
    Vetor::fill( int _iSz, int _aiNewVals[] )
    {
         // Verifica se o novo tamnho do vetor é válido
        if ( _iSz <= 0 )
            throw std::invalid_argument( "Novo tamanho de vetor invalido!" );

        // Realoca o vetor de acordo com _iSz
        this->miSize = _iSz;
        this->mpiData = new int[ _iSz ];

        // Atribui os valores para mpiData
        for ( int i(0); i < this->miSize; i++ )
            this->mpiData[i] = _aiNewVals[i];
    }

    //! Elimina elementos repetidos no vetor.
    /*! O método procura eliminar todas as ocorrências de elementos repetidos no Vetor.
     *  @return O número de elementos que restaram no vetor.
     *
     *  Exemplo: a = [ mpiData = { 1, 2, 2, 3, 2, 2, 1 }, miSize = 7 ]
     *  após unique(a) fica, a = [ mpiData = {1, 2, 3 }, miSize = 3 ].
     *
     *  O método também deve ter o cuidado de modificar o tamanho do vetor original,
     *  de maneira que ele tenha o tamanho reduzido se necessário.
     *  O método retorna o número de elementos que restaram no vetor.
     */
    int
    Vetor::unique( void )
    {
        // Variáveis auxiliares
        int idxSlow(0);
        int idxFast(1);
        bool checked = true;

        // Percorre o vetor
        while ( idxFast < miSize )
        {
            for ( auto i(idxSlow); i >= 0 && checked; --i )
            {
                if ( mpiData[ i ] == mpiData[ idxFast ] )
                    checked = false;
            }

            if ( checked )
                std::swap( mpiData[ ++idxSlow ] , mpiData[ idxFast ] );

            idxFast++;
        }

        this->resize( idxSlow + 1 );
        return miSize;
    }

    //! Ordena os elementos no Vetor.
    /*! O método ordena os elementos do Vetor.
     *
     *  Exemplo: a = { 4, 5, 2, 3, 1, 2, 8 },
     *  após a.sort() fica, a = { 1, 2, 2, 3, 4, 5, 8 }.
     */
    void
    Vetor::sort( void )
    {
        // Chama o método de ordenação
        //this->quickSort(mpiData, 0, (miSize - 1));

        int key, holePos;
        /* ordenação InsertionSort */
        for (int i = 1; i < miSize; i++)
        {
            key = mpiData[ i ];
            holePos = i - 1;

            while( holePos >= 0 && compara(key,mpiData[holePos]) == -1)
            {
                mpiData[ holePos + 1 ] = mpiData[ holePos ];
                holePos = holePos - 1; 
            }
            mpiData[holePos + 1] = key;
        }
    }

    /**
     * Quicksort.
     * @param _rhs - The array to be sorted.
     * @param first - The start of the sequence to be sorted.
     * @param last - The end of the sequence to be sorted.
    */
    void
    Vetor::quickSort( Vetor& _rhs, int first, int last ) 
    {
        int pivotElement;

        if( first < last )
        {
            pivotElement = this->pivot(_rhs, first, last);
            this->quickSort(_rhs, first, pivotElement-1);
            this->quickSort(_rhs, pivotElement+1, last);
        }
    }

    //! Compara dois valores.
    /*! O método compara dois valores e retorna -1 caso o 1º seja menor que o 2º
     *  e retorna 1 caso contrario.
     *  @param _a O primeiro valor.
     *  @param _b O segundo valor.
     *  @return -1 se (_a < _b) e 1 caso contrario
     */ 
    int Vetor::compara(int _a, int _b)
    {
        if(_a < _b)
            return -1;
        return 1;   
    }

    /**
     * Find and return the index of pivot element.
     * @param _rhs - The array.
     * @param first - The start of the sequence.
     * @param last - The end of the sequence.
     * @return - the pivot element
    */
    int
    Vetor::pivot( Vetor& _rhs, int first, int last ) 
    {
        int  p = first;
        int pivotElement = _rhs[first];
     
        for(int i = first+1 ; i <= last ; i++)
        {
            /* If you want to sort the list in the other order, change "<=" to ">" */
            if(_rhs[i] <= pivotElement)
            {
                p++;
                std::swap(_rhs[i], _rhs[p]);
            }
        }
     
        std::swap(_rhs[p], _rhs[first]);
     
        return p;
    }

}

// ==============================[ Fim vetor.cpp ]============================== //
