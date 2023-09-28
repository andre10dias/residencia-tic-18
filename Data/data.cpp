#include <iostream>
#include <string>

using namespace std;

struct Data {
    int dia, mes, ano;
};

bool ehDigito(string &somenteDigitos);

bool ehAnoBisexto(int ano);

bool ehDataValida(int dia, int mes, int ano);

string retornaMesPorExtenso(int mes);

int main(void) {
    string data, dia, mes, ano;

    cout << "Informe uma data no formato dd/mm/aaaa: ";
    cin >> data;

    dia = data.substr(0, 2);
    mes = data.substr(3, 2);
    ano = data.substr(6, 4);

    string somenteDigitos = dia+mes+ano;

    if (ehDigito(somenteDigitos) && ehDataValida(stoi(dia), stoi(mes), stoi(ano)))
    {
        cout << data << " é uma data válida." << endl;
        cout << dia << " de " << retornaMesPorExtenso(stoi(mes)) << " de " << ano << endl;
    }
    else
    {
        cout << data << " não é uma data válida." << endl;
    }
    
    cout << endl;
    return 0; 
}

bool ehDigito(string &somenteDigitos) {
    for (long unsigned int i = 0; i < somenteDigitos.size(); i++)
    {
        if (!isdigit(somenteDigitos[i]))
        {
            return false;
        }
    }

    return true;
}

bool ehAnoBisexto(int ano) {
    if (ano % 100 > 0 && ano % 4 == 0)
    {
        return true;
    }
    
    return false;
}

bool ehDataValida(int dia, int mes, int ano) {
    bool ehValido = true;

    if (dia < 1 || dia > 31 || mes < 1 || mes > 12)
    {
        return false;
    }
    else 
    {
        if (mes < 8)
        {
            if (mes % 2 == 0 && dia > 30) //Meses pares de JAN a JUL só vão até dia 30
            {
                ehValido = false;
            }

            if (mes == 2)
            {
                if ((!ehAnoBisexto(ano) && dia > 28) || dia > 29) //FEV vai somente até 28 nos anos não bisextos 
                {
                    ehValido = false;
                }
            }
        }
        else if (mes % 2 == 1 && dia > 30) //Meses ímpares de AGO a DEZ só vão até dia 30
        {
            ehValido = false;
        }
    }
    
    return ehValido;
}

string retornaMesPorExtenso(int mes) {
    string porExtenso;

    switch (mes)
    {
        case 1:
            porExtenso = "Janeiro";
            break;

        case 2:
            porExtenso = "Fevereiro";
            break;

        case 3:
            porExtenso = "Março";
            break;

        case 4:
            porExtenso = "Abril";
            break;

        case 5:
            porExtenso = "Maio";
            break;

        case 6:
            porExtenso = "Junho";
            break;

        case 7:
            porExtenso = "Julho";
            break;

        case 8:
            porExtenso = "Agosto";
            break;

        case 9:
            porExtenso = "Setembro";
            break;

        case 10:
            porExtenso = "Outubro";
            break;

        case 11:
            porExtenso = "Novembro";
            break;

        case 12:
            porExtenso = "Dezembro";
            break;
        
        default:
            porExtenso = "";
            break;
    }

    return porExtenso;
}