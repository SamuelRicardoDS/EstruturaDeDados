#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *vetorDaFila;
    int tamanhoDaFila;
    int inicioDaFila;
    int fimDaFila;
} *Fila;

void criaFila(Fila *fila, int tamanhoDaFila) {
    *fila = malloc(sizeof(Fila));
    (*fila)->vetorDaFila = malloc(tamanhoDaFila * sizeof(int));
    (*fila)->tamanhoDaFila = tamanhoDaFila;
    (*fila)->inicioDaFila = 0;
    (*fila)->fimDaFila = 0;
}

void InsereNaFila () {

}

int main(void) {
   
}