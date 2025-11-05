#include <iostream>
#include <string>

using namespace std;
void classes(){
class Personagem {
protected:
    string nome;
    int vida;
    int ataque;
    int defesa;

public:
    Personagem(string nome_personagem, int vida_personagem, int ataque_personagem, int defesa_personagem)
    : nome(nome_personagem), vida(vida_personagem), ataque(ataque_personagem),
    defesa(defesa_personagem) {}

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
}
