#include <stdio.h>
#include <stdlib.h>

// Definição da struct no
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função para inserir um valor na árvore binária de busca
no *inserir(no *r, int x) {
    if (r == NULL) {
        no *novo = (no *)malloc(sizeof(no)); // Aloca memória para o novo nó
        novo->chave = x; // Define o valor da chave
        novo->esq = NULL; // Inicializa a subárvore esquerda como NULL
        novo->dir = NULL; // Inicializa a subárvore direita como NULL
        return novo; // Retorna o novo nó
    }
    
    if (x < r->chave) {
        r->esq = inserir(r->esq, x); // Insere na subárvore esquerda
    } else if (x > r->chave) {
        r->dir = inserir(r->dir, x); // Insere na subárvore direita
    }
    // Se x == r->chave, a chave já existe, então não faz nada (não permite duplicatas)
    
    return r; // Retorna a raiz atualizada da árvore
}