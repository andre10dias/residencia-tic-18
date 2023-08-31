#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int main(void) {
    float pif = 3.141592653589793238462643383279502884197169;
    double pid = 3.141592653589793238462643383279502884197169;
    long double pil = 3.141592653589793238462643383279502884197169L;
    
    cout << "O menor valor representado pelo tipo float é: " << numeric_limits<float>::min() << endl;
    cout << "O maior valor representado pelo tipo float é: " << numeric_limits<float>::max() << endl;
    
    cout << "\n**************************** FLOAT **************************** \n";
    cout << "Valor de PI com Float: " << pif << endl;

    int casasDecimais = 2;
    for (int i = 0; i < 4; i++)
    {
        cout << fixed << setprecision(casasDecimais);
        cout << "Valor de PI com "<< casasDecimais << " casas decimais: " << pif << endl;

        casasDecimais *= 2;
    }

    cout << "\n**************************** DOUBLE **************************** \n";
    cout << "Valor de PI com Double: " << pid << endl;

    casasDecimais = 2;
    for (int i = 0; i < 4; i++)
    {
        cout << fixed << setprecision(casasDecimais);
        cout << "Valor de PI com "<< casasDecimais << " casas decimais: " << pid << endl;

        casasDecimais *= 2;
    }

    cout << "\n**************************** LONG **************************** \n";
    cout << "Valor de PI com Long: " << pil << endl;

    casasDecimais = 2;
    for (int i = 0; i < 4; i++)
    {
        cout << fixed << setprecision(casasDecimais);
        cout << "Valor de PI com "<< casasDecimais << " casas decimais: " << pil << endl;

        casasDecimais *= 2;
    }


    cout << endl;
    return 0; 
}