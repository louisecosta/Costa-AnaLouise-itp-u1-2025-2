#include <stdio.h>
#include <math.h>

int main() {
    float x, y, L;  // posição inicial e comprimento da teia
    int n;          // número de alvos

    printf("Digite a posição inicial do Homem-Aranha (x y): ");
    scanf("%f %f", &x, &y);

    printf("Digite o comprimento máximo da teia: ");
    scanf("%f", &L);

    printf("Digite a quantidade de alvos: ");
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {
        float ax, ay;
        printf("Digite as coordenadas do alvo %d (x y): ", i + 1);
        scanf("%f %f", &ax, &ay);

        // Calcula distância euclidiana
        float dist = sqrt((ax - x) * (ax - x) + (ay - y) * (ay - y));

        if (dist > L) {
            printf("N\n");
            return 0;
        }

        // Atualiza posição do Homem-Aranha (espelhamento)
        x = 2 * ax - x;
        y = 2 * ay - y;
    }

    printf("S\n");
    return 0;
}