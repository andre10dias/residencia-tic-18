#include <iostream>
#include <string.h>

using namespace std;
#define MAX 100

int main(void) {
    for (int i = 1; i <= MAX; i++)
    {
        if (i % 3 == 0 && i % 5 == 0){
            cout << to_string(i) + ": FizzBuzz";
        }
        else if (i % 3 == 0) {
            cout << to_string(i) + ": Fizz";
        }
        else if (i % 5 == 0) {
            cout << to_string(i) + ": Buzz";
        }
        else {
            cout << i;
        }

        cout << endl;
    }
    
    
    cout << endl;
    return 0; 
}