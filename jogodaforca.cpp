#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>
#include <array>
#include <fstream>
#include "letra_existe.hpp"
#include "nao_acertou.hpp"
#include "imprimecabecario.hpp"
#include "imprimechuteserrados.hpp"
#include "imprimepalavrasacertadas.hpp"
#include "escrevechute.hpp"
#include "le_arquivo.hpp"
#include "sorteia_palavra.hpp"
#include "salva_arquivo.hpp"
#include "adiciona_palavra.hpp"

using namespace std;

    static string palavra_secreta;
    static map<char, bool> chutou;
    static array<char, 5> chutes_errados;
    int numero_de_chutes=0;

int main(){
    imprimecabecario();
    palavra_secreta = sorteia_palavra();
    while ( nao_acertou(palavra_secreta, chutou) && numero_de_chutes < 5 )
    {
        Forca::imprimechuteserrados(chutes_errados);
        Forca::imprimepalavrasacertadas(palavra_secreta, chutou);
        Forca::escrevechute(chutou, chutes_errados, palavra_secreta);
    }
    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    if (nao_acertou(palavra_secreta, chutou))
    {
        cout << "Você PERDEU! Tente novamente!";
    }else{
        char adicionar;
        cout << "Parabéns!! Você GANHOU!" << endl;
        cout << "Você gostaria de adicionar mais uma palavra? (S/N): " << endl;
        cin >> adicionar;
        if (adicionar == 'S')
        {
            adiciona_palavra();
        }else{
            exit(0);
        }
        cout << "Jogue novamente quando quiser XD" << endl;
    }
}