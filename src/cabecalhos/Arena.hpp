#ifndef ARENA_HPP
#define ARENA_HPP

#include "Personagem.hpp"

class Arena
{
private:
    int rodada;
    void fazerPersonagemAtacar(const Personagem &atacante, Personagem &alvo, int dano);
    void Fugir(Personagem lutador);

public:
    Arena();
    void batalhar(Personagem &lutador1, Personagem &lutador2);
};

#endif