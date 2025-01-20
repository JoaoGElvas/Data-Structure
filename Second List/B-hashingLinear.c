
#include <stdlib.h>

typedef struct {
  int *tb; // tabela hash
  int M;   // tamanho da tabela hash
  int N;   // total de chaves presentes na tabela
} TH;

// Declaração da função já implementada para aumentar o tamanho
int aumentaTamanho(int M);

// Função auxiliar para calcular o hash
int hash(int chave, int M) {
  return chave % M;
}

// Função auxiliar para redimensionar a tabela
void redimensionaTabela(TH *h) {
  int novoM = aumentaTamanho(h->M);
  int *novaTabela = (int *)malloc(novoM * sizeof(int));

  // Inicializa a nova tabela com -1 (vazio)
  for (int i = 0; i < novoM; i++) {
    novaTabela[i] = -1;
  }

  // Reinsere os elementos da tabela antiga na nova tabela
  for (int i = 0; i < h->M; i++) {
    if (h->tb[i] != -1) {
      int pos = hash(h->tb[i], novoM);
      while (novaTabela[pos] != -1) {
        pos = (pos + 1) % novoM;
      }
      novaTabela[pos] = h->tb[i];
    }
  }

  free(h->tb);
  h->tb = novaTabela;
  h->M = novoM;
}

// Insere uma chave na tabela hash
void THinsere(TH *h, int ch) {
  // Verifica taxa de ocupação e redimensiona se necessário
  if (h->N > h->M / 2) {
    redimensionaTabela(h);
  }

  // Calcula posição inicial
  int pos = hash(ch, h->M);

  // Evita duplicatas e encontra posição vazia
  while (h->tb[pos] != -1) {
    if (h->tb[pos] == ch) return; // Chave já existe
    pos = (pos + 1) % h->M;
  }

  // Insere a chave
  h->tb[pos] = ch;
  h->N++;
}

// Remove uma chave da tabela hash
int THremove(TH *h, int ch) {
  int pos = hash(ch, h->M);

  // Procura a chave
  while (h->tb[pos] != -1) {
    if (h->tb[pos] == ch) {
      h->tb[pos] = -1; // Remove a chave
      h->N--;

      // Reinsere elementos necessários
      pos = (pos + 1) % h->M;
      while (h->tb[pos] != -1) {
        int chaveReinserir = h->tb[pos];
        h->tb[pos] = -1;
        h->N--;
        THinsere(h, chaveReinserir);
        pos = (pos + 1) % h->M;
      }

      return 0; // Remoção bem-sucedida
    }
    pos = (pos + 1) % h->M;
  }

  return -1; // Chave não encontrada
}

// Busca por uma chave na tabela hash
int THbusca(TH *h, int ch) {
  int pos = hash(ch, h->M);

  // Procura a chave
  while (h->tb[pos] != -1) {
    if (h->tb[pos] == ch) return 1; // Chave encontrada
    pos = (pos + 1) % h->M;
  }

  return 0; // Chave não encontrada
}