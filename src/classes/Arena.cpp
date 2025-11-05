#include "../cabecalhos/Arena.hpp"
#include <iostream>

Arena::Arena()
{
    rodada = 1;
}

void Arena::batalhar(Personagem &lutador1, Personagem &lutador2)
{

    while (lutador1.estaVivo() && lutador2.estaVivo())
    {
        std::cout << rodada << std::endl;
        int opcaoLutador1 = lutador1.efetuarAcao();
        int opcaoLutador2 = lutador2.efetuarAcao();

        if (opcaoLutador1 > opcaoLutador2)
        {
            fazerPersonagemAtacar(lutador1, lutador2, opcaoLutador1 - opcaoLutador2);
        }
        else if (opcaoLutador2 > opcaoLutador1)
        {
            fazerPersonagemAtacar(lutador2, lutador1, opcaoLutador2 - opcaoLutador1);
        }

        rodada = rodada + 1;
    }

    lutador1.mostrarStatus();
    lutador2.mostrarStatus();
}

void Arena::fazerPersonagemAtacar(const Personagem &atacante, Personagem &alvo, int dano)
{
    alvo.receberDano(dano);

    std::cout << "O personagem " << atacante.nome << " causou " << dano << " de dano no personagem " << alvo.nome << std::endl;
}

void Arena::Fugir(Personagem lutador)
{
    // Implementation for Fugir is missing in the original file.
    // I will leave it empty for now.
}
