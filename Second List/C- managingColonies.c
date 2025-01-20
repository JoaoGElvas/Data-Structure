#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COLONIES (1 << 20) // Limite garantido de 2^20 colônias
#define MAX_FOOD_LEN 11        // Tamanho máximo da string do alimento (10 + 1 para '\0')

// Estrutura para armazenar cada entrada na tabela hash
typedef struct Node {
    int colony_id;               // ID da colônia
    char food[MAX_FOOD_LEN];     // Nome do alimento
    struct Node *next;           // Ponteiro para o próximo nó (em caso de colisão)
} Node;

// Tabela hash (lista ligada para tratar colisões)
Node *hash_table[MAX_COLONIES];

// Função de hash para mapear colônia e alimento
unsigned long hash(int colony_id, const char *food) {
    unsigned long h = colony_id;
    while (*food) {
        h = h * 31 + *food; // Multiplica por número primo para criar hash único
        food++;
    }
    return h % MAX_COLONIES;
}

// Função para verificar duplicação na tabela hash
bool is_duplicate(int colony_id, const char *food) {
    unsigned long h = hash(colony_id, food);
    Node *current = hash_table[h];

    // Percorre a lista na posição `h` para verificar duplicados
    while (current) {
        if (current->colony_id == colony_id && strcmp(current->food, food) == 0) {
            return true; // Duplicado encontrado
        }
        current = current->next;
    }

    // Não é duplicado, adicionar à lista
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->colony_id = colony_id;
    strcpy(new_node->food, food);
    new_node->next = hash_table[h];
    hash_table[h] = new_node;

    return false; // Não era duplicado
}

// Libera a memória alocada para a tabela hash
void free_hash_table() {
    for (int i = 0; i < MAX_COLONIES; i++) {
        Node *current = hash_table[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    // Inicializa a tabela hash
    memset(hash_table, 0, sizeof(hash_table));

    int colony_id;
    char food[MAX_FOOD_LEN];

    // Lendo a entrada até EOF
    while (scanf("%d %s", &colony_id, food) != EOF) {
        if (is_duplicate(colony_id, food)) {
            printf("%d\n", colony_id); // Imprime o ID da colônia para alimentos duplicados
        }
    }

    // Libera a memória usada pela tabela hash
    free_hash_table();

    return 0;
}