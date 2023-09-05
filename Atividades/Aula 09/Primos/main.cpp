#include <iostream>
#include <string.h>

using namespace std;

#define MAX 100

int main(void) {
    for (int i = 1; i <= MAX; i++)
    {
        int contador = 0;

        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                contador++;
            }
        }

        if (contador == 2)
        {
            cout << i << endl;
        }
        
    }
    
    cout << endl;
    return 0; 
}