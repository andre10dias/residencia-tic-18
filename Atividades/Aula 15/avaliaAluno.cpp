#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define TRACO "---------------------------------------------------------------------------------------------------"
#define MSG_ERRO_CADASTRO "Falha ao cadastrar "
#define MSG_SUCES_CADASTRO " cadasrado(a) com sucesso!"
#define MSG_N_LOCALIZADO "NÃO existem dados para serem exibidos"
#define PESO_PRATICA 1
#define PESO_TEORICA 2
#define MEDIA_APROVACAO 7

struct Prova
{
    float notaPratica1;
    float notaPratica2;
    float notaTeorica1;
    float notaTeorica2;
};

struct Aluno
{
    string matricula;
    string nome;
    Prova prova;
    float media;
    string situacao;
};

void telaCadastrarAluno(vector<Aluno> &listaAlunos);
bool cadastrarAlunos(vector<Aluno> &listaAlunos, Aluno aluno);
bool lancarNotas(vector<Aluno> &listaAlunos);
void calcularMediaAluno(vector<Aluno> &listaAlunos, int index);
float retornarMediaTurma(vector<Aluno> &listaAlunos);
void telaListarAlunosAprovadosOuReprovados(vector<Aluno> &listaAlunos, bool aprovados, bool reprovados);
void telaListarAlunosAcimaDaMedia(vector<Aluno> &listaAlunos);
void listarAlunos(vector<Aluno> &listaAlunos, bool aprovados, bool reprovados, float mediaTurma);
int buscarAluno(vector<Aluno> &listaAlunos, string matricula);
void menu(vector<Aluno> &listaAlunos);

int main(void) 
{
    vector<Aluno> listaAlunos;
    Aluno aluno;
    menu(listaAlunos);
    cout << endl;
    return 0;
}

void menu(vector<Aluno> &listaAlunos) {
    int opcao = 0;

    cout << TRACO << endl;
    cout << "\t\t\t\t\tAvalia alunos" << endl;
    cout << TRACO << endl;

    cout << "[ 1 ] Cadastrar alunos\n";
    cout << "[ 2 ] Lançar notas\n";
    cout << "[ 3 ] Alunos aprovados\n";
    cout << "[ 4 ] Alunos reprovados\n";
    cout << "[ 5 ] Alunos acima da media\n";

    cout << "\nSelecione uma opção: ";
    cin >> opcao;

    switch (opcao)
    {
        case 1:
            telaCadastrarAluno(listaAlunos);
            break;

        case 2:
            lancarNotas(listaAlunos);
            break;

        case 3:
            telaListarAlunosAprovadosOuReprovados(listaAlunos, true, false);
            break;

        case 4:
            telaListarAlunosAprovadosOuReprovados(listaAlunos, false, true);
            break;

        case 5:
            telaListarAlunosAcimaDaMedia(listaAlunos);
            break;
        
        default:
            break;
    }
}

void telaCadastrarAluno(vector<Aluno> &listaAlunos) {
    Aluno novoAluno;

    cout << TRACO << endl;
    cout << "\t\t\t\t\tCadastro de alunos" << endl;
    cout << TRACO << endl;

    cout << "Matricula: ";
    cin >> novoAluno.matricula;

    cout << "Nome: ";
    cin.ignore();
    getline(cin, novoAluno.nome);

    bool sucesso = cadastrarAlunos(listaAlunos, novoAluno);

    if (sucesso)
    {
        cout << "Aluno" << MSG_SUCES_CADASTRO << endl;
    }
    else
    {
        cout << MSG_ERRO_CADASTRO << "aluno." << endl;
    }
}

bool cadastrarAlunos(vector<Aluno> &listaAlunos, Aluno aluno) {
    if (aluno.matricula != "" && aluno.nome != "")
    {
        listaAlunos.push_back(aluno);
        return true;
    }

    return false;
}

bool lancarNotas(vector<Aluno> &listaAlunos) {
    int tamanho = listaAlunos.size();

    cout << TRACO << endl;
    cout << "\t\t\t\t\tLançamento de notas" << endl;
    cout << TRACO << endl;

    for(int i = 0; i < tamanho; i++)
    {
        Prova prova = listaAlunos[i].prova;

        if (listaAlunos[i].matricula != "" && listaAlunos[i].nome != "")
        {
            cout << "Informe a nota da prova teórica 1: ";
            cin >> prova.notaTeorica1;

            cout << endl;

            cout << "Informe a nota da prova teórica 2: ";
            cin >> prova.notaTeorica2;

            cout << endl;

            cout << "Informe a nota da prova prática 1: ";
            cin >> prova.notaPratica1;

            cout << endl;

            cout << "Informe a nota da prova prática 2: ";
            cin >> prova.notaPratica2;

            calcularMediaAluno(listaAlunos, i);
            listaAlunos[i].situacao = listaAlunos[i].media >= MEDIA_APROVACAO ? "APROVADO" : "REPROVADO";
            return true;
        }
    }
    
    return false;
}

void calcularMediaAluno(vector<Aluno> &listaAlunos, int index) {
    float soma = 0;

    Aluno aluno = listaAlunos[index];
    Prova prova = aluno.prova;

    soma += (prova.notaPratica1 + prova.notaPratica2) * PESO_PRATICA;
    soma += (prova.notaTeorica1 + prova.notaTeorica2) * PESO_TEORICA;

    aluno.media = soma / 4;
}

float retornarMediaTurma(vector<Aluno> &listaAlunos) {
    int divisor = listaAlunos.size();
    float soma = 0;

    for (Aluno aluno : listaAlunos)
    {
        soma += aluno.media;
    }

    return soma / divisor;
}

void telaListarAlunosAprovadosOuReprovados(vector<Aluno> &listaAlunos, bool aprovados, bool reprovados) {
    string titulo = aprovados ? "aprovados" : reprovados ? "reprovados" : aprovados && reprovados ? "aprovados e reprovados" : "";

    cout << TRACO << endl;
    cout << "\t\t\t\t\tLista de alunos " << titulo << endl;
    cout << TRACO << endl;
    
    listarAlunos(listaAlunos, aprovados, reprovados, -1);
}

void telaListarAlunosAcimaDaMedia(vector<Aluno> &listaAlunos) {
    cout << TRACO << endl;
    cout << "\t\t\t\t\tLista de alunos acima da média" << endl;
    cout << TRACO << endl;

    float media = retornarMediaTurma(listaAlunos);

    listarAlunos(listaAlunos, false, false, media);
}

void listarAlunos(vector<Aluno> &listaAlunos, bool aprovados, bool reprovados, float mediaTurma) {
    for (Aluno aluno : listaAlunos)
    {   
        Prova prova = aluno.prova;
        if ((aprovados && aluno.situacao == "APROVADO") || (reprovados && aluno.situacao == "REPROVADO") 
            || (aprovados && reprovados) || (mediaTurma >= 0 && aluno.media > mediaTurma))
        {
            cout << aluno.matricula << "\t" << aluno.nome << "\t" << prova.notaPratica1 << "\t" << prova.notaPratica2 << "\t"; 
            cout << prova.notaTeorica1 << "\t" << prova.notaTeorica2 << "\t" << endl;
        }
        else
        {
            cout << aluno.matricula << "\t" << aluno.nome << endl;
        }
    }
}

int buscarAluno(vector<Aluno> &listaAlunos, string matricula) {
    int tamanho = listaAlunos.size();

    for (int i = 0; i < tamanho; i++)
    {
        if (listaAlunos[i].matricula == matricula)
        {
            return i;
        }
        
    }
    
    return -1;
}