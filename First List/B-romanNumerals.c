#include <stdio.h>
#include <string.h>

// Função para converter um número inteiro para o numeral romano correspondente
void decimalParaRomano(int numero, char *romano) {
    struct {
        int valor;
        char *simbolo;
    } romanos[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    romano[0] = '\0';

    for (int i = 0; i < 13; i++) {
        while (numero >= romanos[i].valor) {
            strcat(romano, romanos[i].simbolo);  // Adiciona o símbolo romano à string
            numero -= romanos[i].valor;          // Subtrai o valor correspondente do número
        }
    }
}

int main() {
    int n;
    scanf("%d", &n); 

    int numeros[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }

    for (int i = 0; i < n; i++) {
        char romano[16];
        decimalParaRomano(numeros[i], romano);
        printf("%s", romano);
        if (i < n - 1) {
            printf("\n");
        }
    }
    printf("\n"); 
    return 0;
}