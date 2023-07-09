#ifndef S21_MATH_H
#define S21_MATH_H

#include <stdio.h>
#include <stdlib.h>

#define S21_PI 3.14159265358979323846
#define S21_EXP 2.7182818284590452354
#define S21_EPS 1e-17
#define S21_IS_INF(x) (x == S21_INF_POSITIVE || x == S21_INF_NEGATIVE)
#define S21_IS_NAN(x) (x != x)
#define S21_ZERO_NEGATIVE -(0.0)
#define S21_ZERO_POSITIVE 0.0
#define S21_INF_NEGATIVE (-1.0 / 0.0)
#define S21_INF_POSITIVE (+1.0 / 0.0)
#define S21_NAN (-(0.0f / 0.0f))
#define S21_DBL_MAX 1.7976931348623158e+308

#define isPOS_INF(x) (x == S21_INF_POSITIVE)
#define isNEG_INF(x) (x == S21_INF_NEGATIVE)

int s21_abs(int);
long double s21_acos(double);
long double s21_asin(double);
long double s21_atan(double);
long double s21_ceil(double);
long double s21_cos(double);
long double s21_exp(double);
long double s21_fabs(double);
long double s21_floor(double);
long double s21_fmod(double, double);
long double s21_log(double);
long double s21_pow(double, double);
long double s21_sin(double);
long double s21_sqrt(double);
long double s21_tan(double);

#endif
