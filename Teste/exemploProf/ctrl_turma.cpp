#include "ctrl_turma.h"
#include "interface.h"




void ctrl_turma::insere_aluno(Turma turma)
{   
    Aluno aluno;
    string nome;
    string email;
    int n1, n2;

    cout << endl << "Digite o nome do aluno: "; cin >> nome;
    cout << endl << "Digite o e-mail: ";        cin >> email;
    cout << endl << "Digite a nota 1: ";        cin >> n1;
    cout << endl << "Digite a nota 2: ";        cin >> n2;
    
    aluno.set_nome(nome);
    aluno.set_email(email);
    aluno.setnota1(n1);
    aluno.setnota2(n2);
    turma.insere_aluno(aluno);
    aguarde();
}


void ctrl_turma::mostra_alunos(Turma turma)
{
    Aluno aluno;
    int i = 0,qtde;
    qtde  = turma.qtde_alunos();

    cout << endl <<        "Relat¢rio de Alunos" << endl;
    cout << "----------------------------------------------- ---" << endl;
    while (i < qtde)
    {
        aluno = turma.aluno_at(i);
        cout << aluno.get_nome() << "  " << aluno.get_email() << "  " << aluno.getnota1() << "  " << aluno.getnota2() << endl;
        i++;
    }
    aguarde();
}

void ctrl_turma::mostra_aprovados (Turma turma, int nota_corte)
{
    Aluno aluno;
    cout << "     Alunos Aprovados " << endl;
    cout << "-------------------------------------------------------" << endl;
    for(int i = 0; i < turma.qtde_alunos(); i++)
    {
        aluno = turma.aluno_at(i);
        if (aluno.media() >= nota_corte)
        {
            cout << aluno.get_nome() << "\t\t\t" << "m‚dia: " << aluno.media() << "\t\t" << "  Aprovado" << endl;
        }
    }
}

void ctrl_turma::mostra_reprovados(Turma turma, int nota_corte)
{
    Aluno aluno;
    cout << "     Alunos Reprovados " << endl;
    cout << "-------------------------------------------------------" << endl;
    for(int i = 0; i < turma.qtde_alunos(); i++)
    {
        aluno = turma.aluno_at(i);
        if (aluno.media() < nota_corte)
        {
            cout << aluno.get_nome() << "\t\t\t" << "m‚dia: " << aluno.media() << "\t\t" << "  Reprovado" << endl;
        }
    }
}
