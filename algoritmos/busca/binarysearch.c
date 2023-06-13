#include <stdio.h>
#include <stdlib.h>

void binarySearch(int *vetor, int valor, int tamanhoVetor) {
  int meio;
  int inicio = 0;
  int fim = tamanhoVetor - 1;

  while(inicio <= fim) {
    meio = (inicio + fim) / 2;
    if(vetor[meio] == valor) {
      printf("valor encontrado na posição %d", meio);
      break;
    } else if(vetor[meio] < valor) {
      inicio = meio + 1;
    } else {
      fim = meio - 1;
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

  puts("qual valor deseja encontrar");
  scanf("%d", &valor);

  binarySearch(vetor, valor, tamanhoV);
  free(vetor);

}