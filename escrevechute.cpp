#include <iostream>
#include "letra_existe.hpp"
#include "escrevechute.hpp"
extern int numero_de_chutes;

void Forca:: escrevechute(std::map<char, bool>& chutou, std::array<char, 5>& chutes_errados, std::string& palavra_secreta){
    char chute;
    std::cout << "Escreva seu chute:";
    std::cin >> chute;
   chutou[chute] = true;
    if (letra_existe(chute, palavra_secreta))
    {
        std::cout << "Você Acertou! Seu chute está na palavra!" << std::endl;
    } else{
        std::cout << "Você Errou! Seu chute NAO está na palavra!" << std::endl;
        chutes_errados [numero_de_chutes] = chute;
        numero_de_chutes++;
    }
    std::cout << std::endl;
}