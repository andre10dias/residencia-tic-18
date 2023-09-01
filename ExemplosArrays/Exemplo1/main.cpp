#include <iostream>

using namespace std;

int main(void) {
    char word[6] = {'H', 'e', 'l', 'o'};
    char name[30];

    cout << "Enter your name: ";
    cin >> name;

    cout << word << ", " << name << endl;

    return 0; 
}