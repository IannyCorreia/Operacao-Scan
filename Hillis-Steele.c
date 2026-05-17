#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void hillisSteele(int *entrada, int *saida, int n) {
    int *temp = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        saida[i] = entrada[i];
    }

    for (int passo = 1; passo < n; passo *= 2) {
        for (int i = 0; i < n; i++) {
            if (i >= passo) {
                temp[i] = saida[i] + saida[i - passo];
            } else {
                temp[i] = saida[i];
            }
        }

        for (int i = 0; i < n; i++) {
            saida[i] = temp[i];
        }
    }

    free(temp);
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

        hillisSteele(entrada, saida, n);

        clock_t fim = clock();

        double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        int passos = (int) ceil(log2(n));
        long long trabalho = (long long)n * passos;

        printf("Hillis-Steele | n = %d | tempo = %f segundos | trabalho = %lld | passos = %d\n",
               n, tempo, trabalho, passos);

        free(entrada);
        free(saida);
    }

    return 0;
}