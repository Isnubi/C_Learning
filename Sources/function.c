#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void getHours(int *P_hours, int *P_minutes)
{
    *P_hours = *P_minutes / 60;  // 90 / 60 = 1
    *P_minutes = *P_minutes % 60; // 90 % 60 = 30
}


void convertIntToString(int *number, char **string)
{
    *string = malloc(sizeof(char) * (int)log10(*number) + 1);
    sprintf(*string, "%d", *number);
}

void BMI_calculator(int *height, int *weight, float *BMI)
{
    *BMI = (float)*weight / (pow(*height, 2) / 10000);
}