#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <string>
using namespace std;

class Personagem
{
private:
    int vida;
    int ataque;
    int defesa;

public:
    string nome;
    Personagem(string nome, int vida, int ataque, int defesa);
    void atacar();
    bool estaVivo();
    int efetuarAcao();
    void receberDano(int dano);
    void mostrarStatus();
};

#endif
