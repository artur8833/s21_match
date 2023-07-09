#include "../s21_math.h"

long double s21_exp(double x) {
  long double res;

  if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (S21_IS_INF(x)) {
    if (x == S21_INF_POSITIVE) res = S21_INF_POSITIVE;
    if (x == S21_INF_NEGATIVE) res = S21_ZERO_POSITIVE;
  } else {
    long double add_value = 1;
    long double series = 1;
    long double i = 1;

    while (s21_fabs(add_value) > S21_EPS) {
      add_value *= x / i;
      i += 1;
      series += add_value;
      if (series > S21_DBL_MAX) {
        series = S21_INF_POSITIVE;
        break;
      }
    }
    res = series;
  }
  return res;
}
