#include <iostream>
#include "../cabecalhos/Personagem.hpp"

Personagem::Personagem(std::string nome, int vida, int ataque, int defesa)
{
    this->nome = nome;
    this->vida = vida;
    this->ataque = ataque;
    this->defesa = defesa;
}

void Personagem::atacar()
{
    return;
}

bool Personagem::estaVivo()
{
    return vida > 0;
}

int Personagem::efetuarAcao()
{
    return ataque;
}

void Personagem::receberDano(int dano)
{
    vida -= dano;
}

void Personagem::mostrarStatus()
{
    std::cout << nome << " | Vida: " << vida
              << " | Ataque: " << ataque
              << " | Defesa: " << defesa << std::endl;
}
