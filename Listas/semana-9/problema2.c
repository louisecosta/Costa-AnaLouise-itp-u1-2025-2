#include <stdio.h>

int main() {
    int M;
    scanf("%d", &M);

    int amizade[100][100];

    // Leitura da matriz de amizades
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &amizade[i][j]);
        }
    }

    int x;
    scanf("%d", &x);

    int sugestoes[100];
    int contador = 0;

    // Percorre todos os usuários
    for (int i = 0; i < M; i++) {
        if (i == x) continue;    
        if (amizade[x][i] == 1) continue; // já é amigo, então pula

        int temAmigoEmComum = 0;

        // Verifica se há amigo em comum com o usuário x
        for (int j = 0; j < M; j++) {
            if (amizade[x][j] == 1 && amizade[i][j] == 1) {
                temAmigoEmComum = 1;
                break; // achou um amigo em comum
            }
        }

        if (temAmigoEmComum) {
            sugestoes[contador] = i;
            contador++;
        }
    }

    // Exibição das sugestões em ordem crescente
    for (int i = 0; i < contador; i++) {
        printf("%d ", sugestoes[i]);
    }

    if (contador == 0) {
        printf("sem sugestoes");
    }

    printf("\n");
    return 0;
}