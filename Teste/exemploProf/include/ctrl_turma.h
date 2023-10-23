#ifndef CTRL_H
#define CTRL_H

#include "curso.h"

class ctrl_turma
{
    public:
        static void insere_aluno     (Turma turma);
        static void exclui_aluno     (Turma turma);
        static void altera_aluno     (Turma turma);
        static void mostra_alunos    (Turma turma);
        static void mostra_aprovados (Turma turma, int nota_corte);
        static void mostra_reprovados(Turma turma, int nota_corte);   
};
#endif