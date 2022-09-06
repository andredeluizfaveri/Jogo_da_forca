#include <iostream>
#include <vector>
#include "letra_existe.hpp"
#include<map>


extern std::map<char, bool> chutou;
extern std::vector<char> chutes_errados;

void escrevechute(){
    char chute;
    std::cout << "Escreva seu chute:";
    std::cin >> chute;
    chutou[chute] = true;
    if (letra_existe(chute))
    {
        std::cout << "Você Acertou! Seu chute está na palavra!" << std::endl;
    } else{
        std::cout << "Você Errou! Seu chute NAO está na palavra!" << std::endl;
        chutes_errados.push_back(chute);
    }
    std::cout << std::endl;
}