#include <iostream>
#include <string.h>

using namespace std;

int main(void) {
    int num;

    cout << "Digite um número inteiro: ";
    cin >> num;
    
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            cout << i << endl;
        }
        
    }
    
    cout << endl;
    return 0; 
}