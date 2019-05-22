#include <stdio.h>

int somatorio(int v){
    if (v == 1){
        return v;
    }
    else{
        return v + somatorio(v-1);
    }
}

int main(void){
    int valor, soma;
    printf("Digite um valor: ");
    scanf("%d",&valor);
    soma = somatorio(valor);
    printf("Somatorio de 1 a %d eh %d\n", valor, soma);
}
