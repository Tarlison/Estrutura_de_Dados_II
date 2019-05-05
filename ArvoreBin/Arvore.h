#ifndef ARVORE_H_
#define ARVORE_H_

typedef struct no{
    char info;
    struct no *esq;
    struct no *dir;
}Nodo;

typedef struct arv_bin{
    Nodo * raiz;
}Arv_bin;


Arv_bin *arv_cria(Nodo * raiz);
Arv_bin *espelho(Arv_bin *arv);
Nodo *espelho_no(Nodo *raiz);
void largura(Nodo *raiz);
void arv_free(Arv_bin *arv);
void arv_imprime_escolhendo_ordem(Arv_bin * arv, int ordem);
void arv_imprime_pre_ordem(Nodo * raiz);
void arv_imprime_infixa(Nodo * raiz);
void arv_imprime_pos_ordem(Nodo * raiz);
void nodo_free(Nodo *nodo);
void arv_imprime_formatado(Arv_bin *arv);
void arv_imprime_formatado_no(Nodo *nodo);
int arv_folhas(Nodo *raiz);
int arv_altura(Arv_bin *arv);
int arv_altura_no(Nodo *raiz);
int arv_pertence(Arv_bin* arv, char c);
int arv_pertence_no(Nodo *raiz, char c);
int tamanho_arv(Arv_bin *arv);
int tamanho_no(Nodo *raiz);
int arv_estrita(Nodo *raiz);
int arv_completa(Arv_bin *arv);
Nodo *arv_busca(Arv_bin* arv, char c);
Nodo *arv_busca_no(Nodo *raiz, char c);
Nodo *arv_cria_no(char c, Nodo *esq, Nodo *dir);
void infixa_com_pilha(Arv_bin* arv);
void posfixa_com_pilha(Arv_bin *arv);
#endif // ARVORE_H_
