#include <stdio.h>
#include "book.h"

void check(int x, int y, int (*func)(int x), char *name);
#define CHECK(x, y, z, q) \
    check(x, y, z, #q)

void check(int x, int y, int (*func)(int x), char *name)
{
    printf("%s: ", name);
    if (x == func(y))
    {
        printf("Pass!\n");
    }
    else
    {
        printf("Fail! Expected %d, got %d\n", x, func(y));
    }
}
int main()
{
    CHECK(1, 0, numDigitCount, numDigitCount);
    CHECK(1, 9, numDigitCount, numDigitCount);
    CHECK(2, 10, numDigitCount, numDigitCount);
}