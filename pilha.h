#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define limpa system("cls");
#define C_VM "\033[31m"
#define C_VRD    "\033[32m"
#define C_AZ     "\033[34m"
#define RESE_C  "\033[0m"

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
} Tpilha;

/*
  O QUE A FUNÇÃO FAZ:
    Inicializa a pilha dinamica encadeada apontando o topo para NULL[cite: 6].

  PARAMETROS:
    ponteiro que aponta para a struct Tpilha[cite: 6]

  RETORNO:
    Retorna um conjunto vazio[cite: 6]
*/
void inicializarPilha(Tpilha * const pilha);

/*
  O QUE A FUNÇÃO FAZ:
    verifica se existe algum elemento dentro da pilha[cite: 6]

  PARAMETROS:
    variavel que guarda um ponteiro que aponta apenas para a struct[cite: 6]

  RETORNO:
    Retorna uma booleana (true or false)[cite: 6]
*/
bool estaVazia(Tpilha const * const pilha);

/*
  O QUE A FUNÇÃO FAZ:
    verifica se a pilha atingiu a capacidade maxima[cite: 6]

  PARAMETROS:
    variavel que guarda um ponteiro que aponta apenas para a struct[cite: 6]

  RETORNO:
    Retorna uma booleana (true or false)[cite: 6]
*/
bool estaCheia(Tpilha const * const pilha);

/*
  O QUE A FUNÇÃO FAZ:
    Libera a memoria de todos os nos criados dinamicamente na pilha[cite: 6]

  PARAMETROS:
    variavel que guarda um ponteiro que aponta apenas para a struct[cite: 6]

  RETORNO:
    Retorna um conjunto vazio[cite: 6]
*/
void liberarPilha(Tpilha *const pilha);

/*
  O QUE A FUNÇÃO FAZ:
    acessa a pilha sempre pelo topo[cite: 6]

  PARAMETROS:
    variavel que guarda um ponteiro que aponta apenas para a struct[cite: 6]

  RETORNO:
    Retorna o valor do topo da pilha[cite: 6]
*/
int acessar(Tpilha const * const pilha);

/*
  O QUE A FUNÇÃO FAZ:
    aloca dinamicamente um novo no e empilha o elemento no topo[cite: 6]

  PARAMETROS:
    variavel que guarda um ponteiro que aponta apenas para a struct, Elemento a ser inserido[cite: 6]

  RETORNO:
    Retorna um conjunto vazio[cite: 6]
*/
void empilhar(Tpilha *const pilha, int elemento);

/*
  O QUE A FUNÇÃO FAZ:
    remove o no do topo e libera a memoria alocada[cite: 6]

  PARAMETROS:
    variavel que guarda um ponteiro que aponta apenas para a struct[cite: 6]

  RETORNO:
    Retorna um conjunto vazio[cite: 6]
*/
void desempilhar(Tpilha *const pilha);

/*
  O QUE A FUNÇÃO FAZ:
    Converte o valor passado por referencia para binario ou Octal[cite: 6]

  PARAMETROS:
    ponteiro que aponta apenas para a struct, valor(a ser convertido), tipo(para saber se eh binario ou octal)[cite: 6]

  RETORNO:
    Retorna um conjunto vazio[cite: 6]
*/
void converterValor(Tpilha *const pilha, int valor_a_converter, int tipo);

/*
  O QUE A FUNÇÃO FAZ:
    Converte o valor passado por referencia para hexadecimal[cite: 6]

  PARAMETROS:
    ponteiro que aponta apenas para a struct, valor(a ser convertido)[cite: 6]

  RETORNO:
    Retorna um conjunto vazio[cite: 6]
*/
void converterHexadecimal(Tpilha *const pilha, int valor_a_converter);

#endif