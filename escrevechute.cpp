#include <iostream>
#include "letra_existe.hpp"
#include "escrevechute.hpp"

void Forca:: escrevechute(std::map<char, bool>& chutou, std::vector<char>& chutes_errados, std::string& palavra_secreta){
    char chute;
    std::cout << "Escreva seu chute:";
    std::cin >> chute;
   chutou[chute] = true;
    if (letra_existe(chute, palavra_secreta))
    {
        std::cout << "Você Acertou! Seu chute está na palavra!" << std::endl;
    } else{
        std::cout << "Você Errou! Seu chute NAO está na palavra!" << std::endl;
        chutes_errados.push_back(chute);
    }
    std::cout << std::endl;
}