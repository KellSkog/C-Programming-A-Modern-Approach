#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "book.h"

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

void printPrelude(int row)
{
    if (row == 3)
        printf("* ");
    else if (row == 4)
        printf(" *");
    else
        printf("  ");
}
void printEnding(int row)
{
    for (int j = 0; j < (5 - row); ++j)
    {
        printf(" ");
    }
    printf("*\n");
}

void programmingProjects_2_1(void)
{
    const int rows = 6;
    // const int cols = 8;
    for (int row = 0; row < rows; ++row)
    {
        printPrelude(row);
        printEnding(row);
    }
}

void programmingProjects_2_2(void)
{
    printf("Enter a radius: ");
    float radius;
    scanf("%f", &radius);
    printf("A spere with radius: %.3f, has the volume %.3f\n", radius, calcSphereVol(radius));
}

void printingDate_5_3(void)
{
    const char *months[] = {"", // No month 0
                            "January",
                            "February",
                            "Mars",
                            "April",
                            "May",
                            "June",
                            "July",
                            "August",
                            "September",
                            "October",
                            "November",
                            "December"};
    printf("Enter date (mm/dd/yy): ");
    int day, month, year;
    scanf("%d/%d/%d", &month, &day, &year);
    printf("Dated this %d", day);
    switch (day)
    { // "st", "rd", "th"
    case 21:
    case 31:
        printf("st ");
        break;
    case 23:
        printf("rd ");
        break;
    default:
        printf("th ");
    }
    printf("day of %s. ", months[month]);
    printf("20%d.\n", year);
}

void programmingProjects_5_3_1(void)
{
    int num;
    printf("Enter an integer ");
    scanf("%d", &num);
    printf("The number %d has %d digits\n", num, numDigitCount(num));
}

void oddsquare(void)
{
    int i, n, square, odd;
    printf("Enter number of entries: ");
    scanf("%d", &n);

    i = 1;
    odd = 3;
    for (square = 1; i <= n; odd += 2)
    {
        printf("%10d%10d\n", i, square);
        ++i;
        square += odd;
    }
}

int main(int argc, char **argv)
{
    printf("To C, or not C: that is the question.\n");
    /*calcWeight(argc, argv);
    calcTemp(argc, argv);
    programmingProjects_2_1();
    programmingProjects_2_2();
    printingDate_5_3();
    programmingProjects_5_3_1();
     */
    oddsquare();
    (void)argc;
    (void)argv;

    return 0;
}