#include "../s21_math.h"

long double s21_atan(double x) {
  long double res = 0;
  long double res2 = 0;
  if (S21_IS_NAN(x))
    res = x;
  else if (isPOS_INF(x))
    res = S21_PI / 2;
  else if (isNEG_INF(x))
    res = (S21_PI / 2);
  else if (x == 1)
    res = S21_PI / 4;
  else if (x == -1)
    res = -(S21_PI / 4);

  else {
    if (x > -1 && x < 1) {
      for (int i = 0; i < 500; i++) {
        res += (s21_pow(-1, i) * s21_pow(x, 2 * i + 1)) / (i * 2 + 1);
      }
    } else {
      for (int i = 0; i < 500; i++) {
        res2 += (s21_pow(-1, i) * s21_pow(x, -1 - (2 * i))) / (i * 2 + 1);
      }
      res = ((S21_PI * s21_sqrt(s21_pow(x, 2))) / (2 * x)) - res2;
    }
  }
  return res;
}
