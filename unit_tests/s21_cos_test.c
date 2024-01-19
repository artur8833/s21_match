#include "s21_test.h"

START_TEST(cosTest1) {
  int testValue1 = 100;
  int testValue2 = -3003;
  double testValue3 = 0.0005;
  double testValue4 = 0.98439849385;
  double testValue5 = S21_PI;
  double testValue6 = -S21_PI;
  double testValue7 = S21_PI / 2;
  double testValue8 = -S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_cos(testValue1), cos(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(testValue2), cos(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(testValue3), cos(testValue3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(testValue4), cos(testValue4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(testValue5), cos(testValue5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(testValue6), cos(testValue6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(testValue7), cos(testValue7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(testValue8), cos(testValue8), 1e-6);

  ck_assert(S21_IS_NAN(s21_cos(NAN)) == S21_IS_NAN(cos(NAN)));
  ck_assert(S21_IS_NAN(s21_cos(INFINITY)) == S21_IS_NAN(cos(INFINITY)));
}
END_TEST;

START_TEST(cosTest2) {
  double step = 0.01;
  for (double i = -5 * S21_PI; i <= 5 * S21_PI; i += step) {
    ck_assert_ldouble_eq_tol(s21_cos(i), cos(i), 1e-6);
  }
}
END_TEST

Suite *cosTest(void) {
  Suite *s = suite_create("\033[45mCos test\033[0m");
  TCase *tc = tcase_create("Cos test");

  tcase_add_test(tc, cosTest1);
  tcase_add_test(tc, cosTest2);

  suite_add_tcase(s, tc);
  return s;
}