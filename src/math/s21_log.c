#include "../s21_math.h"

long double s21_log(double x) {
  long double res = 0;
  if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (x == 1)
    res = S21_ZERO_POSITIVE;
  else if (x < 0)
    res = -S21_NAN;
  else if (x == 0)
    res = S21_INF_NEGATIVE;
  else if (x == S21_INF_POSITIVE)
    res = S21_INF_POSITIVE;
  else {
    long double temp = 0;
    int series = 0;
    long double sum = 1;
    for (; x >= S21_EXP; series++) x /= S21_EXP;

    for (int i = 0; i < 100; i++) {
      temp = sum;
      sum = temp + 2 * (x - s21_exp(temp)) / (x + s21_exp(temp));
    }
    sum = sum + series;
    res = sum;
  }
  return res;
}
