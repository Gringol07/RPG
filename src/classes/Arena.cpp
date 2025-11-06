#include "../cabecalhos/Arena.hpp"
#include <iostream>
#include <random>
#include "../cabecalhos/Personagem.hpp"

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

        // --- CASO 1: ambos tentam fugir ---
        if (acaoLutador1 == FUGIR && acaoLutador2 == FUGIR)
        {
            bool jogador1TentativaFugir = tentarFugir(lutador1);
            bool jogador2TentativaFugir = tentarFugir(lutador2);

            if (jogador1TentativaFugir && jogador2TentativaFugir)
            {
                std::cout << "Ambos conseguiram fugir! Empate." << std::endl;
                return;
            }
            else if (jogador1TentativaFugir)
            {
                std::cout << lutador1.getNome() << " conseguiu fugir!" << std::endl;
                vencedor = lutador2;
                break;
            }
            else if (jogador2TentativaFugir)
            {
                std::cout << lutador2.getNome() << " conseguiu fugir!" << std::endl;
                vencedor = lutador1;
                break;
            }
            else
            {
                std::cout << "Ambos tentaram fugir e falharam! Ninguém ataca nesta rodada." << std::endl;
                rodada++;
                continue;
            }
        }

        // --- CASO 2: apenas um tenta fugir ---
        else if (acaoLutador1 == FUGIR)
        {
            if (tentarFugir(lutador1))
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
        else if (acaoLutador2 == FUGIR)
        {
            if (tentarFugir(lutador2))
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

        // --- CASO 3: ataques ---
        if (acaoLutador1 != FUGIR)
        {
            std::cout << lutador1.getNome() << ": " << lutador1.getFraseAleatoria() << std::endl;
            fazerPersonagemAtacar(lutador1, lutador2);
        }

        if (acaoLutador2 != FUGIR)
        {
            std::cout << lutador2.getNome() << ": " << lutador2.getFraseAleatoria() << std::endl;
            fazerPersonagemAtacar(lutador2, lutador1);
        }

        rodada++;
        lutador1.mostrarStatus();
        lutador2.mostrarStatus();
        std::cout << std::endl;
    }

    if (lutador1.estaVivo() && !lutador2.estaVivo())
        vencedor = lutador1;
    else if (!lutador1.estaVivo() && lutador2.estaVivo())
        vencedor = lutador2;

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

    if (alvo.getAcaoAtual() == DEFENDER)
    {
        dano /= 2; // reduz dano pela metade
        std::cout << alvo.getNome() << " defendeu parte do ataque!" << std::endl;
    }

    if (dano > 0)
        alvo.receberDano(dano);
    else
    {
        dano = 0;
    }

    std::cout << "O personagem " << atacante.getNome() << " causou " << dano
              << " de dano no personagem " << alvo.getNome() << std::endl;
}

bool Arena::tentarFugir(Personagem lutador)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 2);

    return distrib(gen) == 1;
}