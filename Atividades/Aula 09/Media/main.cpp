#include <iostream>
#include<string.h>

using namespace std;

#define MAX 10
#define MIN 1

int isDigit(char v[MAX]) {
    for (int i = 0; i < MAX; i++) {
        cout << "tete: "<< isdigit(v[i]) << endl;
        if (!isdigit(v[i])) {
            return 0;
        }
    }

    return 1;
}
 
int main(void) {
    char matricula[MAX];
    char opcao;

    do {
        cout << matricula;
        cout << "Informe a matrícula (somente números): ";
        cin >> matricula;

        cout << isDigit(matricula);

        if (isDigit(matricula) == 0) {
            cout << "\nInforme somente números\n\n\n";
        }
        else {
            cout << endl;
            cout << "Deseja informar outra matrícula?\n";
            cout << "(Digite 'S' para sim ou outra para continuar) ";
            cin >> opcao;
            system("clear");
        }


    } while (int(opcao) != 83 && int(opcao) != 115);
}