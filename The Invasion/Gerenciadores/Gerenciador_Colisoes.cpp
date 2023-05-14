#include "Gerenciador_Colisoes.h"

Gerenciadores::Gerenciador_Colisoes::Gerenciador_Colisoes() : pGerenciador_Colisoes(NULL) {

}
Gerenciadores::Gerenciador_Colisoes::~Gerenciador_Colisoes() {
    delete pGerenciador_Colisoes;
}
Gerenciadores::Gerenciador_Colisoes* Gerenciadores::Gerenciador_Colisoes::getGerenciador_Colisoes() {

    if (pGerenciador_Colisoes == NULL)
        pGerenciador_Colisoes = new Gerenciador_Colisoes();
    return pGerenciador_Colisoes;
}
void Gerenciadores::Gerenciador_Colisoes::incluiInimigo(Personagens::Inimigo* pInimigo) {
    if (pInimigo)
        vetor_inimigos.push_back(pInimigo);
    else
        cout << "erro: incluindo ponteiro nulo no vetor_inimigos do Gerenciador de colisoes" << endl;
}
void Gerenciadores::Gerenciador_Colisoes::incluiObstaculo(Obstaculos::Obstaculo* pObs) {
    if (pObs)
        vetor_obstaculos.push_back(pObs);
    else
        cout << "erro: incluindo ponteiro nulo no vetor_obstaculos do Gerenciador de colisoes" << endl;
}
void Gerenciadores::Gerenciador_Colisoes::testa_colisoes(Personagens::Jogador* pJogador) {
    if (pJogador) {

        Entidade* pEntiJogador = static_cast<Entidade*> (pJogador);
        Entidade* pEnti = NULL;
        sf::Vector2f DistanciaExtremidades;

        //testa coli�o com os inimigos
        for (int i = 0; i < (int)vetor_inimigos.size(); i++) {
            if (vetor_inimigos[i]) {
                pEnti = static_cast<Entidade*> (vetor_inimigos[i]);

                //Calcula_colisao retorna a distancia entre as duas extremidades mais proximas em cada eixp
                DistanciaExtremidades = Calcula_colisao(pEntiJogador, pEnti);
                if (DistanciaExtremidades.x < 0.0f && DistanciaExtremidades.y < 0.0f)
                    pEntiJogador->colisao(pEnti, DistanciaExtremidades);

            }
        }
        //testa coli�o com os Obstaculos
        for (int i = 0; i < (int)vetor_obstaculos.size(); i++) {
            if (vetor_obstaculos[i]) {
                pEnti = static_cast<Entidade*> (vetor_obstaculos[i]);

                //Calcula_colisao retorna a distancia entre as duas extremidades mais proximas em cada eixp
                DistanciaExtremidades = Calcula_colisao(pEntiJogador, pEnti);
                if (DistanciaExtremidades.x < 0.0f && DistanciaExtremidades.y < 0.0f)
                    pEntiJogador->colisao(pEnti, DistanciaExtremidades);

            }
        }


    }
    //

}


sf::Vector2f Gerenciadores::Gerenciador_Colisoes::Calcula_colisao(Entidade* pEnti1, Entidade* pEnti2) {

    sf::Vector2f tamanho_1 = pEnti1->getSize(), tamanho_2 = pEnti2->getSize();
    sf::Vector2f pos_1 = pEnti1->getPosition(), pos_2 = pEnti2->getPosition();
    sf::Vector2f distanciaCentros(
        fabs((pos_1.x + (tamanho_1.x / 2.0f)) - (pos_2.x + (tamanho_2.x / 2.0f))),
        fabs((pos_1.y + (tamanho_1.y / 2.0f)) - (pos_2.y + (tamanho_2.y / 2.0f)))
    );
    //calcula Distancia das extremidades fazendo Distancia dos centros menos a metade dos tamanhos
    sf::Vector2f DistanciaExtremidades(
        distanciaCentros.x - (tamanho_1.x / 2.0f + tamanho_2.x / 2.0f),
        distanciaCentros.y - (tamanho_1.y / 2.0f + tamanho_2.y / 2.0f)
    );
    return DistanciaExtremidades;




}



