#include <stdio.h>

int main(){
    float peso, altura, imc;

    printf("Digite seu peso em kg: ");
    scanf("%f", &peso);

    printf("Digite sua altura em m: ");
    scanf("%f", &altura);

    imc = peso/(altura*altura); 
    
    printf("\nSeu IMC é: %.2f\n", imc);
   

}