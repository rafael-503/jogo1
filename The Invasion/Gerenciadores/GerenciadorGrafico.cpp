#include "../Gerenciadores/GerenciadorGrafico.h"
#define TAM_X 1200.0f
#define TAM_Y 800.0f
#include <stdlib.h>
using namespace Gerenciadores;

GerenciadorGrafico* GerenciadorGrafico::pGrafico = NULL;
GerenciadorGrafico::GerenciadorGrafico() : window(new sf::RenderWindow(sf::VideoMode(TAM_X, TAM_Y), "The Invasion")),
    view(sf::Vector2f(TAM_X/2.0f, TAM_Y/2.0f), sf::Vector2f(TAM_X, TAM_Y))
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

sf::View GerenciadorGrafico::getView() {
	return view;
}

void GerenciadorGrafico::atualizarView(const sf::Vector2f& jogadorPos) {
	sf::Vector2f cameraPos = view.getCenter(); // Obtém a posição atual da câmera
	cameraPos.x = jogadorPos.x; // Mantem apenas a coordenada x do jogador

	view.setCenter(cameraPos);
	window->setView(view);
}

void GerenciadorGrafico::reiniciarView() {
	view.setCenter(TAM_X/2.0f, TAM_Y/2.0f);
	window->setView(view);
}
void GerenciadorGrafico::mostrarElementos() {
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

	if (!tex.loadFromFile(caminho)) {
		std::cout << "Erro ao carregar a textura" << std::endl;
		return;
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
	sf::Vector2f cameraPos = view.getCenter(); // posicao atual da camera
	sf::Vector2f cameraSize = view.getSize(); // tamanho da área visível da câmera

	// Define a posição do sprite do fundo com base na posicao da camera
	sprite.setPosition(cameraPos.x - cameraSize.x / 2, cameraPos.y - cameraSize.y / 2);

	// Redimensiona o sprite do fundo para cobrir toda a area visivel da camera
	sf::Vector2u textureSize = sprite.getTexture()->getSize();
	sprite.setScale(
		cameraSize.x / textureSize.x,
		cameraSize.y / textureSize.y
	);
	getWindow()->draw(sprite);
}
/*
void GerenciadorGrafico::mostrarVidaJogador(int vida) {
	sf::Font font;
	if (!font.loadFromFile("The invasion/assets/fonts/PlayfairDisplay-Regular.ttf"))
		return;

	sf::Text texto;
	texto.setFont(font);
	texto.setString("Vida: " + std::to_string(vida));
	texto.setCharacterSize(20);
	texto.setFillColor(sf::Color::White);
	texto.setPosition(10, 10); // Posição do texto no canto superior esquerdo
	desenharElemento(texto);
	//mostrarElementos();
*/

void GerenciadorGrafico::mostrarVidaJogador(int vida) {
	sf::Font font;
	if (!font.loadFromFile("The invasion/assets/fonts/PlayfairDisplay-Regular.ttf"))
		return;
	sf::Vector2f cameraPos = view.getCenter(); // Posição central da câmera
	sf::Vector2f telaPos = cameraPos - sf::Vector2f(TAM_X / 2, TAM_Y / 2); // Canto superior esquerdo da tela

	sf::Text texto;
	texto.setFont(font);

	texto.setString("Vida: " + std::to_string(vida) );

	texto.setCharacterSize(20);
	texto.setFillColor(sf::Color::White);

	sf::Vector2f posicaoTexto = telaPos + sf::Vector2f(10.0f, 10.0f); // Posição do texto no canto superior esquerdo da tela
	texto.setPosition(posicaoTexto);

	desenharElemento(texto);
}

