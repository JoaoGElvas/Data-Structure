#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    if (*(float*)a < *(float*)b) return -1;
    if (*(float*)a > *(float*)b) return 1;
    return 0;
}

int main() {
    float D;
    float notas[7], soma = 0.0, resultado;

    // Leitura da dificuldade do salto
    scanf("%f", &D);

    // Leitura das 7 notas
    for (int i = 0; i < 7; i++) {
        scanf("%f", &notas[i]);
    }

    // Ordena as notas em ordem crescente
    qsort(notas, 7, sizeof(float), compare);

    // Soma as 5 notas do meio (descartando a maior e a menor)
    for (int i = 1; i < 6; i++) {
        soma += notas[i];
    }

    // Calcula a média das 5 notas restantes e multiplica pela dificuldade
    resultado = (soma / 5) * D;

    printf("%.1f\n", resultado);

    return 0;
}