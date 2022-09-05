#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

    string palavra_secreta;
    map<char, bool> chutou;
    vector<char> chutes_errados;


bool letra_existe(char chute){
    
    for (char letra : palavra_secreta)
    {
        if (chute == letra)
        {
            return true;
        }
    }
    return false;
}

bool nao_acertou(){
    for (char letra : palavra_secreta)
    {
        if (!chutou[letra])
        {
            return true;
        }
    } 
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}
void imprimecabecario(){
    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl;
    cout << endl;
}
void imprimechuteserrados(){
    cout << "Chutes errados: ";
    for (char letra : chutes_errados)
    {
        cout << letra << " " ;
    }
    cout << endl;
}
void imprimepalavrasacertadas(){
    for (char letra : palavra_secreta){
        if (chutou[letra])
        {
            cout << letra << " ";
        }else{
            cout << "_ ";
        }
    }
    cout << endl << endl;
}
void escrevechute(){
    char chute;
    cout << "Escreva seu chute:";
    cin >> chute;
    chutou[chute] = true;
    if (letra_existe(chute))
    {
        cout << "Você Acertou! Seu chute está na palavra!" << endl;
    } else{
        cout << "Você Errou! Seu chute NAO está na palavra!" << endl;
        chutes_errados.push_back(chute);
    }
    cout << endl;
}
vector<string> le_arquivo(){
    ifstream arquivo;
    arquivo.open("palavras.txt");

    if (arquivo.is_open()){
    int quantidade_palavras;
    arquivo >> quantidade_palavras;
    vector<string> palavras_do_arquivo;

    for (int i = 0; i < quantidade_palavras; i++)
    {
        string palavra_lida;
        arquivo >> palavra_lida;
        palavras_do_arquivo.push_back(palavra_lida);
    }
    arquivo.close();
    return palavras_do_arquivo;
    }else{
        cout << "Não foi possível achar o banco de palavras." << endl;
        exit(0);
    }
}
void sorteia_palavra(){
    vector<string> palavras = le_arquivo();
    unsigned seed = time(0);
    srand(seed);
    int indice_sorteado = rand()%palavras.size();
    palavra_secreta = palavras[indice_sorteado];
}
void salva_arquivo(vector<string> novalista){
    ofstream arquivo;
    arquivo.open("palavras.txt");
    if (arquivo.is_open())
    {
        arquivo << novalista.size() << endl;
        for (string palavra : novalista)
        {
            arquivo << palavra << endl;
        }
        
        arquivo.close();
    }else{
        cout << "Não foi possível achar o banco de palavras." << endl;
        exit(0);
    }
    
}
void adiciona_palavra(){
    cout << "Escreva a palavra, usando letras MAIÚSCULAS: " << endl;
    string novapalavra;
    cin >> novapalavra;

    vector<string> lista_palavras = le_arquivo();
    lista_palavras.push_back(novapalavra);

    salva_arquivo(lista_palavras);
}
int main(){
    imprimecabecario();
    sorteia_palavra();
    le_arquivo();
    while (nao_acertou() && nao_enforcou() )
    {
        imprimechuteserrados();
        imprimepalavrasacertadas();
        escrevechute();
    }
    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    if (nao_acertou())
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