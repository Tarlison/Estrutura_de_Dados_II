#ifndef ARVOREBUSCA_H_
#define ARVOREBUSCA_H_
#include <stdlib.h>
#include <stdio.h>
#include "ArvoreBusca.h"
#include <queue>
#include <iostream>
using namespace std;
typedef struct no{
    int info;
    struct no *esq;
    struct no *dir;
}Nodo;
// ////////////////////////////////////////////////////////////////////////////////////////////
typedef struct arv_bin{
    Nodo * raiz;
}Arv_bin;
// ////////////////////////////////////////////////////////////////////////////////////////////
Arv_bin *arv_cria();
Nodo *arv_busca(Arv_bin *arv, int k);
Nodo *arv_busca_no(Nodo *raiz, int k);
Nodo *arv_insere_no(Nodo *raiz, int c);
Nodo *remove_no(Nodo *raiz, int c);
Nodo *remove_no_sucessor(Nodo *raiz, int c);
int valor_min_iterativo(Nodo *raiz);
int valor_max(Nodo *raiz);
int sequencia_pertence(Arv_bin *arv, queue<int> *vet);
int arv_iguais(Nodo *raiz1, Nodo *raiz2);
int quant_no(Nodo *raiz);
bool check_arvBusca(Nodo *raiz);
void k_esimo_termo(Nodo *r, int *k);
void arv_remove_sucessor(Arv_bin *arv, int c);
void arv_remove(Arv_bin *arv, int c);
void arv_imprime_escolhendo_ordem(Arv_bin * arv, int ordem);
void arv_imprime_pre_ordem(Nodo * raiz);
void arv_imprime_infixa(Nodo * raiz);
void arv_imprime_pos_ordem(Nodo * raiz);
void arv_insere(Arv_bin *arv, int c);
void arv_free(Arv_bin *arv);
void nodo_free(Nodo *nodo);

#endif
