#include <iostream>
#include <string>
#include "DictionaryAL.h"
#include "DictionarySAL.h"

using namespace std;

int main()
{
	DictionaryAL dicionario;
	//=============================[ Testando a inserção ]=============================//
	cout << ">>> Testando Insercao...\n";
	dicionario.push(1,"Leandro");
	dicionario.push(2,"Josy");
	dicionario.push(3, "Davi");
	dicionario.push(4, "Dandara");
	dicionario.push(5, "Silva");

	std::cout << dicionario << endl;
	std::cout << ">>> Insercao ok!!!\n";

	//=============================[ Testando a busca ]=============================//
	std::string str;
	dicionario.search(4, str);
	cout << "\n\n>>> Testando o search...\n";
	cout << "O resultado da busca foi " << str << std::endl;
	cout << ">>> search ok!!!\n";

	//=============================[ Testando a min e max ]=============================//
	std::cout << "\n\n>>> Testando Min() e Max()\n";
	std::cout << "Max key = [ " << dicionario.max() << " ], Min key = [ " << dicionario.min() << " ]." << std::endl;
	std::cout << ">>> Min() e Max() ok!!!\n";
	//=============================[ Testando a remove ]=============================//

	std::cout << "\n\n>>> Testando remove()...\n";
	std::cout << ">>> Removendo davi da lista...\n";
	dicionario.pop(3, str);
	std::cout << str << " removido com sucesso...\n";
	std::cout << dicionario << endl;

	//=============================[ Testando a sucessor ]=============================//
	int index;
	std::cout << "\n\n>>> Testando sucessor e antecesssor...\n";
	dicionario.successor( 2, index);
	std::cout << "O indice sucessor de Josy eh " << index << "!\n";
	dicionario.predecessor( 4, index);
	std::cout << "O indice do predecessor de Dandara eh " << index << "!\n";

	//************************************************************************************************************//
	//************************************************************************************************************//
	//=========================================[ Testando DictionarySAL ]=========================================//
    DictionarySAL dicionarioS;
    dicionarioS.push(1, "Eu mesmo");
    dicionarioS.push(2, "Eu mesmo1");
    dicionarioS.push(3, "Eu mesmo2");
    dicionarioS.push(4, "Eu mesmo3");
    dicionarioS.push(6, "Eu mesmo6");
    dicionarioS.push(5, "Eu mesmo5");
    dicionarioS.push(7, "Eu mesmo5");
    dicionarioS.push(1, "eu mesmo tentando entrar de novo na lista");

    cout << dicionarioS << endl;
    int y;
    dicionarioS.successor(7, y);
    cout << "O sucessor de 7 eh: " << y << endl;

    dicionarioS.predecessor(1,y);
    cout << "O predecessor de 1 eh: " << y << endl;
    dicionarioS.predecessor(2,y);
    cout << "O predecessor de 2 eh: " << y << endl;
    dicionarioS.predecessor(7,y);
    cout << "O predecessor de 7 eh: " << y << endl;

    cout << dicionarioS << endl;

    cout << "Apagando o indice 5... e imprimindo a lista!" << endl;
    dicionarioS.pop(5, str);
	cout << dicionarioS << endl;    
	cout << "O elemento: " << str << ", foi apagado..." << endl;
	
	return EXIT_SUCCESS;
}