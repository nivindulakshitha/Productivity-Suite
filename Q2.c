#include <stdio.h>

//User Inputs
int rawValueType;
float convertingValue;

//Funtions Declarations
float CelsiusFahrenheit(float rawValue);
float FahrenheitCelsius(float rawValue);

float CelsiusFahrenheit (float rawValue) {
    return (rawValue * 9/5) + 32;
}

float FahrenheitCelsius (float rawValue) {
    return (rawValue - 32) * 5/9;
}

void main() {
    printf("\n\nConversion between Celsius & Fahrenheit\n");
    printf("---------------------------------------\n\n");

    printf("Raw value in (1. Celsius  2. Fahrenheit): ");
    scanf("%d", &rawValueType);

    if (rawValueType == 1) {
        printf("Value to be converted (in Celsius): ");
        scanf("%f", &convertingValue);
        printf("\n\t%.1f C = %.1f F\n\n", convertingValue, CelsiusFahrenheit(convertingValue));

    } else if (rawValueType == 2) {
        printf("Value to be converted (in Fahrenheit): ");
        scanf("%f", &convertingValue);
        printf("\n\t%.1f F = %.1f C\n\n", convertingValue, FahrenheitCelsius(convertingValue));

    } else {
        printf("Unexpected option. Try again.");
    }
}