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
    if (novaPalavra == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

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
    char operacao[10];
    char frase[1000];

    char *frases_desfeitas[1000];
    int num_frases_desfeitas = 0;

    while (scanf("%s", operacao) != EOF)
    {
        if (strcmp(operacao, "inserir") == 0)
        {
            scanf(" %[^\n]", frase);
            empilha(&pilha, frase);
        }
        else if (strcmp(operacao, "desfazer") == 0)
        {
            char *frase_desfeita = desempilha(&pilha);
            if (frase_desfeita != NULL)
            {
                frases_desfeitas[num_frases_desfeitas++] = frase_desfeita;
            }
            else
            {
                frases_desfeitas[num_frases_desfeitas++] = strdup("NULL");
            }
        }
    }

    for (int i = 0; i < num_frases_desfeitas; i++)
    {
        if (strcmp(frases_desfeitas[i], "NULL") == 0)
        {
            printf("NULL\n");
        }
        else
        {
            printf("%s\n", frases_desfeitas[i]);
            free(frases_desfeitas[i]);
        }
    }

    while (pilha.topo != NULL)
    {
        char *frase_desfeita = desempilha(&pilha);
        free(frase_desfeita);
    }

    return 0;
}
