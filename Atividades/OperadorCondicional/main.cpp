#include <iostream>
#include <string>

using namespace std;

int main(void) {
    char ch1, ch2, ch3;

    cout << "Digite um caractere: ";
    cin >> ch1;
   
    string resp = int(ch1) >= 65 && int(ch1) <= 90 ? "Letra maiúscula" : int(ch1) >= 97 && int(ch1) <= 122 ? "Letra minúscula" : int(ch1) >= 48 && int(ch1) <= 57 ? "Dígito" : "Outro caractere";

    cout << "O caractere informado é: " << resp << endl;

    cout << "***************************************** \n";
    ch2 = 'Q';
    cout << "Caractere: " << ch2 << endl;
    cout << "Decimal: " << dec << int(ch2) << endl;
    cout << "Octal: " << oct << int(ch2) << endl;
    cout << "Hexadecimal: " << hex << int(ch2) << endl;

    cout << "***************************************** \n";
    ch3 = int(ch2) + 32;
    cout << "Caractere: " << ch3 << endl;
    cout << "Decimal: " << dec << int(ch3) << endl;
    cout << "Octal: " << oct << int(ch3) << endl;
    cout << "Hexadecimal: " << hex << int(ch3) << endl;

    return 0; 
}