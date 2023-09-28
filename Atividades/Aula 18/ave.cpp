#include <iostream>
#include <string>

using namespace std;

class ave
{
    private:
        string especie;
        float peso;
        string nomeCientifico;
        string habitat;
        bool ameacadoEstincao;

    public:
        ave();
        ave(string especie, float peso, string nomeCientifico, string habitat, bool ameacadoEstincao);
        ~ave();
};

ave::ave(string especie, float peso, string nomeCientifico, string habitat, bool ameacadoEstincao)
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
    peso = 0; 
    nomeCientifico = ""; 
    habitat = ""; 
    ameacadoEstincao = false;
}

ave::~ave()
{
}
