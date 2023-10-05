#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

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
        void salvarNotas(vector<Nota> listaNotas);
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
    ofstream saida;

    saida.open("aluno.txt", ios_base::out);

    if (saida.is_open())
    {
        saida << "nome:"+aluno.nome+","+"email:"+aluno.email+"\n";
        saida.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
}

void Aluno::salvarNotas(vector<Nota> listaNotas) {
    ofstream saida;

    saida.open("aluno.txt", ios_base::out);

    if (saida.is_open())
    {
        for (Nota nota : listaNotas)
        {
            saida << "valor:"+to_string(nota.getValor())+"\n";
        }

        saida.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
}

int main(void) {
    Aluno aluno;
    Nota nota;
    vector<Nota> listaNotas;

    aluno = cadastrarAluno();
    Aluno::salvarAluno(aluno);

    cout << endl;
    return 0;
}

Aluno cadastrarAluno() {
    string nome, email;

    cout << "\nCadastrar novo aluno\n";
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);

    cout << endl;

    cout << "E-mail: ";
    cin >> email;

    return Aluno(nome, email);
}

//Em andamento
