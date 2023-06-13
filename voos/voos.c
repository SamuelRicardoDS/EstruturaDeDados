#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct chave {
  int tempoDeVoo;
  int id;
} Chave;

int main() {
  FILE *fp = fopen("Airlines.csv", "r");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  char line[100];
  int *tempoDeVooOrdenado;

  while(fgets(line, sizeof(line), fp)) {

    char *token = strtok(line, ",");

    while(token != NULL) {
      printf("%s\n", token);
      token = strtok(NULL, ",");
    }
    printf("%s", line);
  }

}