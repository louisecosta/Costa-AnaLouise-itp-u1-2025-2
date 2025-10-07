#include <stdio.h>

int main(){
    //Variaveis
    float peso, altura, imc;
//Entrada de dados
    printf("Digite seu peso em kg: ");
    scanf("%f", &peso);

    printf("Digite sua altura em m: ");
    scanf("%f", &altura);
//Calculo do imc
    imc = peso/(altura*altura);
//Condições p/ estar normal, acima ou abaixo do peso
    if (imc < 18.5){
        printf("\nAbaixo do peso");
   } 
   if (imc >= 18.5 && imc <= 24.9){
       printf("\n Peso normal");
   }
   if (imc >= 25 && imc <= 29.9){
       printf("\nSobrepeso");
   }
   if (imc >=30){
       printf("\nObesidade");
   }
    
    return 0;
 
}