#include <stdio.h>
#include <stdbool.h>

//User Inputs
int functionIndex;
float number_01;
float number_02;

//Functions Declarations
void addFunction (float number_01, float number_02);
void subtractFunction (float number_01, float number_02);
void multiplyFunction (float number_01, float number_02);
void divideFunction (float number_01, float number_02);
void modulusFunction (int number_01, int number_02);

void addFunction (float number_01, float number_02) {
    printf("\n\t%f + %f = %f\n\n", number_01,  number_02, number_01 + number_02);
}

void subtractFunction (float number_01, float number_02) {
    printf("\n\t%f - %f = %f\n\n", number_01,  number_02, number_01 - number_02);
}

void multiplyFunction (float number_01, float number_02) {
    printf("\n\t%f * %f = %f\n\n", number_01,  number_02, number_01 * number_02);
}

void divideFunction (float number_01, float number_02) {
    if (number_02) {
            printf("\n\t%f / %f = %f\n\n", number_01,  number_02, number_01 / number_02);
    } else {
        printf("Division by 0 is undefined.\n");
    }
}

void modulusFunction (int number_01, int number_02) {
    if (number_02) {
        printf("\n\t%d %% %d = %d\n\n", number_01,  number_02, number_01 % number_02);
    } else {
        printf("Division by 0 is undefined.\n");
    }
}

void main () {
    printf("Select one of following function. Enter 0 to exit.");

    do {
        printf("\n\nFUNCTIONS MENU\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Modulus\n\tFunction Number > ");
        scanf("%d", &functionIndex);

        if (functionIndex > 0 && functionIndex <= 5) {
            printf("Input two values: ");
            scanf("%f %f", &number_01, &number_02);

            switch (functionIndex) {
                case 1:
                    addFunction(number_01, number_02);
                    break;
                case 2:
                    subtractFunction(number_01, number_02);
                    break;
                case 3:
                    multiplyFunction(number_01, number_02);
                    break;
                case 4:
                    divideFunction(number_01, number_02);
                    break;
                case 5:
                    modulusFunction(number_01, number_02);
                    break;
            }
        } else {
            printf("Unsupported function number. Try again.\n");
        }
    } 
    while (functionIndex);
}