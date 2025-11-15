#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int largada[n], chegada[n];
    int posicao_largada[21]; // para achar rapidamente a posição inicial de cada piloto

    // Leitura da ordem de largada
    for (int i = 0; i < n; i++) {
        scanf("%d", &largada[i]);
        posicao_largada[largada[i]] = i; // salva posição de largada do piloto
    }

    // Leitura da ordem de chegada
    for (int i = 0; i < n; i++) {
        scanf("%d", &chegada[i]);
    }

    int maxGanho = 0;
    int pilotoMax = -1;
    int empate = 0;

    // Para cada piloto, calcular o ganho de posições
    for (int i = 0; i < n; i++) {
        int piloto = chegada[i];
        int ganho = posicao_largada[piloto] - i; // quanto ganhou (posição inicial - final)

        if (ganho > maxGanho) {
            maxGanho = ganho;
            pilotoMax = piloto;
            empate = 0;
        } else if (ganho == maxGanho && ganho > 0) {
            empate = 1;
        }
    }

    // Verificação de empate ou nenhum ganho
    if (maxGanho <= 0 || empate) {
        printf("empate\n");
    } else {
        printf("%d\n", pilotoMax);
    }

    return 0;
}