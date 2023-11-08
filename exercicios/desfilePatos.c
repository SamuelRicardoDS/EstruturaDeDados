#include <stdio.h>
#include <stdlib.h>

// ver qual a cor majoritária

typedef struct node
{
    int numeroDeElementos;
    int codigo;
    struct node *prox;
} Node;

typedef struct HashTable
{
    Node *cabeca;
    int tamanhoM;
    int totalChavesN;
} HashTable;

HashTable *inicializaHashTable(int quantidadeDePatos)
{
    HashTable *tabelaHash = (HashTable *)malloc(sizeof(HashTable));
    tabelaHash->tamanhoM = quantidadeDePatos;

    tabelaHash->cabeca = (Node *)malloc(sizeof(Node) * tabelaHash->tamanhoM);
    tabelaHash->totalChavesN = 0;
    return tabelaHash;
}

void THinsere(HashTable *tabela, int codigo)
{
    int posicao = codigo % tabela->tamanhoM;
    Node *noAtual = &tabela->cabeca[posicao];

    while (noAtual->prox != NULL)
    {
        if (noAtual->prox->codigo == codigo)
        {
            noAtual->numeroDeElementos++;
        }
        noAtual = noAtual->prox;
    }
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->codigo = codigo;
    novoNo->prox = tabela->cabeca[posicao].prox;
    tabela->cabeca[posicao].prox = novoNo;

    tabela->totalChavesN++;
}

int main()
{
    int quantidadeDePatos;
    scanf("%d", quantidadeDePatos);

    inicializaHashTable(quantidadeDePatos);
}