#include <stdio.h>
#include <math.h>

// Função para calcular z = x - y
double calcula_z(double x, double y) {
    return x - y;
}

// Função para calcular h(x,y)
double calcula_h(double x, double y) {
    double z = calcula_z(x, y);
    return sin(cos(x + y) + z) + cos(x + y + sin(z));
}

// Função para verificar se o pouso é seguro
int pouso_seguro(double h) {
    if (h >= 0 && h <= 1)
        return 1; // seguro
    else
        return 0; // não seguro
}

int main() {
    double x, y, h;
    
    // Leitura das coordenadas
    scanf("%lf %lf", &x, &y);
    
    // Cálculo da altura
    h = calcula_h(x, y);
    
    // Verificação e saída
    if (pouso_seguro(h)) {
        printf("0 pousar eh seguro\n");
    } else {
        printf("1 perigo de colisao\n");
    }
    
    // Mostra coordenadas e valor de h
    printf("%.1lf %.1lf %.1lf\n", x, y, h);
    
    return 0;
}