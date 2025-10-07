#include <stdio.h>
#include <stdlib.h>

// Função que calcula a soma dos divisores próprios de n
int somaDivisores(int n) {
    int soma = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            soma += i;
        }
    }
    return soma;
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    int DA = somaDivisores(A);
    int DB = somaDivisores(B);

    if (abs(DA - B) <= 2 && abs(DB - A) <= 2) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}