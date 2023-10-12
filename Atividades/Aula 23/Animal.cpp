#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal
{
    private:
        string nome;
        int idade;

    public:
        Animal(/* args */);
        ~Animal();
        void fazerSom();
};

Animal::Animal(/* args */)
{
}

Animal::~Animal()
{
}

void Animal::fazerSom() 
{
}

class Cachorro : Animal
{
    private:
        /* args */
    public:
        Cachorro(/* args */);
        ~Cachorro();
        void fazerSom();
};

Cachorro::Cachorro(/* args */)
{
}

Cachorro::~Cachorro()
{
}

void Cachorro::fazerSom() 
{
    cout << "\nAu, au!\n";
}


int main(void)
{
    Cachorro cachorro;
    Animal animal;

    animal.fazerSom();
    cachorro.fazerSom();

    cout << endl;
    return 0;
}
