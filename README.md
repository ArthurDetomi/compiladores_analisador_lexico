# Analisador Léxico (Scanner) em C

Este projeto implementa a primeira fase de um compilador: o **Analisador Léxico**. Escrito em C, o scanner lê um arquivo de código-fonte, fatiando os caracteres e agrupando-os em unidades lógicas chamadas **Tokens** (identificadores, palavras reservadas, números, operadores, etc.), além de ignorar espaços em branco e comentários.

O analisador utiliza alocação dinâmica de memória para suportar lexemas de qualquer tamanho e possui um sistema de recuperação de erros (Error Recovery), permitindo que o processo continue mesmo se encontrar caracteres inválidos.

## 🚀 Como Executar

O projeto utiliza o `make` para facilitar a compilação. No terminal, na raiz do projeto, utilize os seguintes comandos:

1. **Para compilar o projeto:**

```bash
   make
```

2. **Para rodar o analisador:**

```bash
./main nome_do_arquivo.c
```

3. **Para limpar os arquivos binários gerados:**

```bash
make clean
```

---

## Exemplo de entrada/saída

O arquivo de exemplo se encontra em /input/entrada

**Entrada:**

```c
/*
nasjkdbahjsdgashjk  hjghjasgdhjghj  hjg
asdikahsdgasdjko
asdkjasgdjasgd
asdhasghsdjiaghsdko
ashasgal
*/

int main() {
  // comment
  int idade_usuario = 25;
  float salario_atual = 3500.50;

  // comment
  char inicial = 'A';
  char plica = '\'';

  // comment
  char texto = "Ola, \"Mundo\"!\n";

  // comment
  if (idade_usuario >= 18 == 1) {
    salario_atual = salario_atual + 500.0;
    idade_usuario++;
  } else {
    salario_atual = salario_atual - 100;
  }

  // comment
  while (idade_usuario != 30) {
    idade_usuario = idade_usuario + 1;
    continue;
  }

  // comment
  int vetor[5];
  vetor[0] = 10;

  // comment
  int preco = 10 @5;
#

  return 0;
}
```

**Saída:**

```
ERRO LEXICO: Caractere invalido na linha 19, coluna 29, lexema_erro = \
ERRO LEXICO: Caractere invalido na linha 40, coluna 18, lexema_erro = @
ERRO LEXICO: Caractere invalido na linha 41, coluna 1, lexema_erro = #

--- RESULTADO DA ANALISE LEXICA ---
CODIGO  | LEXEMA               | TIPO                 | LINHA | COLUNA
---------------------------------------------------------------------------
1       | int                  | PALAVRA_RESERVADA    | 9     | 1
0       | main                 | IDENT                | 9     | 5
25      | (                    | SEP_ABRE_PAR         | 9     | 9
26      | )                    | SEP_FECHA_PAR        | 9     | 10
27      | {                    | SEP_ABRE_CHAVE       | 9     | 12
1       | int                  | PALAVRA_RESERVADA    | 11    | 3
0       | idade_usuario        | IDENT                | 11    | 7
21      | =                    | OP_ATRIB             | 11    | 21
2       | 25                   | INT_LITERAL          | 11    | 23
29      | ;                    | SEP_PONTO_VIRGULA    | 11    | 25
1       | float                | PALAVRA_RESERVADA    | 12    | 3
0       | salario_atual        | IDENT                | 12    | 9
21      | =                    | OP_ATRIB             | 12    | 23
3       | 3500.50              | FLOAT_LITERAL        | 12    | 25
29      | ;                    | SEP_PONTO_VIRGULA    | 12    | 32
1       | char                 | PALAVRA_RESERVADA    | 15    | 3
0       | inicial              | IDENT                | 15    | 8
21      | =                    | OP_ATRIB             | 15    | 16
4       | 'A'                  | CHAR_LITERAL         | 15    | 18
29      | ;                    | SEP_PONTO_VIRGULA    | 15    | 21
1       | char                 | PALAVRA_RESERVADA    | 16    | 3
0       | plica                | IDENT                | 16    | 8
21      | =                    | OP_ATRIB             | 16    | 14
4       | '\''                 | CHAR_LITERAL         | 16    | 16
29      | ;                    | SEP_PONTO_VIRGULA    | 16    | 20
1       | char                 | PALAVRA_RESERVADA    | 19    | 3
0       | texto                | IDENT                | 19    | 8
21      | =                    | OP_ATRIB             | 19    | 14
5       | "Ola, \"             | STRING_LITERAL       | 19    | 16
0       | Mundo                | IDENT                | 19    | 24
5       | "!\n"                | STRING_LITERAL       | 19    | 30
29      | ;                    | SEP_PONTO_VIRGULA    | 19    | 35
1       | if                   | PALAVRA_RESERVADA    | 22    | 3
25      | (                    | SEP_ABRE_PAR         | 22    | 6
0       | idade_usuario        | IDENT                | 22    | 7
16      | >=                   | OP_MAIOR_IGUAL       | 22    | 21
2       | 18                   | INT_LITERAL          | 22    | 24
11      | ==                   | OP_IGUAL             | 22    | 27
2       | 1                    | INT_LITERAL          | 22    | 30
26      | )                    | SEP_FECHA_PAR        | 22    | 31
27      | {                    | SEP_ABRE_CHAVE       | 22    | 33
0       | salario_atual        | IDENT                | 23    | 5
21      | =                    | OP_ATRIB             | 23    | 19
0       | salario_atual        | IDENT                | 23    | 21
6       | +                    | OP_SOMA              | 23    | 35
3       | 500.0                | FLOAT_LITERAL        | 23    | 37
29      | ;                    | SEP_PONTO_VIRGULA    | 23    | 42
0       | idade_usuario        | IDENT                | 24    | 5
17      | ++                   | OP_INCR              | 24    | 18
29      | ;                    | SEP_PONTO_VIRGULA    | 24    | 20
28      | }                    | SEP_FECHA_CHAVE      | 25    | 3
1       | else                 | PALAVRA_RESERVADA    | 25    | 5
27      | {                    | SEP_ABRE_CHAVE       | 25    | 10
0       | salario_atual        | IDENT                | 26    | 5
21      | =                    | OP_ATRIB             | 26    | 19
0       | salario_atual        | IDENT                | 26    | 21
7       | -                    | OP_SUB               | 26    | 35
2       | 100                  | INT_LITERAL          | 26    | 37
29      | ;                    | SEP_PONTO_VIRGULA    | 26    | 40
28      | }                    | SEP_FECHA_CHAVE      | 27    | 3
1       | while                | PALAVRA_RESERVADA    | 30    | 3
25      | (                    | SEP_ABRE_PAR         | 30    | 9
0       | idade_usuario        | IDENT                | 30    | 10
12      | !=                   | OP_DIF               | 30    | 24
2       | 30                   | INT_LITERAL          | 30    | 27
26      | )                    | SEP_FECHA_PAR        | 30    | 29
27      | {                    | SEP_ABRE_CHAVE       | 30    | 31
0       | idade_usuario        | IDENT                | 31    | 5
21      | =                    | OP_ATRIB             | 31    | 19
0       | idade_usuario        | IDENT                | 31    | 21
6       | +                    | OP_SOMA              | 31    | 35
2       | 1                    | INT_LITERAL          | 31    | 37
29      | ;                    | SEP_PONTO_VIRGULA    | 31    | 38
1       | continue             | PALAVRA_RESERVADA    | 32    | 5
29      | ;                    | SEP_PONTO_VIRGULA    | 32    | 13
28      | }                    | SEP_FECHA_CHAVE      | 33    | 3
1       | int                  | PALAVRA_RESERVADA    | 36    | 3
0       | vetor                | IDENT                | 36    | 7
31      | [                    | SEP_ABRE_COLCH       | 36    | 12
2       | 5                    | INT_LITERAL          | 36    | 13
32      | ]                    | SEP_FECHA_COLCH      | 36    | 14
29      | ;                    | SEP_PONTO_VIRGULA    | 36    | 15
0       | vetor                | IDENT                | 37    | 3
31      | [                    | SEP_ABRE_COLCH       | 37    | 8
2       | 0                    | INT_LITERAL          | 37    | 9
32      | ]                    | SEP_FECHA_COLCH      | 37    | 10
21      | =                    | OP_ATRIB             | 37    | 12
2       | 10                   | INT_LITERAL          | 37    | 14
29      | ;                    | SEP_PONTO_VIRGULA    | 37    | 16
1       | int                  | PALAVRA_RESERVADA    | 40    | 3
0       | preco                | IDENT                | 40    | 7
21      | =                    | OP_ATRIB             | 40    | 13
2       | 10                   | INT_LITERAL          | 40    | 15
2       | 5                    | INT_LITERAL          | 40    | 19
29      | ;                    | SEP_PONTO_VIRGULA    | 40    | 20
1       | return               | PALAVRA_RESERVADA    | 43    | 3
2       | 0                    | INT_LITERAL          | 43    | 10
29      | ;                    | SEP_PONTO_VIRGULA    | 43    | 11
28      | }                    | SEP_FECHA_CHAVE      | 44    | 1
---------------------------------------------------------------------------
```

---

## 📚 Documentação das Funções

Abaixo está a descrição objetiva das funções que compõem o núcleo do Analisador Léxico (`scanner.c`):

### Motor Principal

- **`executar_analise_lexica(char *nome_arq_codigo_fonte)`**
  Abre o arquivo fonte e lê caractere por caractere (laço `while`). Funciona como um grande "despachante": dependendo do caractere lido, ele invoca a função de coleta correspondente. Retorna a Lista Encadeada contendo todos os tokens gerados.

### Funções de Coleta (Criadores de Tokens)

Todas as funções de coleta utilizam `malloc` e `realloc` para alocar a memória exata necessária para a string do lexema lido, prevenindo estouros de buffer (Buffer Overflow).

- **`coletar_ident_keyword(...)`**
  Lê letras, números e underlines (`_`). Ao finalizar a leitura, verifica se a palavra formada é uma palavra reservada da linguagem (ex: `int`, `if`). Se for, gera um token `PALAVRA_RESERVADA`; caso contrário, gera um token de identificador (`IDENT`).
- **`coletar_numero(...)`**
  Lê sequências numéricas. Identifica automaticamente se o número é um inteiro (`INT_LITERAL`) ou se possui ponto decimal (`FLOAT_LITERAL`). Contém validação básica para floats mal formatados.
- **`coletar_string(...)`**
  Lê todo o conteúdo entre aspas duplas `" "`. Ignora aspas internas caso estejam escapadas com barra invertida (`\"`). Gera o token `STRING_LITERAL`.
- **`coletar_char(...)`**
  Lê caracteres individuais entre plicas `' '`. Suporta caracteres de escape (como `\n`). Gera o token `CHAR_LITERAL`.
- **`coletar_operadores(...)`**
  Lê símbolos matemáticos e lógicos (`+`, `-`, `=`, `<`, `>`, `!`, `*`, `/`). Faz a verificação (lookahead) do próximo caractere para identificar se é um operador simples (ex: `=`) ou composto (ex: `==`, `++`).
- **`coletar_separadores(...)`**
  Identifica caracteres únicos de pontuação que organizam o código, como chaves `{}`, parênteses `()`, colchetes `[]`, vírgulas `,` e pontos e vírgulas `;`.

### Funções de Descarte (Ignoradas pelo Compilador)

- **`ignorar_comentario_linha(...)`**
  Ao detectar `//`, avança o cursor de leitura ignorando todos os caracteres até encontrar uma quebra de linha (`\n`).
- **`ignorar_comentario_bloco(...)`**
  Ao detectar `/*`, avança o cursor ignorando todos os caracteres, inclusive quebras de linha, até encontrar a sequência de fechamento `*/`.

### Utilitários e Tratamento de Erro

- **`is_palavra_reservada(char *lexema)`**
  Compara uma string lida com um dicionário interno de palavras-chave da linguagem C. Retorna `1` (verdadeiro) se for uma palavra reservada.
- **`criar_token(char *lexema, TokenType type, Posicao p)`**
  Aloca memória para a estrutura do Token, copia a string do lexema e anexa a posição exata (linha e coluna) de onde ele foi lido no arquivo original.
- **`disparar_erro(const char *mensagem, int linha, int coluna, char *lexema)`**
  Imprime mensagens de erro léxico no console sem interromper a execução (`exit`), permitindo que o scanner identifique múltiplos erros na mesma varredura.

---

## 🛠 Estrutura de Dados

Os tokens gerados são armazenados sequencialmente em uma **Lista Simplesmente Encadeada**, garantindo uso eficiente da memória. O ciclo de vida da memória é encerrado de forma segura no arquivo `main.c` com a função `destroiLista`, que varre a lista liberando os nós e os textos alocados.
