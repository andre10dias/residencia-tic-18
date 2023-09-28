#include <iostream>
#include <string>

using namespace std;

class flor
{
    private:
        string especie;
        string nomeCientifico;
        bool ameacadoEstincao;

    public:
        flor();
        flor(string especie, string nomeCientifico, bool ameacadoEstincao);
        ~flor();
};

flor::flor(string especie, string nomeCientifico, bool ameacadoEstincao)
{
    especie = especie; 
    nomeCientifico = nomeCientifico; 
    ameacadoEstincao = ameacadoEstincao;
}

flor::flor()
{
    especie = ""; 
    nomeCientifico = ""; 
    ameacadoEstincao = false;
}

flor::~flor()
{
}
