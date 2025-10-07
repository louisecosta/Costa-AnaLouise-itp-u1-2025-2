#include <stdio.h>

int main() {
    int sugestao[10];
    int visitado[10] = {0};
    int atual = 0;

    for (int i = 0; i < 10; i++)
        scanf("%d", &sugestao[i]);

    while (!visitado[atual]) {
        visitado[atual] = 1;
        atual = sugestao[atual];
    }

    printf("%d\n", atual);

    return 0;
}