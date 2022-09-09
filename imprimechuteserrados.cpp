#include <iostream>
#include "imprimechuteserrados.hpp"

    void Forca :: imprimechuteserrados(const std::vector<char>& chutes_errados){
        std::cout << "Chutes errados: ";
        for (char letra : chutes_errados)
        {
            std::cout << letra << " " ;
        }
        std::cout << std::endl;
    }
