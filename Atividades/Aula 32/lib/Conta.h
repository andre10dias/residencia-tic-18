#ifndef CONTA_H

#define CONTA_H

#include "lib/Transacao.h"
#include <vector>

class Conta
{
    private:
        vector<Transacao> listaTransacoes;
        string numeroConta;
        string nomeCorrentista;
        double saldo;
        
    public:
        Conta(/* args */);
        Conta(vector<Transacao> _listaTransacoes, string numeroConta, string nomeCorrentista);
        ~Conta();

        vector<Transacao> getlistaTransacoes();
        void setListaTrasacoes(vector<Transacao> _listaTransacoes);
        string getNumeroConta();
        void setNumeroConta(string _numeroConta);
        string getNumeroCorrentista();
        void setNumeroCorrentista(string _numeroCorrentista);
        double getSaldo();
};

#endif