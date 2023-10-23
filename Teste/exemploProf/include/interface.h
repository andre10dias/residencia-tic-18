#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <vector>
#include <iostream>

void aguarde(void);
void monta_menu(std::vector<std::string> itens, std::string titulo);
int obter_opcao(int qtde_opcoes);

#endif