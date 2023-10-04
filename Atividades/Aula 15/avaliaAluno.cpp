#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <random>

using namespace std;

#define TRACO "---------------------------------------------------------------------------------------------------"
#define MSG_ERRO_CADASTRO "Falha ao cadastrar "
#define MSG_SUCES_CADASTRO " cadasrado(a) com sucesso!"
#define MSG_N_LOCALIZADO "NÃO existem dados para serem exibidos."
#define MSG_OPCAO_INVALIDA "Opção inválida."
#define MSG_SUCES_NOTAS "Nota(s) lançada(s) com sucesso!"
#define PESO_PRATICA 1
#define PESO_TEORICA 2
#define MEDIA_APROVACAO 7
#define MAX_MOCK 12

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
void cabecalhoLancarNotas(vector<Aluno> &listaAlunos, int index);
void lancarNotas(vector<Aluno> &listaAlunos);
void calcularMediaAluno_old(vector<Aluno> &listaAlunos, int index);
void calcularMediaAluno(Aluno aluno);
float retornarMediaTurma(vector<Aluno> &listaAlunos);
void telaListarAlunosAprovadosOuReprovados(vector<Aluno> &listaAlunos, bool aprovados, bool reprovados);
void telaListarAlunosAcimaDaMedia(vector<Aluno> &listaAlunos);
void listarAlunos(vector<Aluno> &listaAlunos, bool aprovados, bool reprovados, float mediaTurma);
string gerarMatricula(int tamanhoListaAlunos);
int buscarAluno(vector<Aluno> &listaAlunos, string matricula);
void menu(vector<Aluno> &listaAlunos);
int menuContinuar(string msg);
int sair();
void systemClear();
void systemPause();
void systemPauseAndClear();
void mockInserirAlunos(vector<Aluno> &listaAlunos, int numeroAlunos);
// void mockLancarNotas(vector<Aluno> &listaAlunos);

int main(void) 
{
    vector<Aluno> listaAlunos;
    Aluno aluno;
    mockInserirAlunos(listaAlunos, 5);
    // mockLancarNotas(listaAlunos);
    menu(listaAlunos);
    cout << endl;
    return 0;
}

void menu(vector<Aluno> &listaAlunos) {
    systemClear();
    int opcao = 0;

    do
    {
        cout << TRACO << endl;
        cout << "\t\t\t\t\tAvalia alunos" << endl;
        cout << TRACO << endl << endl;

        cout << "[ 1 ] Cadastrar alunos\n";
        cout << "[ 2 ] Lançar notas\n";
        cout << "[ 3 ] Alunos aprovados\n";
        cout << "[ 4 ] Alunos reprovados\n";
        cout << "[ 5 ] Alunos acima da media\n";
        cout << "[ 0 ] Sair\n";

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

            case 0:
                sair();
                break;
            
            default:
                cout << MSG_OPCAO_INVALIDA << endl;
                systemPauseAndClear();
                break;
        }
    } while (opcao > 5 || opcao < 0);
}

void telaCadastrarAluno(vector<Aluno> &listaAlunos) {
    int tam = listaAlunos.size();
    Aluno novoAluno;
    int opcao;

    do
    {
        systemClear();

        cout << TRACO << endl;
        cout << "\t\t\t\t\tCadastro de alunos" << endl;
        cout << TRACO << endl << endl;

        opcao = menuContinuar("Deseja cadastrar um novo aluno?");

        if (opcao == 0)
        {
            menu(listaAlunos);
        }
        else if (opcao ==  1)
        {
            systemClear();

            cout << TRACO << endl;
            cout << "\t\t\t\t\tCadastro de alunos" << endl;
            cout << TRACO << endl << endl;

            novoAluno.matricula = gerarMatricula(tam);

            cout << "Nome: ";
            cin.ignore();
            getline(cin, novoAluno.nome);

            bool sucesso = cadastrarAlunos(listaAlunos, novoAluno);

            if (sucesso)
            {
                cout << "Aluno" << MSG_SUCES_CADASTRO << endl;
                systemPause();
            }
            else
            {
                cout << MSG_ERRO_CADASTRO << "aluno." << endl;
                systemPause();
            }
        }
        else
        {
            systemPauseAndClear();
        }
    } while (opcao != 0);
}

bool cadastrarAlunos(vector<Aluno> &listaAlunos, Aluno aluno) {
    if (aluno.matricula != "" && aluno.nome != "")
    {
        listaAlunos.push_back(aluno);
        return true;
    }

    return false;
}

void cabecalhoLancarNotas(vector<Aluno> &listaAlunos, int index) {
    systemClear();
    cout << TRACO << endl;
    cout << "\t\t\t\t\tLançamento de notas" << endl;
    cout << TRACO << endl << endl;

    cout << "Aluno: " << listaAlunos[index].nome << endl << endl;
}

void lancarNotas(vector<Aluno> &listaAlunos) {
    int tamanho = listaAlunos.size();
    int opcao;

    do
    {
        systemClear();

        cout << TRACO << endl;
        cout << "\t\t\t\t\tLançamento de notas" << endl;
        cout << TRACO << endl << endl;

        opcao = menuContinuar("Deseja lançar notas?");

        if (opcao == 0)
        {
            menu(listaAlunos);
        }
        else if (opcao ==  1)
        {
            for(int i = 0; i < tamanho; i++)
            {
                Prova prova = listaAlunos[i].prova;

                if (listaAlunos[i].matricula != "" && listaAlunos[i].nome != "")
                {
                    cabecalhoLancarNotas(listaAlunos, i);

                    cout << "Prova teórica 1\n\n";
                    cout << "Nota: ";
                    cin >> prova.notaTeorica1;

                    cabecalhoLancarNotas(listaAlunos, i);

                    cout << "Prova teórica 2\n\n";
                    cout << "Nota: ";
                    cin >> prova.notaTeorica2;

                    cabecalhoLancarNotas(listaAlunos, i);

                    cout << "Prova prática 1\n\n";
                    cout << "Nota: ";
                    cin >> prova.notaPratica1;

                    cabecalhoLancarNotas(listaAlunos, i);

                    cout << "Prova prática 2\n\n";
                    cout << "Nota: ";
                    cin >> prova.notaPratica2;

                    calcularMediaAluno_old(listaAlunos, i);
                    listaAlunos[i].situacao = listaAlunos[i].media >= MEDIA_APROVACAO ? "APROVADO" : "REPROVADO";

                    if (i == tamanho-1)
                    {
                        cout << endl << endl;
                        cout << MSG_SUCES_NOTAS << endl;
                        systemPauseAndClear();
                        menu(listaAlunos);
                    }
                }
            }    
        }
        else
        {
            systemPauseAndClear();
        } 
    } while (opcao != 0);
}

void calcularMediaAluno_old(vector<Aluno> &listaAlunos, int index) {
    float soma = 0;

    Aluno aluno = listaAlunos[index];
    Prova prova = aluno.prova;

    soma += (prova.notaPratica1 + prova.notaPratica2) * PESO_PRATICA;
    soma += (prova.notaTeorica1 + prova.notaTeorica2) * PESO_TEORICA;

    aluno.media = soma / 4;
}

void calcularMediaAluno(Aluno aluno) {
    float soma = 0;

    // Aluno aluno = listaAlunos[index];
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

    systemClear();

    cout << TRACO << endl;
    cout << "\t\t\t\t\tLista de alunos " << titulo << endl;
    cout << TRACO << endl;
    
    cout << "Matrícula\tNome\t\t\t\tPrática 1\tPrática 2\tTeórica 1\tTeórica 2\tMédia\tSituação" << endl;
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

        if ((aprovados && aluno.media >= MEDIA_APROVACAO) || (reprovados && aluno.media < MEDIA_APROVACAO) 
            || (aprovados && reprovados) || (mediaTurma >= 0 && aluno.media > mediaTurma))
        {
            cout << aluno.matricula << "\t\t" << aluno.nome << "\t\t\t";
            cout << fixed << setprecision(2);
            cout << prova.notaPratica1 << fixed << setprecision(2) << "\t";
            cout << fixed << setprecision(2);
            cout << prova.notaPratica2 << fixed << setprecision(2) << "\t"; 
            cout << fixed << setprecision(2);
            cout << prova.notaTeorica1 << fixed << setprecision(2) << "\t";
            cout << fixed << setprecision(2);
            cout << prova.notaTeorica2 << fixed << setprecision(2) << "\t";
            cout << fixed << setprecision(2);
            cout << aluno.media << fixed << setprecision(2);
            cout << aluno.situacao << endl;
        }
        else
        {
            cout << aluno.matricula << "\t\t" << aluno.nome << endl;
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

string gerarMatricula(int tamanhoListaAlunos) {
    string digito = "000";
    tamanhoListaAlunos += 1;
    digito = tamanhoListaAlunos > 9 ? "00" : digito;

    return "BA"+digito+to_string(tamanhoListaAlunos);      
}

int menuContinuar(string msg) {
    int opcao;

    cout << msg << endl;
    cout << " [ 1 ] Sim\t[ 0 ] Não\n\n";

    cout << "Selecione: ";
    cin >> opcao;

    if (opcao < 0 || opcao > 1)
    {
        cout << MSG_OPCAO_INVALIDA << endl;
        return -1;
    }

    return opcao;
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

void mockInserirAlunos(vector<Aluno> &listaAlunos, int numeroAlunos) {
    int tam = listaAlunos.size();
    int i = 0;

    Aluno novoAluno1;
    novoAluno1.matricula = gerarMatricula(tam);
    novoAluno1.nome = "Carlos Dias";
    // novoAluno1.prova.notaPratica1 = mockLancarNotas(listaAlunos);
    // novoAluno1.prova.notaPratica2 = mockLancarNotas(listaAlunos);
    // novoAluno1.prova.notaTeorica1 = mockLancarNotas(listaAlunos);
    // novoAluno1.prova.notaTeorica2 = mockLancarNotas(listaAlunos);
    if (i < numeroAlunos && i < MAX_MOCK)
    {
        listaAlunos.push_back(novoAluno1);
    }
    i++;

    Aluno novoAluno2;
    novoAluno2.matricula = gerarMatricula(tam);
    novoAluno2.nome = "Maria Candido";
    // novoAluno2.prova.notaPratica1 = mockLancarNotas(listaAlunos);
    // novoAluno2.prova.notaPratica2 = mockLancarNotas(listaAlunos);
    // novoAluno2.prova.notaTeorica1 = mockLancarNotas(listaAlunos);
    // novoAluno2.prova.notaTeorica2 = mockLancarNotas(listaAlunos);
    if (i < numeroAlunos && i < MAX_MOCK)
    {
        listaAlunos.push_back(novoAluno2);
    }
    i++;

    Aluno novoAluno3;
    novoAluno3.matricula = gerarMatricula(tam);
    novoAluno3.nome = "Fernanda Santos";
    // novoAluno3.prova.notaPratica1 = mockLancarNotas(listaAlunos);
    // novoAluno3.prova.notaPratica2 = mockLancarNotas(listaAlunos);
    // novoAluno3.prova.notaTeorica1 = mockLancarNotas(listaAlunos);
    // novoAluno3.prova.notaTeorica2 = mockLancarNotas(listaAlunos);
    if (i < numeroAlunos && i < MAX_MOCK)
    {
        listaAlunos.push_back(novoAluno3);
    }
    i++;

    Aluno novoAluno4;
    novoAluno4.matricula = gerarMatricula(tam);
    novoAluno4.nome = "Francisco Lima";
    // novoAluno4.prova.notaPratica1 = mockLancarNotas(listaAlunos);
    // novoAluno4.prova.notaPratica2 = mockLancarNotas(listaAlunos);
    // novoAluno4.prova.notaTeorica1 = mockLancarNotas(listaAlunos);
    // novoAluno4.prova.notaTeorica2 = mockLancarNotas(listaAlunos);
    if (i < numeroAlunos && i < MAX_MOCK)
    {
        listaAlunos.push_back(novoAluno4);
    }
    i++;

    Aluno novoAluno5;
    novoAluno5.matricula = gerarMatricula(tam);
    novoAluno5.nome = "João Brito";
    // novoAluno5.prova.notaPratica1 = mockLancarNotas(listaAlunos);
    // novoAluno5.prova.notaPratica2 = mockLancarNotas(listaAlunos);
    // novoAluno5.prova.notaTeorica1 = mockLancarNotas(listaAlunos);
    // novoAluno5.prova.notaTeorica2 = mockLancarNotas(listaAlunos);
    if (i < numeroAlunos && i < MAX_MOCK)
    {
        listaAlunos.push_back(novoAluno5);
    }
    i++;

    Aluno novoAluno6;
    novoAluno6.matricula = gerarMatricula(tam);
    novoAluno6.nome = "Pedro Cardoso";
    // novoAluno6.prova.notaPratica1 = mockLancarNotas(listaAlunos);
    // novoAluno6.prova.notaPratica2 = mockLancarNotas(listaAlunos);
    // novoAluno6.prova.notaTeorica1 = mockLancarNotas(listaAlunos);
    // novoAluno6.prova.notaTeorica2 = mockLancarNotas(listaAlunos);
    if (i < numeroAlunos && i < MAX_MOCK)
    {
        listaAlunos.push_back(novoAluno6);
    }
    i++;

    Aluno novoAluno7;
    novoAluno7.matricula = gerarMatricula(tam);
    novoAluno7.nome = "Luana Dias";
    // novoAluno7.prova.notaPratica1 = mockLancarNotas(listaAlunos);
    // novoAluno7.prova.notaPratica2 = mockLancarNotas(listaAlunos);
    // novoAluno7.prova.notaTeorica1 = mockLancarNotas(listaAlunos);
    // novoAluno7.prova.notaTeorica2 = mockLancarNotas(listaAlunos);
    if (i < numeroAlunos && i < MAX_MOCK)
    {
        listaAlunos.push_back(novoAluno7);
    }
    i++;

    Aluno novoAluno8;
    novoAluno8.matricula = gerarMatricula(tam);
    novoAluno8.nome = "Agatha Dias";
    // novoAluno8.prova.notaPratica1 = mockLancarNotas(listaAlunos);
    // novoAluno8.prova.notaPratica2 = mockLancarNotas(listaAlunos);
    // novoAluno8.prova.notaTeorica1 = mockLancarNotas(listaAlunos);
    // novoAluno8.prova.notaTeorica2 = mockLancarNotas(listaAlunos);
    if (i < numeroAlunos && i < MAX_MOCK)
    {
        listaAlunos.push_back(novoAluno8);
    }
    i++;

    Aluno novoAluno9;
    novoAluno9.matricula = gerarMatricula(tam);
    novoAluno9.nome = "Antônio Ferreira";
    // novoAluno9.prova.notaPratica1 = mockLancarNotas(listaAlunos);
    // novoAluno9.prova.notaPratica2 = mockLancarNotas(listaAlunos);
    // novoAluno9.prova.notaTeorica1 = mockLancarNotas(listaAlunos);
    // novoAluno9.prova.notaTeorica2 = mockLancarNotas(listaAlunos);
    if (i < numeroAlunos && i < MAX_MOCK)
    {
        listaAlunos.push_back(novoAluno9);
    }
    i++;

    Aluno novoAluno10;
    novoAluno10.matricula = gerarMatricula(tam);
    novoAluno10.nome = "Bruno Mezenga";
    // novoAluno10.prova.notaPratica1 = mockLancarNotas(listaAlunos);
    // novoAluno10.prova.notaPratica2 = mockLancarNotas(listaAlunos);
    // novoAluno10.prova.notaTeorica1 = mockLancarNotas(listaAlunos);
    // novoAluno10.prova.notaTeorica2 = mockLancarNotas(listaAlunos);
    if (i < numeroAlunos && i < MAX_MOCK)
    {
        listaAlunos.push_back(novoAluno10);
    }
    i++;

    Aluno novoAluno11;
    novoAluno11.matricula = gerarMatricula(tam);
    novoAluno11.nome = "Claudia Lopes";
    // novoAluno11.prova.notaPratica1 = mockLancarNotas(listaAlunos);
    // novoAluno11.prova.notaPratica2 = mockLancarNotas(listaAlunos);
    // novoAluno11.prova.notaTeorica1 = mockLancarNotas(listaAlunos);
    // novoAluno11.prova.notaTeorica2 = mockLancarNotas(listaAlunos);
    if (i < numeroAlunos && i < MAX_MOCK)
    {
        listaAlunos.push_back(novoAluno11);
    }
    i++;

    Aluno novoAluno12;
    novoAluno12.matricula = gerarMatricula(tam);
    novoAluno12.nome = "Aparecida da Silva";
    // novoAluno12.prova.notaPratica1 = mockLancarNotas(listaAlunos);
    // novoAluno12.prova.notaPratica2 = mockLancarNotas(listaAlunos);
    // novoAluno12.prova.notaTeorica1 = mockLancarNotas(listaAlunos);
    // novoAluno12.prova.notaTeorica2 = mockLancarNotas(listaAlunos);
    if (i < numeroAlunos && i < MAX_MOCK)
    {
        listaAlunos.push_back(novoAluno12);
    }
    i++;
}

// void mockLancarNotas(vector<Aluno> &listaAlunos) {
//     std::random_device rd;
//     std::mt19937 gen(rd());

//     std::uniform_int_distribution<int> dist(0, 10);
//     int numeroRandom = 0;

//     for (Aluno aluno : listaAlunos)
//     {   
//         Prova prova = aluno.prova;

//         numeroRandom = dist(gen);
//         prova.notaPratica1 = numeroRandom;

//         numeroRandom = dist(gen);
//         prova.notaPratica2 = numeroRandom;

//         numeroRandom = dist(gen);
//         prova.notaTeorica1 = numeroRandom;
        
//         numeroRandom = dist(gen);
//         prova.notaTeorica2 = numeroRandom;

//         calcularMediaAluno(aluno);

//         // cout << "teste media: " << aluno.media << endl;

//         string situacao = aluno.media >= MEDIA_APROVACAO ? "APROVADO" : "REPROVADO";
//         aluno.situacao = situacao;

//         // cout << "teste situacao: " << aluno.situacao << endl;
//         // systemPause();
//     }

    // for (Aluno aluno : listaAlunos)
    // {
    //     cout << "teste notas: " << aluno.prova.notaPratica1 << endl;
    //     cout << "teste notas: " << aluno.prova.notaPratica2 << endl;
    //     cout << "teste notas: " << aluno.prova.notaTeorica1 << endl;
    //     cout << "teste notas: " << aluno.prova.notaTeorica2 << endl;

    //     cout << "teste media: " << aluno.media << endl;
    //     cout << "teste situacao: " << aluno.situacao << endl;
    // }

    // systemPause();
// }