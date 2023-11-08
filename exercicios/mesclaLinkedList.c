#include <stdio.h>
#include <stdlib.h>
typedef struct celula
{
  int dado;
  struct celula *prox;
} celula;

celula* inicializa() {
  celula *le;
  le = (celula *) malloc(sizeof(celula));
  le->prox = NULL;
  return le;
}

void imprime(celula *le) {
  celula *noAtual = le->prox;
  if(le->prox == NULL) {
    printf("NULL\n");
  } else {
    while(noAtual != NULL) {
        printf("%d -> ", noAtual->dado);
        noAtual = noAtual->prox;
    }
    printf("NULL\n");
  }
}

void imprime_rec(celula *le) {
  if(le->prox == NULL) {
    printf("NULL\n");
  } else {
    printf("%d -> ", le->prox->dado);
    imprime_rec(le->prox);
  }
}

void insere_inicio(celula *le, int x) {
  celula *novo = (celula *) malloc(sizeof(celula));
  novo->dado = x;
  novo->prox = le->prox;

  le->prox = novo;
}

void insere_antes(celula *le, int x, int y) {
  celula *anterior = le;
  celula *atual = le->prox;

  celula *novo = (celula *) malloc(sizeof(celula));
  novo->dado = x;

  while(atual != NULL) {
    if(atual->dado == y) {
        novo->prox = atual;
        anterior->prox = novo;
        return;
  }
    anterior = atual;
    atual = atual->prox;
  }
  novo->prox = NULL;
  anterior->prox = novo;
}
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

int main() {
    celula *le;
    celula *le2;
    celula *le3;

    le = inicializa();
    insere_inicio(le, 3);
    insere_inicio(le, 3);
    insere_inicio(le, 2);
    insere_inicio(le, 1);

    le2 = inicializa();
    insere_inicio(le2, 9);
    insere_inicio(le2, 8);
    insere_inicio(le2, 7);
    insere_inicio(le2, 6);

    le3 = inicializa();
    mescla_listas(le, le2, le3);
    printf("------- LE ------ \n");
    imprime(le);
    printf("------- LE2 ------ \n");
    imprime(le2);
    printf("------- MESCLA ------ \n");
    imprime(le3);
    return 0;
}
