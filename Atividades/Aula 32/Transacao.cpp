#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transacao
{
    private:
        double valor;
        string descricao;

    public:
        Transacao(/* args */);
        Transacao(double valor, string descricao);
        ~Transacao();
};

Transacao::Transacao(/* args */)
{
}

Transacao::Transacao(double _valor, string _descricao)
{
    valor = _valor;
    descricao = _descricao;
}

Transacao::~Transacao()
{
}
