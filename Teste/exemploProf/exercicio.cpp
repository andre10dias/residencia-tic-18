/*---------------------------------------------------------------------------------------------

Implemente uma solu‡Æo em C++ para que os professores da Residˆncia gerenciem suas turmas.
Seu programa deve ser capaz de inserir o nome, email e duas notas (0 a 100) para cada discente. 
Seu programa deve permitir inserir, alterar ou excluir os dados.
Seu programa deve salvar e carregar os dados em arquivo(s).
Seu programa deve implementar as classes: Aluno e BancoDeDados.
-----------------------------------------------------------------------------------------------
*/

#include "BD.h"
#include "curso.h"
#include "interface.h"
#include "ctrl_turma.h"

using namespace std;

int main(void)
{
    
    Aluno aluno;
    Turma turma;
    int   opcao;

    
    vector<string> menu = {"1. Insere Aluno", 
                           "2. Excui Aluno",
                           "3. Altera Aluno",
                           "4. Mostra Alunos",
                           "5. Mostra Aprovados",
                           "6. Mostra Reprovados",
                           "7. Sair do Programa"};

    while(true)
    {
        monta_menu(menu, "Escolha uma op‡Æo: \n");
        opcao = obter_opcao(7);
        switch (opcao)
        {
            case 1: ctrl_turma::insere_aluno(turma);
                    break;
        //   case 2: ctrl_turma::exclui_aluno(turma);
        //           break;
        //   case 3: ctrl_turma::altera_aluno(turma);
        //           break;
            case 4: ctrl_turma::mostra_alunos(turma);
                    break;
            
            case 5: ctrl_turma::mostra_aprovados(turma, 60);
                    break;
            case 6: ctrl_turma::mostra_reprovados(turma, 60);
                    break;
                    
            case 7: exit(0);
        }
    }
    return 0;
}