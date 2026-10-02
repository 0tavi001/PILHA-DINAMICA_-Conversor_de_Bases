#include "pilha.h"

/*
  O QUE A FUNÇÃO FAZ:
    Inicializa a pilha dinamica encadeada apontando o topo para NULL[cite: 5].

  PARAMETROS:
    ponteiro que aponta para a struct Tpilha[cite: 5]

  RETORNO:
    Retorna um conjunto vazio[cite: 5]
*/
void inicializarPilha(Tpilha * const pilha) {
    pilha->topo = NULL;
}

/*
  O QUE A FUNÇÃO FAZ:
    verifica se existe algum elemento dentro da pilha[cite: 5]

  PARAMETROS:
    variavel que guarda um ponteiro que aponta apenas para a struct[cite: 5]

  RETORNO:
    Retorna uma booleana (true or false)[cite: 5]
*/
bool estaVazia(Tpilha const * const pilha) {
    return (pilha->topo == NULL);
}

/*
  O QUE A FUNÇÃO FAZ:
    Confere se a pilha atingiu a sua capacidade máxima[cite: 5]

  PARAMETROS:
    variavel que guarda um ponteiro que aponta apenas para a struct[cite: 5]

  RETORNO:
    Retorna uma booleana (true or false)[cite: 5]
*/
bool estaCheia(Tpilha const * const pilha) {
    return false;
}

/*
  O QUE A FUNÇÃO FAZ:
    diminui o controlador da pilha liberando o no do topo[cite: 5]

  PARAMETROS:
    variavel que guarda um ponteiro que aponta apenas para a struct[cite: 5]

  RETORNO:
    Retorna um conjunto vazio[cite: 5]
*/
void desempilhar(Tpilha *const pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia! Nao e possivel desempilhar.\n");
        return;
    }
    No *aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(aux);
}

/*
  O QUE A FUNÇÃO FAZ:
    Libera a pilha criada dinamicamente[cite: 5]

  PARAMETROS:
    variavel que guarda um ponteiro que aponta apenas para a struct[cite: 5]

  RETORNO:
    Retorna um conjunto vazio[cite: 5]
*/
void liberarPilha(Tpilha *const pilha) {
    while (!estaVazia(pilha)) {
        desempilhar(pilha);
    }
}

/*
  O QUE A FUNÇÃO FAZ:
    acessa a pilha sempre pelo topo[cite: 5]

  PARAMETROS:
    variavel que guarda um ponteiro que aponta apenas para a struct[cite: 5]

  RETORNO:
    Retorna o valor do topo da pilha[cite: 5]
*/
int acessar(Tpilha const * const pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia! Nenhum elemento para acessar.\n");
        return -1;
    }
    return pilha->topo->dado;
}

/*
  O QUE A FUNÇÃO FAZ:
    aloca dinamicamente um novo no e empilha o elemento no topo[cite: 5]

  PARAMETROS:
    variavel que guarda um ponteiro que aponta apenas para a struct, Elemento a ser inserido[cite: 5]

  RETORNO:
    Retorna um conjunto vazio[cite: 5]
*/
void empilhar(Tpilha *const pilha, int elemento) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: Memoria insuficiente para empilhar!\n");
        return;
    }
    novo->dado = elemento;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

/*
  O QUE A FUNÇÃO FAZ:
    Converte o valor passado por referencia para binario ou Octal[cite: 5]

  PARAMETROS:
    ponteiro que aponta apenas para a struct, valor(a ser convertido), tipo(para saber se eh binario ou octal)[cite: 5]

  RETORNO:
    Retorna um conjunto vazio[cite: 5]
*/
void converterValor(Tpilha *const pilha, int valor_a_converter, int tipo) {
    if (valor_a_converter == 0) {
        empilhar(pilha, 0);
        return;
    }

    while (valor_a_converter > 0) {
        empilhar(pilha, valor_a_converter % tipo); 
        valor_a_converter = valor_a_converter / tipo;
    }
}

/*
  O QUE A FUNÇÃO FAZ:
    Converte o valor passado por referencia para hexadecimal[cite: 5]

  PARAMETROS:
    ponteiro que aponta apenas para a struct, valor(a ser convertido)[cite: 5]

  RETORNO:
    Retorna um conjunto vazio[cite: 5]
*/
void converterHexadecimal(Tpilha *const pilha, int valor_a_converter) {
    if (valor_a_converter == 0) {
        empilhar(pilha, 0);
        return;
    }

    while (valor_a_converter > 0) {
        int resto = valor_a_converter % 16;
        empilhar(pilha, resto);
        valor_a_converter = valor_a_converter / 16;
    }
}