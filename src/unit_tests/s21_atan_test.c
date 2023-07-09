#include "s21_test.h"

START_TEST(atanTest1) {
  ck_assert_ldouble_eq_tol(s21_atan(1.0), atan(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.1), atan(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1.0), atan(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atan(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1000.0), atan(1000.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1000.0), atan(-1000.0), 1e-6);
  ck_assert(S21_IS_NAN(s21_atan(NAN)) == S21_IS_NAN(atan(NAN)));
  ck_assert(S21_IS_NAN(s21_atan(INFINITY)) == S21_IS_NAN(atan(INFINITY)));
  ck_assert(S21_IS_NAN(s21_atan(-INFINITY)) == S21_IS_NAN(atan(-INFINITY)));
}
END_TEST;

Suite *atanTest(void) {
  Suite *s = suite_create("\033[45mAtan test\033[0m");
  TCase *tc = tcase_create("Atan test");

  tcase_add_test(tc, atanTest1);

  suite_add_tcase(s, tc);
  return s;
}