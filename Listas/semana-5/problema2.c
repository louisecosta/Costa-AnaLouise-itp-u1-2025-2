#include <stdio.h>
#include <math.h>

// Função para verificar se um número é primo
int ehPrimo(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int limite = 50000;

    for (int x = 2; x <= limite - 6; x++) {
        if (ehPrimo(x) && ehPrimo(x + 2) && ehPrimo(x + 6)) {
            printf("(%d, %d, %d)\n", x, x + 2, x + 6);
        }
    }

    return 0;
}