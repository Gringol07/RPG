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
    static std::random_device rd;
    static std::mt19937 gen;
    static std::uniform_int_distribution<> distrib;

    std::string nome;
    int vida;
    int ataque;
    int defesa;
    std::string frases[20];
    Acao acaoAtual;

public:
    Personagem();
    Personagem(std::string nome, int vida, int ataque, int defesa, const std::string frases[20]);
    bool estaVivo();
    Acao efetuarAcao();
    void receberDano(int dano);
    void mostrarStatus();
    int getAtaque();
    void setDefesa(int newDefesa);
    void setAtaque(int newAtaque);
    int getDefesa();
    std::string getNome();
    std::string getFraseAleatoria();
    Acao getAcaoAtual();
};

#endif
