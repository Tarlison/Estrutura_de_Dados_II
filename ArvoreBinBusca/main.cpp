#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include "ArvoreBusca.h"
#include <iostream>
using namespace std;

int main(){
    int ordem,quant, i, *new_arv, valor, aux,k;
    queue<int> vet;

    Arv_bin *arv1 = arv_cria();
    Arv_bin *arv2 = arv_cria();
    Arv_bin *arv3 = arv_cria();

    arv_insere(arv1, 50); arv_insere(arv1, 30); arv_insere(arv1, 70);
    arv_insere(arv1, 20); arv_insere(arv1, 40); arv_insere(arv1, 60);
    arv_insere(arv1, 80); arv_insere(arv1, 15); arv_insere(arv1, 25);
    arv_insere(arv1, 35); arv_insere(arv1, 45); arv_insere(arv1, 36);
    // ///////////////////////////////////////////// // /////////////////////////////////////////////
    arv_insere(arv2, 50); arv_insere(arv2, 30); arv_insere(arv2, 70);
    arv_insere(arv2, 20); arv_insere(arv2, 40); arv_insere(arv2, 60);
    arv_insere(arv2, 80); arv_insere(arv2, 15); arv_insere(arv2, 25);
    arv_insere(arv2, 35); arv_insere(arv2, 45); arv_insere(arv2, 36);

    // ///////////////////////////////////////////// // /////////////////////////////////////////////
    printf("Escolha a ordem de impressao. 1-pre ordem, 2-infixa, 3-pos ordem:\n");
    scanf(" %d", &ordem);
    arv_imprime_escolhendo_ordem(arv1, ordem); //impressão da arvore
    printf("\n");

    // ///////////////////////////////////////////// // /////////////////////////////////////////////
    arv_remove(arv1, 30); // remoção com predecessor
    printf("Escolha a ordem de impressao. 1-pre ordem, 2-infixa, 3-pos ordem:\n");
    scanf(" %d", &ordem);
    arv_imprime_escolhendo_ordem(arv1, ordem);
    printf("\n");

    // ///////////////////////////////////////////// // /////////////////////////////////////////////
    arv_remove_sucessor(arv1, 25); // remoção com sucessor
    printf("Escolha a ordem de impressao. 1-pre ordem, 2-infixa, 3-pos ordem:\n");
    scanf(" %d", &ordem);
    arv_imprime_escolhendo_ordem(arv1, ordem);
    printf("\n");
    // ///////////////////////////////////////////// // /////////////////////////////////////////////
    //arv->raiz->info = 100; //teste para verificar a função check_arvBusca;
    printf("A arvore eh de busca? se sim == 1 se nao == 0: %d\n",check_arvBusca(arv1->raiz));

    // ///////////////////////////////////////////// // /////////////////////////////////////////////
    printf("O valor maximo da arvore eh: %d\n",valor_max(arv1->raiz));

    // ///////////////////////////////////////////// // /////////////////////////////////////////////
    printf("O valor minimo da arvore eh: %d\n",valor_min_iterativo(arv1->raiz));

    // ///////////////////////////////////////////// // /////////////////////////////////////////////
    printf("As arvores sao iguais? %s\n", arv_iguais(arv1->raiz,arv2->raiz) > 0 ? "Nao" : "Sim" );

    // ///////////////////////////////////////////// // /////////////////////////////////////////////
    printf("Quantidade de nos na arv1: %d\n", quant_no(arv1->raiz));

    // ///////////////////////////////////////////// // /////////////////////////////////////////////
    printf("Digite quantos valores vao ser inseridos:\n");
    scanf(" %d",&quant);
    new_arv = (int*)malloc(quant*sizeof(int));
    for(i = 0; i < quant; i++){
        scanf("%d",&valor);
        arv_insere(arv3,valor);
    }
    printf("Escolha a ordem de impressao. 1-pre ordem, 2-infixa, 3-pos ordem:\n");
    scanf(" %d", &ordem);
    arv_imprime_escolhendo_ordem(arv3, ordem);
    printf("\n");

    // ///////////////////////////////////////////// // /////////////////////////////////////////////
    printf("Digite a quantidade de valores da subsquencia:\n");
    scanf("%d",&quant);
    printf("Digite uma subsequencia ordenada:\n");
    for (i = 0; i < quant; i++){
        scanf("%d",&aux);
        vet.push(aux);
    }
    printf("se pertence == 1, se nao == 0: -> %d\n",sequencia_pertence(arv1,&vet));
    // ///////////////////////////////////////////// // /////////////////////////////////////////////
    printf("Digite um k para ser procurado o k-esimo menor valor na arvore: ");
    cin >> k;
    k_esimo_termo(arv1->raiz, &k);
    arv_free(arv1);
    arv_free(arv2);
    return 0;
}