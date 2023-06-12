#include "Ranking.h"
#include "../Gerenciadores/GerenciadorEstado.h"
using namespace Estados;

Ranking::Ranking() :Menu(), BotaoMenuPrincipal("Menu Principal", font), vectorPontuacoes() {
    sf::Vector2u tamJanela(600.f, 400.f);
    BotaoMenuPrincipal.setScale(1.5f, 1.5f);

    BotaoMenuPrincipal.setPosition(tamJanela.x / 2 + 500, 700);
    carregarRanking();
}

Ranking::~Ranking() {}

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
    else
        BotaoMenuPrincipal.setFillColor(sf::Color::White);

    /// Mostra as Pontuações
    MultiMapaIntText::const_iterator iterador;
    int i = 0;
    for(iterador = MapPontuacoes.begin(); iterador != MapPontuacoes.end(); ++iterador){

        (iterador->second)->setPosition(100.0f, 60.0f + i*50.0f);
        pGrafico->desenharElemento(*iterador->second);
        i++;
    }
    pGrafico->desenharElemento(BotaoMenuPrincipal);
}

void Ranking::TeclaPressionada(const sf::Keyboard::Key tecla) {}

void Ranking::guardarPontuacao(int num) {
    std::ostringstream oss;
    string aux("Jogador X: ");
    oss << aux << num;
    sf::Text* pAux = new sf::Text(oss.str(), font);
    pAux->setScale(1.0f, 1.0f);
    vectorPontuacoes.push_back(pAux);
    cout << "Pontuação guardada" << endl;
}

void Ranking::imprimirPontuacao() {
    for (int i = 0; i < (int) vectorPontuacoes.size(); i++)
		cout << vectorPontuacoes[i]->getString().toAnsiString() << endl;
}

void Ranking::SalvarTextoPontuacao(sf::Text* pTexto, int pontuacao){
    MapPontuacoes.insert(std::make_pair(pontuacao, pTexto));
    salvarRanking();
}

void Ranking::salvarRanking(){

    std::ofstream GravadorRanking("data/Ranking.txt", ios::out);
    if (!GravadorRanking){
        cerr << "Ranking.txt não pode ser aberto" << endl;
        fflush (stdin);
        getchar();
        return;
    }

    MultiMapaIntText::const_iterator iterador;
    string texto;
    for(iterador = MapPontuacoes.begin(); iterador != MapPontuacoes.end(); ++iterador){
        texto = (iterador->second)->getString();
        /// a propria string contem a chave separada por um espaço
        GravadorRanking << texto << endl;
    }
    GravadorRanking.close();
}
void Ranking::carregarRanking(){

    ifstream RecuperadorRanking("data/Ranking.txt", ios::in);
    if (!RecuperadorRanking){
        cout << "Ranking.txt não pode ser aberto" << endl;
        cout << "Por Favor termine uma fase e salve sua pontuação" << endl;
    }

    int pontuacao;
    string texto;
    while (RecuperadorRanking >> texto >> pontuacao){
        /// recolocando pois o espaçamento da string o perde
        std::ostringstream oss;
        oss << texto << ' ' << pontuacao;
        sf::Text* pTexto = new sf::Text(oss.str(), font);
        MapPontuacoes.insert(std::make_pair(pontuacao, pTexto));
    }

    RecuperadorRanking.close();
}
