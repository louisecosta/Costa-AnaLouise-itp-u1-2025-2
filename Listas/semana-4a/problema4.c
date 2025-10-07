#include <stdio.h>
#include <math.h>

int main() {
    float x, y;
    float ultimoX = 0, ultimoY = 0; // última posição
    int total = 0;

    for (int i = 0; i < 10; i++) {
        scanf("%f %f", &x, &y);

        // Distância ao centro
        float distCentro = sqrt(x * x + y * y);

        int pontos = 0;
        if (distCentro <= 1) pontos = 10;
        else if (distCentro <= 2) pontos = 6;
        else if (distCentro <= 3) pontos = 4;
        else pontos = 0;

        total += pontos;

        // Calcula bônus se não for o primeiro lançamento
        if (i > 0) {
            float distAnterior = sqrt((x - ultimoX) * (x - ultimoX) + (y - ultimoY) * (y - ultimoY));

            int bonus = 0;
            if (distAnterior <= 1) bonus = 5;
            else if (distAnterior <= 2) bonus = 3;
            else if (distAnterior <= 3) bonus = 2;
            else bonus = 0;

            total += bonus;
        }

        // Atualiza última posição
        ultimoX = x;
        ultimoY = y;
    }

    printf("%d\n", total);
    return 0;
}
