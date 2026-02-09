#include<stdio.h>
#include<stdlib.h>

#define CAP 10

typedef struct{
    int valores[CAP];
    int topo;
} Pilha;

int esta_cheia(Pilha *pilha){
    return pilha->topo == CAP;
}

int empilhar(Pilha *pilha, int valor){
    if(esta_cheia(pilha)){
        return 0;
    }
    pilha->valores[pilha->topo] = valor;
    pilha->topo++;
    return 1;
}

int esta_vazia(Pilha *pilha){
    return pilha->topo == 0;
}

int desempilhar(Pilha *pilha){
    if(esta_vazia(pilha)){
        return 0;
    }
    return pilha->valores[--pilha->topo];
}

void imprimir(Pilha *pilha){
    printf("BASE\n");
    for(int i = pilha->topo - 1; i>=0; i--){
        printf("%d\n", pilha->valores[i]);
    }
    printf("BASE\n");

}

int main(){
    Pilha pilha;
    pilha.topo = 0;
    for(int i = 0;i<CAP;i++){
        empilhar(&pilha, i);
        imprimir(&pilha);
    }
    return 0;
}