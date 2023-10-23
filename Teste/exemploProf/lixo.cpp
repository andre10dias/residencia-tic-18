/*
#include <iostream>
class Forma {
public:
    //virtual void desenhar()       const = 0;  // M‚todo puro virtual
    virtual double calcularArea() const = 0;
    virtual void mostrarInfo()    const = 0;
    // ... outros m‚todos comuns
};


class Circulo : public Forma {
private:
    double raio;

public:
    Circulo(double r) : raio(r) {}

    // Implementa‡Æo do m‚todo para calcular a  rea do c¡rculo
    double calcularArea() const override {
        return 3.141592653589793 * raio * raio;
    }

    // Implementa‡Æo do m‚todo para mostrar informa‡äes espec¡ficas do c¡rculo
    void mostrarInfo() const override {
        std::cout << "C­rculo com raio: " << raio << std::endl;
    }
};
int main(void)
{
    Circulo circulo(10);
    circulo.mostrarInfo();
    std::cout << "Area do Circulo: " << circulo.calcularArea();
}
*/