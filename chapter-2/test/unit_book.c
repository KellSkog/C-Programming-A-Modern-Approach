#include "unity.h"
#include "book.h"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void test_numDigitCount(void)
{
    // test stuff
    TEST_ASSERT_EQUAL_INT(1, numDigitCount(0));
    TEST_ASSERT_EQUAL_INT(1, numDigitCount(9));
    TEST_ASSERT_EQUAL_INT(2, numDigitCount(10));
    TEST_ASSERT_EQUAL_INT(2, numDigitCount(99));
    TEST_ASSERT_EQUAL_INT(3, numDigitCount(100));
    TEST_ASSERT_EQUAL_INT(3, numDigitCount(999));
}

void test_to12h(void)
{
    Time12h time = {20, 20, AM};
    to12h(&time); // Transform..
    Time12h expected = {8, 20, PM};
    TEST_ASSERT_EQUAL_INT(expected.hour, time.hour);
    TEST_ASSERT_EQUAL_INT(expected.minutes, time.minutes);
    TEST_ASSERT_EQUAL_INT(expected.ampm, time.ampm);
}

// not needed when using generate_test_runner.rb
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_numDigitCount);
    RUN_TEST(test_to12h);

    return UNITY_END();
}