#include <stdio.h>
#include <stdlib.h>

typedef struct circulo
{
  int raioMenor;
  int raioMaior;
  int pontuacao;
  struct circulo *prox;
} circulo;

circulo *inicializa()
{
  circulo *cabeca;
  cabeca = (circulo *)malloc(sizeof(circulo));
  cabeca->prox = NULL;
  return cabeca;
}

int calculaPontuacao()
{
  return 1;
}

void imprime_rec(circulo *le)
{
  if (le->prox == NULL)
  {
    printf("NULL\n");
  }
  else
  {
    printf("%d -> ", le->prox->raio);
    imprime_rec(le->prox);
  }
}

int main()
{
  int QuantidadeDeCirculos;
  int QuantidadeDeTiros;

  circulo *cabeca = inicializa();

  scanf("%d %d", &QuantidadeDeCirculos, &QuantidadeDeTiros);

  printf("quantidade de circulos %d\n", QuantidadeDeCirculos);
  printf("quantidade de tiros %d\n", QuantidadeDeTiros);

  circulo *atual = cabeca->prox;

  for (int i = 0; i < QuantidadeDeCirculos; i++)
  {
    atual = (circulo *)malloc(sizeof(circulo));
    atual->raio = scanf("%d", &atual->raio);
    atual = atual->prox;
  }

  imprime_rec(cabeca);
}