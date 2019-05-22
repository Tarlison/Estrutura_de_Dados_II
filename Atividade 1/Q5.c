#include <stdio.h>

void decrescente(int v){
    if (v >= 0){
        printf("%d ", v);
        decrescente(v - 1);
    }
}
void crescente(int v){
     if (v >= 0){
        crescente(v - 1);
        printf("%d ", v);
    }

}

int main(void){
    int n;
    printf("digite um valor: ");
    scanf("%d", &n);
    printf("Decrescente: \n");
    decrescente(n);
    printf("\nCrescente: \n");
    crescente(n);
}
