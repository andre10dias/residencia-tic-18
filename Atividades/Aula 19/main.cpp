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
        void setX(float _x);
        float getY();
        void setY(float _y);
};

Ponto::Ponto()
{
    x = 0;
    y = 0;
}

Ponto::Ponto(float _x, float _y)
{
    x = _x;
    y = _y;
}

Ponto::~Ponto()
{
}

float Ponto::getX()
{
    return x;
}

void Ponto::setX(float _x)
{
    x = _x;
}

float Ponto::getY()
{
    return y;
}

void Ponto::setY(float _y)
{
    y = _y;
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
        void setPonto(Ponto ponto);
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

void Poligono::setPonto(Ponto ponto)
{
    pontos.push_back(ponto);
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
        poli.setPonto(p);

        cout << "\nDeseja inserir mais pontos (s/b)? ";
        cin >> sn;
    } while (sn != 'n');
    
    vector<Ponto> pontos = poli.getPontos();
    cout << "\nAs coordenadas digitadas foram:" << endl;
    for (Ponto p : pontos)
    {
        cout << "( " << p.getX() << ", " << p.getY() << " )\t";
    }
    
    cout << endl;
    return 0;
}