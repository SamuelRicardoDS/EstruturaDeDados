#include <stdio.h>
#include <stdlib.h>
// a arvore é binária caso cada  nó tenha no máximo 2 filhos

typedef struct no
{
    int valor;
    struct no *filhoEsquerdo;
    struct no *filhoDireito;
} No;

typedef struct arvore
{
    struct no *raiz;
} Arvore;

Arvore *inicializaArvore()
{
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

void insereArvore(Arvore *arvore, int chave)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->valor = chave;
    novoNo->filhoDireito = NULL;
    novoNo->filhoEsquerdo = NULL;

    if (arvore->raiz == NULL)
    {
        arvore->raiz = novoNo;
    }
    else
    {
        No *noAtual = arvore->raiz;
        No *noPai;
        while (1)
        {
            noPai = noAtual;
            if (chave < noAtual->valor)
            {
                noAtual = noAtual->filhoEsquerdo;
                if (noAtual == NULL)
                {
                    noPai->filhoEsquerdo = novoNo;
                    return;
                }
            }
            else
            {
                noAtual = noAtual->filhoDireito;
                if (noAtual == NULL)
                {
                    noPai->filhoDireito = novoNo;
                    return;
                }
            }
        }
    }
}

void preOrder(No *no)
{
    if (no != NULL)
    {
        printf("%d ", no->valor);
        preOrder(no->filhoEsquerdo);
        preOrder(no->filhoDireito);
    }
}

void inOrder(No *no)
{
    if (no != NULL)
    {
        inOrder(no->filhoEsquerdo);
        printf("%d ", no->valor);
        inOrder(no->filhoDireito);
    }
}

void posOrder(No *no)
{
    if (no != NULL)
    {
        posOrder(no->filhoEsquerdo);
        posOrder(no->filhoDireito);
        printf("%d ", no->valor);
    }
}

int main()
{
    Arvore *arvore = inicializaArvore();
    insereArvore(arvore, 10);
    insereArvore(arvore, 5);
    insereArvore(arvore, 15);
    insereArvore(arvore, 3);
    insereArvore(arvore, 7);
    insereArvore(arvore, 12);
    printf("PreOrder: ");
    preOrder(arvore->raiz);
    printf("\nInOrder: ");
    inOrder(arvore->raiz);
    printf("\nPosOrder: ");
    posOrder(arvore->raiz);
    return 0;
}