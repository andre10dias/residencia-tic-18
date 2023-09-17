#include <iostream>
#include <string.h>
#include <list>

using namespace std;

#define MAX 10

typedef struct  {
    string nome;
    double valor;
} Produto;

typedef struct  {
    Produto listaProdutos[MAX];
} Estoque;

Produto novoProduto(string nome, double valor) {
    Produto produto;
    produto.nome = nome;
    produto.valor = valor;

    return produto;
}

void adicionaProduto(Produto produto[], Estoque estoque) {
    for (int i = 0; i < MAX; i++)
    {
        estoque.listaProdutos[i] = produto[i];
    }
}

double retornaValorTotalEstoque(Estoque estoque) {
    double valorTotal = 0;
    
    for (int i = 0; i < MAX; i++)
    {
        valorTotal += estoque.listaProdutos[i].valor;
    }
    
    return valorTotal;
}

string listarProdutos(Estoque estoque) {
    for (int i = 0; i < MAX; i++)
    {
        cout << "Produtos: \n";
        cout << "nome: " << estoque.listaProdutos[i].nome << endl;
        cout << "valor: " << estoque.listaProdutos[i].valor << endl << endl;
    }
    
}

int main(void) {
    Estoque estoque;
    Produto vetProdutos[MAX];
    double valor;

    valor = 2780.1;
    Produto produto1 = novoProduto("Notebook", valor);
    vetProdutos[0] = produto1;

    valor = 1200;
    Produto produto2 = novoProduto("Smartfone", valor);
    vetProdutos[1] = produto2;

    valor = 700;
    Produto produto3 = novoProduto("Monitor", valor);
    vetProdutos[2] = produto3;

    adicionaProduto(vetProdutos, estoque);

    listarProdutos(estoque);

    cout << endl;
    return 0;
}