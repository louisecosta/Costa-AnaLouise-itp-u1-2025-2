#include <stdio.h>

int main() {
    int m, n;
    
    // Leitura de m e n
    scanf("%d %d", &m, &n);

    int sorteados[m];
    int aposta[n];
    int acertos = 0;

    // Leitura dos números sorteados
    for (int i = 0; i < m; i++) {
        scanf("%d", &sorteados[i]);
    }

    // Leitura dos números apostados
    for (int j = 0; j < n; j++) {
        scanf("%d", &aposta[j]);
    }

    // Contagem de acertos usando laços aninhados
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (sorteados[i] == aposta[j]) {
                acertos++;
                break; // evita contar o mesmo número mais de uma vez
            }
        }
    }

    // Exibição do resultado
    printf("%d\n", acertos);

    return 0;
}