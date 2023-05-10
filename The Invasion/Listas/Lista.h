#pragma once
#include <list>
#include <iostream>
#include "../Gerenciadores/GerenciadorGrafico.h"

namespace Listas {
	template <class TL>
	class Lista {
		private:
			template <class TE>
			class Elemento {
				private:
					TE* pInfo;
					Elemento<TE> *pAnt;
					Elemento<TE> *pProx;
				public:
					Elemento(TE* pInfo_aux = NULL) :
						pInfo(pInfo_aux), pAnt(NULL), pProx(NULL){}
					~Elemento(){}
					void setAnt(Elemento<TE>* anterior) { pAnt = anterior; }
					Elemento<TE> *getAnt() const { return pAnt; }

					void setProx(Elemento<TE>* proximo) { pProx = proximo; }
					Elemento<TE>* getProx() const { return pProx; }

					void setInfo(TE* pInfo_aux) { pInfo = pInfo_aux; }
					TE* getInfo() const { return pInfo; }
			};

			Elemento<TL> *pPrimeiro;
			Elemento<TL> *pAtual;
			Elemento<TL> *pUltimo;

		public:
			Lista() : pPrimeiro(NULL), pAtual(NULL), pUltimo(NULL){}
			~Lista() { esvaziar(); }

			void inserir(TL* pTipo) {
				if (pTipo) {
                    Elemento<TL>* pNovo = NULL;
                    pNovo = new Elemento<TL>(pTipo);

					if (!pPrimeiro){
						pPrimeiro = pNovo;
						pUltimo = pNovo;
					}
					else{
						pUltimo->setProx(pNovo);
						pNovo->setAnt(pUltimo);

						pUltimo = pNovo;
					}
				}
			}
			void esvaziar(){
				Elemento<TL> *pAux = pPrimeiro;
				pAtual = pPrimeiro;

				while (pAtual != NULL){
					pAux = pAtual->getProx();
					delete pAtual;
					pAtual = pAux;
				}

				pPrimeiro = NULL;
				pAtual = NULL;
				pUltimo = NULL;
			}

			TL* retornaInicio(){ // retorna o primeiro elemento da lista
				pAtual = pPrimeiro;

				if(pAtual)
					return pAtual->getInfo();
				else
					return NULL;

			}

			TL* retornaProximo() { // retorna o proximo elemento da lista
				pAtual = pAtual->getProx();

				if (pAtual)
					return pAtual->getInfo();
				else
					return NULL;
			}
            void executar(){
                pAtual = pPrimeiro;
                while(pAtual){
                    TL* pAux = pAtual->getInfo();
                    pAux->executar();
                    pAtual = pAtual->getProx();
                }
            }
            void seDesenhe (){
                pAtual = pPrimeiro;
                while(pAtual){
                    TL* pAux = pAtual->getInfo();
                    Gerenciadores::GerenciadorGrafico* pGrafico = pGrafico->getGerenciadorGrafico();
                    pGrafico->desenharElemento(pAux->getCorpo());
                    pAtual = pAtual->getProx();
                }
            }
	};
}
