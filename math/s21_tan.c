#include "../s21_math.h"

long double s21_tan(double x) {
  long double res;
  if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (S21_IS_INF(x))
    res = S21_NAN;
  else {
    res = s21_sin(x) / s21_cos(x);
  }
  return res;
}
