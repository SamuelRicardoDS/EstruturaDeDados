
int posicao = chave % tabela->M;
celula *novoNo = (celula *)malloc(sizeof(celula));
if (novoNo == NULL)
{
    // Tratamento de erro se a alocação de memória falhar
    exit(1); // Ou outra ação apropriada
}
novoNo->dado = chave;
novoNo->prox = tabela->tb[posicao].prox;
tabela->tb[posicao].prox = novoNo;

tabela->N++;