#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "book.h"
#include "constants.h"

void calcWeight(int argc, char **argv) {
  int height, length, width;
  int volume;
  if (argc == 4)  // Three arguments
  {
    // TODO: Prefere stol
    height = atoi(argv[1]);
    length = atoi(argv[2]);
    width = atoi(argv[3]);
  } else {
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

void calcTemp(int argc, char **argv) {
  float farenheit;
  if (argc == 2)  // Three arguments
  {
    farenheit = atof(argv[1]);
  } else {
    printf("Farenheit temperature: ");
    scanf("%f", &farenheit);
  }
  printf("Farenheit %.1f -> Celsius: %.1f\n", farenheit, farenheitToCelisius(farenheit));
}

void printPrelude(int row) {
  if (row == 3)
    printf("* ");
  else if (row == 4)
    printf(" *");
  else
    printf("  ");
}
void printEnding(int row) {
  for (int j = 0; j < (5 - row); ++j) {
    printf(" ");
  }
  printf("*\n");
}

void programmingProjects_2_1(void) {
  const int rows = 6;
  // const int cols = 8;
  for (int row = 0; row < rows; ++row) {
    printPrelude(row);
    printEnding(row);
  }
}

void programmingProjects_2_2(void) {
  printf("Enter a radius: ");
  float radius;
  scanf("%f", &radius);
  printf("A spere with radius: %.3f, has the volume %.3f\n", radius, calcSphereVol(radius));
}

void printingDate_5_3(void) {
  const char *months[] = {"",  // No month 0
                          "January", "February", "Mars",      "April",   "May",      "June",
                          "July",    "August",   "September", "October", "November", "December"};
  printf("Enter date (mm/dd/yy): ");
  int day, month, year;
  scanf("%d/%d/%d", &month, &day, &year);
  printf("Dated this %d", day);
  switch (day) {  // "st", "rd", "th"
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

void programmingProjects_5_3_1(void) {
  int num;
  printf("Enter an integer ");
  scanf("%d", &num);
  printf("The number %d has %d digits\n", num, numDigitCount(num));
}

void oddsquare(void) {
  int i, n, square, odd;
  printf("Enter number of entries: ");
  scanf("%d", &n);

  i = 1;
  odd = 3;
  for (square = 1; i <= n; odd += 2) {
    printf("%10d%10d\n", i, square);
    ++i;
    square += odd;
  }
}

void checkBook(void) {
  int account;
  int command;
  printf("ACME checkbook\n");
  do {
    printf("Enter cmd (0=clear, 1=credit, 2=debit, 3=balance, 4=exit): ");
    scanf("%d", &command);
    checkbookHandlecommand(&account, (Command)command);

  } while (command != 4);
}

void reddit_u_No_Kitchen_9597() {
  // Does this program calculate largest prime?
  // Well, sometimes.. but no
  int largestPrime, i, j, prime;
  scanf("%d", &largestPrime);
  for (i = 2; i < largestPrime; i++) {
    j = 2;
    while (j <= i / j && i % j == 1) {
      printf("i=%d, j=%d, i/j=%d, imodj=%d\n", i, j, i / j, i % j);
      j++;
    }
    if (j > i / j) prime = i;
  }
  printf("prime: %d\n", prime);
}
void remaindr() {
  for (int i = 1; i <= 10; ++i) {
    printf("i=%d, 10modi=%d, imod3=%d\n", i, 10 % i, i % 3);
  }
}
struct entry {
  char x[256];
};
/*error: ISO C forbids forward parameter declarations [-Wpedantic]
   struct entry tester(int len; char data[len][len], int len) { */
struct entry tester(int len, char data[len][len]) { /* … */
  (void)data;
  struct entry q = {{42}};
  printf("q at %p, q.x=%d\n", (void *)&q, q.x[0]);
  return q;
}
void gcc_vla() {
  /* https://gcc.gnu.org/onlinedocs/gcc/Variable-Length.html
   * You can also use variable-length arrays as arguments to functions: */
  int len = 2;
  char data[len][len];
  struct entry q = tester(len, data);  // q is copied!!
  (void)q;
}
void exercice_6_3_13() {
  int m = 8;
  for (int n = 0; m > 0; n++) m /= 2;
  printf("%d\n", m);

  m = 8;
  for (int n = 0; m > 0; n++, m /= 2)
    ;
  printf("%d\n", m);
}
void programmingProjects_6_5_1() {
  float num;
  float max = 0.0, min = __FLT_MAX__;
  int cnt = 0;
  do {
    printf("Enter a number: ");
    scanf("%f", &num);
    if (num < min) min = num;
    if (num > max) max = num;
    if (num > 0) ++cnt;
  } while (num > 0);
  printf("Of %d nums max was %f, min %f", cnt, max, min);
}
int GCD(int m, int n) {
  // Euclids
  if (n == 0) return m;
  return GCD(n, m % n);
}
void programmingProjects_6_5_2() {
  int alpha, beta;
  printf("Enter two integers: ");
  scanf("%d%d", &alpha, &beta);
  printf("GCD is: %d\n", GCD(alpha, beta));
}
void programmingProjects_6_5_8() {
  printf("Enter days in month: ");
  int daysInMonth;
  scanf("%d", &daysInMonth);
  printf("Enter starting day ow week(1=Mon): ");
  int startingDay;
  scanf("%d", &startingDay);
  int dayOfWeek = 1;
  do {
    if (dayOfWeek < startingDay) {
      printf("   ");
    } else {
      printf("%3d", dayOfWeek);
    }
    if (dayOfWeek % 7 == 0) {
      printf("\n");
    }
  } while (++dayOfWeek <= daysInMonth);
  printf("\n");
}
void designatedInitializers() {
#define size 9
  // int a[size] = {-1, 1, 2, [2] = 2, [3] = 3, [5] = 5, [7] = 7}; error:
  // initialized field overwritten [-Werror=override-init]
  // int a[size] = {[2] = 2, -1, 1, [5] = 5, [3] = 3, [7] = 7}; error:
  // initialized field overwritten [-Werror=override-init]
  int a[size] = {-1, 1, [2] = 2, [5] = 5, [3] = 3, [7] = 7, -8};
  printf("%d", a[0]);
  for (int i = 1; i < size; ++i) {
    printf(", %d", a[i]);
  }
  printf("\n");
}
void checkingNumberForRepeatedDigit() {
  /* Page 166/191 Ch. 8.1 Arrays, a flag is set to true if corresponding digit is repeated
   * Number of digits in input is limited to 32,
   */

  printf("Enter a number: ");
  int digits[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};  // Initialize all ditits -1 represents not entered (yet)
  int digit;
  digit = getchar();
  while (digit != '\n' && digit != EOF) {
    digits[digit - '0']++;
    digit = getchar();
  }
  printf("Repeated digits ");
  for (int i = 0; i <= 9; ++i) {
    if (digits[i] > 0) {
      printf("%d", i);
    }
  }
  printf("\n");
}
/** Dealing a hand of cards
 * Cards have suit (clubs, diamonds, hearts, spades) and rank (2..10,jack, queen, king, ace)
 */
typedef enum { NONE, CLUBS, DIAMONDS, HEARTS, SPADES } eSuit;
typedef enum { JACK, QUEEN, KING, ACE } eRank;
typedef struct {
  eSuit suit;
  eRank rank;
} Card_str;
#define DECKSIZE 3
#define HANDSIZE 2
void dealHand() {
  const char *suitNames[] = {"", "CLUBS", "DIAMONDS", "HEARTS", "SPADES"};
  const char *rankNames[] = {"JACK", "QUEEN", "KING", "ACE"};
  Card_str deck[DECKSIZE] = {{CLUBS, JACK}, {DIAMONDS, ACE}, {HEARTS, QUEEN}};
  srand(time(NULL));

  Card_str hand[HANDSIZE];
  for (int i = 0; i < 2; ++i) {
    int card = rand() % HANDSIZE;
    while (deck[card].suit == NONE) {  // #define NULL ((void *)0)
      card = rand() % HANDSIZE;
    }
    hand[i] = deck[card];
    deck[card].suit = NONE;  // Remove card from deck!
  }
  for (int i = 0; i < HANDSIZE; ++i) {
    printf("%s of %s\n", rankNames[hand[i].rank], suitNames[hand[i].suit]);
  }
}
int main(int argc, char **argv) {
  // (void)argv;
  if (argc == 2) {
    int func = atoi(argv[1]);
    switch (func) {
      case 1:
        calcWeight(argc, argv);
        break;
      case 2:
        calcTemp(argc, argv);
        break;
      case 3:
        programmingProjects_2_1();
        break;
      case 4:
        programmingProjects_2_2();
        break;
      case 5:
        printingDate_5_3();
        break;
      case 6:
        programmingProjects_5_3_1();
        break;
      case 7:
        oddsquare();
        break;
      case 8:
        checkBook();
        break;
      case 9:
        reddit_u_No_Kitchen_9597();
        break;
      case 10:
        remaindr();
        break;
      case 11:
        gcc_vla();
        break;
      case 12:
        exercice_6_3_13();
        break;
      case 13:
        programmingProjects_6_5_1();
        break;
      case 14:
        programmingProjects_6_5_2();
        break;
      case 15:
        programmingProjects_6_5_8();
        break;
      case 16:
        designatedInitializers();
        break;
      case 17:
        checkingNumberForRepeatedDigit();
        break;
      case 18:
        dealHand();
        break;
      default:
        argc = 1;
    }
  }
  if (argc == 1) {
    printf("To C, or not C: that is the question.\n");
    printf("Size of double %ld\n", sizeof(0.0));
    printf("Size of float %ld\n", sizeof(0.0F));
    printf("Size of long long %ld\n", sizeof(0LL));
    printf("Size of long %ld\n", sizeof(0L));
    printf("Size of int %ld\n", sizeof(0));
    printf("Size of char %ld\n", sizeof('S'));
  }

  return 0;
}