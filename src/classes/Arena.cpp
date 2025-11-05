#include "../cabecalhos/Arena.hpp"
#include <iostream>
#include <random>

Arena::Arena()
{
    rodada = 1;
}

void Arena::batalhar(Personagem &lutador1, Personagem &lutador2)
{
    while (lutador1.estaVivo() && lutador2.estaVivo())
    {
        std::cout << "Rodada " << rodada << std::endl;

        Acao acaoLutador1 = lutador1.efetuarAcao();
        Acao acaoLutador2 = lutador2.efetuarAcao();

        if (acaoLutador1 == FUGIR)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(1, 2);
            if (distrib(gen) == 1)
            {
                std::cout << lutador1.getNome() << " conseguiu fugir!" << std::endl;
                vencedor = lutador2;
                break;
            }
            else
            {
                std::cout << lutador1.getNome() << " tentou fugir e falhou!" << std::endl;
            }
        }
        if (acaoLutador2 == FUGIR)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(1, 2);
            if (distrib(gen) == 1)
            {
                std::cout << lutador2.getNome() << " conseguiu fugir!" << std::endl;
                vencedor = lutador1;
                break;
            }
            else
            {
                std::cout << lutador2.getNome() << " tentou fugir e falhou!" << std::endl;
            }
        }
        
        int colisao = acaoLutador1 - acaoLutador2;

        fazerPersonagemAtacar(lutador1, lutador2);
        fazerPersonagemAtacar(lutador2, lutador1);

        rodada++;
        lutador1.mostrarStatus();
        lutador2.mostrarStatus();
        std::cout << std::endl;
    }

    if (lutador1.estaVivo() && !lutador2.estaVivo())
    {
        vencedor = lutador1;
    }
    else if (!lutador1.estaVivo() && lutador2.estaVivo())
    {
        vencedor = lutador2;
    }

    verificarVencedor();
}

void Arena::verificarVencedor()
{
    std::cout << "Vencedor: " << vencedor.getNome() << std::endl;
}

void Arena::fazerPersonagemAtacar(Personagem &atacante, Personagem &alvo)
{
    alvo.setDefesa(alvo.getDefesa() - atacante.getAtaque());
    int dano = atacante.getAtaque() - alvo.getDefesa();
    if(dano > 0){
        alvo.receberDano(dano);

    }

    std::cout << "O personagem " << atacante.getNome() << " causou " << dano << " de dano no personagem " << alvo.getNome() << std::endl;
}