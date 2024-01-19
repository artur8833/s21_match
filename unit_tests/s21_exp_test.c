#include "s21_test.h"

START_TEST(expTest1) {
  double testValue1 = -5;
  double testValue2 = 5;
  double testValue3 = 0.1;
  ck_assert_ldouble_eq_tol(s21_exp(testValue1), exp(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(testValue2), exp(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(testValue3), exp(testValue3), 1e-6);
}
END_TEST

START_TEST(expTest2) {
  double testValue1 = 243757437;
  double testValue2 = -24.4353425;
  double testValue3 = 0.0;
  for (double i = -20.0; i <= 20.00; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_exp(i), exp(i), 1e-6);
  }
  ck_assert_float_infinite(s21_exp(testValue1));
  ck_assert_ldouble_eq_tol(s21_exp(testValue2), exp(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(testValue3), exp(testValue3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(testValue2), exp(testValue2), 1e-6);
  ck_assert_float_infinite(s21_exp(S21_INF_POSITIVE));
  ck_assert_ldouble_eq(s21_exp(S21_INF_NEGATIVE), 0.0);
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_nan(s21_exp(-S21_NAN));
}
END_TEST

Suite *expTest(void) {
  Suite *s = suite_create("\033[45mExp test\033[0m");
  TCase *tc = tcase_create("Exp test");

  tcase_add_test(tc, expTest1);
  tcase_add_test(tc, expTest2);

  suite_add_tcase(s, tc);
  return s;
}