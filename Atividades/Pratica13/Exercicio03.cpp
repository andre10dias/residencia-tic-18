#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_PRODUTOS 300
#define TAM_CODIGO 13
#define MAX_NOME_PROD 20

struct Produto
{
    string codigo;
    string nome;
    double preco;
};

void cabecalhoInserirProduto();

int exibirListaProdutos(vector<Produto> &listaProdutos);

void inserirProduto(vector<Produto> &listaProdutos);
int excluirProduto(vector<Produto> &listaProdutos);
void listarProdutos(vector<Produto> &listaProdutos);
int consultarValorProdutoPorCodigo(vector<Produto> &listaProdutos);
void menu(vector<Produto> &listaProdutos);

bool ehCodigoExistente(vector<Produto> &listaProdutos, string codigo);
bool ehNomeExistente(vector<Produto> &listaProdutos, string _nome);
bool validarCodigoProduto(string codigo);
bool validarNomeProduto(string nome);

bool excluirProdutoPorCodigo(vector<Produto> &listaProdutos, string codigo);
int buscarProdutoPorCodigo(vector<Produto> &listaProdutos, string codigo);
string my_to_lower(string str);

void systemPauseAndClear();
void systemPause();
void systemClear();
int sair();

int main(void) {
    vector<Produto> listaProdutos;
    menu(listaProdutos);
    cout << endl;
    return 0;
}

void menu(vector<Produto> &listaProdutos) {
    int opcao;

    do
    {
        systemClear();
        cout << "-------------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\tSistema de consulta de preços" << endl;
        cout << "-------------------------------------------------------------------------------------------------" << endl << endl;
        
        cout << "[ 1 ] Inserir produto\n[ 2 ] Excluir produto" << endl;
        cout << "[ 3 ] Listar produtos\n[ 4 ] Consultar preço" << endl;
        cout << "[ 0 ] Sair" << endl;
        cout << "\nSelecione uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
            case 1:
                inserirProduto(listaProdutos);
                break;

            case 2:
                excluirProduto(listaProdutos);
                break;

            case 3:
                exibirListaProdutos(listaProdutos);
                break;

            case 4:
                consultarValorProdutoPorCodigo(listaProdutos);
                break;

            case 0:
                sair();
                break;
            
            default:
                cout << "\nOpção inválida!\n";
                systemPause();
                break;
        }
    } while (opcao != 0);
}

void cabecalhoInserirProduto() {
    cout << "-------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\tSistema de consulta de preços" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl << endl;
}

void inserirProduto(vector<Produto> &listaProdutos)
{
    Produto produto;

    systemClear();
    cabecalhoInserirProduto();

    if (listaProdutos.size() < MAX_PRODUTOS)
    {
        do
        {
            systemClear();
            cabecalhoInserirProduto();

            cout << "Código (13 caracteres): ";
            cin >> produto.codigo;

            if (!validarCodigoProduto(produto.codigo))
            {
                cout << "\nCódigo inválido\n";
                systemPause();
            }

            if (ehCodigoExistente(listaProdutos, produto.codigo))
            {
                cout << "\nCódigo já existente\n";
                systemPause();
            }
        } while (!validarCodigoProduto(produto.codigo) || ehCodigoExistente(listaProdutos, produto.codigo));

        do
        {
            systemClear();
            cabecalhoInserirProduto();

            cout << "Nome (máximo " << MAX_NOME_PROD << " caracteres): ";
            cin >> produto.nome;

            if (produto.nome.size() > MAX_NOME_PROD)
            {
                cout << "\nTamanho máximo excedido.\n";
                systemPause();
            }

            if (ehNomeExistente(listaProdutos, produto.nome))
            {
                cout << "\nNome já existente\n";
                systemPause();
            }
        } while (produto.nome.size() > MAX_NOME_PROD || ehNomeExistente(listaProdutos, produto.nome));

        systemClear();
        cabecalhoInserirProduto();
        cout << "Preço: ";
        cin >> produto.preco;

        listaProdutos.push_back(produto);
    }
    else
    {
        cout << "Limite de máximo produtos atingido." << endl;
        systemPause();
    }
}

int excluirProduto(vector<Produto> &listaProdutos) {
    int tam = listaProdutos.size();
    string codigo;

    systemClear();
    cout << "-------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\tExcluir produto" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl << endl;

    if (tam > 0)
    {
        listarProdutos(listaProdutos);

        cout << "\nCódigo do produto: ";
        cin >> codigo;

        bool excluir = excluirProdutoPorCodigo(listaProdutos, codigo);
        if (excluir)
        {
            cout << "\nProduto excluído com sucesso.\n";
        }
        else
        {
            cout << "\nProduto não localizado\n";
        }
    }
    else
    {
        cout << "\nNenhum dado encontrado.\n";
    }

    systemPause();
    return 0;
}

int consultarValorProdutoPorCodigo(vector<Produto> &listaProdutos) {
    string codigo;

    systemClear();
    cout << "-------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\tConsultar produto" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl << endl;

    cout << "Código do produto: ";
    cin >> codigo;

    int index = buscarProdutoPorCodigo(listaProdutos, codigo);
    if (index >= 0)
    {
        cout << "\nValor do produto: R$ " << listaProdutos[index].preco << endl;
    }
    else
    {
        cout << "\nProduto não localizado.\n";
    }

    systemPause();
    return 0;
}

int exibirListaProdutos(vector<Produto> &listaProdutos) {
    int tamanho = listaProdutos.size();
    string situacao;

    systemClear();
    cout << "-------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\tLista de produtos" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl << endl;

    if (tamanho > 0)
    {
        listarProdutos(listaProdutos);
    }
    else
    {
        cout << "\nNenhum dado encontrado.\n";
    }

    systemPauseAndClear();
    return 0;
}

void listarProdutos(vector<Produto> &listaProdutos) {
    cout << "Código\t\t\tNome\t\tPreço" << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    for (Produto produto : listaProdutos)
    {
        cout << produto.codigo << "\t\t" << produto.nome << "\t\t" << produto.preco << endl;
    }
}

bool excluirProdutoPorCodigo(vector<Produto> &listaProdutos, string codigo) {
    int index = buscarProdutoPorCodigo(listaProdutos, codigo);

    if (index >= 0)
    {
        listaProdutos.erase(listaProdutos.begin() + (index));
        return true;
    }
    
    return false;
}

int buscarProdutoPorCodigo(vector<Produto> &listaProdutos, string codigo) {
    int tam = listaProdutos.size();

    for (int i = 0; i < tam; i++)
    {
        if (listaProdutos[i].codigo == codigo)
        {
            return i;
        }
    }
    
    return -1;
}

bool ehCodigoExistente(vector<Produto> &listaProdutos, string codigo) {
    for (Produto produto : listaProdutos)
    {
        if (produto.codigo == codigo)
        {
            return true;
        }
    }
    
    return false;
}

bool ehNomeExistente(vector<Produto> &listaProdutos, string _nome) {
    string nome = my_to_lower(_nome);
    string nomeProd;

    for (Produto produto : listaProdutos)
    {
        nomeProd = my_to_lower(produto.nome);

        if (nomeProd == nome)
        {
            return true;
        }
    }
    
    return false;
}

bool validarNomeProduto(string nome) {
    int tam = nome.size();
    
    if (tam > MAX_NOME_PROD)
    {
        return false;
    }
    
    return true;
}

bool validarCodigoProduto(string codigo) {
    int tam = codigo.size();
    
    if (tam != TAM_CODIGO)
    {
        return false;
    }

    for (int i = 0; i < tam; i++)
    {
        if (!isdigit(codigo[i]))
        {
            return false;
        }
    }
    
    return true;
}

string my_to_lower(string str) {
    int tam = str.size();
    char c[tam];

    for (int i = 0; i < tam; i++)
    {
        c[i] = int(str[i]) + 32;
    }
    
    return c;
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