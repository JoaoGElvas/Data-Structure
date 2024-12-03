#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> 

// Função para verificar se a sigla é válida
bool siglaValida(char *aeroporto, char *sigla) {
    int lenAeroporto = strlen(aeroporto);
    int lenSigla = 3;
    int j = 0;

    // Caso a sigla termine com 'X', considerar apenas os dois primeiros caracteres
    if (sigla[2] == 'X') {
        lenSigla = 2;
    }

    // Percorrer o nome do aeroporto e verificar se as letras da sigla aparecem em ordem
    for (int i = 0; i < lenAeroporto && j < lenSigla; i++) {
        char letraAtual = aeroporto[i];
        if (letraAtual >= 'a' && letraAtual <= 'z') {
            letraAtual -= 32; // Converte para maiúscula (equivalente a toupper())
        }
        
        // Verifica se a letra do aeroporto corresponde à da sigla
        if (letraAtual == sigla[j]) {
            j++;
        }
    }

    return j == lenSigla;
}

int main() {
    char aeroporto[100001];
    char sigla[4];

    scanf("%s", aeroporto);
    scanf("%s", sigla);

    // Verifica e imprime o resultado
    if (siglaValida(aeroporto, sigla)) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    return 0;
}