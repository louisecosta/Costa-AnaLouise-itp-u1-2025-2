#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função que mistura duas strings alternando seus caracteres
char *misturar(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len_total = len1 + len2;

    // Aloca memória para a nova string (+1 para o caractere '\0')
    char *resultado = (char *) malloc((len_total + 1) * sizeof(char));
    if (resultado == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    int i = 0, j = 0, k = 0;

    // Alterna os caracteres enquanto ambas têm letras
    while (i < len1 && j < len2) {
        *(resultado + k) = *(str1 + i);
        k++;
        i++;
        *(resultado + k) = *(str2 + j);
        k++;
        j++;
    }

    // Copia o restante da string maior, se houver
    while (i < len1) {
        *(resultado + k) = *(str1 + i);
        i++;
        k++;
    }

    while (j < len2) {
        *(resultado + k) = *(str2 + j);
        j++;
        k++;
    }

    // Finaliza a string
    *(resultado + k) = '\0';

    return resultado;
}

int main() {
    char str1[101], str2[101];

    printf("Digite a primeira string:\n");
    fgets(str1, sizeof(str1), stdin);
    printf("Digite a segunda string:\n");
    fgets(str2, sizeof(str2), stdin);

    // Remove o '\n' deixado pelo fgets
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Chama a função misturar
    char *resultado = misturar(str1, str2);

    printf("String misturada: %s\n", resultado);

    // Libera memória alocada
    free(resultado);

    return 0;
}