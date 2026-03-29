#include "../include/LSE.h"
#include "../include/scanner.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    perror("ERROR: arquivo de entrada não informado!");
    exit(1);
  }

  Lista *lista_tokens = executar_analise_lexica(argv[1]);

  exibir_tokens(lista_tokens);

  destroiLista(lista_tokens);

  return 0;
}