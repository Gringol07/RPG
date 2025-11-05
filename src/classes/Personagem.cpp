#include <iostream>
#include "../cabecalhos/Personagem.hpp"
#include <random>

std::random_device Personagem::rd;
std::mt19937 Personagem::gen(Personagem::rd());
std::uniform_int_distribution<> Personagem::distrib(1,2);

Personagem::Personagem()
{
    this->nome = "";
    this->vida = 0;
    this->ataque = 0;
    this->defesa = 0;
}

Personagem::Personagem(std::string nome, int vida, int ataque, int defesa)
{
    this->nome = nome;
    this->vida = vida;
    this->ataque = ataque;
    this->defesa = defesa;
}

bool Personagem::estaVivo()
{
    return vida > 0;
}

Acao Personagem::efetuarAcao()
{
    int option;
    do
    {
        std::cout << "Jogador da vez: " << this->nome << std::endl;
        std::cout << "Escolha uma acao:\n1-Atacar\n2-Defender\n3-Fugir" << std::endl;
        std::cin >> option;
    } while (option > 3 || option < 1);

    if (option == 1)
    {
        return ATACAR;
    }
    else if (option == 2)
    {
        return DEFENDER;
    }
    else
    {
        int fugir_result = distrib(gen);
        if (fugir_result == 1)
        {
            std::cout << "Você conseguiu fugir!" << std::endl;
            return FUGIR;
        }
        else
        {
            std::cout << "Tentativa de fuga falhou! A luta continua" << std::endl;
            return ATACAR;
        }
    }
}

void Personagem::receberDano(int dano)
{
    if (dano > 0)
    {
        vida -= dano;
    }
}

void Personagem::mostrarStatus()
{
    std::cout << nome << " | Vida: " << vida
              << " | Ataque: " << ataque
              << " | Defesa: " << defesa << std::endl;
}

int Personagem::getAtaque()
{
    return ataque;
}

int Personagem::getDefesa()
{
    return defesa;
}

std::string Personagem::getNome()
{
    return nome;
}

