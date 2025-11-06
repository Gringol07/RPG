#ifndef ARENA_HPP
#define ARENA_HPP

#include "Personagem.hpp"

class Arena
{
private:
    int rodada;
    Personagem vencedor;
    void fazerPersonagemAtacar(Personagem &atacante, Personagem &alvo);
    bool tentarFugir(Personagem lutador);

public:
    Arena();
    void batalhar(Personagem &lutador1, Personagem &lutador2);
    void verificarVencedor();
};

#endif