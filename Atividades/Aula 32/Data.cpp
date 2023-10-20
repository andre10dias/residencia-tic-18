#include "lib/Data.h"

Data::Data(/* args */)
{
}

Data::Data(int _dia, int _mes, int _ano) {
    dia = _dia;
    mes = _mes;
    ano = _ano;
}

Data::~Data()
{
}

int Data::getDia() {
    return dia;
}

void Data::setDia(int _dia) {
    dia = _dia;
}

int Data::getMes() {
    return mes;
}

void Data::setMes(int _mes) {
    mes = _mes;
}

int Data::getAno() {
    return ano;
}

void Data::setAno(int _ano) {
    ano = _ano;
}

// int main(void) {
//     Data data(31, 5, 2023);

//     cout << data.formatar(data, data.SHORT) << endl;
//     cout << data.formatar(data, data.MEDIUM) << endl;
//     cout << data.formatar(data, data.LONG) << endl;
//     cout << data.formatar(data, data.FULL) << endl;

//     cout << endl;
//     return 0;
// }

string Data::formatar(Data data, int formato) {
    string retorno = "";
    string diaSemana, _dia, _mes, _ano;

    if (!ehDataValida())
    {
        return retorno;
    }

    _dia = data.dia <= 9 ? "0" + to_string(data.dia) : to_string(data.dia);
    _mes = data.mes <= 9 ? "0" + to_string(data.mes) : to_string(data.mes);

    switch (formato)
    {
        case 1:
            _ano = to_string(data.ano);
            _ano = _ano.substr(2, 2);
            retorno = _dia + "/" + _mes + "/" + _ano;
            break;

        case 2:
            retorno = _dia + "/" + _mes + "/" + to_string(data.ano);
            break;

        case 3:
            _mes = retornarMesPorExtenso();
            retorno = _dia + " de " + _mes + " de " + to_string(data.ano);
            break;

        case 4:
            diaSemana = retornarDiaDaSemana();
            _mes = retornarMesPorExtenso();
            retorno = diaSemana + ", " + _dia + " de " + _mes + " de " + to_string(data.ano);
            break;
        
        default:
            break;
    }

    return retorno;
}

string Data::retornarDiaDaSemana() {
    string retorno = "";

    if (mes == 1)
    {
        mes = 13;
        ano = ano - 1;
    }
        
    if (mes == 2)
    {
        mes = 14;
        ano = ano - 1;
    } 
        
    int formula = dia + 2 * mes + (3 * (mes + 1) / 5) + ano + ano / 4 - ano / 100 + ano / 400 + 2;
    int diaSemana = formula % 7;

    if (mes == 13)
    {
        mes = 1;
        ano = ano + 1;
    }

    if (mes == 14)
    {
        mes = 2;
        ano = ano + 1;
    }
    
    switch (diaSemana)
    {
        case 0:
            retorno = "Sábado";
            break;
                
        case 1:
            retorno = "Domingo";
            break;
            
        case 2:
            retorno = "Segunda-feira";
            break;
            
        case 3:
            retorno = "Terça-feira";
            break;
            
        case 4:
            retorno = "Quarta-feira";
            break;
            
        case 5:
            retorno = "Quinta-feira";
            break;
            
        case 6:
            retorno = "Sexta-feira";
            break;
    }

    return retorno;
}

string Data::retornarMesPorExtenso() {
    string retorno;

    switch (mes)
    {
        case 1:
            retorno = "Janeiro";
            break;

        case 2:
            retorno = "Fevereiro";
            break;

        case 3:
            retorno = "Março";
            break;

        case 4:
            retorno = "Abril";
            break;

        case 5:
            retorno = "Maio";
            break;

        case 6:
            retorno = "Junho";
            break;

        case 7:
            retorno = "Julho";
            break;

        case 8:
            retorno = "Agosto";
            break;

        case 9:
            retorno = "Setembro";
            break;

        case 10:
            retorno = "Outubro";
            break;

        case 11:
            retorno = "Novembro";
            break;

        case 12:
            retorno = "Dezembro";
            break;
        
        default:
            retorno = "";
            break;
    }

    return retorno;
}

bool Data::ehAnoBisexto() {
    if (ano % 100 > 0 && ano % 4 == 0)
    {
        return true;
    }
    
    return false;
}

bool Data::ehDataValida() {
    bool ehValido = true;
    string _ano = to_string(ano);

    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || _ano.size() < 4)
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
                if ((!ehAnoBisexto() && dia > 28) || dia > 29) //FEV vai somente até 28 nos anos não bisextos 
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