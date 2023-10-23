/*
#include <iostream>

// Classe abstrata para representar uma forma geométrica
class Forma {
public:
    // Método virtual puro para calcular a área da forma
    virtual double calcularArea() const = 0;

    // Método virtual para exibir informações sobre a forma
    virtual void mostrarInfo() const {
        std::cout << "Forma genérica" << std::endl;
    }

    // Destrutor virtual
    virtual ~Forma() {
    }
};

// Classe derivada para representar um círculo
class Circulo : public Forma {
private:
    double raio;

public:
    Circulo(double r) : raio(r) {}

    // Implementação do método para calcular a área do círculo
    double calcularArea() const override {
        return 3.141592653589793 * raio * raio;
    }

    // Implementação do método para mostrar informações específicas do círculo
    void mostrarInfo() const override {
        std::cout << "Círculo com raio: " << raio << std::endl;
    }
};

// Classe derivada para representar um retângulo
class Retangulo : public Forma {
private:
    double largura;
    double altura;

public:
    Retangulo(double w, double h) : largura(w), altura(h) {}

    // Implementação do método para calcular a área do retângulo
    double calcularArea() const override {
        return largura * altura;
    }

    // Implementação do método para mostrar informações específicas do retângulo
    void mostrarInfo() const override {
        std::cout << "Retângulo com largura: " << largura << " e altura: " << altura << std::endl;
    }
};

int main() {
    // Exemplo de uso de classes abstratas
    Forma* forma1 = new Circulo(5.0);
    Forma* forma2 = new Retangulo(4.0, 6.0);

    // Chamada de métodos polimórficos
    forma1->mostrarInfo();
    std::cout << "Área: " << forma1->calcularArea() << std::endl;

    forma2->mostrarInfo();
    std::cout << "Área: " << forma2->calcularArea() << std::endl;

    // Libera a memória
    delete forma1;
    delete forma2;

    return 0;
    
}
*/