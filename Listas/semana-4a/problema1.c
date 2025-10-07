#include <stdio.h>

int main() {
    float comprimento, largura, bolso;
    int dobras = 0;

    printf("Digite o comprimento e a largura da folha:\n");
    scanf("%f %f", &comprimento, &largura);

    printf("Digite o comprimento do bolso:\n");
    scanf("%f", &bolso);

    while (comprimento > bolso && largura > bolso) {
        // Descobrir o maior lado e dobrar ele
        if (comprimento >= largura) {
            comprimento /= 2.0;
        } else {
            largura /= 2.0;
        }
        dobras++;
    }

    printf("Número de dobras necessárias: %d\n", dobras);

    return 0;
}