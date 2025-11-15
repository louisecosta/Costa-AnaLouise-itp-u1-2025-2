#include <stdio.h>
#include <string.h>

int main() {
    char campo[21];  
    int indice;

    scanf("%20s", campo);
    scanf("%d", &indice);

    int tamanho = strlen(campo);

    // Se no índice houver uma bomba
    if (campo[indice] == 'x') {
        printf("bum!");
    } else {
        int bombas = 0;

        // Verifica vizinho da esquerda
        if (indice - 1 >= 0 && campo[indice - 1] == 'x') {
            bombas++;
        }

        // Verifica vizinho da direita
        if (indice + 1 < tamanho && campo[indice + 1] == 'x') {
            bombas++;
        }

        printf("%d", bombas);
    }

    return 0;
}