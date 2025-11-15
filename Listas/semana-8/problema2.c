#include <stdio.h>

int main() {
    int chuva[12];
    char *meses[12] = {
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    // Leitura da quantidade de chuva para cada mês
    for (int i = 0; i < 12; i++) {
        scanf("%d", &chuva[i]);
    }

    // Bubble sort (ordenação decrescente)
    for (int i = 0; i < 11; i++) { // repetições aninhadas
        for (int j = 0; j < 11 - i; j++) {
            if (chuva[j] < chuva[j + 1]) { // troca se o próximo for maior
                int temp = chuva[j];
                chuva[j] = chuva[j + 1];
                chuva[j + 1] = temp;

                // Também troca os nomes dos meses para manter correspondência
                char *tempMes = meses[j];
                meses[j] = meses[j + 1];
                meses[j + 1] = tempMes;
            }
        }
    }

    // Exibição do ranking
    for (int i = 0; i < 12; i++) {
        printf("%s %d\n", meses[i], chuva[i]);
    }

    return 0;
}