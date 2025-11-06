#include <iostream>
#include "src/cabecalhos/Arena.hpp"
#include "src/cabecalhos/Personagem.hpp"
#include "windows.h"
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Arena arena = Arena();
    std::string falas[20] = {
        "Se você quiser jogar comigo, é melhor conhecer bem o jogo.",
        "Não confunda piedade com fraqueza.",
        "Não confunda piedade com fraqueza.",
        "Eles esperam que eu jogue limpo. Nós nem estamos jogando o mesmo jogo.",
        "Todo mundo morre, alguns só precisam de uma ajudinha.",
        "Precisão é a diferença entre um Açougueiro e um Cirurgião.",
        "Nunca subestime o poder de um bom insulto.",
        "Eu não sou muito homem, mas sou melhor do que a maioria.",
        "Você não precisa ser um atirador melhor, você só precisa disparar mais balas!",
        "Puta merda, lá vamos nós de novo.",
        "Regras são feitas para serem quebradas… como prédios! Ou pessoas.",
        "Você pode correr, mas não pode se esconder do inevitável.",
        "O silêncio antes da luta é a parte que eu mais gosto.",
        "Alguns chamam de destino, eu chamo de mira firme.",
        "Não é arrogância se você pode provar.",
        "Ganhar é bom, mas vencer humilhando é melhor ainda.",
        "O caos é a minha zona de conforto.",
        "O jogo só acaba quando eu digo.",
        "Às vezes, o truque é parecer louco o suficiente pra ninguém duvidar.",
        "Nunca subestime quem não tem nada a perder."};

    std::string falas2[20] = {
        "A guerra é onde os jovens e estúpidos são enganados pelos velhos e amargos para se matarem.",
        "Você acabou de chamar sua mãe.",
        "Tá pensando o quê? Rapadura é doce, mas não é mole, não!",
        "Tô na área, derrubou é pênalti.",
        "Você não larga do meu pé, parece chulé.",
        "Me erra, diabo.",
        "Você é grande, mas não é dois; eu sou pequeno, mas não sou metade!",
        "Minha mira é uma promessa, e promessas devem ser cumpridas.",
        "Alguns chamam de sorte, eu chamo de estatística aplicada.",
        "A dor ensina mais rápido que qualquer mestre.",
        "Entre o caos e a ordem, eu escolho vencer.",
        "Você pode ter poder, mas eu tenho propósito.",
        "Às vezes é preciso perder uma vida para salvar o jogo.",
        "Treine até que sua sombra te tema.",
        "A vitória não é o fim — é o convite para o próximo desafio.",
        "Que vença o que tiver mais coragem para continuar.",
        "Se correr, o bicho pega; se ficar, eu pego.",
        "No fim das contas, todo chefão cai do mesmo jeito.",
        "Não sou herói, só não gosto de perder.",
        "Pode vir com tudo, eu já tô acostumado com o impossível."};

    Personagem lutador1 = Personagem("Ahri", 200, 50, 70, falas);
    Personagem lutador2 = Personagem("Garen", 300, 70, 100, falas2);

    arena.batalhar(lutador1, lutador2);
}