#include "../s21_math.h"

long double s21_ceil(double x) {
  long double res;
  long double ceil_x = (long long int)x;
  if ((x == (int)x) || x == S21_ZERO_NEGATIVE || x == S21_ZERO_POSITIVE ||
      S21_IS_NAN(x) || S21_IS_INF(x))
    res = x;
  else {
    if (x != ceil_x) {
      if (x > 0) {
        ceil_x += 1;
        res = ceil_x;
      } else if (x < 0 && ceil_x != 0) {
        res = ceil_x;
      } else {
        res = -ceil_x;
      }
    }
  }
  return res;
}
