#include <iostream>

using namespace std;

// atoi() - converte string para inteiro

int main(int argc, char* argv[]) {

    /**
     * argc - Retorna a quantidade de argumentos passados em argv. Sendo que retorno igual a 1 
     * significa que nenhum argumento foi passado.
     * 
     * argv - Array de argumentos. Sendo que a promeira posição argv[0] é sempre o nome do programa 
     * e as demais posições são os argimentos informados no console pelo usuário.
     * Ex: Digite no console: ./main (nome do programa) carlos 1982
     * O programa irá imprimir no console: Olá Carlos você possui 41 anos.
    */

    cout << "Olá " << argv[1] << " você possui " << 2023 - atoi(argv[2]) << " anos." << endl;

    if (argc == 1) {
        cout << "Nenhum argumento passado." << endl;
    }
    else {
        cout << "Os parâmetros passados são: " << endl;
        for (int i = 0; i < argc; i++)
        {
            cout << "argv[" << i << "]: " << argv[i] << endl;
        }
    }
    
    cout << endl;
    return 0; 
}