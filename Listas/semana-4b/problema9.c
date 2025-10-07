#include <stdio.h>

int main() {
    int preco1, preco2, dinheiro;
    printf("Digite o preco do primeiro fornecedor: ");
    scanf("%d", &preco1);
    printf("Digite o preco do segundo fornecedor: ");
    scanf("%d", &preco2);
    printf("Digite a quantia disponivel: ");
    scanf("%d", &dinheiro);

    int melhorResto = dinheiro;
    int melhorQ1 = 0, melhorQ2 = 0;

    for(int q1 = 0; q1 <= 10; q1++) {
        for(int q2 = 0; q2 <= 10; q2++) {
            int gasto = q1*preco1 + q2*preco2;
            if(gasto <= dinheiro) {
                int resto = dinheiro - gasto;
                if(resto < melhorResto) {
                    melhorResto = resto;
                    melhorQ1 = q1;
                    melhorQ2 = q2;
                }
            }
        }
    }

    printf("Resta menos comprando %d do primeiro e %d do segundo\n", melhorQ1, melhorQ2);
    return 0;
}