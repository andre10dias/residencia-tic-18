#include <iostream>

using namespace std;

void passagemPorValor(int x) {
    x = x * 2; //Modificando valor local do parâmetro
    cout << "Valor dentro da funcao: " << x << endl;
}

void passagemPorReferencia(int &x) {
    x = x * 2; //Modificando valor original através da referência
    cout << "Valor dentro da funcao: " << x << endl;
}

int main(void) {
    int numero = 5;

    cout << "\n########### PASSAGEM POR VALOR ###########\n";
    cout << "Valor antes da funcao: << " << numero << endl;
    passagemPorValor(numero);
    cout << "Valor depois da funcao: << " << numero << endl;

    numero = 5;

    cout << "\n######### PASSAGEM POR REFERENCIA #########\n";
    cout << "Valor antes da funcao: << " << numero << endl;
    passagemPorReferencia(numero);
    cout << "Valor depois da funcao: << " << numero << endl;

    cout << endl;
    return 0;
}