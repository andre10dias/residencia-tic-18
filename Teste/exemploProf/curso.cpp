#include "curso.h"
#include "BD.h"


//--------------------------------------------------------
// Implementação da Classe Aluno
//--------------------------------------------------------
Aluno::Aluno(void)
{
    nome  = "";
    email = "";
    nota1 = 0;
    nota2 = 0;
}

Aluno::Aluno(string _nome, string _email, int _nota1, int _nota2)
{
    this->nome  = _nome;
    this->email = _email;
    this->nota1 = _nota1;
    this->nota2 = _nota2;
}

void Aluno::set_nome(string _nome)
{
    this->nome = _nome;
}

string Aluno::get_nome(void)
{
    return this->nome;
}

void   Aluno::set_email(string _email)
{
    this->email = _email;
}

string Aluno::get_email(void)
{
    return this->email;
}

void   Aluno::setnota1(int _nota1)
{
    this->nota1 = _nota1;
}

int    Aluno::getnota1(void)
{
    return this->nota1;
}

void   Aluno::setnota2(int _nota2)
{
    this->nota2 = _nota2;
}

int    Aluno::getnota2(void)
{
    return this->nota2;
}

int  Aluno::media()
{
    return (this->nota1 + this->nota2) / 2;
}


//----------------------------------------------------------
//   Implementação da Classe Turma
//----------------------------------------------------------

Turma::Turma(void)
{
    this->recupera();
}

void Turma::insere_aluno(Aluno _aluno)
{
    this->Alunos.push_back(_aluno);
    this->salva();
}

//-------------------------------------------------------------------------------
//   Exclui um aluno de nome _nome da turma
//-------------------------------------------------------------------------------
int Turma::retira_aluno(string _nome)
{
    vector <Aluno>::iterator Iter;
    Iter = Alunos.begin();
    for (Aluno a : Alunos)
    {
        if (a.get_nome() == _nome)
        {
            Alunos.erase(Iter);
            this->salva();
            return 1; // exclusão bem sucedida
        }
        Iter++;
    }
    return 0;  // aluno não existe
}

void Turma::salva()
{   
    vector<string>  AlunosStr;
    int i = 0;
    for(Aluno a : this->Alunos)
    {
         
        AlunosStr.push_back(a.get_nome()            + "," + 
                            a.get_email()           + "," + 
                            to_string(a.getnota1()) + "," +
                            to_string(a.getnota2()));
                               
        i++;
    }
    bancodados::salvarDados(AlunosStr, "alunos.txt");
};

void Turma::recupera(void)
{
    vector<Aluno> Alunos;
    Aluno aluno;
    vector<string> alunosStr;
    alunosStr = bancodados::recuperarDados("alunos.txt");
    std::stringstream ss;
    string token;
    for(string str : alunosStr)
    {
         
         ss << str;
         getline(ss, token, ',');
         aluno.set_nome(token);
         getline(ss, token, ',');
         aluno.set_email(token);
         getline(ss, token, ',');
         aluno.setnota1(stoi(token));
         getline(ss, token, ',');
         aluno.setnota2(stoi(token));
         ss.clear();
         this->Alunos.push_back(aluno);
    }
}

int  Turma::qtde_alunos(void)
{
    return this->Alunos.size();
}

Aluno Turma::aluno_at(int n)
{
   return Alunos.at(n);
}

