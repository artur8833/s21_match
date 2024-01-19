#include "s21_test.h"

START_TEST(logTest1) {
  double testValue1 = S21_EXP;
  double testValue2 = 10;
  double testValue3 = 3;
  ck_assert_ldouble_eq_tol(s21_log(testValue1), log(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(testValue2), log(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(testValue3), log(testValue3), 1e-6);
  for (double i = 0.1; i < 100.0; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_log(i), log(i), 1e-6);
  }
}
END_TEST

START_TEST(logTest2) {
  double testValue1 = -0.46376;
  double testValue2 = 0;
  double testValue3 = 0.00001;
  double testValue4 = -4;
  ck_assert_double_nan(s21_log(testValue1));
  ck_assert_ldouble_infinite(s21_log(testValue2));
  ck_assert_ldouble_eq_tol(s21_log(testValue3), log(testValue3), 0.00001);
  ck_assert(S21_IS_NAN(s21_log(testValue4)) == S21_IS_NAN(log(testValue4)));
  ck_assert_double_nan(s21_log(NAN));
  ck_assert_double_nan(s21_log(S21_NAN));
  ck_assert_double_nan(s21_log(-S21_NAN));
  ck_assert_ldouble_infinite(s21_log(S21_INF_POSITIVE));
  ck_assert_ldouble_nan(s21_log(S21_INF_NEGATIVE));
  ck_assert(S21_IS_NAN(s21_log(1)) == S21_IS_NAN(log(1)));
  ck_assert(S21_IS_NAN(s21_log(NAN)) == S21_IS_NAN(log(NAN)));
}
END_TEST

Suite *logTest(void) {
  Suite *s = suite_create("\033[45mLog test\033[0m");
  TCase *tc = tcase_create("Log test");

  tcase_add_test(tc, logTest1);
  tcase_add_test(tc, logTest2);

  suite_add_tcase(s, tc);
  return s;
}