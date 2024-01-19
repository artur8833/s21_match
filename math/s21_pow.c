#include <stdint.h>

#include "../s21_math.h"

int s21_signbit(double x) {
  union {
    double d;
    uint64_t i;
  } u;
  u.d = x;
  return (u.i >> 63) & 1;
}

long double s21_pow(double x, double y) {
  long double res = 1.0;
  long double fabs_y = s21_fabs(y);
  int odd = (fabs_y / 2) > s21_floor(fabs_y / 2);
  if (((x < 0 && x != S21_INF_POSITIVE) && y != s21_floor(y)) ||
      (x != x || y != y)) {
    res = S21_NAN;
  } else if ((x == 0 && y > 0) || (s21_fabs(x) > 1 && y == S21_INF_NEGATIVE) ||
             (s21_fabs(x) < 1 && y == S21_INF_POSITIVE) ||
             (x == S21_INF_NEGATIVE && y < 0) ||
             (x == S21_INF_POSITIVE && y < 0)) {
    res = 0.0;
  } else if ((x == -1 && (y == S21_INF_POSITIVE || y == S21_INF_NEGATIVE)) ||
             y == 0 || x == 1) {
    res = 1.0;
  } else if (((s21_fabs(x) < 1 && x != 0) && y == S21_INF_NEGATIVE) ||
             (s21_fabs(x) > 1 && y == S21_INF_POSITIVE) ||
             (x == S21_INF_POSITIVE && y > 0)) {
    res = S21_INF_POSITIVE;
  } else if (x == S21_INF_NEGATIVE && y > 0) {
    (y / 2 > s21_floor(y / 2)) ? (res = S21_INF_NEGATIVE)
                               : (res = S21_INF_POSITIVE);
  } else if (x == 0 && y < 0) {
    int x_sign = s21_signbit(x);
    ((x_sign != 0 && !odd) || (odd && x_sign == 0)) ? (res = S21_INF_POSITIVE)
                                                    : (res = S21_INF_NEGATIVE);
  } else {
    double x_fabs = s21_fabs(x);
    res = s21_exp(y * s21_log(x_fabs));
    if (odd && x < 0) res = -res;
  }
  return res;
}
