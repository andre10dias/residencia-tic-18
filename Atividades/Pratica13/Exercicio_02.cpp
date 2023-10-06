#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Empregado
{
    string nome;
    string sobrenome;
    int anoNascimento;
    string rg;
    int anoAdmissao;
    float salario;
};

void reajusta_dez_porcento(Empregado vetor[], int qtdPosicoes);

int main(void) {
    int qtdPosicoes = 50;
    int count = 1;
    Empregado vetor[qtdPosicoes];

    for (int x = 0; x < count; x++)
    {
        vetor[x].nome = "Carlos";
        vetor[x].sobrenome = "Dias";
        vetor[x].rg = "0496832175";
        vetor[x].anoNascimento = 1982;
        vetor[x].anoAdmissao = 2023;
        vetor[x].salario = 2000;
    }

    cout << "\nSalário antes do reajuste\n" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << "Nome: " << vetor[i].nome << endl;
        cout << "Sobrenome: " << vetor[i].sobrenome << endl;
        cout << "RG: " << vetor[i].rg << endl;
        cout << "Ano nascimento: " << vetor[i].anoNascimento << endl;
        cout << "Ano admissão: " << vetor[i].anoAdmissao << endl;
        cout << "Salário: " << fixed << setprecision(2) << vetor[i].salario << endl;

        cout << endl;
    }
    
    reajusta_dez_porcento(vetor, qtdPosicoes);
    cout << "Salário reajustado\n" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << "Nome: " << vetor[i].nome << endl;
        cout << "Sobrenome: " << vetor[i].sobrenome << endl;
        cout << "RG: " << vetor[i].rg << endl;
        cout << "Ano nascimento: " << vetor[i].anoNascimento << endl;
        cout << "Ano admissão: " << vetor[i].anoAdmissao << endl;
        cout << "Salário: " << fixed << setprecision(2) << vetor[i].salario << endl;

        cout << endl;
    }

    cout << endl;
    return 0;
}

void reajusta_dez_porcento(Empregado vetor[], int qtdPosicoes) {
    for (int i = 0; i < qtdPosicoes; i++)
    {
        vetor[i].salario *= 0.1 + 1;
    }
}