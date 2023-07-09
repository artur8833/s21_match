#include "../s21_math.h"

long double s21_fabs(double x) {
  long double res;
  if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (x == S21_ZERO_NEGATIVE)
    res = S21_ZERO_POSITIVE;
  else if (S21_IS_INF(x))
    res = S21_INF_POSITIVE;
  else {
    if (x > 0) {
      res = x;
    } else {
      res = -x;
    }
  }
  return res;
}
