#include <stdio.h>

int main() {
    int D, A, N;
    
    // Entrada
    scanf("%d", &D);  // Valor da diária no dia 1
    scanf("%d", &A);  // Aumento da diária por dia
    scanf("%d", &N);  // Dia de chegada no hotel
    
    // Cálculo do valor da diária no dia de chegada
    int valor_diaria = D + (N - 1) * A;
    
    // Cálculo do número de dias de estadia
    int dias = 32 - N; 
    
    int total = dias * valor_diaria;
    
    // Saída
    printf("%d\n", total);

    return 0;
}