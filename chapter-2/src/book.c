// #define __USE_MISC 1 // defines M_PI...
// #include <math.h>
#include "book.h"

#include <stdio.h>

#include "constants.h"

int dimensionalWeight(int volume) {
  // Assure division is rounded up
  return (volume + (ALLOWED_CU_INCH_PER_POUND - 1)) / ALLOWED_CU_INCH_PER_POUND;
}

float farenheitToCelisius(float farenheit_temp) {
  return (farenheit_temp - FARENHEIT_FREEZING_PT) * FARENHEIT_CELSIUS_SCALE;
}

float calcSphereVol(float radius) { return radius * radius * radius * 4.0f * 3.14 /*M_PI*/ / 3.0f; }

int numDigitCount(int num) {
  int digitCount = 1;
  while (num >= 10) {
    num /= 10;
    digitCount++;
  }
  return digitCount;
}

void to12h(Time12h *time) {
  if (time->hour >= 13) {
    time->ampm = PM;
  } else {
    time->ampm = AM;
  }
  time->hour -= 12;
  if (time->hour == 0) {
    time->hour = 12;
  }
}

void checkbookHandlecommand(int *account, Command cmd) {
  int input;
  if (cmd > EXIT) cmd = EXIT;
  switch (cmd) {
    case CLEAR:
      *account = 0;
      break;
    case CREDIT:
      printf("Credit: ");
      scanf("%d", &input);
      *account += input;
      break;
    case DEBIT:
      printf("Dedit: ");
      scanf("%d", &input);
      *account -= input;
      break;
    case BALANCE:
      printf("Balance: %d\n", *account);
      break;
    case EXIT:
      break;
    default:
      printf("Command %d\n", cmd);
  }
}

int multisoft(int n) {
  if (n == 0)
    return 2;
  else if (n == 1)
    return 1;
  else
    return multisoft(n - 1) + multisoft(n - 2);
}

/** Implement Quicksort for integers */
// void quicksortInt(int n, int arr[*]) //variable length array with unspecified bound is not allowed
// clang-format off
int split(int a[], int low, int high) {
    int partition_element = a[low];
    for(;;) {
        while((low < high) && (partition_element <= a[high])) --high;
        if(low >= high) break;
        a[low++] = a[high];

        while((low < high) && (a[low] <= partition_element)) ++low;
        if(low >= high) break;
        a[high--] = a[low];
    }
    a[high] = partition_element;
    return high;
}
void quicksortInt(int a[], int low, int high) {
  int middle;
  if(low >= high) return;
  middle = split(a, low, high);
  quicksortInt(a, low, middle - 1);
  quicksortInt(a, middle + 1, high);
}
//clang-format on