#include <iostream>
#include "../cabecalhos/Personagem.hpp"
#include <random>
std::random_device rd; // Semente
std::mt19937 gen(rd()); // Motor de geração
std::uniform_int_distribution<> distrib(1,2); // Distribuição (números de 1 a 100)
int fugir = distrib(gen);

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
{   int acao;
    std:: cout << "Escolha uma ação: 1-Atacar\n2-Defender\n3-Fugir\n ";
    std:: cin >> acao;
    if (acao == 1){
        return ataque;
    }
    else if (acao == 2){
        return defesa;
    }
    else if(acao == 3){
        if (fugir == 1){
            std:: cout <<"Você conseguiu fugir!";
            return 0;
        }
        else {
            std:: cout << "Tentativa de fuga falhou! a luta continua";
            return -1;
        }
        return fugir;
    }
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
