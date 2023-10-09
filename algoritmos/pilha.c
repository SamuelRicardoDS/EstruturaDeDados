#include <stdio.h>

typedef struct pilha
{
    int topo;
    int capacidade;
    int *elementos;
} Pilha;

void inicializaPilha(Pilha *pilha, int capacidade)
{
    pilha->topo = -1;
    pilha->capacidade = capacidade;
    pilha->elementos = (int *)malloc(sizeof(int) * pilha->capacidade);
}

void inserePilha(Pilha *pilha, int item)
{
    pilha->topo++;
    pilha->elementos[pilha->topo] = item;
}

void removePilha(Pilha *pilha, int item)
{
    pilha->topo--;
}

int main(void)
{
}