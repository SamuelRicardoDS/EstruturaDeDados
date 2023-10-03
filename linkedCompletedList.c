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

void remove_depois(celula *p) {
  celula *celulaARemover = p->prox;
  if(celulaARemover == NULL) {
    return;
  }
  p->prox = celulaARemover->prox;
  free(celulaARemover);
}

void remove_elemento(celula *le, int x) {
  celula *anterior = le;
  celula *atual = le->prox;
  while(atual != NULL) {
    if(atual->dado == x) {
      anterior->prox = atual->prox;
      free(atual);
      return;
    }
    anterior = atual;
    atual = atual->prox;
  }
}

void remove_todos_elementos(celula *le, int x) {
  celula *anterior = le;
  celula *atual = le->prox;
  while(atual != NULL) {
   if (atual->dado == x) {
      celula *temp = atual;
      anterior->prox = atual->prox;
      atual = atual->prox;
      free(temp);
    } else {
      anterior = atual;
      atual = atual->prox;
    }
  }
}

celula* busca(celula *le, int x) {
  celula *noAtual = le->prox;
  while(noAtual != NULL) {
    if(noAtual->dado == x) {
      return noAtual;
    }
    noAtual = noAtual->prox;
  }
  return NULL;
}

celula* busca_rec(celula *le, int x) {
  celula *noAtual = le->prox;
  if(noAtual == NULL) {
    return NULL;
  }
  if(noAtual->dado == x) {
    return noAtual;
  }
  return busca_rec(noAtual, x);
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
  le = inicializa();
  insere_inicio(le, 1);
  insere_inicio(le, 2);
  insere_inicio(le, 3);
  insere_inicio(le, 3);
  insere_antes(le, 9, 1);
  insere_antes(le, 1, 9);
  insere_antes(le, 1, 2);
  remove_todos_elementos(le, 9);
  imprime(le);
  imprime_rec(le);
  printf("\n digite o valor que deseja buscar");
  int x;
  scanf("%d", &x);
  celula *noEncontrado = busca_rec(le, x);
  if(noEncontrado == NULL) {
    printf("Valor nao encontrado");
  } else {
    printf("Valor encontrado: %d", noEncontrado->dado);
  }
  return 0;
}
