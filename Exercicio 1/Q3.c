#include <stdio.h>
#include <stdlib.h>

int MultipRec(int n1,int n2){
    if (n1 == 0){
        return 0;
    }
    return MultipRec(n1-1,n2) + n2;
}
int main(void){
    int n1,n2,resultado;
    printf("Digite os dois numeros: ");
    scanf("%d %d",&n1,&n2);
    //tratamento do valor negativo;
    if (n1 < 0 && n2 < 0){
        resultado = MultipRec(abs(n1),abs(n2));
    }
    else if (n1 < 0 || n2 < 0){
        resultado = MultipRec(abs(n1),abs(n2)) * -1;
    }
    else{
        resultado = MultipRec(n1,n2);
    }
    printf("resultado da mult : %d \n", resultado);
    return 0;
}
