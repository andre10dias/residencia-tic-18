#include <iostream>

using namespace std;

void systemPause() {
    cout << "\nPressione ENTER para continuar...\n";
    cin.sync();
    cin.get();
}

void systemClear() {
    system("echo ''") != 0 ? system("clear") : system("cls");
}

void testaSO() {
    int retorno = system("echo ''"); 
    cout << "Retorno: " << retorno << endl;
}

int main(void) {
    testaSO();
    return 0;
}