#include <queue>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include "Arvore.h"
#include <math.h>
using namespace std;

Arv_bin * arv_cria(Nodo * raiz){
    Arv_bin * arv = (Arv_bin *) malloc(sizeof(Arv_bin));
    arv->raiz = raiz;
    return arv;
}

Arv_bin *espelho(Arv_bin *arv){
    Arv_bin *arv_aux = (Arv_bin*)malloc(sizeof(Arv_bin));
    arv_aux->raiz = arv_cria_no(arv->raiz->info, arv->raiz->esq,arv->raiz->dir);
    arv_aux->raiz->esq = espelho_no(arv->raiz->dir);
    arv_aux->raiz->dir = espelho_no(arv->raiz->esq);
    return arv_aux;
}

Nodo *espelho_no(Nodo *raiz){
    if (raiz == NULL){
        return NULL;
    }
    Nodo *no_aux = (Nodo*) malloc(sizeof(Nodo));
    no_aux->dir = espelho_no(raiz->esq);
    no_aux->esq = espelho_no(raiz->dir);
    no_aux->info = raiz->info;
    return no_aux;
}

void largura(Nodo *raiz){
    queue<Nodo*> fila;
    fila.push(raiz);
    while(!fila.empty()){
        Nodo *p = fila.front();
        fila.pop();
        if(p){
            printf("%c",p->info);
            fila.push(p->esq);
            fila.push(p->dir);
        }
    }
}
void arv_imprime_escolhendo_ordem(Arv_bin * arv, int ordem){
    if(ordem == 1)
            arv_imprime_pre_ordem(arv->raiz);
    if(ordem == 2)
            arv_imprime_infixa(arv->raiz);
    if(ordem == 3)
            arv_imprime_pos_ordem(arv->raiz);
}

void arv_imprime_pre_ordem(Nodo * raiz){
    if(raiz != NULL){
        printf("%c", raiz->info);
        arv_imprime_pre_ordem(raiz->esq);
        arv_imprime_pre_ordem(raiz->dir);
    }
}

void arv_imprime_infixa(Nodo * raiz){
    if(raiz != NULL){
        arv_imprime_infixa(raiz->esq);
        printf("%c", raiz->info);
        arv_imprime_infixa(raiz->dir);
    }
}

void arv_imprime_pos_ordem(Nodo * raiz){
    if(raiz != NULL){
        arv_imprime_pos_ordem(raiz->esq);
        arv_imprime_pos_ordem(raiz->dir);
        printf("%c", raiz->info);
    }
}

void arv_free(Arv_bin *arv){
    nodo_free(arv->raiz);
    free(arv);
}

void nodo_free(Nodo *nodo){
     if(nodo != NULL){
        nodo_free(nodo->esq);
        nodo_free(nodo->dir);
        free(nodo);
    }
}

void arv_imprime_formatado(Arv_bin *arv){
    arv_imprime_formatado_no(arv->raiz);

}

void arv_imprime_formatado_no(Nodo *nodo){
    printf("<");
    if(nodo != NULL){
        printf("%c", nodo->info);
        arv_imprime_formatado_no(nodo->esq);
        arv_imprime_formatado_no(nodo->dir);
    }

    printf(">");
}

Nodo * arv_cria_no(char c, Nodo* esq, Nodo* dir){
    Nodo * nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->esq = esq;
    nodo->dir = dir;
    nodo->info = c;
    return nodo;
}

int arv_altura(Arv_bin *arv){
	return arv_altura_no(arv->raiz);
}

int arv_altura_no(Nodo *raiz){
	if (raiz == NULL){
		return -1;
	}
	else{
		return arv_altura_no(raiz->esq) > arv_altura_no(raiz->dir) ? 1 + arv_altura_no(raiz->esq) : 1 + arv_altura_no(raiz->dir);
	}

}
int tamanho_arv(Arv_bin *arv){
    return tamanho_no(arv->raiz);

}

int tamanho_no(Nodo *raiz){
    if (raiz == NULL){
        return 0;
    }
    else{
        return 1 + tamanho_no(raiz->esq) + tamanho_no(raiz->dir);
    }
}

Nodo *arv_busca(Arv_bin* arv, char c){
	return arv_busca_no(arv->raiz, c);
}

Nodo *arv_busca_no(Nodo *raiz, char c){
	if (raiz == NULL){
		return raiz;
	}
	if (raiz->info == c){
		return raiz;
	}
	if (arv_busca_no(raiz->esq, c)){
		return raiz->esq;
	}
	return arv_busca_no(raiz->dir, c);
}
int arv_pertence(Arv_bin* arv, char c){
	return arv_pertence_no(arv->raiz, c);
}

int arv_pertence_no(Nodo *raiz, char c){
	if (raiz == NULL){
		return 0;
	}
	if (raiz->info == c){
		return 1;
	}
	if (arv_pertence_no(raiz->esq, c)){
		return 1;
	}
	return arv_pertence_no(raiz->dir, c);
}

int arv_folhas(Nodo *raiz){
    if (raiz==NULL){
        return 0;
    }
    if (raiz->esq == NULL && raiz->dir == NULL){
        return 1;
    }
    else{
        return arv_folhas(raiz->esq) + arv_folhas(raiz->dir);
    }


}

void infixa_com_pilha(Arv_bin *arv){
    stack<Nodo*> pilha;
    Nodo* corr = NULL;
    pilha.push(arv->raiz);
    while(!pilha.empty()){
        corr = pilha.top();
        while(corr->esq != NULL){
            pilha.push(corr->esq);
            corr = pilha.top();
        }
        printf("%c", corr->info);
        pilha.pop();
        if(corr->dir != NULL){
            pilha.push(corr->dir);
        }
        else {
            if(!pilha.empty()){
                corr = pilha.top();
                printf("%c", corr->info);
                pilha.pop();
                if(corr->dir != NULL){
                    pilha.push(corr->dir);
                }
            }
        }
    }
}
void posfixa_com_pilha(Arv_bin *arv){
    stack<Nodo*> pilha1;
    stack<Nodo*> pilha2;
    Nodo *corr = NULL;
    pilha1.push(arv->raiz);
    while(!pilha1.empty()){
        corr = pilha1.top();
        pilha2.push(corr);
        pilha1.pop();

        if(corr->esq!=NULL){
            pilha1.push(corr->esq);
        }

        if(corr->dir!=NULL){
            pilha1.push(corr->dir);
        }

    }
    while(!pilha2.empty()){
        printf("%c",pilha2.top()->info);
        pilha2.pop();
    }
}
int arv_estrita(Nodo *raiz){
    if (raiz->dir == NULL && raiz->esq == NULL){
        return 0;
    }
    if ((raiz->dir && !raiz->esq) || (!raiz->dir && raiz->esq)){
        return 1;
    }
    else{
        return arv_estrita(raiz->esq) + arv_estrita(raiz->dir);
    }
}
int arv_completa(Arv_bin *arv){
    if( arv_folhas(arv->raiz) == pow(2,arv_altura(arv))){
        return 1;
    }
    else{
        return 0;
    }
}


