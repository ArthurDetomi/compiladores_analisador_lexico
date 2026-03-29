#include "../include/LSE.h"

Lista *criaLista() {
  Lista *li;
  li = (Lista *)malloc(sizeof(Lista));
  if (li != NULL) {
    *li = NULL;
  }
  return li;
}

int listaVazia(Lista *li) {
  if (li == NULL)
    return 1;
  if (*li == NULL)
    return 1; // True - Vazia!
  return 0;   // False - tem elemento!
}

NO *alocarNO() { return (NO *)malloc(sizeof(NO)); }

void liberarNO(NO *q) { free(q); }

int insereFim(Lista *li, Token elem) {
  if (li == NULL)
    return 0;
  NO *novo = alocarNO();
  if (novo == NULL)
    return 0;
  novo->info = elem;
  novo->prox = NULL;
  if (listaVazia(li)) {
    *li = novo;
  } else {
    NO *aux = *li;
    while (aux->prox != NULL)
      aux = aux->prox;
    aux->prox = novo;
  }
  return 1;
}

int removeIni(Lista *li) {
  if (li == NULL)
    return 0;
  if (listaVazia(li))
    return 0;
  NO *aux = *li;
  *li = aux->prox;
  liberarNO(aux);
  return 1;
}

int removeFim(Lista *li) {
  if (li == NULL)
    return 0;
  if (listaVazia(li))
    return 0;
  NO *ant, *aux = *li;
  while (aux->prox != NULL) {
    ant = aux;
    aux = aux->prox;
  }
  if (aux == *li)
    *li = aux->prox;
  else
    ant->prox = aux->prox;
  liberarNO(aux);
  return 1;
}

int tamanho(Lista *li) {
  if (li == NULL)
    return -1;
  if (listaVazia(li)) {
    return 0;
  }

  NO *aux = *li;

  int tamanho = 0;

  while (aux != NULL) {
    aux = aux->prox;
    tamanho++;
  }

  return tamanho;
}

void destroiLista(Lista *li) {
  if (li != NULL) {
    NO *aux;
    while ((*li) != NULL) {
      aux = *li;
      *li = (*li)->prox;

      if (aux->info.lexema != NULL) {
        free(aux->info.lexema);
      }

      liberarNO(aux);
    }
    free(li);
  }
}

void exibir_tokens(Lista *li) {
  if (li == NULL || *li == NULL) {
    printf("Lista de tokens vazia ou nao inicializada.\n");
    return;
  }

  printf("\n--- RESULTADO DA ANALISE LEXICA ---\n");
  printf("%-7s | %-20s | %-20s | %-5s | %-5s\n", "CODIGO", "LEXEMA", "TIPO",
         "LINHA", "COLUNA");
  printf("---------------------------------------------------------------------"
         "------\n");

  NO *atual = *li;

  while (atual != NULL) {
    Token t = atual->info;

    printf("%-7d | %-20s | %-20s | %-5d | %-5d\n", t.type, t.lexema,
           obter_nome_token(t.type), t.pos.linha, t.pos.coluna);

    atual = atual->prox;
  }

  printf("---------------------------------------------------------------------"
         "------\n\n");
}