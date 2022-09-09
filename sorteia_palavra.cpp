#include <ctime>
#include "le_arquivo.hpp"

std:: string sorteia_palavra(){
    std::vector<std::string> palavras = le_arquivo();
    unsigned seed = time(0);
    srand(seed);
    int indice_sorteado = rand()%palavras.size();
    return palavras[indice_sorteado];
}