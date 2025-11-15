#include <stdio.h>

int main() {
    int M;
    scanf("%d", &M);

    int preco[M][M];

    // Leitura da matriz de preços
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &preco[i][j]);
        }
    }

    int X, Z;
    scanf("%d %d", &X, &Z);

    int menorCusto = preco[X][Z]; // custo direto de X -> Z
    int cidadeIntermediaria = -1; // -1 indica rota direta

    // Testar todas as cidades intermediárias possíveis (Y)
    for (int Y = 0; Y < M; Y++) {
        if (Y != X && Y != Z) { // não pode ser a mesma cidade
            int custo = preco[X][Y] + preco[Y][Z];
            if (custo < menorCusto) {
                menorCusto = custo;
                cidadeIntermediaria = Y;
            }
        }
    }

    // Saída formatada
    if (cidadeIntermediaria == -1)
        printf("%d-%d %d\n", X, Z, menorCusto);
    else
        printf("%d-%d-%d %d\n", X, cidadeIntermediaria, Z, menorCusto);

    return 0;
}