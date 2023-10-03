#include <stdio.h>

typedef struct celula
{
  int dado;
  struct celula *prox;
} celula;

void mescla_listas(celula *le, celula *le2, celula *le3) {
    celula *menorLum = le->prox;
    celula *menorLdois = le2->prox;
    celula *atualLtres = le3;
    
    while(menorLum != NULL && menorLdois != NULL) {
        if(menorLum->dado < menorLdois->dado) {
            atualLtres->prox = menorLum;
            menorLum = menorLum->prox;
        } else {
            atualLtres->prox = menorLdois;
            menorLdois = menorLdois->prox;
        }
        atualLtres = atualLtres->prox;
    }
     while(menorLum != NULL) {
      atualLtres->prox = menorLum;
      menorLum = menorLum->prox;
      atualLtres = atualLtres->prox;
     }

     while(menorLdois != NULL) {
      atualLtres->prox = menorLdois;
      menorLdois = menorLdois->prox;
      atualLtres = atualLtres->prox;
     }

     atualLtres->prox = NULL;
}








