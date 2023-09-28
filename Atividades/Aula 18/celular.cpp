#include <iostream>
#include <string>

class celular
{
    private:
        string marca;
        string modelo;
        string imei;
        string cor;

    public:
        celular();
        celular(string marca, string modelo, string imei, string cor);
        ~celular();
};

celular::celular()
{
    marca = "";
    modelo = "";
    imei = "";
    cor = "";
}

celular::celular(string marca, string modelo, string imei, string cor)
{
    marca = marca;
    modelo = modelo;
    imei = imei;
    cor = cor;
}

celular::~celular()
{

}
