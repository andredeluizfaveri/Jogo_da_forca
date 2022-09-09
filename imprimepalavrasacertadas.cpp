#include <iostream>
#include "imprimepalavrasacertadas.hpp"


void Forca:: imprimepalavrasacertadas(std::string& palavra_secreta,const std::map<char, bool>& chutou){
    for (char letra : palavra_secreta){
        if (chutou.find(letra) != chutou.end())
        {
            std::cout << letra << " ";
        }else{
            std::cout << "_ ";
        }
    }
    std::cout << std::endl << std::endl;
}