#include <stdio.h>
#include <stdlib.h>

// Definição da struct no
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função para encontrar o valor mínimo na árvore binária de busca
no *minimo(no *r) {
    if (r == NULL) return NULL; // Caso a árvore esteja vazia
    while (r->esq != NULL) {
        r = r->esq; // Percorre para a esquerda até encontrar o menor valor
    }
    return r; // Retorna o nó com o menor valor
}