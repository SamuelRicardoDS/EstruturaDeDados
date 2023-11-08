#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int valor;
    struct node *prox;
} Node;

typedef struct HashTable
{
    Node *cabeca;
    int tamanhoM;
    int totalChavesN;
} HashTable;

HashTable *inicializaHashTable()
{
    HashTable *tabelaHash = (HashTable *)malloc(sizeof(HashTable));
    tabelaHash->tamanhoM = 3;

    tabelaHash->cabeca = (Node *)malloc(sizeof(Node) * tabelaHash->tamanhoM);
    tabelaHash->totalChavesN = 0;
    return tabelaHash;
}

void THinsere(HashTable *tabela, int chave)
{

    
    int posicao = chave % tabela->tamanhoM;
    Node *noAtual = &tabela->cabeca[posicao];

    while (noAtual->prox != NULL)
    {
        if (noAtual->prox->valor == chave)
        {
            return;
        }
        noAtual = noAtual->prox;
    }
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->valor = chave;
    novoNo->prox = tabela->cabeca[posicao].prox;
    tabela->cabeca[posicao].prox = novoNo;

    tabela->totalChavesN++;
}

void THremove(HashTable *tabela, int chave)
{
    int posicao = chave % tabela->tamanhoM;
    Node *noAtual = &tabela->cabeca[posicao];

    Node *aux;
    while (noAtual->prox != NULL)
    {
        if (noAtual->prox->valor == chave)
        {
            Node *aux = noAtual->prox;
            noAtual->prox = aux->prox;
            free(aux);
            tabela->totalChavesN--;
            return;
        }
        noAtual = noAtual->prox;
    }
}

int THbusca(HashTable *tabela, int chave)
{
    int posicao = chave % tabela->tamanhoM;
    Node *noAtual = &tabela->cabeca[posicao];

    while (noAtual->prox != NULL)
    {
        if (noAtual->prox->valor == chave)
        {
            return 1;
        }
        noAtual = noAtual->prox;
    }
    return 0;
}

void imprime_hash(HashTable *h)
{
    for (int i = 0; i < h->tamanhoM; i++)
    {
        Node *atual = h->cabeca[i].prox;

        printf("Entrada %d: ", i);

        while (atual != NULL)
        {

            printf("%d -> ", atual->valor);
            atual = atual->prox;
        }

        printf("\n");
    }
}

int main()
{
    HashTable *tabelaHash = inicializaHashTable();

    THinsere(tabelaHash, 16);
    THinsere(tabelaHash, 3);
    THinsere(tabelaHash, 16);
    THinsere(tabelaHash, 3);
    THinsere(tabelaHash, 35);
    THinsere(tabelaHash, 38);
    THinsere(tabelaHash, 41);
    THremove(tabelaHash, 38);

    printf("achou: %d\n", THbusca(tabelaHash, 35));
    imprime_hash(tabelaHash);
}