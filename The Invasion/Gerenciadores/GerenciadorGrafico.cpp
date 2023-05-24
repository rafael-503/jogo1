#include "../Gerenciadores/GerenciadorGrafico.h"
#define TAM_X 1200.0f
#define TAM_Y 800.0f
using namespace Gerenciadores;

GerenciadorGrafico* GerenciadorGrafico::pGrafico = NULL;
GerenciadorGrafico::GerenciadorGrafico() : window(new sf::RenderWindow(sf::VideoMode(TAM_X, TAM_Y), "The Invasion")),
    view(sf::FloatRect(0.0f, 0.0f, TAM_X, TAM_Y))
{
	if (window == NULL)
		std::cout << "Erro ao criar a janela" << std::endl;
    window->setView(view);
}

GerenciadorGrafico::~GerenciadorGrafico(){
	if (window){
		delete window;
		window = NULL;
	}
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico(){
	if(pGrafico == NULL)
		pGrafico = new GerenciadorGrafico();
	return pGrafico;
}

sf::RenderWindow* GerenciadorGrafico::getWindow() {
	return window;
}

void GerenciadorGrafico::limparJanela() {
	window->clear();
}

void GerenciadorGrafico::desenharElemento(sf::RectangleShape corpo) {
	window->draw(corpo);
}
void GerenciadorGrafico::desenharElemento(sf::Text texto){
    window->draw(texto);
}
void GerenciadorGrafico::setView(sf::View view){
    window->setView(view);
}


void GerenciadorGrafico::mostrarElementos() {
	//getWindow()->draw(sprite);
	window->display();
}


void GerenciadorGrafico::fecharJanela() {
	window->close();
}

const bool GerenciadorGrafico::verificarJanelaAberta() {
	return window->isOpen();
}

sf::Texture GerenciadorGrafico::carregarTextura(const char* caminho){
	sf::Texture textura;
	if (!textura.loadFromFile(caminho))
        std::cout << "Erro ao carregar a textura" << std::endl;
	return textura;
}

void GerenciadorGrafico::carregarFundo(const char* caminho) {
	flag = true;
	if (!tex.loadFromFile(caminho)) {
		std::cout << "Erro ao carregar a textura" << std::endl;
		flag = false;
	}

	sprite.setTexture(tex);
	sprite.setPosition(0, 0);

	sf::Vector2u windowSize = pGrafico->getWindow()->getSize();
	sprite.setScale(
		static_cast<float>(windowSize.x) / sprite.getTexture()->getSize().x,
		static_cast<float>(windowSize.y) / sprite.getTexture()->getSize().y
	);
	getWindow()->draw(sprite);
}

void GerenciadorGrafico::atalizaFundo() {
	if (flag)
		getWindow()->draw(sprite);
}
