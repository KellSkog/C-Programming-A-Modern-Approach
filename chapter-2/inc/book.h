#ifndef CHAPTER_2_BOOK
#define CHAPTER_2_BOOK

#include <stdlib.h>  // qsort
int dimensionalWeight(int volume);
float farenheitToCelisius(float farenheit_temp);
float calcSphereVol(float radius);
int numDigitCount(int num);
void quicksortInt(int a[], int low, int high);

typedef enum { AM, PM } MERIDIAN;
typedef struct {
  int hour;
  int minutes;
  MERIDIAN ampm;
} Time12h;
// Changes time from 24h format to 12h
void to12h(Time12h *time);

typedef enum { CLEAR = 0, CREDIT, DEBIT, BALANCE, EXIT } Command;
void checkbookHandlecommand(int *account, Command command);
int multisoft(int n);

#endif