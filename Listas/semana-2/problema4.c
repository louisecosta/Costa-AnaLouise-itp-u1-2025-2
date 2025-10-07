#include <stdio.h>

int main(){
    int num1,num2,soma,produto,diferenca,resto,arit,divisao;
    printf("Digite um número inteiro: ");
    scanf("%d", &num1);
    
    printf("Digite outro número inteiro: ");
    scanf("%d", &num2);
    
    soma = num1+num2;
    diferenca = num1-num2;
    produto = num1*num2;
    divisao = (num1/num2);
    resto = num1%num2;
    arit = (num1+num2)/2;
    
    printf("Soma: %2.d", soma);
    printf("\nDiferença: %2.d", diferenca);
    printf("\nProduto: %2.d", produto);
    printf("\nDivisão: %d", divisao);
    printf("\nResto: %2.d", resto);
    printf("\nAritimetrica: %2.d", arit);
    
    return 0;
}