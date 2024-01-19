#include "../s21_math.h"

long double s21_sin(double x) {
  long double res = 0;

  if (S21_IS_NAN(x))
    res = x;
  else if (S21_IS_INF(x))
    res = -S21_NAN;
  else if (x == S21_PI)
    res = S21_ZERO_POSITIVE;
  else if (x == -S21_PI)
    res = S21_ZERO_NEGATIVE;
  else if (x == 1)
    res = S21_PI / 4;
  else if (x == -1)
    res = -(S21_PI / 4);
  else {
    while (s21_fabs(x) - 2 * S21_PI > 0) {
      x += 2 * S21_PI * x / s21_fabs(x) * -1;
    }
    int sign = 1;
    double xx = x * x;
    double pw = x;
    double fti = 1.0;
    for (int i = 1; i < 200; i += 2) {
      fti *= i;
      res += sign * pw / fti;
      fti *= (i + 1);
      sign = -sign;
      pw *= xx;
    }
  }
  return res;
}
