#include <stdio.h>

// Variáveis globais para armazenar a quantidade de chocolates
int qtdChocolateBranco = 0;
int qtdChocolateAoLeite = 0;
int totalCrocantes = 0;
int totalMistos = 0;
int totalTradicionais = 0;

// Funções para calcular os tipos de bombons
int calcularBombonsCrocantes(int amendoim, int chocolateBranco, int chocolateAoLeite);
int calcularBombonsMistos(int chocolateBranco, int chocolateAoLeite);
int calcularBombonsTradicionais(int chocolateAoLeite);
int calcularCaixasSortidas(int crocantes, int mistos, int tradicionais);
int calcularCaixasPrediletas(int crocantes, int mistos);
int calcularCaixasEspeciais(int crocantes);

int main() {
    // Variáveis locais para entrada e saídas
    int amendoim = 0;
    int caixasEspeciais = 0, caixasPrediletas = 0, caixasSortidas = 0;

    // Entrada de dados
    scanf("%d", &amendoim);
    scanf("%d", &qtdChocolateBranco);
    scanf("%d", &qtdChocolateAoLeite);
    
    // Cálculo de bombons
    totalCrocantes = calcularBombonsCrocantes(amendoim, qtdChocolateBranco, qtdChocolateAoLeite);
    totalMistos = calcularBombonsMistos(qtdChocolateBranco, qtdChocolateAoLeite);
    totalTradicionais = calcularBombonsTradicionais(qtdChocolateAoLeite);
    
    // Cálculo de caixas
    caixasSortidas = calcularCaixasSortidas(totalCrocantes, totalMistos, totalTradicionais);
    caixasPrediletas = calcularCaixasPrediletas(totalCrocantes, totalMistos);
    caixasEspeciais = calcularCaixasEspeciais(totalCrocantes);
    
    // Saída do resultado
    printf("%d %d %d", caixasEspeciais, caixasPrediletas, caixasSortidas);

    return 0;
}

int calcularBombonsCrocantes(int amendoim, int chocolateBranco, int chocolateAoLeite) {
    int crocantes = amendoim / 5;
    qtdChocolateBranco -= crocantes * 25;
    qtdChocolateAoLeite -= crocantes * 20;
    return crocantes;
}

int calcularBombonsMistos(int chocolateBranco, int chocolateAoLeite) {
    int mistos = chocolateBranco / 25;
    qtdChocolateAoLeite -= mistos * 25;
    return mistos;
}

int calcularBombonsTradicionais(int chocolateAoLeite) {
    return chocolateAoLeite / 50;
}

int calcularCaixasSortidas(int crocantes, int mistos, int tradicionais) {
    int caixasSortidas = tradicionais / 10;
    totalMistos -= caixasSortidas * 10;
    totalCrocantes -= caixasSortidas * 10;
    return caixasSortidas;
}

int calcularCaixasPrediletas(int crocantes, int mistos) {
    int caixasPrediletas = mistos / 20;
    totalCrocantes -= caixasPrediletas * 10;
    return caixasPrediletas;
}

int calcularCaixasEspeciais(int crocantes) {
    return crocantes / 30;
}