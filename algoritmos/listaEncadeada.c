#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int valor;
  struct node *proximo;
} Node;

typedef struct descritorLinkedList
{
  Node *primeiroNo;
  int quantidadeDeNos;
  Node *ultimoNo;
} DescritorLinkedList;

DescritorLinkedList inicializalinkedList() {
  DescritorLinkedList lista;
  Node *cabeca;
  cabeca = NULL;
  lista.primeiroNo = cabeca;
  lista.ultimoNo = cabeca;
  lista.quantidadeDeNos = 0;

  return lista;
}

void insereInicio(DescritorLinkedList *lista, int valor) {
  Node *novoNode;
  novoNode = (Node *) malloc(sizeof(Node));
  novoNode->valor = valor;
  if(lista->primeiroNo == NULL) {
    lista->ultimoNo = novoNode;
  }
  novoNode->proximo = lista->primeiroNo;
  
  lista->primeiroNo = novoNode;
  lista->quantidadeDeNos = lista->quantidadeDeNos + 1;

  printf("quantidade de nos: %d\n", lista->quantidadeDeNos);
}

void insereFim(DescritorLinkedList *lista, int valor) {
  Node *novoNode, *aux;
  novoNode = (Node *) malloc(sizeof(Node));
  novoNode->valor = valor;
  novoNode->proximo = NULL;

  lista->ultimoNo->proximo = novoNode;
  lista->ultimoNo = novoNode;
  lista->quantidadeDeNos = lista->quantidadeDeNos +1;

}

void removeInicio(DescritorLinkedList *lista) {

}

void removeFim() {

}

void imprimeLista(DescritorLinkedList *lista) {
  Node *noAtual = lista->primeiroNo;
  puts("Lista:");
  while(noAtual != NULL) {
    printf("%d", noAtual->valor);
    noAtual = noAtual->proximo;
  }
  printf("\n");
}

int menu() {
  int escolhaMenu = 0;
  int valorInserir;
  
  do {

    puts("Qual operação deseja realizar?");
    puts("digite 1: para inicializar uma linkedList");
    puts("digite 2: para inserir um no no inicio da lista");
    puts("digite 3: para inserir um no no final da lista");
    puts("digite 4: para remover o no do inicio da lista");
    puts("digite 5: para remover o no do inicio da lista");
    puts("digite 6: para imprimir a lista");
    puts("----------------------------------");

    scanf("%d", &escolhaMenu);

    switch (escolhaMenu)
    {
    case 1:
      DescritorLinkedList lista = inicializalinkedList();
      printf("Quantidade de nos: %d\n", lista.quantidadeDeNos);
      break;

    case 2:
      puts("Qual valor deseja inserir?");
      scanf("%d", &valorInserir);

      insereInicio(&lista, valorInserir);
      break;

    case 3:
      puts("Qual valor deseja inserir?");
      scanf("%d", &valorInserir);

      insereFim(&lista, valorInserir);
      break;

    case 4:
      removeInicio(&lista);
      break;

    case 5:
      removeFim();
      break;

    case 6:
      imprimeLista(&lista);
      break;
      
    default:
      puts("insere um numero do menu oh carai");
    }
  } while (escolhaMenu != 0); 
}

int main(void) {
  menu();
}