#include <iostream>
#include <vector>



void imprimechuteserrados(std::vector<char> chutes_errados){
    std::cout << "Chutes errados: ";
    for (char letra : chutes_errados)
    {
        std::cout << letra << " " ;
    }
    std::cout << std::endl;
}