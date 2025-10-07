#include <stdio.h>

int main() {
    int a, b, i, j, primo;

    do {
        printf("Digite dois numeros (a b): ");
        scanf("%d %d", &a, &b);
    } while (a <= b);

    printf("Primos entre %d e %d:\n", b, a);
    for(i = b+1; i < a; i++) {
        primo = 1;
        if(i < 2) primo = 0;
        for(j = 2; j*j <= i; j++) {
            if(i % j == 0) {
                primo = 0;
                break;
            }
        }
        if(primo) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}