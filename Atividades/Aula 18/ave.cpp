#include <iostream>
#include <string>

class ave
{
    private:
        string especie;
        int peso;
        string nomeCientifico;
        string habitat;
        bool ameacadoEstincao;

    public:
        ave();
        ave(string especie, int peso, string nomeCientifico, string habitat, bool ameacadoEstincao);
        ~ave();
};

ave::ave(string especie, int peso, string nomeCientifico, string habitat, bool ameacadoEstincao)
{
    especie = especie; 
    peso = peso; 
    nomeCientifico = nomeCientifico; 
    habitat = habitat; 
    ameacadoEstincao = ameacadoEstincao;
}

ave::ave()
{
    especie = ""; 
    peso = ""; 
    nomeCientifico = ""; 
    habitat = ""; 
    ameacadoEstincao = false;
}

ave::~ave()
{
}
