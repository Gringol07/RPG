#ifndef ARENA_HPP
#define ARENA_HPP

#include "Personagem.hpp"

class Arena
{
private:
    int rodada;

public:
    void batalhar(Personagem lutador1, Personagem lutador2);
};

#endif