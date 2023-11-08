No *noAtual = arvore->raiz;
No *noPai;

while (noAtual->filhoEsquerdo != NULL || noAtual->filhoDireito != NULL)
{
    noPai = noAtual;
    if (chave < noAtual->valor)
    {
        noAtual = noAtual->filhoEsquerdo;
    }
    else
    {
        noAtual = noAtual->filhoDireito;
    }
}
if (chave < noPai->valor)
{
    noPai->filhoEsquerdo = novoNo;
}
else
{
    noPai->filhoDireito = novoNo;
}