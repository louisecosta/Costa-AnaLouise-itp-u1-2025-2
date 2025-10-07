#include <stdio.h>

// Função para ajustar horas e minutos (se passar de 60 ou 24)
void ajustaHorario(int *h, int *m) {
    if (*m >= 60) {
        *h += *m / 60;
        *m = *m % 60;
    }
    if (*h >= 24) {
        *h = *h % 24;
    }
}

// Função para imprimir no formato 24h
void imprime24h(int h, int m) {
    printf("%02d:%02d\n", h, m);
}

// Função para imprimir no formato 12h (com AM/PM)
void imprime12h(int h, int m) {
    int hora12;
    char periodo[3];

    if (h == 0) {
        hora12 = 12; // meia noite
        sprintf(periodo, "AM");
    } else if (h < 12) {
        hora12 = h;
        sprintf(periodo, "AM");
    } else if (h == 12) {
        hora12 = 12; // meio dia
        sprintf(periodo, "PM");
    } else {
        hora12 = h - 12;
        sprintf(periodo, "PM");
    }

    printf("%d:%02d %s\n", hora12, m, periodo);
}

int main() {
    int h, m, formato;
    scanf("%d %d %d", &h, &m, &formato);

    // Mostrar 5 horários: inicial + 4 incrementos de 30 min
    for (int i = 0; i < 5; i++) {
        if (formato == 0) 
            imprime24h(h, m);
        else 
            imprime12h(h, m);

        m += 30; // adiciona 30 minutos
        ajustaHorario(&h, &m);
    }

    return 0;
}