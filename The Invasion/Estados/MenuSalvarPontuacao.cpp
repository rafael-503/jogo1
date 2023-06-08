#include "MenuSalvarPontuacao.h"
#include "../Gerenciadores/GerenciadorEstado.h"
using namespace Estados;

MenuSalvarPontuacao::MenuSalvarPontuacao(Ranking* pRankingAux): Menu(), pRanking(pRankingAux),
    TextoParabens("PARABENS VOCÊ PASSOU DE FASE", font), TextoInstrucoes("Digite seu nome e pressione Enter para salvar seu Progresso", font),
    TextoPontuacao("Sua Pontuaco foi:  ", font), TextoNome("", font), UltimaPontuacao(0)
{
    pGrafico->carregarFundo("The invasion/assets/fundo/fundo0.png");
    TextoParabens.setScale(1.7f, 1.7f);
    TextoNome.setScale(1.2f, 1.2f);
    TextoParabens.setPosition(130.0f, 90.0f);
    TextoPontuacao.setPosition(0.0f, 200.0f);
    TextoInstrucoes.setPosition(0.0f, 300.0f);
    TextoNome.setPosition(500.0f, 450.0f);


}
MenuSalvarPontuacao::~MenuSalvarPontuacao(){

}
void MenuSalvarPontuacao::TeclaPressionada(const sf::Keyboard::Key tecla){


    if(tecla == sf::Keyboard::Enter){
        Gerenciadores::GerenciadorEstado::pGEstados->setEstadoAtual("MenuPrincipal");
        std::ostringstream oss;
        string Texto = TextoNome.getString(), textoAux = ": ";
        oss << Texto << textoAux << UltimaPontuacao;
        sf::Text* pTexto = new sf::Text(oss.str(), font);
        pRanking->SalvarTextoPontuacao(pTexto, UltimaPontuacao);

        /// Reiniciando os textos
        string textoPontInicial = "Sua Pontuaco foi:  ", textoNomeInicial = "";
        TextoPontuacao.setString(textoPontInicial);
        TextoNome.setString(textoNomeInicial);


    }

    if(tecla >= 0 && tecla <= 25){
        int pos_letra, i = 0;
        for(i = 0; i <= 25; i++)
            if(tecla == i)
                pos_letra = i;
        char letra = 'A' + pos_letra;
        /// impede de clicar varias vezes sem querer
        if(UltimaLetra != letra){
            string textoNomeAux = TextoNome.getString();
            std::ostringstream oss;
            oss << textoNomeAux << letra;
            TextoNome.setString(oss.str());
            UltimaLetra = letra;
        }
    }
    /// LeftShift reseta ultima letra
    if(tecla == 38)
        UltimaLetra = '\0';


    /// criar algoritimo que coloca letra em TextoNome

}

void MenuSalvarPontuacao::PrimeiroExecutar(){
    pGrafico->carregarFundo("The invasion/assets/fundo/fundo0.png");
    pGrafico->atualizarView(sf::Vector2f(600.0f, 400.0f));
}
void MenuSalvarPontuacao::executar(){
    pGrafico->desenharElemento(TextoParabens);
    pGrafico->desenharElemento(TextoInstrucoes);
    pGrafico->desenharElemento(TextoPontuacao);
    pGrafico->desenharElemento(TextoNome);


}
void MenuSalvarPontuacao::AdicionarPontuacao(int pontuacao){
    UltimaPontuacao = pontuacao;
    std::ostringstream oss;
    string aux(TextoPontuacao.getString());
    oss << aux << UltimaPontuacao;
    TextoPontuacao.setString(oss.str());

}


