#include <stdio.h>
#include <stdlib.h>
#include "../Headers/function.h"

int main(int argc, char *argv[])
{
    int hours = 0, minutes = 564;
    // Send variables addresses to functions
    getHours(&hours, &minutes);
    printf("%d hours et %d minutes\n", hours, minutes);


    int number = 123;
    char *string = NULL;
    // Return the address of string to the function convertIntToString and store the result in string
    convertIntToString(&number, &string);
    printf("%s\n", string);
    free(string);

    return 0;
}
