#include <iostream>
#include "src/cabecalhos/Arena.hpp"
#include "src/cabecalhos/Personagem.hpp"

int main()
{
    Arena arena = Arena();

    Personagem lutador1 = Personagem("Akali", 200, 50, 70);
    Personagem lutador2 = Personagem("Garen", 300, 70, 100);

    arena.batalhar(lutador1, lutador2);
}