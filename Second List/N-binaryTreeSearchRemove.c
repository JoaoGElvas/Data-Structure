#include <stdio.h>
#include <stdlib.h>

// Definição da struct no
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função para encontrar o nó com o maior valor na subárvore esquerda (antecessor)
no *maior(no *r) {
    while (r != NULL && r->dir != NULL) {
        r = r->dir; // Percorre para a direita até encontrar o maior valor
    }
    return r;
}

// Função para remover um valor na árvore binária de busca
no *remover(no *r, int x) {
    if (r == NULL) {
        return NULL; // A chave não foi encontrada
    }

    if (x < r->chave) {
        r->esq = remover(r->esq, x); // Busca na subárvore esquerda
    } else if (x > r->chave) {
        r->dir = remover(r->dir, x); // Busca na subárvore direita
    } else {
        // Caso a chave a ser removida tenha sido encontrada
        if (r->esq == NULL && r->dir == NULL) {
            // Caso 1: O nó é uma folha, apenas o remove
            free(r);
            return NULL;
        } else if (r->esq == NULL) {
            // Caso 2: O nó tem apenas a subárvore direita
            no *temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            // Caso 3: O nó tem apenas a subárvore esquerda
            no *temp = r->esq;
            free(r);
            return temp;
        } else {
            // Caso 4: O nó tem ambas as subárvores
            // Encontra o maior nó da subárvore esquerda (antecessor)
            no *temp = maior(r->esq);
            r->chave = temp->chave; // Substitui a chave do nó pela do antecessor
            r->esq = remover(r->esq, temp->chave); // Remove o antecessor
        }
    }

    return r; // Retorna a raiz da árvore atualizada
}