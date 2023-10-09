#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palavra
{
    char *palavra;
    struct palavra *anterior;
} Palavra;

typedef struct pilha
{
    Palavra *topo;
} Pilha;

void inicializaPilha(Pilha *pilha)
{
    pilha->topo = NULL;
}

void empilha(Pilha *pilha, const char *frase)
{
    Palavra *novaPalavra = (Palavra *)malloc(sizeof(Palavra));

    novaPalavra->palavra = strdup(frase);
    novaPalavra->anterior = pilha->topo;
    pilha->topo = novaPalavra;
}

char *desempilha(Pilha *pilha)
{
    if (pilha->topo == NULL)
    {
        return NULL;
    }

    Palavra *temp = pilha->topo;
    char *frase = temp->palavra;
    pilha->topo = pilha->topo->anterior;
    free(temp);

    return frase;
}

int main()
{
    Pilha pilha;
    inicializaPilha(&pilha);
    char operacao[10]; // Aumentei o tamanho do array para acomodar "desfazer" e "inserir"
    char frase[100];   // Aumentei o tamanho do array para acomodar frases de até 100 caracteres

    while (scanf("%s", operacao) != EOF)
    {
        if (strcmp(operacao, "inserir") == 0)
        {
            scanf(" %[^\n]", frase); // Lê a linha inteira como frase, incluindo espaços
            empilha(&pilha, frase);
        }
        else if (strcmp(operacao, "desfazer") == 0)
        {
            char *frase_desfeita = desempilha(&pilha);
            if (frase_desfeita == NULL)
            {
                printf("NULL\n");
            }
            else
            {
                printf("%s\n", frase_desfeita);
                free(frase_desfeita); // Libera a memória alocada para a frase desfeita
            }
        }
    }

    // Libera a memória restante da pilha
    while (pilha.topo != NULL)
    {
        char *frase_desfeita = desempilha(&pilha);
        free(frase_desfeita);
    }

    return 0;
}
