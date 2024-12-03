#include <stdio.h>

int main() {
    int N, count = 0;
    long long int sum = 0;  // Usando long long int para a soma
    
    scanf("%d", &N);
    int arr[N];
    
    // Leitura dos elementos do vetor e cálculo da soma
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];  // Somando no tipo long long int
    }
    
    // Cálculo da média aritmética inteira
    int media = sum / N;  // Não há problema em fazer a divisão aqui
    
    // Impressão dos elementos maiores que a média
    for (int i = 0; i < N; i++) {
        if (arr[i] > media) {
            if (count > 0) {
                printf(" ");
            }
            printf("%d", arr[i]);
            count++;
        }
    }
    
    // Se nenhum elemento for maior que a média, imprimir 0
    if (count == 0) {
        printf("0");
    }
    
    printf("\n");
    
    return 0;
}