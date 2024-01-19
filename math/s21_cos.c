#include "../s21_math.h"

long double s21_cos(double x) {
  long double res = 0;
  if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (S21_IS_INF(x))
    res = S21_NAN;
  else {
    res = s21_sin(x + S21_PI / 2.0);
  }
  return res;
}
