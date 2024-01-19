#include "s21_test.h"

START_TEST(sinTest1) {
  double step = 0.05;
  for (double i = -5 * S21_PI; i <= 5 * S21_PI; i += step) {
    ck_assert_ldouble_eq_tol(s21_sin(i), sin(i), 1e-6);
  }
}
END_TEST

START_TEST(sinTest2) {
  int testValue1 = 100;
  int testValue2 = -3003;
  double testValue3 = 0.0005;
  double testValue4 = 0.98439849385;
  double testValue5 = S21_PI;
  double testValue6 = -S21_PI;
  double testValue7 = S21_PI / 2;
  double testValue8 = -S21_PI / 2;

  ck_assert_ldouble_eq_tol(s21_sin(testValue1), sin(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(testValue2), sin(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(testValue3), sin(testValue3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(testValue4), sin(testValue4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(testValue5), sin(testValue5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(testValue6), sin(testValue6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(testValue7), sin(testValue7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(testValue8), sin(testValue8), 1e-6);
  ck_assert(S21_IS_NAN(s21_sin(NAN)) == S21_IS_NAN(sin(NAN)));
  ck_assert(S21_IS_NAN(s21_sin(INFINITY)) == S21_IS_NAN(sin(INFINITY)));
  ck_assert(S21_IS_NAN(s21_sin(-INFINITY)) == S21_IS_NAN(sin(-INFINITY)));
  ck_assert(S21_IS_NAN(s21_sin(-1)) == S21_IS_NAN(sin(-1)));
  ck_assert(S21_IS_NAN(s21_sin(1)) == S21_IS_NAN(sin(1)));
}
END_TEST
Suite *sinTest(void) {
  Suite *s = suite_create("\033[45mSin test\033[0m");
  TCase *tc = tcase_create("Sin test");

  tcase_add_test(tc, sinTest1);
  tcase_add_test(tc, sinTest2);

  suite_add_tcase(s, tc);
  return s;
}