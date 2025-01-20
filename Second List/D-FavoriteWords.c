 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 200003 // Tamanho da tabela hash (número primo grande)
#define MAX_PALAVRA 17   // Tamanho máximo da palavra (16 caracteres + '\0')

// Estrutura para armazenar uma palavra e sua contagem
typedef struct No {
    char palavra[MAX_PALAVRA];
    int contagem;
    struct No *prox;
} No;

// Tabela hash
No *hashTable[HASH_SIZE];

// Função hash para strings
unsigned int hash(const char *str) {
    unsigned int h = 0;
    while (*str) {
        h = (h * 31 + (*str)) % HASH_SIZE;
        str++;
    }
    return h;
}

// Função para encontrar ou criar um nó para a palavra na tabela hash
No *encontraOuCria(const char *palavra) {
    unsigned int h = hash(palavra);
    No *atual = hashTable[h];

    // Procura a palavra na lista encadeada
    while (atual) {
        if (strcmp(atual->palavra, palavra) == 0) {
            return atual; // Palavra encontrada
        }
        atual = atual->prox;
    }

    // Se não encontrou, cria um novo nó
    No *novo = (No *)malloc(sizeof(No));
    strcpy(novo->palavra, palavra);
    novo->contagem = 0;
    novo->prox = hashTable[h];
    hashTable[h] = novo;

    return novo;
}

// Função para processar os comandos
void processaComando(int comando, const char *palavra) {
    No *no = encontraOuCria(palavra);

    if (comando == 1) {
        // Computa mais um voto para a palavra
        no->contagem++;
    } else if (comando == 2) {
        // Imprime a quantidade de votos da palavra
        printf("%d\n", no->contagem);
    } else if (comando == 3) {
        // Reseta a quantidade de votos da palavra
        no->contagem = 0;
    }
}

int main() {
    int comando;
    char palavra[MAX_PALAVRA];

    // Inicializa a tabela hash com NULL
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Lê os comandos até EOF
    while (scanf("%d %s", &comando, palavra) != EOF) {
        processaComando(comando, palavra);
    }

    // Libera memória alocada
    for (int i = 0; i < HASH_SIZE; i++) {
        No *atual = hashTable[i];
        while (atual) {
            No *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }

    return 0;
}