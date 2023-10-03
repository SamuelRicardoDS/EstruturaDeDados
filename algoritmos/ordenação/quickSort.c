#include <stdio.h>



void QuickSort(int *vetor, int tamanhoVetor) {
    vetor = (int *) malloc(tamanhoVetor * sizeof(int));
}




int main() {
    int *vetor;
    int tamanhoVetor;
    int elemento;
    puts("qual o tamanho do vetor?");
    scanf("%d", &tamanhoVetor);
    puts("insira os elementos do vetor");

    for(int i = 0; i < tamanhoVetor; i++) {
        scanf("%d", &elemento);
        vetor[i] = elemento;
    }
}