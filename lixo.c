typedef struct Node
{
    int dado;
    struct Node *left, *right;
} Node;

// Pre ordem
void qualquerMerdaOrdem(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d\n", root->dado);
    qualquerMerdaOrdem(root->esq);
    qualquerMerdaOrdem(root->dir);
}

// Em ordem
void qualquerMerdaOrdem(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    qualquerMerdaOrdem(root->esq);
    printf("%d\n", root->dado);
    qualquerMerdaOrdem(root->dir);
}

// Pos ordem
void qualquerMerdaOrdem(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    qualquerMerdaOrdem(root->esq);
    qualquerMerdaOrdem(root->dir);
    printf("%d\n", root->dado);
}