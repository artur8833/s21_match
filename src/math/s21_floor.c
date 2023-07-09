#include "../s21_math.h"

long double s21_floor(double x) {
  long double res;
  if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (S21_IS_INF(x)) {
    if (x == S21_INF_POSITIVE) res = S21_INF_POSITIVE;
    if (x == S21_INF_NEGATIVE) res = S21_ZERO_POSITIVE;
  } else {
    long double floor_x = (long long int)x;  //приводим к int
    if (x < 0) floor_x -= 1;  //если число отрицательное + (-1)
    res = floor_x;
  }
  return res;
}