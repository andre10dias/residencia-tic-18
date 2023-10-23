#ifndef CURSO_H
#define CURSO_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//--------------------------------------------------------------------------
// Classe Base com os dados de aluno
//--------------------------------------------------------------------------
class Aluno
{
    private:
        string nome;
        string email;
        int    nota1;
        int    nota2;

    public:
         Aluno(string _nome, string _email, int _nota1, int _nota2);
         Aluno(void);
         
         void   set_nome(string _nome);
         string get_nome(void);
         void   set_email(string _email);
         string get_email(void);
         void   setnota1(int _nota1);
         int    getnota1(void);
         void   setnota2(int _nota1);
         int    getnota2(void);
         int    media();

};

//--------------------------------------------------------------------------
// Classe de Turma persistente, com uma lista de alunos
//--------------------------------------------------------------------------
class Turma 
{
    private:
        vector<Aluno> Alunos;
    public:
        
        Turma(void);
        void  insere_aluno(Aluno _aluno);
        int   retira_aluno(string _nome);
        int   qtde_alunos(void);
        Aluno aluno_at(int n);
        void  salva(void);
        void  recupera(void);
};


#endif