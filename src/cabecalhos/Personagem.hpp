#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP
#include <string>
#include <random>


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
    static std::random_device rd;
    static std::mt19937 gen;
    static std::uniform_int_distribution<> distrib;

public:
    Personagem();
    Personagem(std::string nome, int vida, int ataque, int defesa);
    bool estaVivo();
    Acao efetuarAcao();
    void receberDano(int dano);
    void mostrarStatus();
    int getAtaque();
    void setDefesa(int newDefesa);
    void setAtaque(int newAtaque);
    int getDefesa();
    std::string getNome();
};

#endif
