#include <iostream>

using namespace std;

void imprimeDecimal(char letra, int repeticoes) {
    for (int i = 0; i < repeticoes; i++)
    {
       cout << letra << " = " << dec << int(letra);
       int(letra++);

       cout << "\t\t" << letra << " = " << dec << int(letra) << endl;
       int(letra++);
    }

    cout << endl;
}

void imprimeHexadecimal(char letra, int repeticoes) {
    for (int i = 0; i < repeticoes; i++)
    {
       cout << letra << " = " << hex << int(letra);
       int(letra++);

       cout << "\t\t" << letra << " = " << hex << int(letra) << endl;
       int(letra++);
    }

    cout << endl;
}

void imprimeOctal(char letra, int repeticoes) {
    for (int i = 0; i < repeticoes; i++)
    {
       cout << letra << " = " << oct << int(letra);
       int(letra++);

       cout << "\t\t" << hex << letra << " = " << oct << int(letra) << endl;
       int(letra++);
    }

    cout << endl;
}

int main(void) {
    cout << "************* Números ************* \n";

    cout << "********* Decimal ********* \n";
    imprimeDecimal('0', 5);

    cout << "********* Hexadecimal ********* \n";
    imprimeHexadecimal('0', 5);

    cout << "********* Octal ********* \n";
    imprimeOctal('0', 5);

    cout << endl;
    cout << "************* Alfabeto Maiúsculo ************* \n";

    cout << "********* Decimal ********* \n";
    imprimeDecimal('A', 13);

    cout << "********* Hexadecimal ********* \n";
    imprimeHexadecimal('A', 13);

    cout << "********* Octal ********* \n";
    imprimeOctal('A', 13);

    cout << endl;
    cout << "************* Alfabeto Minúsculo ************* \n";

    cout << "********* Decimal ********* \n";
    imprimeDecimal('a', 13);

    cout << "********* Hexadecimal ********* \n";
    imprimeHexadecimal('a', 13);

    cout << "********* Octal ********* \n";
    imprimeOctal('a', 13);

    cout << endl;
    return 0; 
}