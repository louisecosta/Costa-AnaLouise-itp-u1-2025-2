#include <stdio.h>
#include <math.h>

int main(){
    float tJuros, cap, temp,mont;
    
    printf("Digite o capital inicial:");
    scanf("%f", &cap);
    
    printf("Digite o juros(porcentagem):");
    scanf("%f", &tJuros);
    
    printf("Digite o tempo(anos):");
    scanf("%f", &temp);
    
    mont = cap*pow((1+tJuros/100),temp);
    
    printf("O montante é: %.2f\n", mont);
}