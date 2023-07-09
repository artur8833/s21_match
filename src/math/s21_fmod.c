#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0;
  if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (S21_IS_INF(x) || y == 0)
    res = S21_NAN;
  else if (x == S21_ZERO_POSITIVE || x == S21_ZERO_NEGATIVE) {
    if ((1 / x == 1 / 0.0) && y != 0)
      res = S21_ZERO_POSITIVE;
    else if ((1 / x == 1 / -0.0) && y != 0)
      res = S21_ZERO_NEGATIVE;
  } else {
    long long int mod = 0;
    mod = x / y;
    res = (long double)x - mod * (long double)y;
  }
  return res;
}
