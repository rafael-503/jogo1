#include "GameOver.h"
#include "../Gerenciadores/GerenciadorEstado.h"
using namespace Estados;

GameOver::GameOver() :Estado(), BotaoTentarNovamente("Tentar novamente", font), BotaoMenuPrincipal("Menu Principal", font), 
BotaoRanking("Ranking", font) {
    sf::Vector2u tamJanela(600.f, 400.f);
    BotaoTentarNovamente.setScale(1.5f, 1.5f);
    BotaoMenuPrincipal.setScale(1.5f, 1.5f);
    BotaoRanking.setScale(1.5f, 1.5f);

    sf::FloatRect tamBotaoTentarNovamente = BotaoTentarNovamente.getLocalBounds();
    BotaoTentarNovamente.setPosition(-(tamJanela.x / 2 - tamBotaoTentarNovamente.width - 120), 550);

    sf::FloatRect tamBotaoMenuPrincipal = BotaoMenuPrincipal.getLocalBounds();
    BotaoMenuPrincipal.setPosition(tamJanela.x / 2 + 500, 550);

    sf::FloatRect tamBotaoRanking = BotaoRanking.getLocalBounds();
    BotaoRanking.setPosition(-(tamJanela.x / 2 - tamBotaoRanking.width -700), 650);

    textoNome.setFont(font);
    textoNome.setCharacterSize(24);
    textoNome.setFillColor(sf::Color::Black);
    textoNome.setPosition(10, 10);
    inserindoNome = false;
}

GameOver::~GameOver() {

}

void GameOver::PrimeiroExecutar() {
	pGrafico->carregarFundo("The invasion/assets/fundo/fundo3.png");
    pGrafico->atualizarView(sf::Vector2f(600.0f, 400.0f));
}

void GameOver::executar() {
    sf::Vector2i posMouse = sf::Mouse::getPosition(*pGrafico->getWindow());
    sf::Vector2f fPosMouse((float)posMouse.x, (float)posMouse.y);

    sf::FloatRect rectTentarNovamente(BotaoTentarNovamente.getGlobalBounds()), rectMenuPrincipal(BotaoMenuPrincipal.getGlobalBounds()),
        rectRanking(BotaoRanking.getGlobalBounds()), corpoMouse(fPosMouse, sf::Vector2f(5.0f, 5.0f));

    if (rectTentarNovamente.intersects(corpoMouse)) {
        BotaoTentarNovamente.setFillColor(sf::Color::Red);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            //Gerenciadores::GerenciadorEstado::pGEstados->setEstadoAtual("NovoJogo");
            cout << "TENTAR NOVAMENTE" << endl;
        }
    }
    else {
        BotaoTentarNovamente.setFillColor(sf::Color::White);
    }

    if (rectMenuPrincipal.intersects(corpoMouse)) {
        BotaoMenuPrincipal.setFillColor(sf::Color::Red);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            Gerenciadores::GerenciadorEstado::pGEstados->setEstadoAtual("MenuPrincipal");
    }
    else {
        BotaoMenuPrincipal.setFillColor(sf::Color::White);
    }
    /*
    if (rectRanking.intersects(corpoMouse)) {
        BotaoRanking.setFillColor(sf::Color::Red);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            Gerenciadores::GerenciadorEstado::pGEstados->setEstadoAtual("Ranking");
        }
    }
    else {
        BotaoRanking.setFillColor(sf::Color::White);
    }*/

    if (rectRanking.intersects(corpoMouse)) {
        BotaoRanking.setFillColor(sf::Color::Red);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            inserindoNome = true;
        }
    }
    else {
        BotaoRanking.setFillColor(sf::Color::White);
    }

    if (inserindoNome) {
        sf::Event event;
        while (pGrafico->getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128 && event.text.unicode != '\b') {
                    nomeJogador += static_cast<char>(event.text.unicode);
                }
                else if (event.text.unicode == '\b' && !nomeJogador.empty()) {
                    nomeJogador.pop_back();
                }
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                inserindoNome = false;
                // Aqui você pode fazer algo com o nome do jogador, como salvá-lo no ranking
                std::cout << "Nome do jogador: " << nomeJogador << std::endl;
            }
        }
    }

    pGrafico->desenharElemento(BotaoTentarNovamente);
    pGrafico->desenharElemento(BotaoMenuPrincipal);
    pGrafico->desenharElemento(BotaoRanking);

    if (inserindoNome) {
        textoNome.setString("Digite seu nome: " + nomeJogador);
        pGrafico->desenharElemento(textoNome);
    }

	pGrafico->desenharElemento(BotaoTentarNovamente);
	pGrafico->desenharElemento(BotaoMenuPrincipal);
    pGrafico->desenharElemento(BotaoRanking);
}

void GameOver::TeclaPressionada(const sf::Keyboard::Key tecla) {

}
