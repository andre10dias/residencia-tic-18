#include <iostream>
#include <string>

using namespace std;

class Livro
{
    private:
        string editora;
        string autor;
        string isbn;
        string dataPublicacao;

    public:
        livro();
        livro(string editora, string autor, string isbn, string dataPublicacao);
        ~livro();
};

livro::livro() {
    editora = "";
    autor = ""; 
    isbn = ""; 
    dataPublicacao = "";
}

livro::livro(string editora, string autor, string isbn, string dataPublicacao)
{
    editora = editora;
    autor = autor; 
    isbn = isbn;
    dataPublicacao = dataPublicacao;
}

livro::~livro()
{

}
