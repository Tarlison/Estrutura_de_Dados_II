#include <stdio.h>

int potencia(int k,int n){
    if(n == 0){
        return 1;
    }
    return k * potencia(k,n-1);
}

int main(void){
    int k,n,pot;
    printf("digite 2 valores: ");
    scanf("%d %d", &k,&n);
    pot = potencia(k,n);
    printf("%d elevado a %d eh : %d",k,n,pot);
}
