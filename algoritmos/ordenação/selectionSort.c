#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *vetor, int tamanhoVetor) {
  for(int j = 0; j < tamanhoVetor; j++) {
    int aux;
    int i;
    //encontrar menor valor 
    int menor = j;
    for( i = j + 1; i < tamanhoVetor; i++) {
      if(vetor[i] < vetor[menor]) {
        menor = i;
      }
    }
    //trocar menor valor com o valor da posição j
    aux = vetor[j];
    vetor[j] = vetor[menor];
    vetor[menor] = aux;
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

  selectionSort(vetor, tamanhoV);
  for(int i = 0; i < tamanhoV; i++) {
    printf("%d", vetor[i]);
  }
  free(vetor);
}