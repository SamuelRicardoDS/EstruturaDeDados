#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int *vetorDaFila;
    int tamanhoDaFila;
    int inicioDaFila;
    int fimDaFila;
} *Fila;

void criaFila(Fila *fila, int tamanhoDaFila)
{
    *fila = malloc(sizeof(Fila));
    (*fila)->vetorDaFila = malloc(tamanhoDaFila * sizeof(int));
    (*fila)->tamanhoDaFila = tamanhoDaFila;
    (*fila)->inicioDaFila = 0;
    (*fila)->fimDaFila = 0;
}

void InsereNaFila(Fila *fila, int item)
{
    if ((*fila)->fimDaFila == (*fila)->tamanhoDaFila)
    {
        printf("Fila cheia\n");
        return;
    }
    (*fila)->vetorDaFila[(*fila)->fimDaFila] = item;
    (*fila)->fimDaFila++;
}

void removeFila(Fila *fila)
{
    if ((*fila)->inicioDaFila == (*fila)->fimDaFila)
    {
        printf("Fila vazia\n");
        return;
    }
    free((*fila)->inicioDaFila);
    (*fila)->inicioDaFila++;
}

int main(void)
{
}