#ifndef TRANSACAO_H

#include "lib/Data.h"

#define TRANSACAO_H

class Transacao
{
    private:
        Data data;
        double valor;
        string descricao;

    public:
        Transacao(/* args */);
        Transacao(double valor, string descricao);
        ~Transacao();

        Data getData();
        void setData(Data _data);
        double getValor();
        void setValor(double _valor);
        string getDescricao();
        void setDescricao(string _descricao);
};

#endif