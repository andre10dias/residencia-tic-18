#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ponto
{
    private:
        float x, y;

    public:
        Ponto(float x, float y);
        Ponto();
        ~Ponto();
        float getX();
        void setX(float x);
        float getY();
        void setY(float y);
};

Ponto::Ponto()
{
    x = 0;
    y = 0;
}

Ponto::Ponto(float x, float y)
{
    x = x;
    y = y;
}

Ponto::~Ponto()
{
}

float Ponto::getX()
{
    return x;
}

void Ponto::setX(float x)
{
    x = x;
}

float Ponto::getY()
{
    return y;
}

void Ponto::setY(float y)
{
    y = y;
}

class Poligono
{
    private:
        vector<Ponto> pontos;

    public:
        Poligono(vector<Ponto> pontos);
        Poligono();
        ~Poligono();
        vector<Ponto> getPontos();
        void setPontos(vector<Ponto> pontos);
};

Poligono::Poligono(vector<Ponto> pontos)
{
    pontos = pontos;
}

Poligono::Poligono()
{
}

Poligono::~Poligono()
{
}

vector<Ponto> Poligono::getPontos()
{
    return pontos;
}

void Poligono::setPontos(vector<Ponto> pontos)
{
    pontos = pontos;
}

int main() {
    Poligono poli;
    Ponto p;
    float x, y;

    cout << "Criando um poligono!" << endl;
    char sn;

    do
    {
        cout << "\nDigite as coordenadas do ponto: ";
        cin >> x >> y;
        
        p.setX(x);
        p.setY(y);
        poli.getPontos().push_back(p);

        cout << "\nDeseja inserir mais pontos (s/b)? ";
        cin >> sn;
    } while (sn != 'n');
    
    cout << "\nAs coordenadas digitadas foram:" << endl;
    for (Ponto p : poli.getPontos())
    {
        cout << "( " << p.getX() << ", " << p.getY() << " )\t";
    }
    
    cout << endl;
    return 0;
}