#include <math.h>

void decoupeMinutes(int *P_heures, int *P_minutes)
{
    *P_heures = *P_minutes / 60;  // 90 / 60 = 1
    *P_minutes = *P_minutes % 60; // 90 % 60 = 30
}


void convertIntToString(int *number, char **string)
{
    *string = malloc(sizeof(char) * (int)log10(*number) + 1);
    sprintf(*string, "%d", *number);
}
