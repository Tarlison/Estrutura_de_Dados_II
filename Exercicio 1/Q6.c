#include<stdio.h>

void conv(int valor){
    if (valor == 0){
        printf("0");
    }
    if (valor == 1){
        printf("1");
    }
    else{
       conv(valor/2);
       printf("%d",valor%2);
    }
}
int main(void){
    int valor;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    conv(valor);
    printf("\n");
}
