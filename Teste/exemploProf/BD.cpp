#include <iostream>
#include <fstream>
#include <sstream>
#include "BD.h"

using namespace std;

//----------------------------------------------------------------------
// Método responsável por salvar os dados em um arquivo
//---------------------------------------------------------------------
void bancodados::salvarDados(vector<string> dados, string arquivo)
    {
        ofstream arq_sai(arquivo, ios::out);
        if (arq_sai.is_open())
        {
            for (auto linha : dados)
            {
                arq_sai << linha << endl;
            }
            arq_sai.close();
        }
        else
        {
            cout << "Erro ao abrir arquivo para armazenamento!!!";
        }
    }

//---------------------------------------------------------------
// Método responsável por recuperar os dados de um arquivo
//---------------------------------------------------------------
vector<string> bancodados::recuperarDados(string arquivo)
    {
        vector<string> texto;
        string linha;
        ifstream arq_leitura(arquivo,ios::in);
        if (arq_leitura.is_open())
        {
            while (!arq_leitura.eof())
            {
                getline(arq_leitura,linha);
                if (linha != "")
                    texto.push_back(linha);


            }
            arq_leitura.close();
        }
        else{
            cout << "Erro ao abrir arquivo para recuperação" << endl;
        }
        return texto;
    }