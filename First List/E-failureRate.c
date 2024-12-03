#include <stdio.h>

#define MAX_DISCIPLINAS 100

typedef struct {
    int codigo;
    int reprovacoes;
} Disciplina;

void ordenar_codigos(int *codigos, int n) {
    // Ordenação por inserção para pequenos conjuntos
    for (int i = 1; i < n; i++) {
        int chave = codigos[i];
        int j = i - 1;
        while (j >= 0 && codigos[j] > chave) {
            codigos[j + 1] = codigos[j];
            j--;
        }
        codigos[j + 1] = chave;
    }
}

int main() {
    int D, A, S, m, codigo, matriculados, aprovados;

    scanf("%d", &D);

    while (scanf("%d %d %d", &A, &S, &m) != EOF) {
        int max_reprovacao = 0;
        int codigos_max_reprovacao[MAX_DISCIPLINAS];
        int num_disciplinas = 0;

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &codigo, &matriculados, &aprovados);
            int qtd_reprovacao = matriculados - aprovados;

            if (qtd_reprovacao > max_reprovacao) {
                max_reprovacao = qtd_reprovacao;
                codigos_max_reprovacao[0] = codigo;
                num_disciplinas = 1;
            } else if (qtd_reprovacao == max_reprovacao) {
                codigos_max_reprovacao[num_disciplinas++] = codigo;
            }
        }

        // Imprime o semestre
        printf("%d/%d\n", A, S);

        // Ordena os códigos das disciplinas com a maior reprovação
        ordenar_codigos(codigos_max_reprovacao, num_disciplinas);

        // Imprime os códigos ordenados
        for (int i = 0; i < num_disciplinas; i++) {
            printf("%d ", codigos_max_reprovacao[i]);
        }
        
        printf("\n\n");
    }

    return 0;
}