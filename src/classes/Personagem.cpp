#include <iostream>
#include "../cabecalhos/Personagem.hpp"
#include <random>

std::random_device Personagem::rd;
std::mt19937 Personagem::gen(Personagem::rd());
std::uniform_int_distribution<> Personagem::distrib(0, 0);

// Construtores
Personagem::Personagem()
{
    this->nome = "";
    this->vida = 0;
    this->ataque = 0;
    this->defesa = 0;
}

Personagem::Personagem(std::string nome, int vida, int ataque, int defesa, const std::string frases[20])
{
    this->nome = nome;
    this->vida = vida;
    this->ataque = ataque;
    this->defesa = defesa;

    for (int i = 0; i < 20; i++)
    {
        this->frases[i] = frases[i];
    }

    distrib = std::uniform_int_distribution<>(0, 19);
}

bool Personagem::estaVivo() { return vida > 0; }
int Personagem::getAtaque() { return ataque; }
int Personagem::getDefesa() { return defesa; }
void Personagem::setAtaque(int newAtaque) { this->ataque = newAtaque; }
Acao Personagem::getAcaoAtual() { return acaoAtual; }
std::string Personagem::getNome() { return nome; }

// Métodos de açoes
Acao Personagem::efetuarAcao()
{
    int escolha;
    do
    {
        std::cout << "Jogador da vez: " << this->nome << std::endl;
        std::cout << "Escolha uma ação:\n1-Atacar\n2-Defender\n3-Fugir" << std::endl;
        std::cin >> escolha;
    } while (escolha < 1 || escolha > 3);

    Acao acaoEscolhida;

    if (escolha == 1)
        acaoEscolhida = ATACAR;
    else if (escolha == 2)
        acaoEscolhida = DEFENDER;
    else
        acaoEscolhida = FUGIR;

    acaoAtual = acaoEscolhida;

    return acaoEscolhida;
}

void Personagem::receberDano(int dano)
{
    if (dano > vida)
    {
        vida = 0;
    }
    else if (dano > 0)
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
void Personagem::setDefesa(int newDefesa)
{
    if (newDefesa <= 0)
    {
        this->defesa = 0;
        return;
    }
    this->defesa = newDefesa;
}
std::string Personagem::getFraseAleatoria()
{
    int index = distrib(gen);
    return frases[index];
}