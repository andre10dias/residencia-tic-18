#include <iostream>

using namespace std;

class calculadoraEstatica
{
    public:
        calculadoraEstatica()
        {
        }

        ~calculadoraEstatica()
        {
        }

        static int soma(int num1, int num2) {
            return num1 + num2;
        }

        static int subtrai(int num1, int num2) {
            return num1 - num2;
        }

        static int multiplica(int num1, int num2) {
            return num1 * num2;
        }

        static int divide(int num1, int num2) {
            return num1 / num2;
        }
};

int main(void) {
    int num1, num2, operacao, resultado;

    cout << "Insira um numero inteiro: ";
    cin >> num1;

    cout << "Insira outro numero inteiro: ";
    cin >> num2;

    cout << endl;

    cout << " [ 1 ] Soma\n [ 2 ] Subtração\n [ 3 ] Multiplicação\n [ 4 ] Divisão\n";

    cout << "\nSelecione a operacao: ";
    cin >> operacao;


    switch (operacao)
    {
        case 1:
            resultado = calculadoraEstatica::soma(num1, num2);
            break;

        case 2:
            resultado = calculadoraEstatica::subtrai(num1, num2);
            break;

        case 3:
            resultado = calculadoraEstatica::multiplica(num1, num2);
            break;

        case 4:
            if (num2 == 0)
            {
                cout << "\nNão é possível realizar divisão por zero.\n";
            }
            else
            {
                resultado = calculadoraEstatica::divide(num1, num2);
            }

            break;
        
        default:
            break;
    }

    if (num2 != 0)
    {
        cout << endl;
        cout << "Resultado da opeação: " << resultado;
    }

    cout << endl;
    return 0;
}
