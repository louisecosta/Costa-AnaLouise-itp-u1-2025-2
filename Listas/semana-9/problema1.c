#include <stdio.h>

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int campo[10][10];
    int irrigado[10][10] = {0}; // matriz auxiliar para marcar setores irrigados

    // Leitura da matriz do campo
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &campo[i][j]);
        }
    }

    // Percorre a matriz para identificar irrigadores
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (campo[i][j] == 2) {
                // Irriga os 4 vizinhos (se forem férteis)
                if (i > 0 && campo[i - 1][j] == 1) irrigado[i - 1][j] = 1; // norte
                if (i < M - 1 && campo[i + 1][j] == 1) irrigado[i + 1][j] = 1; // sul
                if (j > 0 && campo[i][j - 1] == 1) irrigado[i][j - 1] = 1; // oeste
                if (j < N - 1 && campo[i][j + 1] == 1) irrigado[i][j + 1] = 1; // leste
            }
        }
    }

    int fertIrrig = 0, fertNaoIrrig = 0;

    // Conta os setores férteis irrigados e não irrigados
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (campo[i][j] == 1) {
                if (irrigado[i][j] == 1)
                    fertIrrig++;
                else
                    fertNaoIrrig++;
            }
        }
    }

    printf("%d %d\n", fertIrrig, fertNaoIrrig);
    return 0;
}