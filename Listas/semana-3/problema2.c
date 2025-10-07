#include <stdio.h>

int main(){
    
    float consumo,valor,total;
    char tipo;
   
    printf("Quanto foi consumido?(em kWh): ");
    scanf("%f", &consumo);
    
    printf("Qual o tipo de conta?(r,c ou i): ");
    scanf(" %c", &tipo);
    
    if (tipo == 'C' || tipo == 'c'){
        valor = consumo*0.48;
    }
    else if (tipo == 'R'|| tipo == 'r'){
        valor = consumo*0.60;
    }
    else if (tipo == 'I' || tipo == 'i'){
        valor = consumo*1.29;
    }
    else {
        printf("Tipo de consumo invalido\n");
        return 1;
    }
    total = valor + 15;
    printf("Valor total é: R$ %.2f\n", total);
    return 0;
}