#include "DictionarySAL.h"


bool
DictionarySAL::pop( int _x , std::string & _s )
{
	bool bResult;
	/*! Performs private search searching for the index */
	int wanted = _search( _x );
	if( wanted == mi_Length )
		bResult = false;
	else
	{
		if( mpt_Data[ wanted ].id == _x )
		{
			_s = mpt_Data[ wanted ].info;
			for( auto i( wanted ) ; i < mi_Length - 1; ++i )
			{
				mpt_Data[ i ].id 	= mpt_Data[ i + 1 ].id;
				mpt_Data[ i ].info 	= mpt_Data[ i + 1 ].info;
			}
			mi_Length--;
			bResult = true;
		}
		else
			bResult = false;
	}

	return bResult;
}



bool
DictionarySAL::search( int _x, std::string & _s ) const
{
	int left = 0;
	int right = mi_Length - 1;
	int mid;
	while( left <= right )
	{
		mid = (left + right) / 2;
		if( mpt_Data[ mid ].id == _x )
		{
			_s = mpt_Data[ mid ].info;
			return true;
		}

		if( _x > mpt_Data[ mid ].id )
			left = mid + 1;
		else
			right = mid - 1;
	}

	return false;
}

bool
DictionarySAL::push( int _newKey, std::string _newInfo )
{
    int aux = _search( _newKey );

	if( mi_Length != mi_Capacity ) 	// Se a lista ainda nгo esta cheia.
	{
		if( mpt_Data[ aux ].id != _newKey ) 		// Se aux for diferente da novaId
		{
			if( aux != mi_Length )	// Se aux for diferente do tamanho da lista
			{
				for( int i = mi_Length - 1; i >= aux; --i ) 								// percorre toda a lista
					std::swap( mpt_Data[ i ], mpt_Data[ i + 1 ] );	// Faz a troca ultimo elemento com o penultimo depois do penultimo com o ante penultimo e assim consecutivamente.

			}
			mpt_Data[ aux ].id = _newKey; 		// Insere a novaID
			mpt_Data[ aux ].info = _newInfo;	// Insere a nova informaзгo
			mi_Length++; 						// Incrementa o tamanho da lista
			return true;
		}
		else 	// Caso a chave ja exista.
			std::cout << "Operacao nao realizada,chave ja existente" << std::endl;
	}
	else 		// Caso a lista esteja cheia.
		std::cout << "Operacao nao realizada, a lista esta cheia" << std::endl;

	return false;
}


int
DictionarySAL::min() const
{
    if(mi_Length > 0)
    {
        return mpt_Data[0].id;
    }
    else
        std::cout << "lista vazia!!!" << std::endl;

    return -1;
}


int
DictionarySAL::max() const
{
    if(mi_Length > 0)
    {
        return mpt_Data[ mi_Length - 1].id;
    }
    else
        std::cout << "lista vazia!!!" << std::endl;

    return -1;
}



bool
DictionarySAL::successor(int _x, int& _y ) const
{
    bool bResult;
    int aux = _search(_x);
    /* se ele existir na lista e tiver sucessor */
    if( _x == mpt_Data[ aux ].id && aux < mi_Length - 1)
    {
        _y = mpt_Data[ aux + 1 ].id;
        bResult = true;
    }
    else
    {
        std::cout << "Este indice não possui sucessor ou indice não existe!\n";
        _y = -1;
        bResult = false;
    }
    return bResult;
}


bool
DictionarySAL::predecessor(int _x, int& _y) const
{
    bool bResult;
    int aux = _search(_x);
    /* se ele existir na lista e tiver sucessor */
    if( _x == mpt_Data[ aux ].id && aux > 0)
    {
        _y = mpt_Data[ aux - 1 ].id;
        bResult = true;
    }
    else
    {
        std::cout << "Este indice não possui predecessor ou indice não existe!\n";
        _y = -1;
        bResult = false;
    }
    return bResult;
}


int
DictionarySAL::_search(int _x) const
{
    int mid; 							// Variavel usada para definir o meio da lista.
	int left = 0;
	int right = mi_Length - 1; 			// recebe o ultimo elemento da lista.

	while( left <= right ) 				// enquanto a informacao for menor do que o top.
	{
		mid = ( left + right ) / 2;		// Atribui a mid a posicao que eh a metade da lista.
		if(_x == mpt_Data[ mid ].id )   // Se o id foi encontrato na lista.
            return mid;
		if( _x < mpt_Data[ mid ].id ) 	// verifica se a chave eh menor do que o id do mid.
		{
			if( mid == 0 ) 				// se mid for igual a zero entгo ela deve ser retornada.
				return mid;
			else
			{
				/* Verifica se a chave procurada eh maior do que o dado armazenado logo a esquerda na lista, nesse caso a chave eh o proprio mid. */
				if( _x > mpt_Data[mid-1].id )
					return mid;
			}
		}

		if( mpt_Data[mid].id > _x )		// Verifica se a o meio da lista eh maior do que a chave passada por parametro.*/
			right = mid - 1; 				// Caso verdadeiro o top serб o indice mid - 1.
		else
			left = mid + 1; 				// Caso falso a inf serб o mid + 1.
	}

	return mi_Length;					// retorna o tamanho da lista se nгo entrar o while.
}
