#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função para inserir no início da lista encadeada
void insere_inicio(celula *le, int x) {
    celula *novo = malloc(sizeof(celula));
    if (novo != NULL) {
        novo->dado = x;
        novo->prox = le->prox;
        le->prox = novo;
    }
}

// Função para inserir antes da primeira ocorrência de y
void insere_antes(celula *le, int x, int y) {
    celula *p = le;
    while (p->prox != NULL && p->prox->dado != y) {
        p = p->prox;
    }
    celula *novo = malloc(sizeof(celula));
    if (novo != NULL) {
        novo->dado = x;
        novo->prox = p->prox;
        p->prox = novo;
    }
}