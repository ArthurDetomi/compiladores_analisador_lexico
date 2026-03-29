#ifndef LISTASE_H
#define LISTASE_H

#include "../include/token.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
  Token info;
  struct NO *prox;
} NO;

typedef struct NO *Lista;

Lista *criaLista();

int listaVazia(Lista *li);

NO *alocarNO();

void liberarNO(NO *q);

int insereFim(Lista *li, Token elem);

int removeIni(Lista *li);

int removeFim(Lista *li);

void destroiLista(Lista *li);

int tamanho(Lista *li);

void exibir_tokens(Lista *li);

#endif