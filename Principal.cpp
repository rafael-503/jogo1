#include "Principal.h"

Principal::Principal(): 
 janela(new sf::RenderWindow(sf::VideoMode(800, 600), "Jogo")), 
 personagem(0,0, "Woodcutter.png"){
    executar();
}

Principal::~Principal(){
    if(janela)
    delete janela;
}

void Principal::executar(){
    while(janela->isOpen()){
        sf::Event evento;
        while(janela->pollEvent(evento)){
            if(evento.type == sf::Event::Closed)
                janela->close();
        }

        janela->clear();
        personagem.atualizar();
        personagem.desenhar(janela);
        janela->display();
    }
}