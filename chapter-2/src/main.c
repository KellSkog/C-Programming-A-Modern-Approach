#include <stdio.h>
#include <stdlib.h>

#define ALLOWED_CU_INCH_PER_POUND 166

int dimensionalWeight(int volume)
{
    // Assure division is rounded up
    return (volume + (ALLOWED_CU_INCH_PER_POUND - 1)) / ALLOWED_CU_INCH_PER_POUND;
}

int main(int argc, char **argv)
{
    printf("To C, or not C: that is the question.\n");
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
    return 0;
}