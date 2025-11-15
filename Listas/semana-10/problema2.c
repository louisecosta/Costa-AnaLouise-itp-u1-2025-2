#include <stdio.h>
#include <stdlib.h>

int* buscaNoVetor(int *v, int n, int valor, int *maior, int *qtd) {
    *qtd = 0; // inicialmente, nenhuma ocorrência encontrada
    *maior = *v; // começa com o primeiro elemento como o maior

    // Primeiro loop: encontra o maior e conta quantas ocorrências existem
    for (int i = 0; i < n; i++) {
        if (*(v + i) > *maior) {
            *maior = *(v + i);
        }
        if (*(v + i) == valor) {
            (*qtd)++;
        }
    }

    if (*qtd == 0) {
        return NULL; // valor não encontrado
    }

    // Aloca vetor para armazenar os índices das ocorrências
    int indices = (int) malloc((*qtd) * sizeof(int));
    if (indices == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    // Segundo loop: guarda os índices onde o valor aparece
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (*(v + i) == valor) {
            *(indices + pos) = i;
            pos++;
        }
    }

    return indices; // retorna o endereço base do vetor de índices
}

int main() {
    int n, valor;
    int *v;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    // Alocação dinâmica do vetor principal
    v = (int*) malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Digite os %d elementos do vetor:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", (v + i));
    }

    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valor);

    int maior, qtd;
    int *indices = buscaNoVetor(v, n, valor, &maior, &qtd);

    if (indices == NULL) {
        printf("Valor nao encontrado no vetor.\n");
    } else {
        printf("Maior valor no vetor: %d\n", maior);
        printf("Quantidade de ocorrencias de %d: %d\n", valor, qtd);
        printf("Indices das ocorrencias: ");
        for (int i = 0; i < qtd; i++) {
            printf("%d ", *(indices + i));
        }
        printf("\n");

        free(indices);
    }

    free(v);
    return 0;
}