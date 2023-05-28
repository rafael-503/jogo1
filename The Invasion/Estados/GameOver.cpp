#include "GameOver.h"
using namespace Estados;

GameOver::GameOver() {
	BotaoTentarNovamente.setString("Tentar Novamente");
	BotaoTentarNovamente.setFont(font);
	BotaoTentarNovamente.setCharacterSize(30);
	BotaoTentarNovamente.setFillColor(sf::Color::White);
	BotaoTentarNovamente.setPosition(0, 0);

	BotaoMenuPrincipal.setString("Menu Principal");
	BotaoMenuPrincipal.setFont(font);
	BotaoMenuPrincipal.setCharacterSize(30);
	BotaoMenuPrincipal.setFillColor(sf::Color::White);
	BotaoMenuPrincipal.setPosition(100, 200);
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
