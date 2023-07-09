#include "s21_test.h"

START_TEST(asinTest1) {
  ck_assert_ldouble_eq_tol(s21_asin(1.0), asin(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1.0), asin(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.23234), asin(0.23234), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.23234), asin(-0.23234), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.0002), asin(0.0002), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.0002), asin(-0.0002), 1e-6);
  ck_assert(S21_IS_NAN(s21_asin(NAN)) == S21_IS_NAN(asin(NAN)));
  ck_assert(S21_IS_NAN(s21_asin(INFINITY)) == S21_IS_NAN(asin(INFINITY)));
  ck_assert(S21_IS_NAN(s21_asin(-INFINITY)) == S21_IS_NAN(asin(-INFINITY)));
  ck_assert(S21_IS_NAN(s21_asin(5)) == S21_IS_NAN(asin(5)));
}
END_TEST;

Suite *asinTest(void) {
  Suite *s = suite_create("\033[45mAsin test\033[0m");
  TCase *tc = tcase_create("Asin test");

  tcase_add_test(tc, asinTest1);

  suite_add_tcase(s, tc);
  return s;
}