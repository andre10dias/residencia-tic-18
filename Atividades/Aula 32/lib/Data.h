#ifndef DATA_H

#include <iostream>
#include <string>

using namespace std;

#define DATA_H

class Data
{
    private:
        int dia, mes, ano;

        string retornarDiaDaSemana();
        string retornarMesPorExtenso();
        bool ehAnoBisexto();
        bool ehDataValida();

    public:
        Data(/* args */);
        Data(int _dia, int _mes, int _ano);
        ~Data();

        const static int SHORT = 1; //SHORT 31/05/23
        const static int MEDIUM = 2; //MEDIUM 31/05/2023
        const static int LONG = 3; //LONG 31 de Maio de 2023
        const static int FULL = 4; //FULL Quarta-feira, 31 de Maio de 2023

        int getDia();
        void setDia(int _dia);
        int getMes();
        void setMes(int _mes);
        int getAno();
        void setAno(int _ano);

        string formatar(Data data, int formato);
};

#endif