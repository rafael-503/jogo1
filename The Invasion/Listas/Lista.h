#pragma once
#include <list>
#include <iostream>

namespace Listas {
	template <class TL>
	class Lista {
		private:
			template <class TE>
			class Elemento {
				private:
					TE info;
					Elemento<TE> *pAnt;
					Elemento<TE> *pProx;
				public:
					Elemento(TIPO info = NULL, Elemento<TE> *ant = NULL, Elemento<TE> *prox = NULL ) : 
						info(info), pAnt(ant), pProx(prox){}
					~Elemento(){}
					void setProx(Elemento<TE>* proximo) { pProx = proximo; }
					Elemento<TE> *getAnt() { return anterior; }

					void setProx(Elemento<TE>* proximo) { pProx = proximo; }
					Elemento<TE>* getProx() { return proximo; }

					void setInfo(TIPO* Info) { info = Info; }
					TIPO getInfo() { return info; }
			};

			Elemento<TL> *pPrimeiro;
			Elemento<TL> *pAtual;
			Elemento<TL> *pUltimo;
			
		public:
			Lista() : pPrimeiro(NULL), pAtual(NULL), pUltimo(NULL);
			~Lista() { esvaziar(); }
			
			void inserir(TL tipo) {
				if (tipo) {
					Elemento<TL> *novo = new Elemento<TL>(info);
					if (!pPrimeiro){
						pPrimeiro = novo;
						pUltimo = novo;
					}
					else{
						pUltimo->setProx(novo);
						novo->setAnt(pUltimo);
		
						pUltimo = novo;
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

			void retornaInicio(){ // retorna o primeiro elemento da lista
				pAtual = pPrimeiro;

				if(pAtual)
					return pAtual->getInfo();
				else
					return NULL;
				
			}
			void retornaProximo() { // retorna o proximo elemento da lista
				pAtual = pAtual->getProx();

				if (pAtual)
					return pAtual->getInfo();
				else
					return NULL;
			}
	};
}
