#include <stdio.h>
#include <math.h>
int main() {
    double a, b, c;
    double delta, x1, x2;
    printf("Digite os coeficientes a, b e c da equação ax² + bx + c = 0:\n");
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);
    if (a == 0) {
        printf("Não é uma equação do segundo grau (a deve ser diferente de zero).\n");
        return 1;
    }
    delta = b * b - 4 * a * c;
    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("Duas raízes reais distintas:\n");
        printf("x1 = %.2lf\n", x1);
        printf("x2 = %.2lf\n", x2);
    } else if (delta == 0) {
        x1 = -b / (2 * a);
        printf("Uma raiz real:\n");
        printf("x = %.2lf\n", x1);
    } else {
        printf("Não possui raízes reais.\n");
    }
    return 0;
}