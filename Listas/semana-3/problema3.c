#include <stdio.h>

int main(){
    float nota_1, nota_2, nota_3, media,nota_necessaria;
    
    printf("Digite sua 1º nota: ");
    scanf("%f", &nota_1);
    
    printf("Digite sua 2º nota: ");
    scanf("%f", &nota_2);
    
    printf("Digite sua 3º nota: ");
    scanf("%f", &nota_3);
    
    media = (nota_1+nota_2+nota_3)/3;
    
    if(media >= 7){
        printf("Aprovado");
    }
    else if(media<=4){
        printf("Reprovado");
    }
    else if(media >= 4 && media < 7){
        printf("Recuperação");
        nota_necessaria = 10 - media;
        printf("\nNota necessária na prova final para aprovação: %.2f\n", nota_necessaria);
        
    }
    return 0;
}