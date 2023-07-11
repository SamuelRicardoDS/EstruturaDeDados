#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *vetor, int tamanhoVetor) {
  for(int i = 1; i < tamanhoVetor; i++) {
    int valor = vetor[i];
    int j = i - 1;

    while(j >= 0 && vetor[j] > valor) {
      vetor[j + 1] = vetor[j];
      j--;
    }

    vetor[j + 1] = valor;
  }
 
}

int main() {
  int *vetor;
  int tamanhoV;
  int valor;

  puts("qual o tamanho do vetor?");
  scanf("%d", &tamanhoV);
  vetor = (int *) malloc(tamanhoV * sizeof(int));

  puts("digite os valores do vetor");
  for(int i = 0; i < tamanhoV; i++) {
    scanf("%d", &vetor[i]);
  }

  insertionSort(vetor, tamanhoV);

  for(int i = 0; i < tamanhoV; i++) {
    printf("%d", vetor[i]);
  }

  free(vetor);
}