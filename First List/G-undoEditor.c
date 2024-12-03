#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 100
#define MAX_HISTORY 1000

// Pilha para armazenar as alterações
char history[MAX_HISTORY][MAX_STR_LEN];
int top = -1;  // Indicador do topo da pilha

// Função para inserir uma nova alteração no histórico
void inserir(const char *str) {
    if (top < MAX_HISTORY - 1) {
        top++;
        strcpy(history[top], str);
    }
}

// Função para desfazer a última alteração
void desfazer() {
    if (top == -1) {
        printf("NULL\n");
    } else {
        printf("%s\n", history[top]);
        top--;  // Remover o último item
    }
}

int main() {
    char command[MAX_STR_LEN + 10];  // Buffer para ler o comando
    char str[MAX_STR_LEN];  // Buffer para armazenar a string da alteração

    while (fgets(command, sizeof(command), stdin)) {
        // Verificar se é o comando 'inserir'
        if (sscanf(command, "inserir %[^\n]", str) == 1) {
            inserir(str);
        }
        // Verificar se é o comando 'desfazer'
        else if (strcmp(command, "desfazer\n") == 0) {
            desfazer();
        }
    }

    return 0;
}