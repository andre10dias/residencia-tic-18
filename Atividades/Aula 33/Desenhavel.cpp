#include <iostream>

using namespace std;

class Desenhavel
{
    private:
        /* data */
    public:
        Desenhavel(/* args */);
        ~Desenhavel();

        virtual void desenhar() = 0;
};

Desenhavel::Desenhavel(/* args */)
{
}

Desenhavel::~Desenhavel()
{
}

void Desenhavel::desenhar() {}

class Circulo : public Desenhavel
{
    private:
        /* data */
    public:
        Circulo(/* args */);
        ~Circulo();

        void desenhar() override;
};

Circulo::Circulo(/* args */)
{
}

Circulo::~Circulo()
{
}

void Circulo::desenhar() {
    cout << "Desenhanho um círculo..." << endl;
}

class Retangulo : public Desenhavel
{
    private:
        /* data */
    public:
        Retangulo(/* args */);
        ~Retangulo();

        void desenhar() override;
};

Retangulo::Retangulo(/* args */)
{
}

Retangulo::~Retangulo()
{
}

void Retangulo::desenhar() {
    cout << "Desenhanho um retângulo..." << endl;
}

class Triangulo : public Desenhavel
{
    private:
        /* data */
    public:
        Triangulo(/* args */);
        ~Triangulo();

        void desenhar() override;
};

Triangulo::Triangulo(/* args */)
{
}

Triangulo::~Triangulo()
{
}

void Triangulo::desenhar() {
    cout << "Desenhanho um triangulo..." << endl;
}

int main(void) {
    Circulo* circulo = new Circulo();
    Retangulo retangulo;
    Triangulo triangulo;

    circulo->desenhar();
    retangulo.desenhar();
    triangulo.desenhar();

    Desenhavel* item;
    item = circulo;


    item->desenhar();
    item = &retangulo;

    item->desenhar();
    item = &triangulo;

    item->desenhar();

    cout << endl;
    delete(circulo);
    circulo->desenhar(); //Não desenha o circulo (Falha de segmentação)
    return 0;
}