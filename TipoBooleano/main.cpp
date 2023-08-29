#include <iostream>

using namespace std;

int main(void) {
    bool isNumber = true;
    bool isPositive = true, isNegative = false;
    bool condition;
    condition = (isNumber && isPositive);

    bool isEven, isOdd;
    isEven = 4 % 2 == 0;
    isOdd = 4 % 2;
    cout << "isNumber = " << isNumber << endl;
    cout << "isPositive = " << isPositive << endl;
    cout << "isNegative = " << isNegative << endl;

    return 0; 
}