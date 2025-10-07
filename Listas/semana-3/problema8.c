#include <stdio.h>

int main() {
    double a, b, c;
    double maior, lado1, lado2;

    printf("Digite os três lados do triângulo:\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Verifica se os lados podem formar um triângulo
    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        printf("Os valores formam um triângulo.\n");

        // Classificação quanto aos lados
        if (a == b && b == c) {
            printf("Tipo: Equilátero\n");
        } else if (a == b || b == c || a == c) {
            printf("Tipo: Isósceles\n");
        } else {
            printf("Tipo: Escaleno\n");
        }

        // Identifica o maior lado para classificação dos ângulos
        if (a >= b && a >= c) {
            maior = a;
            lado1 = b;
            lado2 = c;
        } else if (b >= a && b >= c) {
            maior = b;
            lado1 = a;
            lado2 = c;
        } else {
            maior = c;
            lado1 = a;
            lado2 = b;
        }

        // Classificação quanto aos ângulos usando o Teorema de Pitágoras
        double maior2 = maior * maior;
        double somaLados2 = lado1 * lado1 + lado2 * lado2;

        if (maior2 == somaLados2) {
            printf("Classificação dos ângulos: Retângulo\n");
        } else if (maior2 < somaLados2) {
            printf("Classificação dos ângulos: Acutângulo\n");
        } else {
            printf("Classificação dos ângulos: Obtusângulo\n");
        }

    } else {
        printf("Os valores NÃO formam um triângulo.\n");
    }

    return 0;
}