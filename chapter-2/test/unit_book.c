#include "book.h"
#include "unity.h"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_numDigitCount(void) {
  // test stuff
  TEST_ASSERT_EQUAL_INT(1, numDigitCount(0));
  TEST_ASSERT_EQUAL_INT(1, numDigitCount(9));
  TEST_ASSERT_EQUAL_INT(2, numDigitCount(10));
  TEST_ASSERT_EQUAL_INT(2, numDigitCount(99));
  TEST_ASSERT_EQUAL_INT(3, numDigitCount(100));
  TEST_ASSERT_EQUAL_INT(3, numDigitCount(999));
}

void test_to12h(void) {
  Time12h time = {20, 20, AM};
  to12h(&time);  // Transform..
  Time12h expected = {8, 20, PM};
  TEST_ASSERT_EQUAL_INT(expected.hour, time.hour);
  TEST_ASSERT_EQUAL_INT(expected.minutes, time.minutes);
  TEST_ASSERT_EQUAL_INT(expected.ampm, time.ampm);
}

void test_multisoft(void) {
  TEST_ASSERT_EQUAL_INT(1, multisoft(1));
  TEST_ASSERT_EQUAL_INT(3, multisoft(2));
  TEST_ASSERT_EQUAL_INT(4, multisoft(3));
  TEST_ASSERT_EQUAL_INT(7, multisoft(4));
  TEST_ASSERT_EQUAL_INT(11, multisoft(5));
}
/** Verify quicksortInt against qsort */
#define ARR_SIZE 10
int cmpfunc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
void test_quicksort() {
  int arr[ARR_SIZE] = {9, 16, 47, 82, 4, 66, 12, 3, 25, 5};
  int arr2[ARR_SIZE] = {9, 16, 47, 82, 4, 66, 12, 3, 25, 5};
  qsort(arr2, ARR_SIZE, sizeof(int), cmpfunc);
  quicksortInt(arr, 0, ARR_SIZE - 1);
  for (int i = 0; i < ARR_SIZE; ++i) {
    TEST_ASSERT_EQUAL_INT(arr2[i], arr[i]);
  }
}

// not needed when using generate_test_runner.rb
int main(void) {
  UNITY_BEGIN();
  TEST_ASSERT_EQUAL(__STDC_VERSION__, 201710L);
  RUN_TEST(test_numDigitCount);
  RUN_TEST(test_to12h);
  RUN_TEST(test_multisoft);
  RUN_TEST(test_quicksort);

  return UNITY_END();
}