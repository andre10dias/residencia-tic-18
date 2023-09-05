#include <iostream>
#include <string.h>

using namespace std;

int contaDigitos(int num) {
    return to_string(num).size();
}

int inverteDigitos(int num) {
    int invertido = 0;

    while (num > 0) {
        invertido = invertido * 10 + num % 10;
        num = num / 10;
    }

    return invertido;
}

int main(void) {
    int num, numInvertido;
    cout << "************************* PALÍNDROMO *************************\n";

    cout << "Digite um número inteiro: ";
    cin >> num;

    if (contaDigitos(num) > 9) {
        cout << "\nO número deve ter no máximo 9 dígitos \n";
    }
    else if (num != 0) {
        numInvertido = inverteDigitos(num);
        
        if (numInvertido == num) {
            cout << "\nÉ Palindromo! \n";
        }
        else {
            cout << "\nNão é Palindromo! \n";
        }
    }
    
    cout << endl;
    return 0; 
}