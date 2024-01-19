#include "s21_test.h"

START_TEST(floorTest1) {
  double testValue1 = -5.7;
  double testValue2 = 5.1;
  double testValue3 = 12.4;
  ck_assert_ldouble_eq_tol(s21_floor(testValue1), floor(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(testValue2), floor(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(testValue3), floor(testValue3), 1e-6);
  for (double i = -2.01; i <= 1.01; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_floor(i), floor(i), 1e-6);
  }
}
END_TEST

START_TEST(floorTest2) {
  double testValue3 = S21_NAN;
  ck_assert_double_nan(s21_floor(testValue3));
  ck_assert(S21_IS_NAN(s21_floor(INFINITY)) == S21_IS_NAN(floor(INFINITY)));
  ck_assert(S21_IS_NAN(s21_floor(-INFINITY)) == S21_IS_NAN(floor(-INFINITY)));
}
END_TEST

Suite *floorTest(void) {
  Suite *s = suite_create("\033[45mFloor test\033[0m");
  TCase *tc = tcase_create("Floor test");

  tcase_add_test(tc, floorTest1);
  tcase_add_test(tc, floorTest2);

  suite_add_tcase(s, tc);
  return s;
}