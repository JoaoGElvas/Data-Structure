#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

typedef struct {
  celula *tb; // tabela hash
  int M;      // tamanho da tabela hash
  int N;      // total de chaves presentes na tabela
} TH;

// Função auxiliar para calcular o hash
int hash(int chave, int M) {
  return chave % M;
}

// Insere uma chave na tabela hash
void THinsere(TH *h, int ch) {
  int pos = hash(ch, h->M);
  celula *atual = h->tb[pos].prox;

  // Verificar duplicatas
  while (atual != NULL) {
    if (atual->dado == ch) return; // Chave já existe
    atual = atual->prox;
  }

  // Inserir no início da lista
  celula *novo = (celula *)malloc(sizeof(celula));
  novo->dado = ch;
  novo->prox = h->tb[pos].prox;
  h->tb[pos].prox = novo;
  h->N++;
}

// Remove uma chave da tabela hash
int THremove(TH *h, int ch) {
  int pos = hash(ch, h->M);
  celula *atual = &h->tb[pos];
  celula *anterior = NULL;

  while (atual->prox != NULL) {
    anterior = atual;
    atual = atual->prox;
    if (atual->dado == ch) {
      anterior->prox = atual->prox;
      free(atual);
      h->N--;
      return 0; // Remoção bem-sucedida
    }
  }
  return -1; // Chave não encontrada
}

// Busca por uma chave na tabela hash
int THbusca(TH *h, int ch) {
  int pos = hash(ch, h->M);
  celula *atual = h->tb[pos].prox;

  while (atual != NULL) {
    if (atual->dado == ch) return 1; // Chave encontrada
    atual = atual->prox;
  }
  return 0; // Chave não encontrada
}