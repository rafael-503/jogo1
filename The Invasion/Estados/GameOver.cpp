#include "GameOver.h"
using namespace Estados;

GameOver::GameOver() :BotaoTentarNovamente("Tentar novamente", font), BotaoMenuPrincipal("Menu Principal", font) {
    sf::Vector2u tamJanela(600.f, 400.f);
    BotaoTentarNovamente.setScale(1.5f, 1.5f);
    BotaoMenuPrincipal.setScale(1.5f, 1.5f);

    sf::FloatRect tamBotaoTentarNovamente = BotaoTentarNovamente.getLocalBounds();
    BotaoTentarNovamente.setPosition(-(tamJanela.x / 2 - tamBotaoTentarNovamente.width + 600), 550);

    sf::FloatRect tamBotaoMenuPrincipal = BotaoMenuPrincipal.getLocalBounds();
    BotaoMenuPrincipal.setPosition(tamJanela.x / 2 - 250, 550);
}

GameOver::~GameOver() {

}

void GameOver::PrimeiroExecutar() {
	pGrafico->carregarFundo("The invasion/assets/fundo/fundo3.png");
}

void GameOver::executar() {
	pGrafico->desenharElemento(BotaoTentarNovamente);
	pGrafico->desenharElemento(BotaoMenuPrincipal);
}

void GameOver::TeclaPressionada(const sf::Keyboard::Key tecla) {

}
