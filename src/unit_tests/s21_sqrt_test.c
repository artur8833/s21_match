#include "s21_test.h"

START_TEST(sqrtTest1) {
  double testValue1 = 256;
  double testValue2 = 25;
  double testValue3 = 0;
  ck_assert_ldouble_eq_tol(s21_sqrt(testValue1), sqrt(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(testValue2), sqrt(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(testValue3), sqrt(testValue3), 1e-6);
}
END_TEST

START_TEST(sqrtTest2) {
  double testValue1 = -1;
  double testValue2 = 1e10;
  double testValue3 = 0.01;
  double testValue4 = -25.01;
  ck_assert_double_nan(s21_sqrt(testValue1));
  ck_assert_ldouble_eq_tol(s21_sqrt(testValue2), sqrt(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(testValue3), sqrt(testValue3), 1e-6);
  ck_assert(S21_IS_NAN(s21_sqrt(testValue4)) == S21_IS_NAN(sqrt(testValue4)));
  ck_assert(S21_IS_NAN(s21_sqrt(NAN)) == S21_IS_NAN(sqrt(NAN)));
  ck_assert(S21_IS_NAN(s21_sqrt(0)) == S21_IS_NAN(sqrt(0)));
  ck_assert(S21_IS_NAN(s21_sqrt(-0.0)) == S21_IS_NAN(sqrt(-0.0)));
  ck_assert(S21_IS_NAN(s21_sqrt(INFINITY)) == S21_IS_NAN(sqrt(INFINITY)));
}
END_TEST

Suite *sqrtTest(void) {
  Suite *s = suite_create("\033[45mSqrt test\033[0m");
  TCase *tc = tcase_create("Sqrt test");

  tcase_add_test(tc, sqrtTest1);
  tcase_add_test(tc, sqrtTest2);
  suite_add_tcase(s, tc);
  return s;
}