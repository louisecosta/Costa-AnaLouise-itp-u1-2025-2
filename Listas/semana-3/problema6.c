#include <stdio.h>

int main(){
    char febre, dor_cabeca, dor_corpo, tosse;
    //leitura dos sintomas
    printf("Tem febre? (s/n): ");
    scanf(" %c", &febre);
    printf("Tem dor de cabeca? (s/n): ");
    scanf(" %c", &dor_cabeca);
    printf("Tem dor no corpo? (s/n): ");
    scanf(" %c", &dor_corpo);
    printf("Tem tosse? (s/n): ");
    scanf(" %c", &tosse);

    //verificacao dos sintomas
    if (febre == 's' && dor_cabeca == 's' && dor_corpo == 's' && tosse == 's') {
        printf("Diagnostico: Gripe\n");
    } else if (febre == 's' && dor_cabeca == 'n' && dor_corpo == 'n' && tosse == 's') {
        printf("Diagnostico: possível enxaqueca\n");
    } else if (febre == 's' && dor_cabeca == 'n' && dor_corpo == 'n' && tosse == 'n') {
        printf("Consulte um médico\n");
    } else if (febre == 'n' && dor_cabeca == 'n' && dor_corpo == 'n' && tosse == 'n') {
        printf("Você parece estar bem\n");
    } else {
        printf("Consulte um médico para avaliação\n");
    }
}