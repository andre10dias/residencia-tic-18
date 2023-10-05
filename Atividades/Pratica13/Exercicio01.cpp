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
    double valorPassagem;
    Viagem viagem;
};

DataHora construtorDataHora(int _dia, int _mes, int _ano, int _hora, int _minuto);
string formatarDataHora(DataHora dataHora);
string formatarData(DataHora dataHora);
string formatarHora(DataHora dataHora);
string formatarCpf(string cpf);
bool ehCpfValido(string cpf);
bool verificarHoraExistenteNaLista(vector<DataHora> listaHorarios, DataHora dataHora);
void popularViagensIda(vector<Viagem> &listaViagens);
void popularViagensVolta(vector<Viagem> &listaViagens);
void listarViagensDisponiveis(vector<Viagem> &listaViagens);
int exibirListaPassagensVendidas(vector<Passagem> &listaPassagens);
void listarPassagensVendidas(vector<Passagem> &listaPassagens);
void cabecalhoArrecadacaoPorViagem();
void cabecalhoArrecadacaoPorMes();
void cabecalhoPassageiroPorViagemPoltrona();
int exibirMediaIdadeDosPassageiros(vector<Passagem> &listaPassagens);
int exibirHorarioMaisRentavel(vector<Viagem> &listaViagens, vector<Passagem> &listaPassagens);
int exibirArrecadacaoPorViagem(vector<Viagem> &listaViagens, vector<Passagem> &listaPassagens);
int exibirArrecadacaoPorMes(vector<Viagem> &listaViagens, vector<Passagem> &listaPassagens);
int exibirPassageiroPorViagemPoltrona(vector<Viagem> &listaViagens, vector<Passagem> &listaPassagens);
float retornarMediaIdadeDosPassageiros(vector<Passagem> listaPassagens);
DataHora retornarHorarioMaisRentavel(vector<Viagem> &listaViagens, vector<Passagem> &listaPassagens);
string retornarNomePassageiroPorViagemPoltrona(vector<Passagem> &listaPassagens, Viagem viagem, int poltorna);
double retornarArrecadacaoPorViagem(vector<Passagem> &listaPassagensPorViagem);
double retornarArrecadacaoPorMes(vector<Passagem> &listaPassagensPorMes);
vector<DataHora> retornarListaHorariosDasViagens(vector<Viagem> &listaViagens);
vector<Viagem> retornarListaViagensPorHorario(vector<Viagem> &listaViagens, DataHora dataHora);
vector<Passagem> retornarListaPassagensPorMes(vector<Passagem> &listaPassagens, int mes);
vector<Passagem> retornarListaPassagensPorViagem(vector<Passagem> &listaPassagens, Viagem viagem);
void selecionarPoltrona(Passagem passagem);
int selecionarViagem(vector<Viagem> &listaViagens);
void viagemSelecionada(Viagem viagem);
void venderPassagens(vector<Passagem> &listaPassagens, vector<Viagem> &listaViagens);
void cabecalhoVendaPassagens();
void menu(vector<Viagem> &listaViagens, vector<Passagem> &listaPassagens);
void systemPauseAndClear();
void systemPause();
void systemClear();
int sair();

//Função utilizada para testes
void mockVendas(vector<Passagem> &listaPassagens, vector<Viagem> &listaViagens);

int main(void)  {
    vector<Viagem> listaViagens;
    vector<Passagem> listaPassagens;

    popularViagensIda(listaViagens);
    popularViagensVolta(listaViagens);
    mockVendas(listaPassagens, listaViagens);
    menu(listaViagens, listaPassagens);
    cout << endl;
    return 0;
}

void menu(vector<Viagem> &listaViagens, vector<Passagem> &listaPassagens) {
    int opcao;

    do
    {
        systemClear();
        cout << "-------------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\tSistema de venda de passagens" << endl;
        cout << "-------------------------------------------------------------------------------------------------" << endl << endl;
        
        cout << "[ 1 ] Vender passagem\n[ 2 ] Listar passagens vendidas" << endl;
        cout << "[ 3 ] Arrecadação por viagem\n[ 4 ] Arrecadação por mês" << endl;
        cout << "[ 5 ] Buscar passageiro por viagem e poltrona\n[ 6 ] Verificar horário mais rentável" << endl;
        cout << "[ 7 ] Verificar média de idade dos passageiros\n[ 0 ] Sair" << endl;
        cout << "\nSelecione uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
            case 1:
                venderPassagens(listaPassagens, listaViagens);
                break;

            case 2:
                exibirListaPassagensVendidas(listaPassagens);
                break;

            case 3:
                exibirArrecadacaoPorViagem(listaViagens, listaPassagens);
                break;

            case 4:
                exibirArrecadacaoPorMes(listaViagens, listaPassagens);
                break;

            case 5:
                exibirPassageiroPorViagemPoltrona(listaViagens, listaPassagens);
                break;

            case 6:
                exibirHorarioMaisRentavel(listaViagens, listaPassagens);
                break;

            case 7:
                exibirMediaIdadeDosPassageiros(listaPassagens);
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
    string dataFormatada = formatarData(dataHora);
    string horaFormatada = formatarHora(dataHora);

    return dataFormatada + " " + horaFormatada;
}

string formatarHora(DataHora dataHora) {
    string hora = dataHora.hora < 10 ? "0"+to_string(dataHora.hora) : to_string(dataHora.hora);
    string minuto = dataHora.minuto < 10 ? "0"+to_string(dataHora.minuto) : to_string(dataHora.minuto);

    return hora + ":" + minuto;
}

string formatarData(DataHora dataHora) {
    string dia = dataHora.dia < 10 ? "0"+to_string(dataHora.dia) : to_string(dataHora.dia);
    string mes = dataHora.mes < 10 ? "0"+to_string(dataHora.mes) : to_string(dataHora.mes);

    return dia + "/" + mes + "/" + to_string(dataHora.ano);
}

string formatarCpf(string cpf) {
    string c1 = cpf.substr(0, 3);
    string c2 = cpf.substr(3, 3);
    string c3 = cpf.substr(6, 3);
    string c4 = cpf.substr(9, 2);

    return c1 + "." + c2 + "." + c3 + "-" + c4;
}

bool ehCpfValido(string cpf) {
    int tamanho = cpf.size();

    if (tamanho < 11)
    {
        return false;
    }
    
    for (int i = 0; i < tamanho; i++)
    {
        if (!isdigit(cpf[i]))
        {
            return false;
        }
    }
    
    return true;
}

void cabecalhoVendaPassagens() {
    cout << "-------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\tVenda de passagens" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl << endl;
}

void venderPassagens(vector<Passagem> &listaPassagens, vector<Viagem> &listaViagens) {
    Passagem passagem;
    int indexViagem;
    bool validarCpf = false;

    indexViagem = selecionarViagem(listaViagens);
    passagem.viagem = listaViagens[indexViagem];

    systemClear();
    cabecalhoVendaPassagens();
    viagemSelecionada(passagem.viagem);

    cout << "Nome do passageiro: ";
    cin.ignore();
    getline(cin, passagem.nomePassageiro);

    do
    {
        systemClear();
        cabecalhoVendaPassagens();
        viagemSelecionada(passagem.viagem);

        cout << "CPF (somente números): ";
        cin >> passagem.cpfPassageiro;

        validarCpf = ehCpfValido(passagem.cpfPassageiro);
        if (!validarCpf)
        {
            cout << "\nCPF inválido.\n";
            systemPause();
        }
        
    } while (!validarCpf);

    systemClear();
    cabecalhoVendaPassagens();
    viagemSelecionada(passagem.viagem);

    cout << "Idade: ";
    cin >> passagem.idadePassageiro;

    passagem.valorPassagem = VL_PASS;

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
            selecaoInvalida = false;
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
        cout << "\nNenhum dado encontrado.\n";
    }

    systemPauseAndClear();
    return 0;
}

void listarPassagensVendidas(vector<Passagem> &listaPassagens) {
    //int tamanho = listaPassagens.size();
    string dataHoraFormatada;
    string cpfFormatado;
    Viagem viagem;    

    cout << "Passageiro\tCPF\t\tIdade\tOrigem\t\tDestino\t\tPoltrona\tData/Hora" << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    for (Passagem passagem : listaPassagens)
    {
        viagem = passagem.viagem;
        dataHoraFormatada = formatarDataHora(viagem.dataHora);
        cpfFormatado = formatarCpf(passagem.cpfPassageiro);
        cout << passagem.nomePassageiro << "\t" << cpfFormatado << "\t" << passagem.idadePassageiro << "\t";
        cout << viagem.origem << "\t" << viagem.destino << "\t" << passagem.numPoltrona << "\t" << dataHoraFormatada << endl;
    }
}

void cabecalhoHorarioMaisRentavel() {
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\tHorário mais rentável" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl << endl;
}

int exibirHorarioMaisRentavel(vector<Viagem> &listaViagens, vector<Passagem> &listaPassagens) {
    DataHora horaMaisRentavel = retornarHorarioMaisRentavel(listaViagens, listaPassagens);

    systemClear();
    cabecalhoHorarioMaisRentavel();
    cout << "Horário mais rentável: " << formatarHora(horaMaisRentavel) + " h" << endl;
    systemPause();
    return 0;
}

void cabecalhoMediaIdadeDosPassageiros() {
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\tMédia de idade dos passageiros" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl << endl;
}

int exibirMediaIdadeDosPassageiros(vector<Passagem> &listaPassagens) {
    float mediaIdade = retornarMediaIdadeDosPassageiros(listaPassagens);

    systemClear();
    cabecalhoMediaIdadeDosPassageiros();
    cout << "Média de idade: " << mediaIdade << endl;
    systemPause();
    return 0;
}

void cabecalhoArrecadacaoPorViagem() {
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\tArrecadação por viagem" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl << endl;
}

int exibirArrecadacaoPorViagem(vector<Viagem> &listaViagens, vector<Passagem> &listaPassagens) {
    vector<Passagem> listaPassagensPorViagem;
    int tamanho = listaViagens.size();
    double arrecadacaoPorViagem;
    int selecao;

    systemClear();
    cabecalhoListar();

    if (tamanho > 0)
    {
        do
        {
            systemClear();
            cabecalhoListar();

            listarViagensDisponiveis(listaViagens);
            cout << "\nSelecione uma viagem: ";
            cin >> selecao;

            if (selecao < 1 || selecao > (tamanho+1))
            {
                cout << "\nViagem inexistente.\n";
                systemPause();
            }
            
        } while (selecao < 1 || selecao > tamanho);

        systemClear();
        cabecalhoArrecadacaoPorViagem();
        viagemSelecionada(listaViagens[(selecao-1)]);
        listaPassagensPorViagem = retornarListaPassagensPorViagem(listaPassagens, listaViagens[(selecao-1)]);
        arrecadacaoPorViagem = retornarArrecadacaoPorViagem(listaPassagensPorViagem);
        cout << "Arrecadação da viagem: R$ " << arrecadacaoPorViagem << endl;
    }
    else
    {
        cout << "\nNenhum dado encontrado.\n";
    }

    systemPauseAndClear();
    return 0;
}

void cabecalhoArrecadacaoPorMes() {
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\tArrecadação por mês" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl << endl;
}

int exibirArrecadacaoPorMes(vector<Viagem> &listaViagens, vector<Passagem> &listaPassagens) {
    vector<Passagem> listaPassagensPorMes;
    int tamanho = listaViagens.size();
    double arrecadacaoPorMes;
    int mes;

    systemClear();
    cabecalhoListar();

    if (tamanho > 0)
    {
        do
        {
            systemClear();
            cabecalhoListar();

            cout << "Informe o mês: ";
            cin >> mes;

            if (mes < 1 || mes > 12)
            {
                cout << "\nMês inválido.\n";
                systemPause();
            }
            
        } while (mes < 1 || mes > 12);

        systemClear();
        cabecalhoArrecadacaoPorMes();
        listaPassagensPorMes = retornarListaPassagensPorMes(listaPassagens, mes);
        arrecadacaoPorMes = retornarArrecadacaoPorMes(listaPassagensPorMes);
        cout << "Arrecadação do mês " << mes << ": R$ " << arrecadacaoPorMes << endl;
    }
    else
    {
        cout << "\nNenhum dado encontrado.\n";
    }

    systemPauseAndClear();
    return 0;
}

void cabecalhoPassageiroPorViagemPoltrona() {
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tBuscar passageiro por viagem e poltrona" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl << endl;
}

int exibirPassageiroPorViagemPoltrona(vector<Viagem> &listaViagens, vector<Passagem> &listaPassagens) {
    vector<Passagem> listaPassagensPorViagem;
    int tamanho = listaViagens.size();
    string nomePassageiro;
    int selecao, numeroPoltrona;

    systemClear();
    cabecalhoListar();

    if (tamanho > 0)
    {
        do
        {
            systemClear();
            cabecalhoListar();

            listarViagensDisponiveis(listaViagens);
            cout << "\nSelecione uma viagem: ";
            cin >> selecao;

            if (selecao < 1 || selecao > (tamanho+1))
            {
                cout << "\nViagem inexistente.\n";
                systemPause();
            }
            
        } while (selecao < 1 || selecao > tamanho);

        do
        {
            systemClear();
            cabecalhoPassageiroPorViagemPoltrona();
            cout << "\nInforme o número da poltrona (1 a 40): ";
            cin >> numeroPoltrona;

            if (numeroPoltrona < 1 || numeroPoltrona > 40)
            {
                cout << "\nPoltrona inexistente.\n";
                systemPause();
            }
            
        } while (numeroPoltrona < 1 || numeroPoltrona > 40);

        systemClear();
        cabecalhoPassageiroPorViagemPoltrona();
        viagemSelecionada(listaViagens[(selecao-1)]);
        nomePassageiro = retornarNomePassageiroPorViagemPoltrona(listaPassagens, listaViagens[(selecao-1)], numeroPoltrona);

        if (nomePassageiro != "")
        {
            cout << "Nome do passageiro: " << nomePassageiro << endl;
            cout << "Poltrona: " << numeroPoltrona << endl;
        }
        else 
        {
            cout << "\nPassageiro não localizado.\n";
        }
    }
    else
    {
        cout << "\nNenhum dado encontrado.\n";
    }

    systemPauseAndClear();
    return 0;
}

DataHora retornarHorarioMaisRentavel(vector<Viagem> &listaViagens, vector<Passagem> &listaPassagens) {
    vector<DataHora> listaHoras = retornarListaHorariosDasViagens(listaViagens);
    vector<Viagem> listaViagensPorHora;
    vector<Passagem> listaPassagensPorViagem;
    double soma, maiorValor = 0;
    DataHora horarioMaisRentavel;
    
    for (Viagem viagem : listaViagens)
    {
        listaPassagensPorViagem = retornarListaPassagensPorViagem(listaPassagens, viagem);
        for (Passagem passagem : listaPassagensPorViagem)
        {
            soma = 0;
            for (DataHora dataHora : listaHoras)
            {
                if (passagem.viagem.dataHora.hora == dataHora.hora 
                    && passagem.viagem.dataHora.minuto == dataHora.minuto)
                {
                    soma += passagem.valorPassagem;
                }
            }

            if (soma > maiorValor)
            {
                maiorValor = soma;
                horarioMaisRentavel = passagem.viagem.dataHora;
            }
        }
    }
    
    return horarioMaisRentavel;
}

string retornarNomePassageiroPorViagemPoltrona(vector<Passagem> &listaPassagens, Viagem viagem, int poltorna) {
    vector<Passagem> listaPassagensPorViagem = retornarListaPassagensPorViagem(listaPassagens, viagem);

    for (Passagem passagem : listaPassagensPorViagem)
    {
        if (passagem.numPoltrona == poltorna)
        {
            return passagem.nomePassageiro;
        }
    }
    
    return "";
}

bool compararViagens(Viagem v1, Viagem v2) {
    string dtHoraFormatadaV1;
    string dtHoraFormatadaV2;

    if (v1.destino == v2.destino && v1.origem == v1.origem)
    {
        dtHoraFormatadaV1 = formatarDataHora(v1.dataHora);
        dtHoraFormatadaV2 = formatarDataHora(v2.dataHora);

        if (dtHoraFormatadaV1 == dtHoraFormatadaV2)
        {
            return true;
        }
        
    }

    return false;
}

bool verificarHoraExistenteNaLista(vector<DataHora> listaHorarios, DataHora dataHora) {
    for (DataHora dtHr : listaHorarios) 
    {
        if (dtHr.hora == dataHora.hora 
            && dtHr.minuto == dataHora.minuto) {
            return true;
        }
    }

    return false;
}

float retornarMediaIdadeDosPassageiros(vector<Passagem> listaPassagens) {
    int tamanho = listaPassagens.size();
    int soma = 0;

    for (Passagem passagem : listaPassagens)
    {
        soma += passagem.idadePassageiro;
    }

    return soma / tamanho;
}

vector<DataHora> retornarListaHorariosDasViagens(vector<Viagem> &listaViagens) {
    vector<DataHora> listaHorarios;
    DataHora dataHora;
    int tamanho;
    
    for (Viagem viagem : listaViagens)
    {
        tamanho = listaHorarios.size();
        dataHora = viagem.dataHora;

        if (tamanho == 0)
        {
            listaHorarios.push_back(dataHora);
        }
        else if (!verificarHoraExistenteNaLista(listaHorarios, dataHora))
        {
            listaHorarios.push_back(dataHora);
        }
    }

    return listaHorarios;
}

vector<Viagem> retornarListaViagensPorHorario(vector<Viagem> &listaViagens, DataHora dataHora) {
    vector<Viagem> listaViagensPorHora;

    for (Viagem viagem : listaViagens) 
    {
        if (viagem.dataHora.hora == dataHora.hora 
            && viagem.dataHora.minuto == dataHora.minuto)
        {
            listaViagensPorHora.push_back(viagem);
        }
    }

    return listaViagensPorHora;
}

vector<Passagem> retornarListaPassagensPorMes(vector<Passagem> &listaPassagens, int mes) {
    vector<Passagem> listaPassagensPorMes;

    for (Passagem passagem : listaPassagens) 
    {
        if (mes == passagem.viagem.dataHora.mes)
        {
            listaPassagensPorMes.push_back(passagem);
        }
    }

    return listaPassagensPorMes;
}

vector<Passagem> retornarListaPassagensPorViagem(vector<Passagem> &listaPassagens, Viagem viagem) {
    vector<Passagem> listaPassagensPorViagem;

    for (Passagem passagem : listaPassagens) 
    {
        if (compararViagens(viagem, passagem.viagem))
        {
            listaPassagensPorViagem.push_back(passagem);
        }
    }

    return listaPassagensPorViagem;
}

double retornarArrecadacaoPorViagem(vector<Passagem> &listaPassagensPorViagem) {
    double valorArrecadado = 0;

    for (Passagem passagem : listaPassagensPorViagem) 
    {
        valorArrecadado += double(VL_PASS);
    }

    return valorArrecadado;
}

double retornarArrecadacaoPorMes(vector<Passagem> &listaPassagensPorMes) {
    double valorArrecadado = 0;

    for (Passagem passagem : listaPassagensPorMes) 
    {
        valorArrecadado += double(VL_PASS);
    }

    return valorArrecadado;
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

void popularViagensIda(vector<Viagem> &listaViagens) {
    Viagem viagem;

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

//Função utilizada para testes
void mockVendas(vector<Passagem> &listaPassagens, vector<Viagem> &listaViagens) {
    Passagem p1;
    Viagem v1 = listaViagens[5];

    p1.nomePassageiro = "Carlos Dias";
    p1.cpfPassageiro = "25463259701";
    p1.idadePassageiro = 41;
    p1.numPoltrona = 20;
    p1.viagem = v1;
    p1.valorPassagem = VL_PASS;
    listaPassagens.push_back(p1);

    Passagem p2;
    Viagem v2 = listaViagens[5];

    p2.nomePassageiro = "Pedro Luis";
    p2.cpfPassageiro = "56980124573";
    p2.idadePassageiro = 40;
    p2.numPoltrona = 32;
    p2.viagem = v2;
    p2.valorPassagem = VL_PASS;
    listaPassagens.push_back(p2);

    Passagem p3;
    Viagem v3 = listaViagens[2];

    p3.nomePassageiro = "Antonio Silva";
    p3.cpfPassageiro = "54648022112";
    p3.idadePassageiro = 20;
    p3.numPoltrona = 19;
    p3.viagem = v3;
    p3.valorPassagem = VL_PASS;
    listaPassagens.push_back(p3);

    Passagem p4;
    Viagem v4 = listaViagens[0];

    p4.nomePassageiro = "Juliana Freire";
    p4.cpfPassageiro = "4654840012365";
    p4.idadePassageiro = 18;
    p4.numPoltrona = 38;
    p4.viagem = v4;
    p4.valorPassagem = VL_PASS;
    listaPassagens.push_back(p4);

    Passagem p5;
    Viagem v5 = listaViagens[9];

    p5.nomePassageiro = "Maria Silva";
    p5.cpfPassageiro = "09871221225";
    p5.idadePassageiro = 30;
    p5.numPoltrona = 40;
    p5.viagem = v5;
    p5.valorPassagem = VL_PASS;
    listaPassagens.push_back(p5);
}