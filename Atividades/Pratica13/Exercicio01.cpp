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

struct Viagem
{
    string origem;
    string destino;
    DataHora dataHora;
};

struct Passagem
{
    int numPoltrona;
    string nomePassageiro;
    string cpfPassageiro;
    int idadePassageiro;
    Viagem viagem;
};

struct Onibus
{
    vector<Viagem> listaViagens;
};

DataHora construtorDataHora(int _dia, int _mes, int _ano, int _hora, int _minuto);
string formatarDataHora(DataHora dataHora);
void popularViagensIda(vector<Viagem> &listaViagens);
void popularViagensVolta(vector<Viagem> &listaViagens);
void listarViagensDisponiveis(vector<Viagem> &listaViagens);
int exibirListaPassagensVendidas(vector<Passagem> &listaPassagens);
// void removerViagemDisponivel(vector<Viagem> &listaViagens, int index);
void listarPassagensVendidas(vector<Passagem> &listaPassagens);
void selecionarPoltrona(Passagem passagem);
int selecionarViagem(vector<Viagem> &listaViagens);
void viagemSelecionada(Viagem viagem);
void venderPassagens(vector<Passagem> &listaPassagens, vector<Viagem> &listaViagens);
void cabecalhoVendaPassagens();
void menu(vector<Viagem> &listaViagens);
void systemPauseAndClear();
void systemPause();
void systemClear();
int sair();

int main(void)  {
    vector<Viagem> listaViagens;
    popularViagensIda(listaViagens);
    popularViagensVolta(listaViagens);
    menu(listaViagens);
    cout << endl;
    return 0;
}

void menu(vector<Viagem> &listaViagens) {
    vector<Passagem> listaPassagens;
    int opcao;

    do
    {
        systemClear();
        cout << "-------------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\tSistema de venda de passagens" << endl;
        cout << "-------------------------------------------------------------------------------------------------" << endl << endl;
        
        cout << "[ 1 ] Vender passagem\n[ 2 ] Listar passagens vendidas\n[ 0 ] Sair\n" << endl;
        cout << "Selecione uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
            case 1:
                venderPassagens(listaPassagens, listaViagens);
                break;

            case 2:
                //listarlistaPassagens(passagems);
                break;

            case 0:
                sair();
                break;
            
            default:
                cout << "\nOpção inválida!\n";
                systemPause();
                break;
        }
    } while (opcao != 0);
}

DataHora construtorDataHora(int _dia, int _mes, int _ano, int _hora, int _minuto) {
    DataHora dataHora;

    dataHora.dia = _dia;
    dataHora.mes = _mes;
    dataHora.ano = _ano;
    dataHora.hora = _hora;
    dataHora.minuto = _minuto;

    return dataHora;
}

string formatarDataHora(DataHora dataHora) {
    string dia = dataHora.dia < 10 ? "0"+to_string(dataHora.dia) : to_string(dataHora.dia);
    string mes = dataHora.mes < 10 ? "0"+to_string(dataHora.mes) : to_string(dataHora.mes);
    string hora = dataHora.hora < 10 ? "0"+to_string(dataHora.hora) : to_string(dataHora.hora);
    string minuto = dataHora.minuto < 10 ? "0"+to_string(dataHora.minuto) : to_string(dataHora.minuto);

    return dia + "/" + mes + "/" + to_string(dataHora.ano) + " " + hora + ":" + minuto;
}

void cabecalhoVendaPassagens() {
    cout << "-------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\tVenda de passagens" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl << endl;
}

void venderPassagens(vector<Passagem> &listaPassagens, vector<Viagem> &listaViagens) {
    Passagem passagem;
    int indexViagem;

    indexViagem = selecionarViagem(listaViagens);
    passagem.viagem = listaViagens[indexViagem];

    systemClear();
    cabecalhoVendaPassagens();
    viagemSelecionada(passagem.viagem);

    cout << "Nome do passageiro: ";
    cin.ignore();
    getline(cin, passagem.nomePassageiro);

    systemClear();
    cabecalhoVendaPassagens();
    viagemSelecionada(passagem.viagem);

    cout << "CPF: ";
    cin >> passagem.cpfPassageiro;

    systemClear();
    cabecalhoVendaPassagens();
    viagemSelecionada(passagem.viagem);

    cout << "Idade: ";
    cin >> passagem.idadePassageiro;

    selecionarPoltrona(passagem);

    listaPassagens.push_back(passagem);
}

int selecionarViagem(vector<Viagem> &listaViagens) {
    int tamanho = listaViagens.size();
    int selecao;
    bool selecaoInvalida = false;

    do {
        systemClear();
        cabecalhoVendaPassagens();

        listarViagensDisponiveis(listaViagens);

        cout << "\nSelecione uma viagem: ";
        cin >> selecao;

        if (selecao > 0 && selecao <= tamanho)
        {
            return selecao-1;
        }
        else
        {
            selecaoInvalida = true;
        }
    } while (selecaoInvalida);
}

void viagemSelecionada(Viagem viagem) {
    string dataHoraFormatada = formatarDataHora(viagem.dataHora);
    cout << "\tOrigem: " << viagem.origem << "\t" << "Destino: " << viagem.destino << "\t\t" << "Data/Hora: " << dataHoraFormatada << endl << endl;
}

void selecionarPoltrona(Passagem passagem) {
    Viagem viagem;
    int poltrona;
    bool selecaoInvalida = false;

    do {
        systemClear();
        cabecalhoVendaPassagens();

        viagem = passagem.viagem;
        viagemSelecionada(viagem);

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

        cout << "\nSelecione uma poltrona: ";
        cin >> poltrona;

        if (poltrona > 0 && poltrona <= MAX_PASS)
        {
            passagem.numPoltrona = poltrona;
        }
        else
        {
            selecaoInvalida = true;
        }
    } while (selecaoInvalida);
}

void cabecalhoListar() {
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\tListar passagens" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl << endl;
}

int exibirListaPassagensVendidas(vector<Passagem> &listaPassagens) {
    int tamanho = listaPassagens.size();
    string situacao;

    systemClear();
    cabecalhoListar();

    if (tamanho > 0)
    {
        listarPassagensVendidas(listaPassagens);
    }
    else
    {
        cout << "\nNenhum dado encontrado\n";
    }

    systemPauseAndClear();
    return 0;
}

void listarPassagensVendidas(vector<Passagem> &listaPassagens) {
    //int tamanho = listaPassagens.size();
    string dataHoraFormatada;
    Viagem viagem;    

    cout << "Passageiro\tCPF\tIdade\tOrigem\tDestino\tData/Hora" << endl;
    for (Passagem passagem : listaPassagens)
    {
        viagem = passagem.viagem;
        dataHoraFormatada = formatarDataHora(viagem.dataHora);
        cout << passagem.nomePassageiro << "\t" << passagem.cpfPassageiro << "\t" << passagem.idadePassageiro << "\t" << viagem.origem << "\t" << viagem.destino << "\t" << dataHoraFormatada << endl;
    }
}

void listarViagensDisponiveis(vector<Viagem> &listaViagens) {
    int tam = listaViagens.size();
    string index;
    string dataFormatada;

    cout << "\tOrigem\t\tDestino\t\tData/Hora" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < tam; i++)
    {
        dataFormatada = formatarDataHora(listaViagens[i].dataHora);
        index = (i+1) < 10 ? "0" + to_string((i+1)) : to_string((i+1));
        cout << "[ " << index << " ] " << listaViagens[i].origem << "\t" << listaViagens[i].destino << "\t" << dataFormatada << endl;
    }
}

// void removerViagemDisponivel(vector<Viagem> &listaViagens, int index) {
//     if (index == 0)
//     {
//         listaViagens.erase(listaViagens.begin());
//     }
//     else
//     {
//         listaViagens.erase(listaViagens.begin()+(index-1));
//     }
// }

void popularViagensIda(vector<Viagem> &listaViagens) {
    Viagem viagem;
    DataHora dataHora;

    viagem.origem = "Rio de Janeiro";
    viagem.destino = "São Paulo";
    viagem.dataHora = construtorDataHora(4, 11, 2023, 5, 32);
    listaViagens.push_back(viagem);

    viagem.origem = "Rio de Janeiro";
    viagem.destino = "São Paulo";
    viagem.dataHora = construtorDataHora(4, 11, 2023, 8, 41);
    listaViagens.push_back(viagem);

    viagem.origem = "Rio de Janeiro";
    viagem.destino = "São Paulo";
    viagem.dataHora = construtorDataHora(6, 11, 2023, 13, 32);
    listaViagens.push_back(viagem);

    viagem.origem = "Rio de Janeiro";
    viagem.destino = "São Paulo";
    viagem.dataHora = construtorDataHora(6, 11, 2023, 18, 0);
    listaViagens.push_back(viagem);

    viagem.origem = "Rio de Janeiro";
    viagem.destino = "São Paulo";
    viagem.dataHora = construtorDataHora(8, 11, 2023, 21, 45);
    listaViagens.push_back(viagem);
}

void popularViagensVolta(vector<Viagem> &listaViagens) {
    Viagem viagem;
    // DataHora dataHora;

    viagem.origem = "São Paulo";
    viagem.destino = "Rio de Janeiro";
    viagem.dataHora = construtorDataHora(7, 11, 2023, 5, 32);
    listaViagens.push_back(viagem);

    viagem.origem = "São Paulo";
    viagem.destino = "Rio de Janeiro";
    viagem.dataHora = construtorDataHora(7, 11, 2023, 8, 41);
    listaViagens.push_back(viagem);

    viagem.origem = "São Paulo";
    viagem.destino = "Rio de Janeiro";
    viagem.dataHora = construtorDataHora(9, 11, 2023, 13, 32);
    listaViagens.push_back(viagem);

    viagem.origem = "São Paulo";
    viagem.destino = "Rio de Janeiro";
    viagem.dataHora = construtorDataHora(9, 11, 2023, 18, 0);
    listaViagens.push_back(viagem);

    viagem.origem = "São Paulo";
    viagem.destino = "Rio de Janeiro";
    viagem.dataHora = construtorDataHora(11, 11, 2023, 21, 45);
    listaViagens.push_back(viagem);
}

int sair() {
    cout << "\nFinalizando programa...";
    systemPauseAndClear();
    return 0;
}

void systemClear() {
    #if __linux__
        system("clear");
    #else
        system("cls");
    #endif
}

void systemPause() {
    cout << "\nPressione ENTER para continuar...\n";
    #if __linux__
        cin.ignore();
    #else
        cin.sync();
    #endif
    cin.get();
}

void systemPauseAndClear() {
    systemPause();
    systemClear();
}