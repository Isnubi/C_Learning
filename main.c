#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Headers/function.h"
#include "Headers/UnitConvert.h"

int main(int argc, char *argv[])
{
    printf("Choose your script:\n");
    printf("1. Hours_converter\n");
    printf("2. Integer_to_string\n");
    printf("3. BMI_calculator\n");
    printf("4. UnitConvert\n");
    printf("5. Exit\n");
    int script;
    scanf("%d", &script);
    if(script == 1){
        int hours = 0, minutes = 564;
        // Send variables addresses to functions
        getHours(&hours, &minutes);
        printf("%d hours et %d minutes\n", hours, minutes);
    }
    else if(script == 2){
        int number = 123;
        char *string = NULL;
        // Return the address of string to the function convertIntToString and store the result in string
        convertIntToString(&number, &string);
        printf("%s\n", string);
        free(string);
    }
    else if(script == 3) {
        int height, weight;
        float BMI;
        printf("Enter your height in cm: ");
        scanf("%d", &height);
        printf("Enter your weight in kg: ");
        scanf("%d", &weight);
        BMI_calculator(&height, &weight, &BMI);
        printf("Your BMI is %.2f\n", BMI);
        FILE *file = fopen("../extern/BMI.csv", "a");
        if (file == NULL) {
            printf("File didn't exist\n");
        } else {
            fprintf(file, "%d;%d;%.2f\n", height, weight, BMI);
            fclose(file);
        }
    }
    else if(script == 4) {
        printf("Choose your category of convertion:\n");
        printf("1. Temperature\n");
        printf("2. Length\n");
        printf("3. Weight\n");
        printf("4. Exit\n");
        int category;
        scanf("%d", &category);
        if(category == 1) {
            printf("Choose your convertion:\n");
            printf("1. Celsius to Fahrenheit\n");
            printf("2. Fahrenheit to Celsius\n");
            printf("3. Exit\n");
            int convertion;
            scanf("%d", &convertion);
            if (convertion == 1) {
                float Celsius = 0, Fahrenheit = 0;
                printf("Enter the temperature in Celsius: ");
                scanf("%f", &Celsius);
                CelsiusToFahrenheit(&Celsius, &Fahrenheit);
                printf("The temperature in Fahrenheit is %.2f\n", Fahrenheit);
            } else if (convertion == 2) {
                float Fahrenheit = 0, Celsius = 0;
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%f", &Fahrenheit);
                FahrenheitToCelsius(&Fahrenheit, &Celsius);
                printf("The temperature in Celsius is %.2f\n", Celsius);
            } else if (convertion == 3) {
                printf("Exit\n");
            } else {
                printf("Wrong input\n");
            }
        }
        else if(category == 2) {
            printf("Choose your convertion:\n");
            printf("1. Meters to kilometers\n");
            printf("2. Kilometers to meters\n");
            printf("3. Exit\n");
            int convertion;
            scanf("%d", &convertion);
            if (convertion == 1) {
                float meters = 0, kilometers = 0;
                printf("Enter the length in meters: ");
                scanf("%f", &meters);
                metersToKilometers(&meters, &kilometers);
                printf("The length in kilometers is %.2f\n", kilometers);
            } else if (convertion == 2) {
                float kilometers = 0, meters = 0;
                printf("Enter the length in kilometers: ");
                scanf("%f", &kilometers);
                kilometersToMeters(&kilometers, &meters);
                printf("The length in meters is %.2f\n", meters);
            } else if (convertion == 3) {
                printf("Exit\n");
            } else {
                printf("Wrong input\n");
            }
        }
        else if(category == 3) {
            printf("Choose your convertion:\n");
            printf("1. Kilograms to pounds\n");
            printf("2. Pounds to kilograms\n");
            printf("3. Exit\n");
            int convertion;
            scanf("%d", &convertion);
            if (convertion == 1) {
                float kilograms = 0, pounds = 0;
                printf("Enter the weight in kilograms: ");
                scanf("%f", &kilograms);
                kilogramsToPounds(&kilograms, &pounds);
                printf("The weight in pounds is %.2f\n", pounds);
            } else if (convertion == 2) {
                float pounds = 0, kilograms = 0;
                printf("Enter the weight in pounds: ");
                scanf("%f", &pounds);
                poundsToKilograms(&pounds, &kilograms);
                printf("The weight in kilograms is %.2f\n", kilograms);
            } else if (convertion == 3) {
                printf("Exit\n");
            } else {
                printf("Wrong input\n");
            }
        }
        else if(category == 4) {
            printf("Exit\n");
        }
        else {
            printf("Wrong input\n");
        }
    }
    else if(script == 5) {
        printf("Exit\n");
    }
    else {
        printf("Wrong input\n");
    }

    system("pause");

    return 0;
}
