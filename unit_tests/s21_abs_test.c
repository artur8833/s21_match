#include "s21_test.h"

START_TEST(absTest1) {
  int testValue1 = -5;
  int testValue2 = 5;
  int testValue3 = 0;
  ck_assert_int_eq(s21_abs(testValue1), abs(testValue1));
  ck_assert_int_eq(s21_abs(testValue2), abs(testValue2));
  ck_assert_int_eq(s21_abs(testValue3), abs(testValue3));
}
END_TEST;

START_TEST(absTest2) {
  int testValue1 = -3.45;
  int testValue2 = 10;
  int testValue3 = 0;
  ck_assert_double_eq(s21_abs(testValue1), abs(testValue1));
  ck_assert_int_eq(s21_abs(testValue2), abs(testValue2));
  ck_assert_int_eq(s21_abs(testValue3), abs(testValue3));
}
END_TEST

Suite *absTest(void) {
  Suite *s = suite_create("\033[45mAbs test\033[0m");
  TCase *tc = tcase_create("Abs test");

  tcase_add_test(tc, absTest1);
  tcase_add_test(tc, absTest2);
  suite_add_tcase(s, tc);
  return s;
}