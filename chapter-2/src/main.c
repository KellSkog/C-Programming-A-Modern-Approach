#include <stdio.h>
#include <stdlib.h>

#include "constants.h"

int dimensionalWeight(int volume)
{
    // Assure division is rounded up
    return (volume + (ALLOWED_CU_INCH_PER_POUND - 1)) / ALLOWED_CU_INCH_PER_POUND;
}
void calcWeight(int argc, char **argv)
{
    int height, length, width;
    int volume;
    if (argc == 4) // Three arguments
    {
        // TODO: Prefere stol
        height = atoi(argv[1]);
        length = atoi(argv[2]);
        width = atoi(argv[3]);
    }
    else
    {
        printf("Enter height: ");
        scanf("%d", &height);
        printf("Enter length: ");
        scanf("%d", &length);
        printf("Enter width: ");
        scanf("%d", &width);
    }
    volume = (height * length * width);
    printf("Dimensional weight: %d\n", dimensionalWeight(volume));
}

float farenheitToCelisius(float farenheit_temp)
{
    return (farenheit_temp - FARENHEIT_FREEZING_PT) * FARENHEIT_CELSIUS_SCALE;
}
void calcTemp(int argc, char **argv)
{
    float farenheit;
    if (argc == 2) // Three arguments
    {
        farenheit = atof(argv[1]);
    }
    else
    {
        printf("Farenheit temperature: ");
        scanf("%f", &farenheit);
    }
    printf("Farenheit %.1f -> Celsius: %.1f\n", farenheit, farenheitToCelisius(farenheit));
}

int main(int argc, char **argv)
{
    printf("To C, or not C: that is the question.\n");
    /*calcWeight(argc, argv);
     */
    calcTemp(argc, argv);

    return 0;
}