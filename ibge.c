#include <stdio.h>
#include <stdlib.h>

typedef struct ibge
{
  char* ufMunicipio;
  int codigo;
  char* regiao;  
  int populacao;
} Ibge;


int main() {
  FILE *file = fopen("municipios.csv", "r");

  if(file != NULL){
        printf("Arquivo lido com sucesso!\n");
    }else{
        printf("Erro ao carregar o arquivo!\n");
  }

  int tamanhoVetor = 5570;

  int *codigos = malloc(tamanhoVetor * sizeof(int));

  for(int i = 0; i < tamanhoVetor; i++) {
    fscanf(file, "%d", &codigos[i]);
    printf("%d\n", codigos[i]);
  }

}