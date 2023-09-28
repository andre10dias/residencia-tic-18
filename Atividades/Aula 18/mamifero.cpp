#include <iostream>
#include <string>

using namespace std;

class mamifero
{
    private:
        string especie;
        float peso;
        string nomeCientifico;
        string habitat;
        bool ameacadoEstincao;

    public:
        mamifero();
        mamifero(string especie, float peso, string nomeCientifico, string habitat, bool ameacadoEstincao);
        ~mamifero();
};

mamifero::mamifero(string especie, float peso, string nomeCientifico, string habitat, bool ameacadoEstincao)
{
    especie = especie; 
    peso = peso; 
    nomeCientifico = nomeCientifico; 
    habitat = habitat; 
    ameacadoEstincao = ameacadoEstincao;
}

mamifero::mamifero()
{
    especie = ""; 
    peso = ""; 
    nomeCientifico = ""; 
    habitat = ""; 
    ameacadoEstincao = false;
}

mamifero::~mamifero()
{
}
