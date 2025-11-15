#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALUNO 11
#define MAX_FREQ 1001

// Função para identificar se uma string tem o formato DD/MM
int ehData(char *s) {
    // Formato esperado: DD/MM, com s[2] = '/' e os demais dígitos numéricos
    if (strlen(s) != 5) return 0;
    if (s[2] != '/') return 0;
    if (!isdigit(s[0]) || !isdigit(s[1]) || !isdigit(s[3]) || !isdigit(s[4])) return 0;
    return 1;
}

int main() {
    char aluno[MAX_ALUNO];
    char frequencias[MAX_FREQ];
    char palavras[300][MAX_ALUNO]; 
    int qtd_palavras = 0;

    
    scanf("%s", aluno);
    getchar();

    // Leitura da linha completa das frequências
    fgets(frequencias, MAX_FREQ, stdin);
    frequencias[strcspn(frequencias, "\n")] = '\0'; // retirar \n

    // Quebrar a linha em palavras (datas e nomes)
    char *token = strtok(frequencias, " ");
    while (token != NULL) {
        strcpy(palavras[qtd_palavras++], token);
        token = strtok(NULL, " ");
    }

    int faltas = 0;
    int i = 0;
    while (i < qtd_palavras) {
       
        if (ehData(palavras[i])) {
            int achou = 0; // flag para saber se aluno está presente nessa data
            i++;
            // Percorrer os nomes depois da data até achar outra data ou fim
            while (i < qtd_palavras && !ehData(palavras[i])) {
                if (strcmp(palavras[i], aluno) == 0) {
                    achou = 1;
                }
                i++;
            }
            if (!achou) {
                faltas++;
            }
        } else {
            // Se não for data, apenas avança
            i++;
        }
    }

    printf("%d\n", faltas);
    return 0;
}