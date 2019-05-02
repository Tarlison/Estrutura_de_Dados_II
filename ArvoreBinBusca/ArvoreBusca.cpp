#include <stdlib.h>
#include <stdio.h>
#include "ArvoreBusca.h"
#include <queue>
#include <iostream>
using namespace std;

Arv_bin *arv_cria(){
    Arv_bin * arv = (Arv_bin *) malloc(sizeof(Arv_bin));
    arv->raiz = NULL;
    return arv;
}

Nodo *arv_busca(Arv_bin *arv, int k){
	return arv_busca_no(arv->raiz, k);
}

Nodo *arv_busca_no(Nodo *raiz, int c){
    if (raiz == NULL || raiz->info == c){
        return raiz;
    }
    if (c < raiz -> info){
        return arv_busca_no(raiz->esq, c);
    }
	else{
        return arv_busca_no(raiz->dir, c);
    }
}

void arv_insere(Arv_bin *arv, int c){
    arv->raiz = arv_insere_no(arv->raiz, c);
}

Nodo *arv_insere_no(Nodo *raiz, int c){
    if (raiz == NULL){
        raiz = (Nodo*)malloc(sizeof(Nodo));
        raiz->dir = raiz->esq = NULL;
        raiz->info = c;
    }
    else if (c < raiz->info)
        raiz->esq = arv_insere_no(raiz->esq, c);
    else
        raiz->dir = arv_insere_no(raiz->dir, c);
    return raiz;

}

void arv_remove(Arv_bin *arv, int c){
    arv->raiz = remove_no(arv->raiz, c);
}

Nodo *remove_no(Nodo *raiz, int c){
    if (raiz == NULL){
        return  NULL;
    }
    else if (c < raiz->info){
        raiz->esq = remove_no(raiz->esq, c);
    }
    else if (c > raiz->info){
        raiz->dir = remove_no(raiz->dir, c);
    }
    else{
        /*nodo não tem filhos:*/
        if (raiz->dir == NULL && raiz->esq == NULL){
            free(raiz);
            raiz = NULL;
        }
        /*só tem filhos a direita*/
        else if (raiz->esq == NULL){
            Nodo *aux = raiz;
            raiz = raiz->dir;
            free(aux);
        }
        /*só tem filhos a esquerda*/
        else if (raiz->dir == NULL){
            Nodo *aux = raiz;
            raiz = raiz->esq;
            free(aux);
        }
        /*tem dois filhos*/
        else{
            Nodo *aux = raiz->esq;
            while (aux->dir != NULL){
                aux = aux->dir;
            }
            /*troca de informações da raiz com
             * o nodo mais a direita da sae*/
            raiz->info = aux->info;
            aux->info = c;
            raiz->esq = remove_no(raiz->esq, c);
        }
    }
    return raiz;
}

void arv_remove_sucessor(Arv_bin *arv, int c){
    arv->raiz = remove_no_sucessor(arv->raiz, c);
}

Nodo *remove_no_sucessor(Nodo *raiz, int c){
    if (raiz == NULL){
        return  NULL;
    }
    else if (c < raiz->info){
        raiz->esq = remove_no(raiz->esq, c);
    }
    else if (c > raiz->info){
        raiz->dir = remove_no(raiz->dir, c);
    }
    else{
        /*nodo não tem filhos:*/
        if (raiz->dir == NULL && raiz->esq == NULL){
            free(raiz);
            raiz = NULL;
        }
            /*só tem filhos a direita*/
        else if (raiz->esq == NULL){
            Nodo *aux = raiz;
            raiz = raiz->dir;
            free(aux);
        }
            /*só tem filhos a esquerda*/
        else if (raiz->dir == NULL){
            Nodo *aux = raiz;
            raiz = raiz->esq;
            free(aux);
        }
            /*tem dois filhos*/
        else{
            Nodo *aux = raiz->dir;
            while (aux->esq != NULL){
                aux = aux->esq;
            }
            /*troca de informações da raiz com
             * o nodo mais a direita da sae*/
            raiz->info = aux->info;
            aux->info = c;
            raiz->dir = remove_no(raiz->dir, c);
        }
    }
    return raiz;
}

int valor_max(Nodo *raiz){
    if (raiz == NULL ){
        printf("A arvore esta vazia \n");
        return 0;
    }
    else if (raiz->dir == NULL){
        return raiz->info;
    }
    else{
        return valor_max(raiz->dir);
    }
}

int valor_min_iterativo(Nodo *raiz){
    int menor;
    while (raiz->esq != NULL){
        raiz = raiz->esq;
    }
    menor = raiz->info;
    return menor;
}

bool check_arvBusca(Nodo *raiz){
    if (raiz == NULL){
        return 1;
    }
    if (raiz->dir == NULL){
        return check_arvBusca(raiz->esq);
    }
    if (raiz->esq == NULL){
        return check_arvBusca(raiz->dir);
    }
    if (raiz->info > raiz->dir->info){
        return 0;
    }
    if (raiz->info < raiz->esq->info){
        return 0;
    }
    else{
        return check_arvBusca(raiz->esq) && check_arvBusca(raiz->dir);
    }
}

void k_esimo_termo(Nodo *r, int *k){
    if(r != NULL){
        k_esimo_termo(r->esq,k);
        (*k)--;
        if (*k == 0){
            printf("K-esimo eh: %d\n", r->info);
        }
        k_esimo_termo(r->dir,k);
    }
}
int sequencia_pertence(Arv_bin *arv, queue<int> *vet){
    queue<Nodo*> aux;
    while(!vet->empty()){
            aux.push(arv_busca(arv,vet->front()));
            vet->pop();
    }
    while (!aux.empty()){
        if(aux.front() == NULL){
            return 0;
        }
        else{
            aux.pop();
        }
    }
    return  1;
}

int arv_iguais(Nodo *raiz1, Nodo *raiz2){
    if (raiz1 == NULL && raiz2 == NULL){
        return 0;
    }
    else if (raiz1 != NULL && raiz2 == NULL || raiz1 == NULL && raiz2 != NULL){
        return 1;
    }
    else if (raiz1->info != raiz2->info){
        return 1;
    } else{
        return arv_iguais(raiz1->esq,raiz2->esq) + arv_iguais(raiz1->dir,raiz2->dir);
    }

}

int quant_no(Nodo *raiz){
    if (raiz == NULL){
        return 0;
    } else if (raiz->dir == NULL && raiz->esq != NULL){
        return 1;
    } else if (raiz->dir != NULL && raiz->esq == NULL){     
    } else if(raiz->dir == NULL && raiz->esq == NULL){
        return 0;
    }
    else{
        if (raiz->dir == NULL){
            return 1 + quant_no(raiz->esq);
        }
        else if (raiz->esq == NULL){
            return 1 + quant_no(raiz->dir);
        }
        else{
            return quant_no(raiz->dir) + quant_no(raiz->esq);
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
        printf("%d ", raiz->info);
        arv_imprime_pre_ordem(raiz->esq);
        arv_imprime_pre_ordem(raiz->dir);
    }
}

void arv_imprime_infixa(Nodo * raiz){
    if(raiz != NULL){
        arv_imprime_infixa(raiz->esq);
        printf("%d ", raiz->info);
        arv_imprime_infixa(raiz->dir);
    }
}

void arv_imprime_pos_ordem(Nodo * raiz){
    if(raiz != NULL){
        arv_imprime_pos_ordem(raiz->esq);
        arv_imprime_pos_ordem(raiz->dir);
        printf("%d ", raiz->info);
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
