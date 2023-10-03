#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class bancoDeDados
{
private:
    /* data */
public:
    bancoDeDados(/* args */);
    ~bancoDeDados();

    static bool salvarDados(vector<string> dados);
    static vector<string> recuperarDados();
};

bool bancoDeDados::salvarDados(vector<string> dados) {
    ofstream saida;

    saida.open("bancoDeDados.txt", ios_base::out);

    if (saida.is_open())
    {
        for (string dado : dados)
        {
            saida << dado;
        }

        saida.close();
        return true;
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
    
    return false;
}

vector<string> bancoDeDados::recuperarDados() {
    vector<string> dados;
    ifstream entrada;

    entrada.open("bancoDeDados.txt", ios_base::in);

    if (entrada.is_open())
    {
        string linha;
        while (entrada.eof() == false)
        {
            getline(entrada, linha);
            dados.push_back(linha);
        }

        entrada.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }

    return dados;
}

int main(void) {
    string texto;
    vector<string> entrada;
    vector<string> saida;

    cout << "Entrada de dados: ";
    getline(cin, texto);

    entrada.push_back(texto);

    bool dadosSalvos = bancoDeDados::salvarDados(entrada);

    if (dadosSalvos)
    {
        cout << "Dados salvos com sucesso.";
    }
    else
    {
        cout << "Falha ao salvar os dados.";
    }
      
    cout << endl << endl;
    cout << "Dados recuperados: " << endl;

    if (dadosSalvos)
    {
        saida = bancoDeDados::recuperarDados();

        for (string s : saida)
        {
            cout << s << endl;
        }
        
    }

    cout << endl;
    return 0;
}
