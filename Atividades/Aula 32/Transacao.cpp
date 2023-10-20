#include "lib/Transacao.h"

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

Data Transacao::getData() {
    return data;
}

void Transacao::setData(Data _data) {
    data = _data;
}

double Transacao::getValor() {
    return valor;
}

void Transacao::setValor(double _valor) {
    valor = _valor;
}

string Transacao::getDescricao() {
    return descricao;
}

void Transacao::setDescricao(string _descricao) {
    descricao = _descricao;
}