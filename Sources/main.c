#include <stdio.h>
#include <stdlib.h>
#include "../Headers/function.h"

int main(int argc, char *argv[])
{
    int heures = 0, minutes = 564;
    // On envoie l'adresse de heures et minutes à la fonction decoupeMinutes
    decoupeMinutes(&heures, &minutes);
    printf("%d heures et %d minutes\n", heures, minutes);


    int number = 123;
    char *string = NULL;
    // On envoie l'adresse de number et string à la fonction convertIntToString
    convertIntToString(&number, &string);
    printf("%s\n", string);
    free(string);

    return 0;
}
