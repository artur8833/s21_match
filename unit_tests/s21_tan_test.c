#include "s21_test.h"

START_TEST(tanTest1) {
  int testValue1 = 1000;
  int testValue2 = -3003;
  double testValue3 = 0.0005;
  double testValue4 = 0.98439849385;
  double testValue5 = S21_PI;

  ck_assert_ldouble_eq_tol(s21_tan(testValue1), tan(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(testValue2), tan(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(testValue3), tan(testValue3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(testValue4), tan(testValue4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(testValue5), tan(testValue5), 1e-6);
  ck_assert(S21_IS_NAN(s21_tan(NAN)) == S21_IS_NAN(tan(NAN)));
  ck_assert(S21_IS_NAN(s21_tan(INFINITY)) == S21_IS_NAN(tan(INFINITY)));
}
END_TEST

Suite *tanTest(void) {
  Suite *s = suite_create("\033[45mTan test\033[0m");
  TCase *tc = tcase_create("Tan test");

  tcase_add_test(tc, tanTest1);

  suite_add_tcase(s, tc);
  return s;
}