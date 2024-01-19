#include "s21_test.h"

START_TEST(powTest1) {
  double base = 2.432434;
  double exp = 343124.14;
  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST;

START_TEST(powTest2) {
  double base = 525;
  double exp = 12;
  ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST;

START_TEST(powTest3) {
  double base = S21_NAN;
  double exp = 3;

  ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST;

START_TEST(powTest4) {
  double base = 2.432523;
  double exp = S21_NAN;

  ck_assert_int_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST;

START_TEST(powTest5) {
  double base = 0;
  double exp = 0;

  ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST;

START_TEST(powTest6) {
  double base = 525;
  double exp = -12;
  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 0.000001);
}
END_TEST;

START_TEST(powTest7) {
  double base = 525;
  double exp = NAN;
  ck_assert_double_nan(s21_pow(base, exp));
  ck_assert_double_nan(pow(base, exp));
}
END_TEST;

START_TEST(powTest8) {
  ck_assert(S21_IS_NAN(s21_pow(5.5, NAN)) == S21_IS_NAN(pow(5.5, NAN)));
  ck_assert(S21_IS_NAN(s21_pow(5, INFINITY)) == S21_IS_NAN(pow(5, INFINITY)));
  ck_assert(S21_IS_NAN(s21_pow(-5, -1)) == S21_IS_NAN(pow(-5, -1)));
  ck_assert(S21_IS_NAN(s21_pow(INFINITY, 1)) == S21_IS_NAN(pow(INFINITY, 1)));
  ck_assert(S21_IS_NAN(s21_pow(INFINITY, 0)) == S21_IS_NAN(pow(INFINITY, 0)));
  ck_assert(S21_IS_NAN(s21_pow(INFINITY, INFINITY)) ==
            S21_IS_NAN(pow(INFINITY, INFINITY)));
  ck_assert(S21_IS_NAN(s21_pow(INFINITY, NAN)) ==
            S21_IS_NAN(pow(INFINITY, NAN)));
  ck_assert(S21_IS_NAN(s21_pow(5.2, INFINITY)) ==
            S21_IS_NAN(pow(5.2, INFINITY)));
  ck_assert(S21_IS_NAN(s21_pow(5.2, -INFINITY)) ==
            S21_IS_NAN(pow(5.2, -INFINITY)));
  ck_assert(S21_IS_NAN(s21_pow(-1, INFINITY)) == S21_IS_NAN(pow(-1, INFINITY)));
  ck_assert(S21_IS_NAN(s21_pow(0, -3)) == S21_IS_NAN(pow(0, -3)));
  ck_assert(S21_IS_NAN(s21_pow(0, -INFINITY)) == S21_IS_NAN(pow(0, -INFINITY)));
  ck_assert(S21_IS_NAN(s21_pow(0, -NAN)) == S21_IS_NAN(pow(0, -NAN)));
  ck_assert(S21_IS_NAN(s21_pow(-INFINITY, 0)) == S21_IS_NAN(pow(-INFINITY, 0)));
  ck_assert(S21_IS_NAN(s21_pow(-INFINITY, 1)) == S21_IS_NAN(pow(-INFINITY, 1)));
  ck_assert(S21_IS_NAN(s21_pow(-INFINITY, INFINITY)) ==
            S21_IS_NAN(pow(-INFINITY, INFINITY)));
  ck_assert(S21_IS_NAN(s21_pow(-INFINITY, NAN)) ==
            S21_IS_NAN(pow(-INFINITY, NAN)));
  ck_assert(S21_IS_NAN(s21_pow(-3, NAN)) == S21_IS_NAN(pow(-3, NAN)));
}
END_TEST;

Suite *powTest(void) {
  Suite *s = suite_create("\033[45mPow test\033[0m");
  TCase *tc = tcase_create("Pow test");

  tcase_add_test(tc, powTest1);
  tcase_add_test(tc, powTest2);
  tcase_add_test(tc, powTest3);
  tcase_add_test(tc, powTest4);
  tcase_add_test(tc, powTest5);
  tcase_add_test(tc, powTest6);
  tcase_add_test(tc, powTest7);
  tcase_add_test(tc, powTest8);

  suite_add_tcase(s, tc);
  return s;
}