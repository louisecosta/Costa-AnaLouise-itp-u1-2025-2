#include <stdio.h>
#include <math.h>

#define N 4

int tabuleiro[N];  // tabuleiro[i] = coluna da rainha na linha i
int solucoes = 0;

// Verifica se a rainha pode ser colocada na linha atual
int podeColocar(int linha, int coluna) {
    for (int i = 0; i < linha; i++) {
        if (tabuleiro[i] == coluna ||                  // mesma coluna
            abs(tabuleiro[i] - coluna) == abs(i - linha)) { // mesma diagonal
            return 0;
        }
    }
    return 1;
}

// Backtracking para posicionar rainhas
void resolver(int linha) {
    if (linha == N) {
        solucoes++;
        printf("Solução %d:\n", solucoes);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (tabuleiro[i] == j) printf(" Q ");
                else printf(" . ");
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    for (int col = 0; col < N; col++) {
        if (podeColocar(linha, col)) {
            tabuleiro[linha] = col;
            resolver(linha + 1);
        }
    }
}

int main() {
    resolver(0);
    printf("Total de soluções encontradas: %d\n", solucoes);
    return 0;
}