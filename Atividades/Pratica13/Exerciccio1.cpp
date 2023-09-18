#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_PASS 40
#define VL_PASS 80
#define MAX_VIAGS 5

struct DataHora
{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
};

struct Passageiro
{
    int numeroAssento;
    string cpfPassageiro;
    string nomePassageiro;
    int idadePassageiro;
};

struct Viagem
{
    vector<Passageiro> listaPassageiros;
    DataHora dataHora;
};

struct Onibus
{
    vector<Viagem> listaViagens;
};

bool comparaDataHora(DataHora data1, DataHora data2) {
    if (data1.dia == data2.dia && data1.mes == data2.mes 
        && data1.ano == data2.ano && data1.minuto == data2.minuto 
        && data1.hora == data2.hora)
    {
        return true;
    }

    return false;
}

double arrecadacaoPorViagem(Viagem viagem) {
    int qtdPassageiros = viagem.listaPassageiros.size();
    double valor = 0;

    for (int i = 0; i < qtdPassageiros; i++)
    {
        valor += double(VL_PASS);
    }

    return valor;
}

double arrecadacaoPorMes(vector<Viagem> &listaViagens, int mes) {
    double valor = 0;

    for (Viagem viagem : listaViagens)
    {
        if (viagem.dataHora.mes == mes)
        {
            valor += double(VL_PASS);
        }
    }
    
    return valor;
}

Passageiro retornaPassageiro(vector<Viagem> &listaViagens, Viagem viagem, int numeroAssento) {
    Passageiro passageiro;

    for (Viagem v : listaViagens)
    {
        if (comparaDataHora(v.dataHora, viagem.dataHora))
        {
            for (Passageiro passageiro : viagem.listaPassageiros)
            {
                if (passageiro.numeroAssento == numeroAssento)
                {
                    return passageiro;
                }
                
            }
            
        }
        
    }

    return passageiro;
}

string retornaHorarioMaisRentavel(vector<Viagem> &listaViagens) {
    int maiorNumeroPass = 0;
    int hora = 0;
    int minuto = 0;

    for (Viagem viagem : listaViagens)
    {
        if (viagem.listaPassageiros.size() > maiorNumeroPass)
        {
            maiorNumeroPass = viagem.listaPassageiros.size();
            hora = viagem.dataHora.hora;
            minuto = viagem.dataHora.minuto;
        }
    }
    
    string horario = to_string(hora) + ":" + to_string(minuto);
    return horario;
}

int retornaMediaIdade(vector<Viagem> &listaViagens) {
    int idade = 0;
    int qtdTotalPass = 0;
    float media;

    for (Viagem viagem : listaViagens)
    {
        for (Passageiro passageiro : viagem.listaPassageiros)
        {
            idade += passageiro.idadePassageiro;
            qtdTotalPass++;
        }
    }

    media = idade / qtdTotalPass;
    return media;
}

int main(void) {
    Passageiro passageiro;
    
}