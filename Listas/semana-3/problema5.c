#include <stdio.h>
int main() {
    float valorCompra, desconto = 0.0, valorFinal;
    float percentualDesconto = 0.0;
    printf("Digite o valor da compra: R$ ");
    scanf("%f", &valorCompra);
    if (valorCompra <= 100.00) {
        percentualDesconto = 0.0;
    } else if (valorCompra <= 500.00) {
        percentualDesconto = 10.0;
    } else if (valorCompra <= 1000.00) {
        percentualDesconto = 15.0;
    } else {
        percentualDesconto = 20.0;
    }
    desconto = (percentualDesconto / 100) * valorCompra;
    valorFinal = valorCompra - desconto;
    printf("Valor do desconto: R$ %.2f\n", desconto);
    printf("Valor final a ser pago: R$ %.2f\n", valorFinal);
    printf("Porcentagem de desconto aplicada: %.0f%%\n", percentualDesconto);
    return 0;
}