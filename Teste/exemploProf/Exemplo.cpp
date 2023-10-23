/*
#include <iostream>

// Classe abstrata para representar uma forma geom�trica
class Forma {
public:
    // M�todo virtual puro para calcular a �rea da forma
    virtual double calcularArea() const = 0;

    // M�todo virtual para exibir informa��es sobre a forma
    virtual void mostrarInfo() const {
        std::cout << "Forma gen�rica" << std::endl;
    }

    // Destrutor virtual
    virtual ~Forma() {
    }
};

// Classe derivada para representar um c�rculo
class Circulo : public Forma {
private:
    double raio;

public:
    Circulo(double r) : raio(r) {}

    // Implementa��o do m�todo para calcular a �rea do c�rculo
    double calcularArea() const override {
        return 3.141592653589793 * raio * raio;
    }

    // Implementa��o do m�todo para mostrar informa��es espec�ficas do c�rculo
    void mostrarInfo() const override {
        std::cout << "C�rculo com raio: " << raio << std::endl;
    }
};

// Classe derivada para representar um ret�ngulo
class Retangulo : public Forma {
private:
    double largura;
    double altura;

public:
    Retangulo(double w, double h) : largura(w), altura(h) {}

    // Implementa��o do m�todo para calcular a �rea do ret�ngulo
    double calcularArea() const override {
        return largura * altura;
    }

    // Implementa��o do m�todo para mostrar informa��es espec�ficas do ret�ngulo
    void mostrarInfo() const override {
        std::cout << "Ret�ngulo com largura: " << largura << " e altura: " << altura << std::endl;
    }
};

int main() {
    // Exemplo de uso de classes abstratas
    Forma* forma1 = new Circulo(5.0);
    Forma* forma2 = new Retangulo(4.0, 6.0);

    // Chamada de m�todos polim�rficos
    forma1->mostrarInfo();
    std::cout << "�rea: " << forma1->calcularArea() << std::endl;

    forma2->mostrarInfo();
    std::cout << "�rea: " << forma2->calcularArea() << std::endl;

    // Libera a mem�ria
    delete forma1;
    delete forma2;

    return 0;
    
}
*/