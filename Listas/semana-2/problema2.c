#include <stdio.h>
#include <math.h>

int main(){
    float celsius, kelvin, fahrenheit;
    
    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &celsius);
    
    fahrenheit = (celsius*9/5)+32;
    kelvin = celsius +273.15;
    
    printf("Temperatura em Fahrenheit é: %.1f\n", fahrenheit);
    printf("Temperatura em Kelvin: %.1f\n", kelvin);

}