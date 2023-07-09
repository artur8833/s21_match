#include "../s21_math.h"

long double s21_floor(double x) {
  long double res;
  if (x == S21_INF_NEGATIVE || x == S21_INF_POSITIVE || x == 0)
    res = x;
  else if (x != x)
    res = S21_NAN;
  else {
    res = (long double)(long long)x;
    if (res > x) res -= 1.0;
  }
  return res;
}
