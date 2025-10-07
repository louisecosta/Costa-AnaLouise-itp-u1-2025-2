#include <stdio.h>

int main(){
    char jogador_1, jogador_2;

    printf("Jogador 1 - Pedra(p), Papel(a), Tesoura(t)?");
    scanf(" %c", &jogador_1);
    
    printf("Jogador 2 - Pedra(p), Papel(a), Tesoura(t)?");
    scanf(" %c", &jogador_2);
   
   //pedra e tesoura 
    if(jogador_1 == 'p' && jogador_2 == 't'){
        printf("Jogador 1 ganhou");
    }
    if(jogador_2 == 'p' && jogador_1 == 't'){
        printf("Jogador 2 ganhou");
    }
    // tesoura e papel
    if(jogador_1 == 't' && jogador_2 == 'a'){
        printf("Jogador 1 ganhou");
    }
    if(jogador_2 == 't' && jogador_1 == 'a'){
        printf("Jogador 2 ganhou");
    }
    //papel e pedra
    if(jogador_1 == 'a' && jogador_2 == 'p'){
        printf("Jogador 1 ganhou");
    }
    if(jogador_2 == 'a'&& jogador_1 == 'p'){
        printf("Jogador 2 ganhou");
    }
    // empate
    if(jogador_1 == jogador_2){
        printf("Empate");
    }
    
    return 0;
}