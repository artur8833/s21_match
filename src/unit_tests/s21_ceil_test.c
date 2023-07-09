#include "s21_test.h"

START_TEST(ceilTest1) {
  double testValue1 = -5.7;
  double testValue2 = -0.1;
  double testValue3 = 12.4;
  ck_assert_ldouble_eq_tol(s21_ceil(testValue1), ceil(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(testValue2), ceil(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(testValue3), ceil(testValue3), 1e-6);
  for (double i = -1.01; i <= 1.01; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_ceil(i), ceil(i), 1e-6);
  }
}
END_TEST;

START_TEST(ceilTest2) {
  double testValue1 = S21_INF_POSITIVE;
  double testValue2 = S21_INF_NEGATIVE;
  double testValue3 = S21_NAN;
  ck_assert_double_infinite(s21_ceil(testValue1));
  ck_assert_double_infinite(s21_ceil(testValue2));
  ck_assert_double_nan(s21_ceil(testValue3));
}
END_TEST;

Suite *ceilTest(void) {
  Suite *s = suite_create("\033[45mCeil test\033[0m");
  TCase *tc = tcase_create("Ceil test");

  tcase_add_test(tc, ceilTest1);
  tcase_add_test(tc, ceilTest2);

  suite_add_tcase(s, tc);
  return s;
}