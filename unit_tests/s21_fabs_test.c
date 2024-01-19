#include "s21_test.h"

START_TEST(fabsTest1) {
  double testValue1 = -5.503;
  double testValue2 = 5.0;
  double testValue3 = 0;
  ck_assert_ldouble_eq(s21_fabs(testValue1), fabs(testValue1));
  ck_assert_ldouble_eq(s21_fabs(testValue2), fabs(testValue2));
  ck_assert_ldouble_eq(s21_fabs(testValue3), fabs(testValue3));
}
END_TEST

START_TEST(fabsTest2) {
  double testValue1 = -10.45934;
  double testValue2 = 10.1;
  double testValue3 = 0.0;
  ck_assert_ldouble_eq(s21_fabs(testValue1), fabs(testValue1));
  ck_assert_ldouble_eq(s21_fabs(testValue2), fabs(testValue2));
  ck_assert_ldouble_eq(s21_fabs(testValue3), fabs(testValue3));
  ck_assert(S21_IS_NAN(s21_fabs(NAN)) == S21_IS_NAN(fabs(NAN)));
  ck_assert(S21_IS_NAN(s21_fabs(INFINITY)) == S21_IS_NAN(fabs(INFINITY)));
}
END_TEST

Suite *fabsTest(void) {
  Suite *s = suite_create("\033[45mFabs test\033[0m");
  TCase *tc = tcase_create("Fabs test");

  tcase_add_test(tc, fabsTest1);
  tcase_add_test(tc, fabsTest2);

  suite_add_tcase(s, tc);
  return s;
}