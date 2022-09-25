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
  to12h(&time); // Transform..
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

// not needed when using generate_test_runner.rb
int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_numDigitCount);
  RUN_TEST(test_to12h);
  RUN_TEST(test_multisoft);

  return UNITY_END();
}