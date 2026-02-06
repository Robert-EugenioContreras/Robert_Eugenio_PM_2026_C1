#include <stdio.h>

float celsiusAFahrenheit(float c);

int main(void)
{
    float c;

    printf("Ingrese temperatura en Celsius: ");
    scanf("%f", &c);

    printf("Temperatura en Fahrenheit: %.2f\n", celsiusAFahrenheit(c));

    return 0;
}

float celsiusAFahrenheit(float c)
{
    return (c * 9 / 5) + 32;
}
