#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Data
{
    private:
        int dia, mes, ano;
        string formato;

        void formato_dd_MM_yyyy(string data);

    public:
        Data(/* args */);
        Data(string data, string formato);
        ~Data();

        int getDia();
        void setDia(int _dia);
        int getMes();
        void setMes(int _mes);
        int getAno();
        void setAno(int _ano);
};

Data::Data(/* args */)
{
}

Data::Data(string data, string formato)
{
    
    int opcao = 0;

    if (formato == "dd/MM/yyyy")
    {
        opcao = 1;
    }

    switch (opcao)
    {
        case 1:
            break;
        
        default:
            break;
    }

    
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

void Data::formato_dd_MM_yyyy(string data) {
    string _dia, _mes, _ano;
    Data data;

    _dia = data.substr(0, 2);
    _mes = data.substr(3, 2);
    _ano = data.substr(6, 4);
}