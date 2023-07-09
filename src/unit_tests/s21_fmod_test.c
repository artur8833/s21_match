#include "s21_test.h"

START_TEST(fmodTest1) {
  double testValueX1 = -8;
  double testValueY1 = 3;
  double testValueX2 = -10;
  double testValueY2 = 2;
  double testValueX3 = 164.2;
  double testValueY3 = 0.3;
  ck_assert_ldouble_eq_tol(s21_fmod(testValueX1, testValueY1),
                           fmod(testValueX1, testValueY1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(testValueX2, testValueY2),
                           fmod(testValueX2, testValueY2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(testValueX3, testValueY3),
                           fmod(testValueX3, testValueY3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(0, testValueY3), fmod(0, testValueY3),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-0.0, testValueY3), fmod(-0.0, testValueY3),
                           1e-6);
}
END_TEST

START_TEST(fmodTest2) {
  double testValueX1 = 0;
  double testValueY1 = 0;
  double testValueY2 = 0;
  double testValueX3 = 100;
  double testValueY3 = -5;
  double testValueX4 = S21_INF_POSITIVE;
  double testValueY4 = -5;
  double testValueX5 = 4;
  double testValueY5 = S21_NAN;
  ck_assert_double_nan(s21_fmod(testValueX1, testValueY1));
  ck_assert_double_nan(s21_fmod(testValueY2, testValueY2));
  ck_assert_ldouble_eq_tol(s21_fmod(testValueX3, testValueY3),
                           fmod(testValueX3, testValueY3), 1e-6);
  ck_assert_double_nan(s21_fmod(testValueX4, testValueY4));
  ck_assert_double_nan(s21_fmod(testValueX5, testValueY5));

  ck_assert(S21_IS_NAN(s21_fmod(NAN, 5)) == S21_IS_NAN(fmod(NAN, 5)));
}
END_TEST

Suite *fmodTest(void) {
  Suite *s = suite_create("\033[45mFmod test\033[0m");
  TCase *tc = tcase_create("Fmod test");

  tcase_add_test(tc, fmodTest1);
  tcase_add_test(tc, fmodTest2);

  suite_add_tcase(s, tc);
  return s;
}