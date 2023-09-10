#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

#define MAX_DIGITOS 10
#define MAX_ALUNOS 10
#define MAX_NOTAS 3

int isDigit(char v[MAX_ALUNOS]) {
    int i = 0;

    while (v[i] != '\0') {
        if (!isdigit(v[i])) {
            return 0;
        }

        i++;
    }

    return 1;
}

float calculaMedia(float v[MAX_NOTAS]) {
    float soma = 0;
    float media = 0;

    for (int i = 0; i < MAX_NOTAS; i++)
    {
        soma += v[i];
    }
    
    media = soma / MAX_NOTAS;

    return media;
}
 
int main(void) {
    int colunas = MAX_NOTAS + 1;
    float alunos[MAX_ALUNOS][colunas];
    char matriculaTemp[MAX_DIGITOS];
    string matricula[MAX_DIGITOS];
    float notas[MAX_NOTAS];
    char opcao = 83;
    int qtdAlunos = 0;
    int qtdDigitos = 0;

    do {
        system("clear");
        cout << "Informe a matrícula (somente números): ";
        cin >> matriculaTemp;

        if (isDigit(matriculaTemp) == 0) {
            cout << "\nInforme somente números\n\n\n";
        }
        else {
            do {
                matricula[qtdAlunos] = matriculaTemp;

                for (int j = 0; j < MAX_NOTAS; j++)
                {
                    system("clear");
                    cout << "Matricula do aluno: " << matricula[qtdAlunos] << endl;
                    cout << "Informe a nota " << j+1 << ": ";
                    cin >> notas[j];

                    alunos[qtdAlunos][j] = notas[j];
                    cout << endl;
                }

                alunos[qtdAlunos][MAX_NOTAS] = calculaMedia(notas); 

                qtdAlunos++;
                
                cout << endl;
                cout << "Deseja informar outra matrícula?\n";
                cout << "(Digite 'S' para sim ou 'N' para não) ";
                cin >> opcao;
                system("clear");
            } while (int(opcao) != 83 && int(opcao) != 115 && int(opcao) != 78 && int(opcao) != 110);
        }

    } while (int(opcao) == 83 || int(opcao) == 115);

    

    system("clear");
    cout << "MATRICULA\tNOTA1\t\tNOTA2\t\tNOTA3\t\tMEDIA\n";
    cout << "=====================================================================\n";

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << matricula[i] << "\t";

        for (int j = 0; j < MAX_NOTAS + 1; j++)
        {
            cout << fixed << setprecision(1);
            cout << alunos[i][j] << "\t\t";
        }
        
        cout << endl;
    }

    cout << endl;
    return 0;
}