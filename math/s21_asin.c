#include "../s21_math.h"

long double s21_asin(double x) {
  long double res = 0;

  if (S21_IS_NAN(x))
    res = x;
  else if (S21_IS_INF(x))
    res = S21_NAN;
  else if (x == 1)
    res = S21_PI / 2;
  else if (x == -1)
    res = -(S21_PI / 2);
  else if (x > -1 && x < 1) {
    res = s21_atan(x / (s21_sqrt(1 - (x * x))));
  } else
    res = S21_NAN;

  return res;
}
