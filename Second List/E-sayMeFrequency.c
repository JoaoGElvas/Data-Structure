#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256  // Número máximo de caracteres ASCII

// Função para comparar os caracteres primeiro por frequência e depois pelo valor ASCII
int compara(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;

    // Comparar por frequência
    if (x[1] != y[1]) {
        return x[1] - y[1];
    }

    // Se as frequências forem iguais, comparar pelo valor ASCII
    return x[0] - y[0];
}

int main() {
    char linha[1001];  // Linha de entrada
    int primeiraLinha = 1;

    // Enquanto houver linhas na entrada
    while (fgets(linha, sizeof(linha), stdin)) {
        int frequencia[MAX_CHAR] = {0};  // Frequência de cada caractere
        int resultados[MAX_CHAR][2];    // Array para armazenar os caracteres e suas frequências
        int total = 0;

        // Contar a frequência de cada caractere
        for (int i = 0; linha[i] != '\0' && linha[i] != '\n'; i++) {
            frequencia[(unsigned char)linha[i]]++;
        }

        // Preencher o array de resultados com os caracteres e suas frequências
        for (int i = 0; i < MAX_CHAR; i++) {
            if (frequencia[i] > 0) {
                resultados[total][0] = i;         // Valor ASCII do caractere
                resultados[total][1] = frequencia[i];  // Frequência do caractere
                total++;
            }
        }

        // Ordenar os resultados
        qsort(resultados, total, sizeof(resultados[0]), compara);

        // Imprimir uma linha em branco entre os conjuntos de saída
        if (!primeiraLinha) {
            printf("\n");
        }
        primeiraLinha = 0;

        // Imprimir os resultados
        for (int i = 0; i < total; i++) {
            printf("%d %d\n", resultados[i][0], resultados[i][1]);
        }
    }

    // Linha em branco ao final da saída
    printf("\n");

    return 0;
}