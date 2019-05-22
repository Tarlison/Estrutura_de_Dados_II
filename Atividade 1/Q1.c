#include <stdio.h>

int aux = 0;

void inverte (int v){
    if (v < 10) {
        printf("%d", v);
    }
    else{
        aux = v % 10;
        printf("%d",aux);
        return inverte(v / 10 );
    }
}

int main(void){
    int valor;
    printf("Digite um numero: ");
    scanf("%d",&valor);
    printf("Inverso: ");
    inverte(valor);
    printf("\n");
}
