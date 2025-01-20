#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore binária
typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

// Estrutura para a pilha
typedef struct pilha {
    no **dados;
    int topo;
    int capacidade;
} pilha;

// Função para criar uma nova pilha
pilha *cria_pilha(int capacidade) {
    pilha *p = (pilha *)malloc(sizeof(pilha));
    p->dados = (no **)malloc(capacidade * sizeof(no *));
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

// Função para empilhar um nó
void empilha(pilha *p, no *n) {
    if (p->topo == p->capacidade - 1) {
        p->capacidade *= 2; // Aumenta a capacidade da pilha
        p->dados = (no **)realloc(p->dados, p->capacidade * sizeof(no *));
    }
    p->dados[++(p->topo)] = n;
}

// Função para desempilhar um nó
no *desempilha(pilha *p) {
    if (p->topo == -1) {
        return NULL;
    }
    return p->dados[(p->topo)--];
}

// Função para verificar se a pilha está vazia
int pilha_vazia(pilha *p) {
    return p->topo == -1;
}

// Função para liberar a memória da pilha
void libera_pilha(pilha *p) {
    free(p->dados);
    free(p);
}

// Função para realizar o percurso pós-ordem não recursivo
void pos_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }

    pilha *p = cria_pilha(10); // Pilha principal
    pilha *saida = cria_pilha(10); // Pilha auxiliar para saída

    empilha(p, raiz);

    while (!pilha_vazia(p)) {
        no *atual = desempilha(p);
        empilha(saida, atual);

        // Empilha os filhos esquerdo e direito na pilha principal
        if (atual->esq != NULL) {
            empilha(p, atual->esq);
        }
        if (atual->dir != NULL) {
            empilha(p, atual->dir);
        }
    }

    // Imprime os nós da pilha de saída (pós-ordem)
    while (!pilha_vazia(saida)) {
        printf("%d ", desempilha(saida)->dado);
    }

    libera_pilha(p);
    libera_pilha(saida);
}

// Função auxiliar para criar um novo nó
no *novo_no(int dado) {
    no *n = (no *)malloc(sizeof(no));
    n->dado = dado;
    n->esq = n->dir = NULL;
    return n;
}