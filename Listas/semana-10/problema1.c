#include <stdio.h>
#include <stdlib.h>

// Função que aloca dinamicamente um vetor de inteiros
int* alocarVetor(int n) {
    int vetor = (int) malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    return vetor;
}

// Função que realiza a soma de dois vetores
int* somaVetores(int *u, int *v, int n1, int n2) {
    if (n1 != n2) {
        return NULL; // dimensões incompatíveis
    }

    int *resultado = alocarVetor(n1);
    for (int i = 0; i < n1; i++) {
        *(resultado + i) = *(u + i) + *(v + i);
    }
    return resultado;
}

int main() {
    int n1, n2;

    printf("Digite o tamanho do vetor u: ");
    scanf("%d", &n1);
    printf("Digite o tamanho do vetor v: ");
    scanf("%d", &n2);

    int *u = alocarVetor(n1);
    int *v = alocarVetor(n2);

    printf("Digite os elementos do vetor u:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", (u + i));
    }

    printf("Digite os elementos do vetor v:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", (v + i));
    }

    int *resultado = somaVetores(u, v, n1, n2);

    if (resultado == NULL) {
        printf("dimensoes incompativeis\n");
    } else {
        printf("Vetor resultante da soma:\n");
        for (int i = 0; i < n1; i++) {
            printf("%d ", *(resultado + i));
        }
        printf("\n");
        free(resultado);
    }

    free(u);
    free(v);

    return 0;
}