#include <iostream>
#include <map>
#include <string>

extern std::map<char, bool> chutou;
extern std::string palavra_secreta;

void imprimepalavrasacertadas(){
    for (char letra : palavra_secreta){
        if (chutou[letra])
        {
            std::cout << letra << " ";
        }else{
            std::cout << "_ ";
        }
    }
    std::cout << std::endl << std::endl;
}