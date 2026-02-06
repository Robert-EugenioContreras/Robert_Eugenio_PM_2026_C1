#include <stdio.h>

float fahrenheitACelsius(float f);

int main(void)
{
    float f;

    printf("Ingrese temperatura en Fahrenheit: ");
    scanf("%f", &f);

    printf("Temperatura en Celsius: %.2f\n", fahrenheitACelsius(f));

    return 0;
}

float fahrenheitACelsius(float f)
{
    return (f - 32) * 5 / 9;
}
