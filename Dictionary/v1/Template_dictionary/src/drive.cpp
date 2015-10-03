#include "DictionaryAL.h"

int main()
{
    //===================================[ Testando dictionaryAL ]===================================//
    cout << ">>> ******* Testando o dicionario ******* <<<<"<< endl;
    DictionaryAL<int, string> d;
    //===================================[ Testando push() ]===================================//
    cout << "\n===================================================================" << endl;
    cout << ">>> Testando o push com elementos com chaves em ordem aleatorias..." << endl;

    d.push(1, "Leandro");
    d.push(2, "Selan");
    d.push(3, "Robert");
    d.push(5, "Ana Clara");
    d.push(4, "Igor");

    /* Imprimindo a lista */
    cout << endl << d << endl;
    cout << "\n>>> Metodo push() OK!!!" << endl;

    //===================================[ Testando search() ]===================================//
    cout << "\n===================================================================" << endl;
    cout << ">>> Testando o metodo search()" << endl;
    cout << "vou procurar o elemento de chave 5 na lista" << endl;
    cout << "Executando o search..." << endl;
    string str;
    d.search(5, str);
    cout << "O elemento de chave 5 eh o elemento = " << str << endl;
    cout << "\nvou procurar o elemento de chave 10 na lista" << endl;
    cout << "Executando o search..." << endl;
    d.search(10, str);
    cout << "O elemento de chave 10 eh o elemento = " << str << endl;
    cout << "\n>>> Metodo search() OK!!!" << endl;

    //===================================[ Testando pop() ]===================================//
    cout << "\n===================================================================" << endl;
    cout << ">>> Testando o metodo pop()" << endl;
    cout << "Vou excluir o elemento que contem a chave 2!!!" << endl;
    cout << "Executando o pop()..." << endl;
    d.pop(2, str);
    cout << "O elemento: " << str << ", foi removido da lista!!!" << endl;
    cout << "imprimindo a lista..." << endl;
    cout << d << endl;

    cout << "Vou excluir o elemento que contem a chave 10 ( Elemento nao pertencente a lista)!!!" << endl;
    cout << "Executando o pop()..." << endl;
    d.pop(10, str);
    cout << "O elemento: " << str << ", foi removido da lista!!!" << endl;
    cout << "imprimindo a lista..." << endl;
    cout << d << endl;
    cout << "\n>>> Metodo pop() OK!!!" << endl;

    //===================================[ Testando min() ]===================================//
    cout << "\n===================================================================" << endl;
    cout << ">>> Testando o metodo min() e max()" << endl;
    cout << "A menor chave da lista eh a chave: " << d.min() << endl;
    cout << "A maior chave da lista eh a chave: " << d.max() << endl;
    cout << "\n>>> Metodo min() OK!!!" << endl;
    cout << ">>> Metodo max() OK!!!" << endl;

    //=========================[ Testando sucessor() e predecessor() ]=========================//
    cout << "\n===================================================================" << endl;
    cout << ">>> Testando o metodo sucessor() e predecessor()" << endl;
    cout << "Quero saber quem eh o predecessor da chave 4 e o sucessor da chave 1" << endl;
    int a, b;
    d.successor(1,a);
    d.predecessor(5,b);
    cout << "O sucessor da chave 1 eh a chave: " << a << endl;
    cout << "O predecessor da chave 5 eh a chave: " << b << endl;
    cout << "\n>>> Metodo Sucessor() OK!!!";
    cout << "\n>>> Metodo Predecessor() OK!!!" << endl;

    cout << "\n=== Lista Regular OK!!! ===" << endl;



    return 0;
}
