// #define __USE_MISC 1 // defines M_PI...
// #include <math.h>
#include "constants.h"
#include "book.h"

int dimensionalWeight(int volume)
{
    // Assure division is rounded up
    return (volume + (ALLOWED_CU_INCH_PER_POUND - 1)) / ALLOWED_CU_INCH_PER_POUND;
}

float farenheitToCelisius(float farenheit_temp)
{
    return (farenheit_temp - FARENHEIT_FREEZING_PT) * FARENHEIT_CELSIUS_SCALE;
}

float calcSphereVol(float radius)
{
    return radius * radius * radius * 4.0f * 3.14 /*M_PI*/ / 3.0f;
}

int numDigitCount(int num)
{
    int digitCount = 1;
    while (num >= 10)
    {
        num /= 10;
        digitCount++;
    }
    return digitCount;
}