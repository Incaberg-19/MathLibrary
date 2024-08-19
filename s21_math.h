#ifndef S21_MATH_H
#define S21_MATH_H
#define S21_LDBL_MAX 1.18973e+4932L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S21_PI2 1.57079632679L
#define S21_PI \
  3.1415926535897932384626433832795028841971693993751058209749445923078164062862L
#define S21_EPS 1e-7
#define S21_NAN (-(0.0f / 0.0f))
#define S21_IS_NAN(x) (x != x)
#define S21_INF_NEGATIVE (-1.0 / 0.0)
#define S21_INF_POSITIVE (+1.0 / 0.0)
#define S21_IS_INF(x) (x == S21_INF_POSITIVE || x == S21_INF_NEGATIVE)
#define S21_NEGATIVE_ZERO -0.0f
#define S21_E 2.718281828459045235360287471352L
long double s21_log_long(long double x);
long double s21_floor_long(long double x);
long double s21_ceil_long(long double x);
long double s21_exp_long(long double x);
long double s21_fabs_long(long double x);
long double s21_sqrt_long(long double x);
long double s21_sin_long(long double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_pow(double base, double exp);
long double s21_acos(double x);
long double s21_tan(double x);
long double s21_fmod(double x, double y);
long double s21_sqrt(double x);
int s21_check_for_sign_zero(double x);
long double s21_log(double x);
int s21_abs(int x);
typedef union {
  float f;
  struct {
    unsigned int mantisa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } parts;
} float_cast;
#endif