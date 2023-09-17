#include <iostream>
#include <list>

using namespace std;

int main(void) {
	list<int> lista;

	list<int>::iterator it;
	for(int i = 0; i < 5; i++){
		lista.push_back(i);
	}

	for(int i = 5; i < 10; i++){
		lista.push_front(i);
	}

    // Conteudo da lista: 9 8 7 6 5 0 1 2 3 4
    cout << "Primeiro elemento da lista: : " << lista.front() << endl;
    //printa 9 na tela
    cout << "Ultimo elemento da lista: " << lista.back() << endl;
    // printa 4 na tela
    cout << "Tamanho da lista: " << lista.size() << endl;
    //printa o tamanho da lista na tela, que é igual a 10

    cout << "Numeros pares na lista: ";
	for(it = lista.begin(); it != lista.end(); it++) {
		//printa os numeros pares começando do inicio da lista
		if(*it % 2 == 0){
			cout << *it << " ";
		}
	}

    cout << endl;

    cout << "Inserindo dois numeros 11 antes do numero 4: ";
    it--;
    // adiciona dois 11 antes do 4 na lista
    lista.insert(it, 2, 11);
	for(it = lista.begin(); it != lista.end(); it++){
		//printa os numeros pares
		cout << *it << " ";
	}

	cout << endl;

    cout << "Removendo o ultimo elemento da lista: \n";
	it--;//retira o 4 da lista
    lista.erase(it);

    cout << "Imprimindo o novo ultimo elemento da lista: ";
    // printa o 3 que agora é o novo ultimo elemento da lista
    cout << lista.back() << endl;

    cout << "Reovendo todos os elementos da lista: \n";
    // limpa a lista inteira
	lista.clear();

    cout << "Imprimindo tamanho da lista: ";
    // printará 0 pois a lista está vazia
	cout << lista.size() << endl;

    return 0;
}