#include <stdio.h>
#include <stdlib.h>

// Definição da struct no
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função para encontrar o valor máximo na árvore binária de busca
no *maximo(no *r) {
    if (r == NULL) return NULL; // Caso a árvore esteja vazia
    while (r->dir != NULL) {
        r = r->dir; // Percorre para a direita até encontrar o maior valor
    }
    return r; // Retorna o nó com o maior valor
}