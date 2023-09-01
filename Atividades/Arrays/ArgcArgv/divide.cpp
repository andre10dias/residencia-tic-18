#include <iostream>
#include <string.h>

using namespace std;

/**
 * Comandos:
 * ./[nome do programa]
 * \[tipo de dado int ou double]
*/

int main(int argc, char* argv[]) {
    cout << "Divide: " << endl;

    if (argc > 1 && argc < 4) {
        cout << "Faltam argumentos a serem passados." << endl;
    }
    else {
        if (strcmp(argv[1], "\int") == 0)
        {
            cout << atoi(argv[2]) / atoi(argv[3]);
        }
        else if (strcmp(argv[1], "\double") == 0)
        {
            cout << atof(argv[2]) / atof(argv[3]);
        }
    }
    
    cout << endl;
    return 0; 
}