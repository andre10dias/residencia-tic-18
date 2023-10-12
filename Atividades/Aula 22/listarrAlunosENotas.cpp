#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#define TRACO "-------------------------------------------------------------------------------------------------------"

class BancoDeDados
{
    private:
        /* data */
    public:
        BancoDeDados(/* args */);
        ~BancoDeDados();

        static void salvarDados(vector<string> listaDados, string nomeArquivo);
        static vector<string> recuperarDados(vector<string> listaDados, string nomeArquivo);
        static vector<string> tratarDados(vector<string> listaDados);
        static vector<string> retornarLinha(vector<string> listaDados);
        static vector<string> retornarCampos(string linha);
};

void BancoDeDados::salvarDados(vector<string> listaDados, string nomeArquivo) {
    ofstream saida;

    saida.open(nomeArquivo, ios_base::out);

    if (saida.is_open())
    {
        for (string dado : listaDados)
        {
            saida << dado;
        }
        
        saida << ";";
        saida.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
}

vector<string> BancoDeDados::recuperarDados(vector<string> listaDados, string nomeArquivo) {
    ifstream entrada;

    entrada.open(nomeArquivo, ios_base::in);

    if (entrada.is_open())
    {
        string linha;
        while (entrada.eof() == false)
        {
            getline(entrada, linha);
            listaDados.push_back(linha);
        }

        entrada.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }

    return listaDados;
}

vector<string> BancoDeDados::tratarDados(vector<string> listaDados) {
    vector<string> listaCampos;
    vector<string> listaLinhas;
    string linha;
    string campo;

    for (string str : listaDados)
    {
        istringstream ss(str);

        while (getline(ss, linha, ';')) {
            listaLinhas.push_back(linha);
        }
    }
    

    for (string str : listaLinhas)
    {
        istringstream ss(str);

        while (getline(ss, campo, ',')) {
            listaCampos.push_back(campo);
        }
    }

    return listaCampos;
}

vector<string> BancoDeDados::retornarLinha(vector<string> listaDados) {
    vector<string> listaLinhas;
    string linha;

    for (string str : listaDados)
    {
        istringstream ss(str);

        while (getline(ss, linha, ';')) {
            listaLinhas.push_back(linha);
        }
    }

    return listaLinhas;
}

vector<string> BancoDeDados::retornarCampos(string linha) {
    vector<string> listaCampos;
    string campo;

    istringstream ss(linha);

    while (getline(ss, campo, ',')) {
        listaCampos.push_back(campo);
    }

    return listaCampos;
}

class Nota
{
    private:
        int valor;

    public:
        Nota(/* args */);
        Nota(int _valor);
        ~Nota();
        int getValor();
        void setValor(int _valor);
};

Nota::Nota(/* args */)
{
}

Nota::Nota(int _valor)
{
    valor = _valor;
}

Nota::~Nota()
{
}

int Nota::getValor()
{
    return valor;
}

void Nota::setValor(int _valor)
{
    valor = _valor;
}

class Aluno
{
    private:
        string nome;
        string email;
        vector<Nota> listaNotas;

    public:
        Aluno(/* args */);
        Aluno(string _nome, string _email);
        Aluno(string _nome, string _email, vector<Nota> _listaNotas);
        ~Aluno();
        string getNome();
        void setNome(string _nome);
        string getEmail();
        void setEmail(string _email);
        vector<Nota> getListaNotas();
        void setListaNotas(vector<Nota> _listaNotas);
        void salvarAluno(Aluno aluno);
        vector<Aluno> recuperarDadosAluno();
};

Aluno::Aluno(/* args */)
{
}

Aluno::Aluno(string _nome, string _email)
{
    nome = _nome;
    email = _email;
}

Aluno::Aluno(string _nome, string _email, vector<Nota> _listaNotas)
{
    nome = _nome;
    email = _email;
    listaNotas = _listaNotas;
}

Aluno::~Aluno()
{
}

string Aluno::getNome() {
    return nome;
}

void Aluno::setNome(string _nome) {
    nome = _nome;
}

string Aluno::getEmail() {
    return email;
}

void Aluno::setEmail(string _email) {
    email = _email;
}

vector<Nota> Aluno::getListaNotas() {
    return listaNotas;
}

void Aluno::setListaNotas(vector<Nota> _listaNotas) {
    listaNotas = _listaNotas;
}

void Aluno::salvarAluno(Aluno aluno) {
    string nomeArquivo = "aluno.txt";
    vector<string> listaDados;
    string dados;

    listaDados = BancoDeDados::recuperarDados(listaDados, nomeArquivo);

    dados += aluno.nome+","+aluno.email;

    for (Nota nota : aluno.getListaNotas())
    {
        if (nota.getValor() >= 0)
        {
            string valor = to_string(nota.getValor());
            dados += ","+valor;
        }
    }

    listaDados.push_back(dados);
    
    BancoDeDados::salvarDados(listaDados, nomeArquivo);
}

vector<Aluno> Aluno::recuperarDadosAluno() {
    string nomeArquivo = "aluno.txt";
    vector<string> listaDados;
    vector<string> listaLinhas;
    vector<string> listaCampos;
    vector<Aluno> listaAlunos;

    const int NOME = 0;
    const int EMAIL = 1;
    const int NOTA1 = 2;
    const int NOTA2 = 3;
    
    listaDados = BancoDeDados::recuperarDados(listaDados, nomeArquivo);

    for (string dado : listaDados)
    {
        listaLinhas = BancoDeDados::retornarLinha(listaDados);

        for (string linha : listaLinhas)
        {
            listaCampos = BancoDeDados::retornarCampos(linha);

            Aluno aluno;
            Nota nota1, nota2;
            vector<Nota> listaNotas;

            string sNota1 = isdigit(listaCampos[NOTA1][0]) ? listaCampos[NOTA1] : "0";
            string sNota2 = isdigit(listaCampos[NOTA2][0]) ? listaCampos[NOTA2] : "0";

            int iNota1 = stoi(sNota1);
            int iNota2 = stoi(sNota2);

            nota1.setValor(iNota1);
            nota2.setValor(iNota2);

            listaNotas.push_back(nota1);
            listaNotas.push_back(nota2);

            aluno.setNome(listaCampos[NOME]);
            aluno.setEmail(listaCampos[EMAIL]);
            aluno.setListaNotas(listaNotas);

            listaAlunos.push_back(aluno);
        }
    }

    return listaAlunos;
}

int cadastrarAluno();
void inserirAluno();
void imprimirAlunos(vector<Aluno> listaAlunos);
int listarAlunosCadastrados(vector<Aluno> listaAlunos);
void menu();
int sair();
void systemClear();
void systemPause();
void systemPauseAndClear();

int main(void) {
    menu();
    cout << endl;
    return 0;
}

void menu() {
    vector<Aluno> listaAlunos;
    Aluno aluno;
    int opcao;

    do
    {
        systemClear();
        cout << TRACO << endl;
        cout << "\t\t\t\tSGT - Sistema de Gerenciamento de Turmas" << endl;
        cout << TRACO << endl << endl;
        
        cout << "[ 1 ] Cadastrar alunos\n[ 2 ] Listar alunos" << endl;
        cout << "[ 0 ] Sair" << endl;
        cout << "\nSelecione uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
            case 1:
                cadastrarAluno();
                break;

            case 2:
                listaAlunos = aluno.recuperarDadosAluno();
                listarAlunosCadastrados(listaAlunos);
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

int cadastrarAluno() {
    char opcao;
    bool opcaoInvalida = false;

    do
    {
        do
        {
            systemClear();
            cout << TRACO << endl;
            cout << "\t\t\t\t\tCadastrar novo aluno" << endl;
            cout << TRACO << endl << endl;

            cout << "Deseja cadastrar um novo aluno (s/n)? ";
            cin >> opcao;

            if (opcao == 's' || opcao == 'S' || opcao == 'n' || opcao == 'N')
            {
                if (opcao == 's' || opcao == 'S')
                {
                    systemClear();
                    cout << TRACO << endl;
                    cout << "\t\t\t\t\tCadastrar novo aluno" << endl;
                    cout << TRACO << endl << endl;

                    inserirAluno();
                    cout << "\nAluno cadastrado com sucesso.\n";
                    systemPause();
                }

                opcaoInvalida = false;
            }
            else
            {
                opcaoInvalida = true;
            }
        } while (opcao == 's' || opcao == 'S');

        if (opcaoInvalida)
        {
            cout << "\nOpção inválida\n";
            opcaoInvalida = true;
            systemPause();
        }
    } while (opcaoInvalida);

    return 0;
}

void inserirAluno() {
    string nome, email;
    int nota1, nota2;
    vector<Nota> listaNotas;
    Nota novaNota1, novaNota2;
    Aluno aluno;

    cout << "Nome: ";
    //cin.ignore();
    cin.sync();
    getline(cin, nome);

    cout << endl;

    cout << "E-mail: ";
    cin >> email;

    cout << endl;

    cout << "Nota 1: ";
    cin >> nota1;

    cout << endl;

    cout << "Nota 2: ";
    cin >> nota2;

    aluno.setNome(nome);
    aluno.setEmail(email);

    novaNota1.setValor(nota1);
    novaNota2.setValor(nota2);

    listaNotas.push_back(novaNota1);
    listaNotas.push_back(novaNota2);

    aluno.setListaNotas(listaNotas);

    aluno.salvarAluno(aluno);
}

int listarAlunosCadastrados(vector<Aluno> listaAlunos) {
    systemClear();
    cout << TRACO << endl;
    cout << "\t\t\t\t\tLista de alunos cadastrados" << endl;
    cout << TRACO << endl << endl;

    if (!listaAlunos.empty())
    {
        imprimirAlunos(listaAlunos);
    }
    else
    {
        cout << "\nNenhum dado encontrado.\n";
    }

    systemPause();
    return 0;
}

void imprimirAlunos(vector<Aluno> listaAlunos) {
    cout << endl;
    cout << left << setw(20) << "Nome" << left << setw(30) << "E-mail" << left << setw(10) << "Nota 1" << left << setw(10) << "Nota 2" << endl;
    cout << TRACO << endl;

    for (Aluno aluno : listaAlunos)
    {
        cout << left << setw(20) << aluno.getNome() << left << setw(30) << aluno.getEmail(); 
        cout << right << setw(6) << aluno.getListaNotas()[0].getValor() << right << setw(10) << aluno.getListaNotas()[1].getValor() << endl;
    }
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