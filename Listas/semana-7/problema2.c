#include <stdio.h>
#include <string.h>

int eh_letra(char c) {
    return c >= 'A' && c <= 'Z';
}

int eh_digito(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    char placa[11];
    scanf("%10s", placa);

    int tam = strlen(placa);

    int brasileiro = 0;
    int mercosul = 0;

    // ------- PADRÃO BRASILEIRO: LLL-AAAA (8 chars) -------
    if (tam == 8 &&
        eh_letra(placa[0]) &&
        eh_letra(placa[1]) &&
        eh_letra(placa[2]) &&
        placa[3] == '-' &&
        eh_digito(placa[4]) &&
        eh_digito(placa[5]) &&
        eh_digito(placa[6]) &&
        eh_digito(placa[7])) 
    {
        brasileiro = 1;
    }

    // ------- PADRÃO MERCOSUL: LLLALAA (7 chars) -------
    if (tam == 7 &&
        eh_letra(placa[0]) &&
        eh_letra(placa[1]) &&
        eh_letra(placa[2]) &&
        eh_digito(placa[3]) &&
        eh_letra(placa[4]) &&
        eh_digito(placa[5]) &&
        eh_digito(placa[6])) 
    {
        mercosul = 1;
    }

    if (brasileiro)
        printf("brasileiro");
    else if (mercosul)
        printf("mercosul");
    else
        printf("invalido");

    return 0;
}