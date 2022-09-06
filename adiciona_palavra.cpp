#include <iostream>
#include "salva_arquivo.hpp"
#include "le_arquivo.hpp"


void adiciona_palavra(){
    std::cout << "Escreva a palavra, usando letras MAIÚSCULAS: " << std::endl;
    std::string novapalavra;
    std::cin >> novapalavra;

    std::vector<std::string> lista_palavras = le_arquivo();
    lista_palavras.push_back(novapalavra);

    salva_arquivo(lista_palavras);
}