#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *vetor, int tamanhoVetor) {
  int aux;
  //tamanhoVetor -1 por conta da comparação com o próximo valor
  for(int i = 0; i < tamanhoVetor -1; i++) {
    for(int j = 0; j < tamanhoVetor -1; j++) {
      if(vetor[j] > vetor[j+1]) {
        aux = vetor[j];
        vetor[j] = vetor[j+1];
        vetor[j+1] = aux;
      }
    }
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

  bubbleSort(vetor, tamanhoV);
  for(int i = 0; i < tamanhoV; i++) {
    printf("%d", vetor[i]);
  }
  free(vetor);
}