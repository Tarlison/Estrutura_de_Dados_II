#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

int main(){
    int ordem;
    char c;
    Arv_bin * arv = arv_cria(
                        arv_cria_no('a',
                            arv_cria_no('b',
                                    NULL,
                                    arv_cria_no('d', NULL, NULL) ),
                            arv_cria_no('c',
                                    arv_cria_no('e', NULL, NULL),
                                    arv_cria_no('f', NULL, NULL))
                        )
                    );

    printf("escolha a ordem :\n1-pre ordem\n2-infixa\n3-pos fixa\n");

    scanf("%d", &ordem);

    arv_imprime_escolhendo_ordem(arv, ordem);

    printf("\nFormatado: \n");

    arv_imprime_formatado(arv);

    int tamanho = tamanho_arv(arv), altura = arv_altura(arv);

    printf("\nO tamanho da arvore eh %d", tamanho);

    printf("\nA altura da arvore eh %d\n",altura);

    printf("Digite uma letra para a busca do Nodo: ");

    scanf(" %c", &c);

    printf("%p endereco do Nodo (se for 0000 eh pq o nodo nao esta na arvore)",arv_busca(arv, c));

    printf("\nDigite um elemento para verificar se pertence a arvore: ");
    scanf(" %c", &c);
    arv_pertence(arv, c) ? printf("Pertence!\n") : printf("Nao pertence!\n");

    printf("Percurso em largura:\n");
    largura(arv->raiz);

    printf("\nescolha a ordem para a espelhada :\n1-pre ordem\n2-infixa\n3-pos fixa\n");
    scanf("%d", &ordem);
    Arv_bin * arv_espelhada = espelho(arv);
    arv_imprime_escolhendo_ordem(arv_espelhada,ordem);

    printf("\nInfixa iterativo:\n");
    infixa_com_pilha(arv);

    printf("\nPosFixa iterativo:\n");
    posfixa_com_pilha(arv);

    printf("\nQuantidade de folhas: %d", arv_folhas(arv->raiz));

    printf("\nA arvore original, eh estritamente binaria? : %s\n",( arv_estrita(arv->raiz) != 0 ? ("Nao"):("Sim") ) );

    printf("\nA arvore original, eh uma arvore completa ? : %s\n",( arv_completa(arv) == 1 ? ("Sim"):("Nao") ) );



    arv_free(arv);

    return 0;
}
