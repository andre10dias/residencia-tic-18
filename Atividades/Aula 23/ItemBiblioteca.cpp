#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ItemBiblioteca
{
    private:
        string titulo;
        string autor;
        int numeroCopias;

    public:
        ItemBiblioteca(string _titulo, string _autor, int _numeroCopias);
        ItemBiblioteca(/* args */);
        ~ItemBiblioteca();
        string getTitulo();
        void setTitulo(string _titulo);
        string getAutor();
        void setAutor(string _autor);
        int getNumeroCopias();
        void setNumeroCopias(int _numeroCopias);
};

ItemBiblioteca::ItemBiblioteca(string _titulo, string _autor, int _numeroCopias)
{
    titulo = _titulo;
    autor = _autor;
    numeroCopias = _numeroCopias;
}

ItemBiblioteca::ItemBiblioteca(/* args */)
{
}

ItemBiblioteca::~ItemBiblioteca()
{
}

string ItemBiblioteca::getTitulo() {
    return titulo;
}

void ItemBiblioteca::setTitulo(string _titulo) {
    titulo = _titulo;
}

string ItemBiblioteca::getAutor() {
    return autor;
}

void ItemBiblioteca::setAutor(string _autor) {
    autor = _autor;
}

int ItemBiblioteca::getNumeroCopias() {
    return numeroCopias;
}

void ItemBiblioteca::setNumeroCopias(int _numeroCopias) {
    numeroCopias = _numeroCopias;
}

class Livro : public ItemBiblioteca
{
    private:
        int numeroPaginas;

    public:
        Livro(int _numeroPaginas);
        Livro(/* args */);
        ~Livro();
        int getNumeroPagianas();
        void getNumeroPagianas(int _numeroPagianas);
};

Livro::Livro(int _numeroPaginas)
{
    numeroPaginas = _numeroPaginas;
}

Livro::Livro(/* args */)
{
}

Livro::~Livro()
{
}

int Livro::getNumeroPagianas() {
    return numeroPaginas;
}

void Livro::getNumeroPagianas(int _numeroPagianas) {
    numeroPaginas = _numeroPagianas;
}

class Dvd : public ItemBiblioteca
{
    private:
        int duracao;

    public:
        Dvd(int _duracao);
        Dvd(/* args */);
        ~Dvd();
        int getDuracao();
        void setDuracao(int _duracao);
};

Dvd::Dvd(/* args */)
{
}

Dvd::Dvd(int _duracao)
{
    duracao = _duracao;
}

Dvd::~Dvd()
{
}

int  Dvd::getDuracao() {
    return duracao;
}

void Dvd::setDuracao(int _duracao) {
    duracao = _duracao;
}

int main(void)
{
    Livro livro(100);
    livro.setTitulo("Era uma vez");
    livro.setAutor("Carlos Dias");
    livro.setNumeroCopias(10000);

    Dvd dvd(1);
    dvd.setTitulo("Meu DVD");
    dvd.setAutor("Francisco Maria");
    dvd.setNumeroCopias(1000);

    cout << "\n\nLivro\n";
    cout << "Titulo: " << livro.getTitulo() << endl;
    cout << "Autor: " << livro.getAutor() << endl;
    cout << "Número de páginas: " << livro.getNumeroPagianas() << endl;
    cout << "Número de Cópias: " << livro.getNumeroCopias() << endl;

    cout << "\nDVD\n";
    cout << "Titulo: " << dvd.getTitulo() << endl;
    cout << "Autor: " << dvd.getAutor() << endl;
    cout << "Duração: " << dvd.getDuracao() << "h" << endl;
    cout << "Número de Cópias: " << dvd.getNumeroCopias() << endl;

    cout << endl;
    return 0;
}
