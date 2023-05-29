#include "Ranking.h"
#include "../Gerenciadores/GerenciadorEstado.h"
using namespace Estados;

Ranking::Ranking() :Estado(), BotaoMenuPrincipal("Menu Principal", font), vectorPontuacoes() {
    sf::Vector2u tamJanela(600.f, 400.f);
    BotaoMenuPrincipal.setScale(1.5f, 1.5f);


    sf::FloatRect tamBotaoMenuPrincipal = BotaoMenuPrincipal.getLocalBounds();
    BotaoMenuPrincipal.setPosition(tamJanela.x / 2 + 500, 700);
}

Ranking::~Ranking() {

}

void Ranking::PrimeiroExecutar() {
    pGrafico->carregarFundo("The invasion/assets/fundo/fundoRanking.png");
    pGrafico->atualizarView(sf::Vector2f(600.0f, 400.0f));
}

void Ranking::executar() {
    sf::Vector2i posMouse = sf::Mouse::getPosition(*pGrafico->getWindow());
    sf::Vector2f fPosMouse((float)posMouse.x, (float)posMouse.y);

    sf::FloatRect rectMenuPrincipal(BotaoMenuPrincipal.getGlobalBounds()),
        corpoMouse(fPosMouse, sf::Vector2f(5.0f, 5.0f));

    if (rectMenuPrincipal.intersects(corpoMouse)) {
        BotaoMenuPrincipal.setFillColor(sf::Color::Red);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            Gerenciadores::GerenciadorEstado::pGEstados->setEstadoAtual("MenuPrincipal");
    }
    else {
        BotaoMenuPrincipal.setFillColor(sf::Color::White);
    }

    pGrafico->desenharElemento(BotaoMenuPrincipal);
    imprimirPontuacao();
}

void Ranking::TeclaPressionada(const sf::Keyboard::Key tecla) {

}

void Ranking::guardarPontuacao(int num) {
    sf::Text* pAux = new sf::Text(std::to_string(num), font);
    vectorPontuacoes.push_back(pAux);
}

void Ranking::imprimirPontuacao() {
    for (int i = 0; i < vectorPontuacoes.size(); i++) {
		cout << vectorPontuacoes[i]->getString().toAnsiString() << endl;
	}
}