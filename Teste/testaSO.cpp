#include <iostream>

using namespace std;

void systemPause() {
    cout << "\nPressione ENTER para continuar...\n";
    cin.sync();
    cin.get();
}

void systemClear() {
    system("echo ''") != 0 ? system("cls") : system("clear");
}

void testaSO() {
    int retorno = system("echo ''"); 
    cout << "Retorno: " << retorno << endl;
    cout << "Testando pause e limpa tela";
    systemPause();
    systemClear();

    #if __linux__
        std::cout << "Olá, GNU/Linux!" << '\n';
    #elif _WIN32
        #if defined(_WIN64)
            std::cout << "Olá, Windows 64-bit!" << '\n';
        #else
            std::cout << "Olá, Windows!" << '\n';
        #endif
    #else
        std::cout << "Olá, Other!" << '\n';
    #endif
}

int main(void) {
    testaSO();
    return 0;
}