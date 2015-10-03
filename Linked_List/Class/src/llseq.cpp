#include "llseq.h"

LLSeq<T>::LLSeq( T initVal ) : mData( new T )
{
    *mData = initVal;
    //std::cout << "Entrei no [ MCELL ]!\n";
}

LLSeq<T>::~LLSeq( )
{
	//std::cout << "Entrei no [ ~MCELL ]!\n";
	delete mData;
}