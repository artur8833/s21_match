#include "../s21_math.h"

long double s21_sqrt(double x) {
  long double res;
  if (S21_IS_NAN(x))
    res = S21_NAN;
  else if ((1 / x == 1 / 0.0))
    res = S21_ZERO_POSITIVE;
  else if ((1 / x == 1 / -0.0))
    res = S21_ZERO_NEGATIVE;
  else if (x == S21_INF_POSITIVE)
    res = S21_INF_POSITIVE;
  else if (x < 0)
    res = -S21_NAN;
  else
    res = s21_pow(x, 0.5);
  return res;
}
