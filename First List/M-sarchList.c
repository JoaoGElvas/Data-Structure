#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x) {
    celula *atual = le->prox; // Começa no primeiro elemento da lista, após o nó cabeça
    while (atual != NULL) {
        if (atual->dado == x) {
            return atual; // Retorna o ponteiro para o nó com o valor x
        }
        atual = atual->prox;
    }
    return NULL; 
}

celula *busca_rec(celula *le, int x) {
    if (le == NULL) {
        return NULL; 
    }
    if (le->dado == x) {
        return le; 
    }
    return busca_rec(le->prox, x);
}