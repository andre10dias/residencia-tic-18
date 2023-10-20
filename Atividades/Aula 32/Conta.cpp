#include "lib/Conta.h"

Conta::Conta(/* args */)
{
}

Conta::Conta(vector<Transacao> _listaTransacoes, string _numeroConta, string _nomeCorrentista) {
    listaTransacoes = _listaTransacoes;
    numeroConta = _numeroConta;
    nomeCorrentista = _nomeCorrentista;
    saldo = 0;
}

Conta::~Conta()
{
}

vector<Transacao> Conta::getlistaTransacoes() {
    return listaTransacoes;
}

void Conta::setListaTrasacoes(vector<Transacao> _listaTransacoes) {
    listaTransacoes = _listaTransacoes;
}

string Conta::getNumeroConta() {
    return numeroConta;
}

void Conta::setNumeroConta(string _numeroConta) {
    numeroConta = _numeroConta;
}

string Conta::getNumeroCorrentista() {
    return nomeCorrentista;
}

void Conta::setNumeroCorrentista(string _nomeCorrentista) {
    nomeCorrentista = _nomeCorrentista;
}

double Conta::getSaldo() {
    return saldo;
}