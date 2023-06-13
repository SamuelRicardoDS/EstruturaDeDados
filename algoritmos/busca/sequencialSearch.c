#include <stdio.h>
#include <stdlib.h>

void sequencialSearch(int *vetor, int valor, int tamanhoVetor) {
  for(int i = 0; i < 9; i++) {
    if(vetor[i] ==  valor) {
      printf("valor encontrado na posição %d", i);
      break;
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

  sequencialSearch(vetor, valor, tamanhoV);
  free(vetor);
}