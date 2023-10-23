//--------------------------------------------------------
//  Utilitário para armazenar e recuperar dados de um arquivo texto.
//  
#include <vector>
#include <string>

class bancodados
{
    public:
        static void salvarDados(std::vector<std::string> dados, std::string arquivo);
        static std::vector<std::string> recuperarDados(std::string arquivo);
    
};
