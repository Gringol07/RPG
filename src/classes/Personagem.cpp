#include <iostream>
#include <string>

#include "Personagem.hpp"
using namespace std;
class Personagem {
public:
    string nome; // nome personagem
    int vida; // vida personagem
    int ataque; // ataque personagem
    int defesa; // defesa personagem

    Personagem(string n,int v,int a, int d){ // os atributos vão receber o valor passado nos parâmetros
    nome = n;
    vida = v;
    ataque = a;
    defesa = d;
    }  

    // Método para atacar outro personagem
    void atacar(Personagem &inimigo) {
        int dano = ataque - inimigo.defesa;

        if (dano < 0)
            dano = 0;

        inimigo.vida -= dano;

        if (inimigo.vida < 0)
            inimigo.vida = 0;

        cout << nome << " atacou " << inimigo.nome
             << " e causou " << dano << " de dano!" << endl;
    }

    // Verifica se o personagem ainda está vivo
    bool estaVivo() const {
        return vida > 0;
    }

    // Mostra o status do personagem
    void mostrarStatus() const {
        cout << nome << " | Vida: " << vida
             << " | Ataque: " << ataque
             << " | Defesa: " << defesa << endl;
    }

};

