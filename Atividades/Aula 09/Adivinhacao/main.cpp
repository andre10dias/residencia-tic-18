#include <iostream>
#include <cstdlib>

using namespace std;

#define MIN 1
#define MAX 100
 
int main(void)
{
    int random, num;

    for (int i = 0; i < 99999; i++)
    {
        srand(random);
        random = rand() % (MAX - MIN + 1) + MIN;
    }

    do {
        cout << "Informe um numero inteiro entre 1 e 100: ";
        cin >> num;

        if (num < MIN || num > MAX) {
            cout << "\nValor fora da faixa.\n";
        }
        else if (num > random) {
            cout << "\nValor alto.\n";
        }
        else if (num < random) {
            cout << "\nValor baixo.\n";
        }
        else {
            cout << "\nValor correto.\n";
        }

        cout << endl;
    } while(num != random);


    return 0;
}