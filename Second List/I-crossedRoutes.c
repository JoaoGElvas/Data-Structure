#include <stdio.h>
#include <string.h>

void posfixo(char* prefixo, char* infixo, int tamanho) {
    // Caso base: se não há elementos, retornamos imediatamente
    if (tamanho == 0) {
        return;
    }

    // A raiz é o primeiro elemento do percurso prefixo
    char raiz = prefixo[0];

    // Encontramos a raiz no percurso infixo
    int raiz_pos = 0;
    for (int i = 0; i < tamanho; i++) {
        if (infixo[i] == raiz) {
            raiz_pos = i;
            break;
        }
    }

    // Chamada recursiva para a sub-árvore esquerda
    posfixo(prefixo + 1, infixo, raiz_pos);
    // Chamada recursiva para a sub-árvore direita
    posfixo(prefixo + raiz_pos + 1, infixo + raiz_pos + 1, tamanho - raiz_pos - 1);
    
    // Imprimimos a raiz após as sub-árvores
    printf("%c", raiz);
}

int main() {
    int C;
    scanf("%d", &C);

    while (C--) {
        int N;
        char S1[53], S2[53];

        scanf("%d %s %s", &N, S1, S2);

        posfixo(S1, S2, N);
        printf("\n");
    }


    return 0;
}