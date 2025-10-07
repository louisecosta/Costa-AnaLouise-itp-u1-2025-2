#include <stdio.h>

int main() {
    float p, q;
    int melhorX = 0, melhorY = 0;
    float melhorRazao = 0.0;

    printf("Digite o preco de venda p: ");
    scanf("%f", &p);
    printf("Digite o preco de producao q: ");
    scanf("%f", &q);

    for(int x = 2; x <= 10; x++) {     // x precisa ser > 1
        for(int y = 1; y < x; y++) {   // y < x
            float receita = y * p;
            float custo   = x * q;
            if(receita >= custo) {     // sem prejuízo
                float razao = (float)x / y;
                if(razao > melhorRazao) {
                    melhorRazao = razao;
                    melhorX = x;
                    melhorY = y;
                }
            }
        }
    }

    if(melhorX == 0) {
        printf("Nao ha promocao possivel sem prejuizo.\n");
    } else {
        printf("A melhor promocao eh: leve %d pague %d\n", melhorX, melhorY);
    }

    return 0;
}