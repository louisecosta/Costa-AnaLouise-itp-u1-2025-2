#include <stdio.h>

int main() {
    int preco1, preco2, dinheiro;
    printf("Digite o preco do primeiro fornecedor: ");
    scanf("%d", &preco1);
    printf("Digite o preco do segundo fornecedor: ");
    scanf("%d", &preco2);
    printf("Digite a quantia disponivel: ");
    scanf("%d", &dinheiro);

    for(int q1 = 0; q1 <= 10; q1++) {
        for(int q2 = 0; q2 <= 10; q2++) {
            int gasto = q1*preco1 + q2*preco2;
            if(gasto <= dinheiro) {
                printf("Comprando %d do primeiro e %d do segundo resta: %d\n",
                       q1, q2, dinheiro - gasto);
            }
        }
    }
    return 0;
}