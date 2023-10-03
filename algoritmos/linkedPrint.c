#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int valor;
  struct node *proximo;
} Node;

Node* inicializalinkedList() {
  Node *cabeca;
  cabeca = (Node * ) malloc(sizeof(Node));
  cabeca->proximo = NULL;
  return cabeca;
}

void insereInicio(Node *cabeca, int valor) {
  Node *novoNode = (Node *) malloc(sizeof(Node));
  novoNode->valor = valor;
  novoNode->proximo = cabeca->proximo;
  cabeca->proximo = novoNode;
}
//c -> 1 -> NULL 
//c -> NULL
void insereFim(Node *cabeca, int valor) {
  Node *noAtual = cabeca;
  Node *novoNode = (Node *) malloc(sizeof(Node));
  novoNode->valor = valor;
  novoNode->proximo = NULL;

  if(cabeca->proximo == NULL) {
    cabeca->proximo = novoNode;
    return;
  } else {
    while(cabeca->proximo != NULL) {
      noAtual = noAtual->proximo;
    }
    noAtual->proximo = novoNode;
  }
}

void imprimeLista(Node *cabeca) {
  Node *noAtual = cabeca->proximo;
  if(cabeca->proximo == NULL) {
    printf("NULL");
  } else {
    while(noAtual != NULL) {
        printf("%d -> ", noAtual->valor);
        noAtual = noAtual->proximo;
    }
    printf("NULL");
  }
}

void imprimeListaRecursiva(Node *cabeca) {
  if(cabeca->proximo == NULL) {
    printf("NULL");
    return;
  } else {
    printf("%d -> ", cabeca->proximo->valor);
    imprimeListaRecursiva(cabeca->proximo);
  }
}

int main() {
    int quantidadeInicial;
    int valorAInserir;
    Node *cabeca = inicializalinkedList();
    imprimeListaRecursiva(cabeca);
    printf("\n");
}