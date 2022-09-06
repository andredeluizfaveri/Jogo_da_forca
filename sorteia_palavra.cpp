#include <ctime>
#include "le_arquivo.hpp"

extern std::string palavra_secreta;

void sorteia_palavra(){
    std::vector<std::string> palavras = le_arquivo();
    unsigned seed = time(0);
    srand(seed);
    int indice_sorteado = rand()%palavras.size();
    palavra_secreta = palavras[indice_sorteado];
}