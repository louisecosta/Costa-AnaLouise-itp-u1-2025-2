#include <stdio.h>

int main() {
    int n; 
    int num = 1; // contador de números

    printf("Digite o número de linhas: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {      
        for (int j = 1; j <= i; j++) { 
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }

    return 0;
}
