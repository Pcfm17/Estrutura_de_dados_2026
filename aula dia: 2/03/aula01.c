#include<stdio.h>
#include<stdlib.h>

#define tamanho 7

typedef struct Celula{
    struct Celula *proxima;
    int valor;
} Celula;

typedef struct{
    Celula  *primeira;
    int qtde;
} Lista;

typedef struct {
    int qtde;
    Lista *lista[tamanho];
} Hash;

Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova -> proxima = NULL;
    nova -> valor = valor;
    return nova;
}

Lista *criar_lista(){
    Lista *nova = malloc(sizeof(Lista));
    nova -> primeira = NULL;
    nova -> qtde = 0;
    return nova;
}

Hash *criar_hash(){
    Hash *nova = malloc(sizeof(Hash));
    nova -> qtde = 0;
    for(int i = 0; i < tamanho; i++){
        nova -> lista[i] = criar_lista();
    }
    return nova;
}

int funcao_hash(int valor){
    return valor % tamanho;
}

void inserir(Hash *hash, int valor){
    int chave = funcao_hash(valor);
    Celula *nova = criar_celula(valor);
    Lista *lista = hash -> lista[chave];
    nova -> proxima = lista -> primeira;
    lista -> primeira = nova;
    lista -> qtde++;
    hash -> qtde++;
}

void imprimir(Hash *hash){
    Celula *atual = NULL;
    for(int i = 0; i < tamanho; i++){
        atual = hash -> lista[i] -> primeira;
        printf("%d ->", i);
        while(atual != NULL){
            printf("%d ", atual -> valor);
            atual = atual->proxima;
        }
        printf("\n");
    }
}

int main(){
    int valores[] = {190, 322, 172, 89, 13, 4, 769, 61, 15, 76};
    int qte = sizeof(valores) / sizeof(int);
    Hash *hash = criar_hash();
    for(int i = 0; i < qte; i++){
        inserir(hash, valores[i]);
    }
    for(int i = 0; i < qte; i++){
        //remover(hash, valores[i]); tem que fazer essa linha 
        imprimir(hash);
    }
    
    return 0;
}