#include <stdio.h>
#include <stdlib.h>

// Definição da struct no
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função para calcular a altura da árvore binária de busca
int altura(no *r) {
    if (r == NULL) {
        return 0; // Altura de uma árvore vazia é 0
    }
    int altura_esq = altura(r->esq); // Altura da subárvore esquerda
    int altura_dir = altura(r->dir); // Altura da subárvore direita
    return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir); // Maior altura + 1
}