#include "s21_test.h"

START_TEST(acosTest1) {
  ck_assert_double_eq(s21_acos(1.0), acos(1.0));
  ck_assert_double_eq(s21_acos(-1.0), acos(-1.0));
  ck_assert(S21_IS_NAN(s21_acos(NAN)) == S21_IS_NAN(acos(NAN)));
  ck_assert(S21_IS_NAN(s21_acos(3)) == S21_IS_NAN(acos(3)));
  ck_assert(S21_IS_NAN(s21_acos(INFINITY)) == S21_IS_NAN(acos(INFINITY)));
}
END_TEST;

START_TEST(acosTest2) {
  ck_assert_double_eq_tol(s21_acos(0.0), acos(0.0), 0.000001);
  ck_assert_double_eq_tol(s21_acos(0.23234), acos(0.23234), 0.000001);
  ck_assert_double_eq_tol(s21_acos(-0.23234), acos(-0.23234), 0.000001);
  ck_assert_double_eq_tol(s21_acos(0.0002), acos(0.0002), 0.000001);
  ck_assert_double_eq_tol(s21_acos(-0.0002), acos(-0.0002), 0.000001);
}
END_TEST;

Suite *acosTest(void) {
  Suite *s = suite_create("\033[45mAcos test\033[0m");
  TCase *tc = tcase_create("Acos test");

  tcase_add_test(tc, acosTest1);
  tcase_add_test(tc, acosTest2);

  suite_add_tcase(s, tc);
  return s;
}