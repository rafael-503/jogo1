#include "../Gerenciadores/GerenciadorEstado.h"
#include "MenuPrincipal.h"
using namespace Estados;



MenuPrincipal::MenuPrincipal(): Estado(), BotaoJogar("JOGAR", font),  BotaoRanking("RANKING", font), BotaoSair("SAIR", font)
{

    pGrafico->carregarFundo("The invasion/assets/fundo/fundo0.png");
    //sf::Vector2u tamJanela = pGrafico->getSize();
    sf::Vector2u tamJanela (600.f, 400.f);
    BotaoJogar.setScale(1.5f, 1.5f);
    BotaoRanking.setScale(1.5f, 1.5f);
    BotaoSair.setScale(1.5f, 1.5f);


    //MUDAR EM BREVE
    sf::Vector2f tamBotao (BotaoJogar.getLocalBounds().width - BotaoJogar.getLocalBounds().top,
                            BotaoJogar.getLocalBounds().height - BotaoJogar.getLocalBounds().left);
    BotaoJogar.setPosition(tamJanela.x - tamBotao.x, tamJanela.y - tamBotao.y*6);
    BotaoRanking.setPosition(tamJanela.x - tamBotao.x - 40, tamJanela.y - tamBotao.y * 2);
    BotaoSair.setPosition(tamJanela.x - tamBotao.x + 12, tamJanela.y - tamBotao.y * -2);

}
MenuPrincipal::~MenuPrincipal(){

}

void MenuPrincipal::executar(){


    sf::Vector2i posMouse = sf::Mouse::getPosition(*pGrafico->getWindow());
    //cout << "X: " << posMouse.x << "   Y: " << posMouse.y << endl;
    sf::Vector2f fPosMouse((float) posMouse.x, (float) posMouse.y);

    sf::FloatRect rectJogar(BotaoJogar.getGlobalBounds()), rectRanking(BotaoRanking.getGlobalBounds()),
                  rectSair(BotaoSair.getGlobalBounds()), corpoMouse(fPosMouse, sf::Vector2f(5.0f, 5.0f));

    if(rectJogar.intersects(corpoMouse)){
        BotaoJogar.setFillColor(sf::Color::Red);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            Gerenciadores::GerenciadorEstado::pGEstados->setEstadoAtual("EstadoJogar");
    }
    else
        BotaoJogar.setFillColor(sf::Color::White);

    if(rectRanking.intersects(corpoMouse)){
        BotaoRanking.setFillColor(sf::Color::Red);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            Gerenciadores::GerenciadorEstado::pGEstados->setEstadoAtual("Ranking");
    }
    else
        BotaoRanking.setFillColor(sf::Color::White);

    if(rectSair.intersects(corpoMouse)){
        BotaoSair.setFillColor(sf::Color::Red);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            pGrafico->fecharJanela();
    }
    else
        BotaoSair.setFillColor(sf::Color::White);

    pGrafico->desenharElemento(BotaoJogar);
    pGrafico->desenharElemento(BotaoRanking);
    pGrafico->desenharElemento(BotaoSair);

}
void MenuPrincipal::PrimeiroExecutar(){
    pGrafico->carregarFundo("The invasion/assets/fundo/fundo0.png");
    pGrafico->atualizarView(sf::Vector2f(600.0f, 400.0f));

}
void MenuPrincipal::TeclaPressionada(const sf::Keyboard::Key tecla){

}

