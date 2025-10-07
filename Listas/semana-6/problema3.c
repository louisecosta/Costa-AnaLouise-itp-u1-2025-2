#include <stdio.h>

int comprimento_ponte(int terreno[], int n) {
    int i;
    int maior = -1000000000;
    int primeiro = -1, segundo = -1;

    // percorre e encontra o maior e as posições (primeira e segunda ocorrência)
    for (i = 0; i < n; i++) {
        if (terreno[i] > maior) {
            maior = terreno[i];
            primeiro = i;   // guarda índice da primeira ocorrência do novo maior
            segundo = -1;   // reset, ainda não há segunda ocorrência
        } else if (terreno[i] == maior) {
            if (segundo == -1) segundo = i; // grava a segunda ocorrência
            else segundo = i; // se houver mais, mantém a última (segundo passa a ser a mais recente)
        }
    }

    return segundo - primeiro; // sem +1 !!
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int terreno[100]; // suficiente (n <= 30 no enunciado)
    for (int i = 0; i < n; i++) {
        scanf("%d", &terreno[i]);
    }

    printf("%d\n", comprimento_ponte(terreno, n));
    return 0;
}