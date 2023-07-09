#include "../s21_math.h"

long double s21_exp(double x) {
  long double res;
  if (x != x)
    res = S21_NAN;
  else if (x == S21_INF_POSITIVE)
    res = S21_INF_POSITIVE;
  else if (x == S21_INF_NEGATIVE)
    res = 0.0;
  else {
    long double comp = 1.0;
    res = 1.0;
    double temp_x = s21_fabs(x);
    for (int i = 1; i <= 1600; i++) {
      comp *= temp_x / i;
      res += comp;
    }
    if (x < 0) res = 1 / res;
  }
  return res;
}
