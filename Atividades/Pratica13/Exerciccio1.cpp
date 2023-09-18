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
    int numPoltrona;
    string cpf;
    string nome;
    int idade;
};

struct Viagem
{
    vector<Passageiro> listaPassageiros;
    string origem;
    string destino;
    DataHora dataHora;
};

struct Onibus
{
    vector<Viagem> listaViagens;
};

void systemPause();

void systemClear();

bool comparaDataHora(DataHora data1, DataHora data2);

double arrecadacaoPorViagem(Viagem viagem);

double arrecadacaoPorMes(vector<Viagem> &listaViagens, int mes);

Passageiro retornaPassageiro(vector<Viagem> &listaViagens, Viagem viagem, int numPoltrona);

string retornaHorarioMaisRentavel(vector<Viagem> &listaViagens);

int retornaMediaIdade(vector<Viagem> &listaViagens);

Viagem venderPassagem();

void menuPoltrona(Passageiro &passageiro);

void menuOrigem(Viagem &viagem);

void menuDestino(Viagem &viagem);

int main(void) {
    Passageiro passageiro;
    Viagem viagem;
    
    viagem = venderPassagem();
    //menuPoltrona(passageiro);

    return 0;
}

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

Passageiro retornaPassageiro(vector<Viagem> &listaViagens, Viagem viagem, int numPoltrona) {
    Passageiro passageiro;

    for (Viagem v : listaViagens)
    {
        if (comparaDataHora(v.dataHora, viagem.dataHora))
        {
            for (Passageiro passageiro : viagem.listaPassageiros)
            {
                if (passageiro.numPoltrona == numPoltrona)
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
            idade += passageiro.idade;
            qtdTotalPass++;
        }
    }

    media = idade / qtdTotalPass;
    return media;
}

Viagem venderPassagem() {
    Passageiro passageiro;
    vector<Passageiro> listaPassageiros;

    Viagem viagem;
    vector<Viagem> listaViagens;

    cout << "\n######################### Venda de passagens #########################\n\n";

    cout << "\nNome: ";
    cin >> passageiro.nome;

    cout << "\nCPF: ";
    cin >> passageiro.cpf;

    cout << "\nIdade: ";
    cin >> passageiro.idade;

    menuPoltrona(passageiro);
    menuOrigem(viagem);
    menuDestino(viagem);

    listaPassageiros.push_back(passageiro);
    viagem.listaPassageiros = listaPassageiros;

    return viagem;
}

void menuPoltrona(Passageiro &passageiro) {
    int poltrona;
    bool selecaoInvalida = false;

    do {
        cout << "\nSelecione a poltrona:\n\n";

        for (int i = 1; i <= MAX_PASS; i++)
        {
            string str = i < 10 ? "0" : "";
            
            cout << "[ " << str << i << " ]";

            if (i % (MAX_PASS / 4) == 0)
            {
                if (i == MAX_PASS / 2)
                {
                    cout << endl << endl;
                }
                
                cout << endl;
            }
            else
            {
                cout << "\t";
            }
        }

        cout << "\n\nSelecao: ";
        cin >> poltrona;

        if (poltrona > 0 && poltrona <= MAX_PASS)
        {
            passageiro.numPoltrona = poltrona;
        }
        else
        {
            selecaoInvalida = true;
        }
    } while (selecaoInvalida);
}

void menuOrigem(Viagem &viagem) {
    int origem;
    bool selecaoInvalida = false;

    do {
        cout << "\nSelecione a origem: ";
    
        cout << "[ 1 ] Sao Paulo";
        cout << "[ 2 ] Rio de Janeiro";
        cin >> origem;

        switch (origem)
        {
            case 1:
                viagem.origem = "Sao Paulo";
                break;
            
            case 2:
                viagem.origem = "Rio de janeiro";
                break;

            default:
                selecaoInvalida = true;
                break;
        }
    } while (selecaoInvalida);
}

void menuDestino(Viagem &viagem) {
    int destino;
    bool selecaoInvalida = false;

    do {
        cout << "\nSelecione o destino: ";
    
        cout << "[ 1 ] Sao Paulo";
        cout << "[ 2 ] Rio de Janeiro";
        cin >> destino;

        switch (destino)
        {
            case 1:
                viagem.destino = "Sao Paulo";
                break;
            
            case 2:
                viagem.destino = "Rio de janeiro";
                break;

            default:
                selecaoInvalida = true;
                break;
        }
    } while (selecaoInvalida);
}

void systemPause() {
    cout << "\nPressione ENTER para continuar...\n";
    cin.sync();
    cin.get();
}

void systemClear() {
    system("echo ''") != 0 ? system("clear") : system("cls");
}