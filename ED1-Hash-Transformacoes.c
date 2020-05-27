#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
#define N 25

int M;

typedef struct vetor *numeros;

struct vetor{
    int lista[MAX];
};

numeros quadrado(numeros lista){
    int i, numero_aux, len;
    char numeroString[MAX];
    numeros lista_quadrado = (numeros)malloc(sizeof(struct vetor));
    for(i=0; i<N; i++){
        numero_aux = lista->lista[i] * lista->lista[i];
        sprintf(numeroString, "%d", numero_aux);
        printf("%s ", numeroString);
        len = strlen(numeroString);
        if(strlen(numeroString) > 1){
            lista_quadrado->lista[i] = numeroString[(len/2)] - '0';
        }
        else{
            lista_quadrado->lista[i] = atoi(numeroString);
        }
    }
    return lista_quadrado;
}

void mudaBase(int numero, int base, char numeroString[]){
    char numeroString_aux[MAX];
    if(numero < base){ 
        sprintf(numeroString_aux, "%d", numero);
        strncat(numeroString, numeroString_aux, 1);      
        return;
    }
    mudaBase(numero / base, base, numeroString);
    sprintf(numeroString_aux, "%d", numero %base);
    strncat(numeroString, numeroString_aux, 1);      
    return;
}

numeros raiz(numeros lista, int base){
    int i, numero_aux;
    char numeroString[MAX];
    numeroString[0] = '\0';
    numeros lista_raiz = (numeros)malloc(sizeof(struct vetor));

    for(i=0; i<N; i++){
        mudaBase(lista->lista[i], base, numeroString);
        numero_aux = atoi(numeroString);
        printf("%d ", numero_aux);
        numero_aux %= M;
        lista_raiz->lista[i] = numero_aux;
        numeroString[0] = '\0';
    }
    return lista_raiz;
}

int main(){
    int i, base;
    numeros lista_prov = (numeros)malloc(sizeof(struct vetor));
    numeros lista_quadrado = (numeros)malloc(sizeof(struct vetor)); 
    numeros lista_raiz = (numeros)malloc(sizeof(struct vetor)); 

    for(i=0; i<N; i++){
        lista_prov->lista[i] = i+1;
    }

    printf("MAX: %d, N (elementos lista): %d\nDigite qualqeur tecla pra continuar...", MAX, N);
    getchar();

    system("clear");
    printf("Digite M: ");
    scanf("%d", &M);
    /////MOSTRA LISTA ORIGINAL/////

    printf("\nLista Original:\n");
    for(i=0; i<N; i++){
        printf("%d ", lista_prov->lista[i]);
    }
    printf("\n");
    ///////////////////////////////

    printf("\nElementos ao quadrado:\n");
    lista_quadrado = quadrado(lista_prov);

    /////MOSTRA LISTA QUADRADO/////

    printf("\n");
    printf("\nLista Quadrado:\n");
    for(i=0; i<N; i++){
        printf("%d ", lista_quadrado->lista[i]);
    }
    ///////////////////////////////


    printf("\n\nDigite uma base: ");
    scanf("%d", &base);

    /////MOSTRA LISTA ORIGINAL/////

    printf("\nLista Original:\n");
    for(i=0; i<N; i++){
        printf("%d ", lista_prov->lista[i]);
    }
    printf("\n");
    ///////////////////////////////

    printf("\nElementos com base %d:\n", base);
    lista_raiz = raiz(lista_prov, base);

    /////MOSTRA LISTA RAIZ/////

    printf("\n");
    printf("\nLista Raiz:\n");
    for(i=0; i<N; i++){
        printf("%d ", lista_raiz->lista[i]);
    }
    ///////////////////////////////
    
}