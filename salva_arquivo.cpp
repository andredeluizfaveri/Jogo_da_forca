#include <iostream>
#include <fstream>
#include "salva_arquivo.hpp"


void salva_arquivo(std::vector<std::string> novalista){
    std::ofstream arquivo;
    arquivo.open("palavras.txt");
    if (arquivo.is_open())
    {
        arquivo << novalista.size() << std::endl;
        for (std::string palavra : novalista)
        {
            arquivo << palavra << std::endl;
        }
        
        arquivo.close();
    }else{
        std::cout << "Não foi possível achar o banco de palavras." << std::endl;
        exit(0);
    }
    
}