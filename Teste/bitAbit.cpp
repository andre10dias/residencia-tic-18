#include <iostream>
#include <string>

using namespace std;

int main(void) {
    unsigned char a, b, c;

    a = 255;
    b = 0;
    
    c = a & b; //AND
    cout << "byteA & byteB = " << int(c) << endl << endl;

    c = a | b; //OR
    cout << "byteA | byteB = " << int(c) << endl << endl;
    
    c = a >> 4; //deslocamento à esquerda
    cout << "byteA >> 4 = " << int(c) << endl << endl;
    
    c = a << 4; //deslocamento à esquerda
    cout << "byteA << 4 = " << int(c) << endl << endl;

    c = ~ a; //complemento de um
    cout << "byteA ~ 4 = " << int(c) << endl << endl;
    
    c = a ^ (a << 4); //OR exclusivo (XOR) + deslocamento
    cout << "byteA ^ (byteA << 4) = " << int(c) << endl << endl;

    return 0;
}