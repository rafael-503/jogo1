#include "../Gerenciadores/GerenciadorEstado.h"
#include "MenuPrincipal.h"
using namespace Estados;



MenuPrincipal::MenuPrincipal(): Menu(), Tela_inicial(true), BotaoJogar("JOGAR", font),  BotaoRanking("RANKING", font), BotaoSair("SAIR", font),
 BotaoNovoJogo("NOVO JOGO", font), BotaoFase1_Jogador1("Fase 1: 1 Jogador", font), BotaoFase1_Jogador2("Fase 1: 2 Jogadores", font), BotaoFase2_Jogador1("Fase 2: 1 Jogador", font),
 BotaoFase2_Jogador2("Fase 2: 2 Jogadores", font)
{

    pGrafico->carregarFundo("The invasion/assets/fundo/fundo0.png");
    //sf::Vector2u tamJanela = pGrafico->getSize();
    sf::Vector2u tamJanela (600.f, 400.f);
    BotaoJogar.setScale(1.5f, 1.5f);
    BotaoRanking.setScale(1.5f, 1.5f);
    BotaoSair.setScale(1.5f, 1.5f);
    BotaoNovoJogo.setScale(1.5f, 1.5f);
    BotaoFase1_Jogador1.setScale(1.5f, 1.5f);
    BotaoFase1_Jogador2.setScale(1.5f, 1.5f);
    BotaoFase2_Jogador1.setScale(1.5f, 1.5f);
    BotaoFase2_Jogador2.setScale(1.5f, 1.5f);

    //MUDAR EM BREVE
    sf::Vector2f tam(pGrafico->getSize());
    BotaoNovoJogo.setPosition(tam.x / 2  -150, 200);
    BotaoJogar.setPosition(tam.x / 2 -100, 325);
    BotaoRanking.setPosition(tam.x / 2 -125, 450);
    BotaoSair.setPosition(tam.x / 2 -80, 575);
    BotaoFase1_Jogador1.setPosition(350, 200);
    BotaoFase1_Jogador2.setPosition(350, 325);
    BotaoFase2_Jogador1.setPosition(350, 450);
    BotaoFase2_Jogador2.setPosition(350, 575);


}
MenuPrincipal::~MenuPrincipal(){

}

void MenuPrincipal::executar(){

    sf::Vector2i posMouse = sf::Mouse::getPosition(*pGrafico->getWindow());
    sf::Vector2f fPosMouse((float) posMouse.x, (float) posMouse.y);

    if(Tela_inicial){

        sf::FloatRect rectJogar(BotaoJogar.getGlobalBounds()), rectRanking(BotaoRanking.getGlobalBounds()),
                      rectSair(BotaoSair.getGlobalBounds()), corpoMouse(fPosMouse, sf::Vector2f(5.0f, 5.0f)), rectNovoJogo(BotaoNovoJogo.getGlobalBounds());

        if(rectJogar.intersects(corpoMouse)){
            BotaoJogar.setFillColor(sf::Color::Red);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                Gerenciadores::GerenciadorEstado::pGEstados->RecuperareExecutarFase();
            }
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

        if(rectNovoJogo.intersects(corpoMouse)){
            BotaoNovoJogo.setFillColor(sf::Color::Red);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                Tela_inicial = false;
                sf::sleep(sf::seconds(1.0f / 8.0f));
            }
        }
        else
            BotaoNovoJogo.setFillColor(sf::Color::White);

        pGrafico->desenharElemento(BotaoJogar);
        pGrafico->desenharElemento(BotaoRanking);
        pGrafico->desenharElemento(BotaoSair);
        pGrafico->desenharElemento(BotaoNovoJogo);

    }
    else{
        sf::FloatRect corpoMouse(fPosMouse, sf::Vector2f(5.0f, 5.0f));

        sf::FloatRect rectFase1_Jogador1(BotaoFase1_Jogador1.getGlobalBounds());
        if(rectFase1_Jogador1.intersects(corpoMouse)){
            BotaoFase1_Jogador1.setFillColor(sf::Color::Red);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                Gerenciadores::GerenciadorEstado::pGEstados->crieEexecuteEstadoJogar(true, true);
                Tela_inicial = true;
            }
        }
        else
            BotaoFase1_Jogador1.setFillColor(sf::Color::White);



        sf::FloatRect rectFase1_Jogador2(BotaoFase1_Jogador2.getGlobalBounds());
        if(rectFase1_Jogador2.intersects(corpoMouse)){
            BotaoFase1_Jogador2.setFillColor(sf::Color::Red);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                Gerenciadores::GerenciadorEstado::pGEstados->crieEexecuteEstadoJogar(true, false);
                Tela_inicial = true;
            }
        }
        else
            BotaoFase1_Jogador2.setFillColor(sf::Color::White);



        sf::FloatRect rectFase2_Jogador1(BotaoFase2_Jogador1.getGlobalBounds());
        if(rectFase2_Jogador1.intersects(corpoMouse)){
            BotaoFase2_Jogador1.setFillColor(sf::Color::Red);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                Gerenciadores::GerenciadorEstado::pGEstados->crieEexecuteEstadoJogar(false, true);
                Tela_inicial = true;
            }
        }
        else
            BotaoFase2_Jogador1.setFillColor(sf::Color::White);



        sf::FloatRect rectFase2_Jogador2(BotaoFase2_Jogador2.getGlobalBounds());
        if(rectFase2_Jogador2.intersects(corpoMouse)){
            BotaoFase2_Jogador2.setFillColor(sf::Color::Red);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                Gerenciadores::GerenciadorEstado::pGEstados->crieEexecuteEstadoJogar(false, false);
                Tela_inicial = true;
            }
        }
        else
            BotaoFase2_Jogador2.setFillColor(sf::Color::White);

        pGrafico->desenharElemento(BotaoFase1_Jogador1);
        pGrafico->desenharElemento(BotaoFase1_Jogador2);
        pGrafico->desenharElemento(BotaoFase2_Jogador1);
        pGrafico->desenharElemento(BotaoFase2_Jogador2);

    }

}
void MenuPrincipal::PrimeiroExecutar(){
    pGrafico->carregarFundo("The invasion/assets/fundo/fundo0.png");
    pGrafico->atualizarView(sf::Vector2f(600.0f, 400.0f));

}
void MenuPrincipal::TeclaPressionada(const sf::Keyboard::Key tecla){

}

