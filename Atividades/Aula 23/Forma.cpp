#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Forma
{
    private:
        /* data */

    public:
        Forma(/* args */);
        ~Forma();
        double calcularArea();
};

Forma::Forma(/* args */)
{
}

Forma::~Forma()
{
}

class Retangulo : public Forma
{
    private:
        double base, altura;

    public:
        Retangulo(double _base, double _altura);
        Retangulo(/* args */);
        ~Retangulo();
        double getBase();
        void setBase(double _base);
        double getAltura();
        void setAltura(double _altura);
        double calcularArea();
};

Retangulo::Retangulo(double _base, double _altura)
{
    base = _base;
    altura = _altura;
}

Retangulo::Retangulo(/* args */)
{
}

Retangulo::~Retangulo()
{
}

double Retangulo::getBase() {
    return base;
}

void Retangulo::setBase(double _base) {
    base = _base;
}

double Retangulo::getAltura() {
    return altura;
}

void Retangulo::setAltura(double _altura) {
    altura = _altura;
}

double Retangulo::calcularArea() {
    return base * altura;
}

class Circulo : public Forma
{
    private:
        double raio;

    public:
        const double PI = 3.14;
        Circulo(double raio);
        Circulo(/* args */);
        ~Circulo();
        double getRaio();
        void setRaio(double _raio);
        double calcularArea();
};

Circulo::Circulo(double _raio)
{
    raio = _raio;
}

Circulo::Circulo(/* args */)
{
}

Circulo::~Circulo()
{
}

double Circulo::getRaio() {
    return raio;
}

void Circulo::setRaio(double _raio) {
    raio = _raio;
}

double Circulo::calcularArea() {
    return PI * pow(raio, 2);
}

int main(void)
{
    Circulo circulo(8);
    Retangulo retangulo(12, 5);

    cout << "\nArea do circulo: ";
    cout << circulo.calcularArea() << endl;

    cout << "\nArea do retângulo: ";
    cout << retangulo.calcularArea() << endl;

    cout << endl;
    return 0;
}
