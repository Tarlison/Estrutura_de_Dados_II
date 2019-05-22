#include <stdio.h>
#include <stdlib.h>

int soma(int *v, int valor){
    if (valor == 0){
        return v[valor];
    }
    else{
        return v[valor] + soma(v,valor-1);
    }
}
int emax(int *v, int *max,int valor){
    if (valor == 0){
        if (v[valor] > *max){
            max = &v[valor];
            }
        return *max;
    }
    if (v[valor] > *max){
        max = &v[valor];
        return emax(v,max,valor - 1);
    }
    else{
        return emax(v,max,valor - 1);
    }
}
int emin(int *v, int *min,int valor){
    if (valor == 0){
            if (v[valor] < *min){
                min = &v[valor];
            }
        return *min;
    }
    if (v[valor] < *min){
        min = &v[valor];
        return emin(v,min,valor - 1);
    }
    else{
        return emin(v,min,valor - 1);
    }
}
int prod(int *v, int valor){
    if (valor == 0){
        return v[valor];
    }
    else{
        return v[valor] * prod(v,valor -1);
    }

}

float media(int *v, int valor, float aux){
    if (valor == 0){
        return v[valor] / aux;
    }
    else{
        return (v[valor]/aux) + media(v,valor -1,aux);
    }
}

int main(void){
    int n,i, max, min;
    float aux_to_media;
    printf("Digite a quantidade de valores: ");
    scanf("%d", &n);
    int *vet = (int*)malloc(n * sizeof(int));
    printf("Digite os numeros:\n");
    for (i = 0; i < n; i++){
        scanf("%d",&vet[i]);
    }
    max = vet[n-1];
    min = vet[n-1];
    aux_to_media = n * 1.0;
    printf("SOMA = %d \n",soma(vet,n-1));
    printf("VALOR MAXIMO = %d \n",emax(vet,&max,n-1));
    printf("VALOR MINIMO = %d \n",emin(vet,&min,n-1));
    printf("PRODUTO = %d \n",prod(vet,n-1));
    printf("MEDIA = %.3f \n",media(vet,n-1,aux_to_media));
    return 0;
}
