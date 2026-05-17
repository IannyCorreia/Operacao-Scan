#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void blelloch(int *entrada, int *saida, int n) {
    for (int i = 0; i < n; i++) {
        saida[i] = entrada[i];
    }

    // Up-sweep
    for (int passo = 1; passo < n; passo *= 2) {
        for (int i = 0; i < n; i += 2 * passo) {
            int indice = i + 2 * passo - 1;
            int anterior = i + passo - 1;

            if (indice < n) {
                saida[indice] += saida[anterior];
            }
        }
    }

    saida[n - 1] = 0;

    // Down-sweep
    for (int passo = n / 2; passo >= 1; passo /= 2) {
        for (int i = 0; i < n; i += 2 * passo) {
            int indice = i + 2 * passo - 1;
            int anterior = i + passo - 1;

            if (indice < n) {
                int temp = saida[anterior];
                saida[anterior] = saida[indice];
                saida[indice] += temp;
            }
        }
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

        blelloch(entrada, saida, n);

        clock_t fim = clock();

        double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        int passos = 2 * (int) ceil(log2(n));
        long long trabalho = 2LL * n;

        printf("Blelloch | n = %d | tempo = %f segundos | trabalho aproximado = %lld | passos = %d\n",
               n, tempo, trabalho, passos);

        free(entrada);
        free(saida);
    }

    return 0;
}