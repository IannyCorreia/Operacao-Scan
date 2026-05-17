#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reduceSerialInclusivo(int *entrada, int *saida, int n) {
    saida[0] = entrada[0];

    for (int i = 1; i < n; i++) {
        saida[i] = saida[i - 1] + entrada[i];
    }
}

void reduceSerialExclusivo(int *entrada, int *saida, int n) {
    saida[0] = 0;

    for (int i = 1; i < n; i++) {
        saida[i] = saida[i - 1] + entrada[i - 1];
    }
}

int main() {
    int tamanhos[] = {100, 1000, 10000, 100000, 1000000, 10000000};
    int qtdTamanhos = 6;

    for (int t = 0; t < qtdTamanhos; t++) {
        int n = tamanhos[t];

        int *entrada = (int*) malloc(n * sizeof(int));
        int *saida = (int*) malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            entrada[i] = 1;
        }

        clock_t inicio = clock();

        reduceSerialInclusivo(entrada, saida, n);

        clock_t fim = clock();

        double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        printf("Reduce Serial | n = %d | tempo = %f segundos\n", n, tempo);

        free(entrada);
        free(saida);
    }

    return 0;
}