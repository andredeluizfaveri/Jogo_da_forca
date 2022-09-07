#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>
#include <vector>
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

    string palavra_secreta;
    map<char, bool> chutou;
    vector<char> chutes_errados;

int main(){
    imprimecabecario();
    palavra_secreta = sorteia_palavra();
    while (nao_acertou(palavra_secreta, chutou) && chutes_errados.size() < 5 )
    {
        imprimechuteserrados(chutes_errados);
        imprimepalavrasacertadas(palavra_secreta, chutou);
        escrevechute(&chutou, &chutes_errados);
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