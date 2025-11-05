#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <string>

enum Acao
{
    ATACAR,
    DEFENDER,
    FUGIR
};

class Personagem
{
private:
    std::string nome;
    int vida;
    int ataque;
    int defesa;

public:
    Personagem();
    Personagem(std::string nome, int vida, int ataque, int defesa);
    bool estaVivo();
    Acao efetuarAcao();
    void receberDano(int dano);
    void mostrarStatus();
    int getAtaque();
    int getDefesa();
    std::string getNome();
};

#endif
