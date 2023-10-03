#include <iostream>
#include <string>

using namespace std;

class validadorSenha
{
    private:
        static bool possuiMaiusculo(string senha) {
            int tam = senha.size();

            for (int i = 0; i < tam; i++)
            {
                if (isupper(senha[i]))
                {
                    return true;
                }
            }

            return false;
        }

        static bool possuiMinusculo(string senha) {
            int tam = senha.size();

            for (int i = 0; i < tam; i++)
            {
                if (islower(senha[i]))
                {
                    return true;
                }
            }

            return false;
        }

        static bool possuiNumero(string senha) {
            int tam = senha.size();

            for (int i = 0; i < tam; i++)
            {
                if (isdigit(senha[i]))
                {
                    return true;
                }
            }

            return false;
        }

        static bool possuiCaracterEspecial(string senha) {
            int tam = senha.size();

            for (int i = 0; i < tam; i++)
            {
                if (int(senha[i]) >= 33 && int(senha[i]) <= 47)
                {
                    return true;
                }
            }

            return false;
        }

    public:
        validadorSenha(/* args */);
        ~validadorSenha();

        static bool ehSenhaValida(string senha) {
            int tam = senha.size();
            bool maiusculo = possuiMaiusculo(senha);
            bool minusculo = possuiMinusculo(senha);
            bool numero = possuiNumero(senha);
            bool caracterEspecial = possuiCaracterEspecial(senha);
            
            if (tam >= 8 && maiusculo && minusculo && numero && caracterEspecial)
            {
                return true;
            }
            
            return false;
        }
};

int main(void) {
    string senha;

    cout << "Digite uma senha: ";
    cin >> senha;

    if (validadorSenha::ehSenhaValida(senha)) 
    {
        cout << "Senha cadastrada com sucesso!";
    }
    else
    {
        cout << "A senha não atende os requisitos mínimos.";
    }

    cout << endl << endl;
    return 0;
}
