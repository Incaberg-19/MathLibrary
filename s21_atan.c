#include "s21_math.h"
long double s21_atan(double x) {
  long double result = 0;
  if (S21_IS_NAN(x)) {
    result = x;
  } else if (x == S21_INF_POSITIVE) {
    result = (S21_PI / 2);
  } else if (x == S21_INF_NEGATIVE) {
    result = -(S21_PI / 2);
  } else if (x == 1) {
    result = S21_PI / 4;
  } else if (x == -1) {
    result = -(S21_PI / 4);
  } else if (s21_check_for_sign_zero(x) == 1) {
    result = S21_NEGATIVE_ZERO;
  } else if ((x > 1)) {
    result = S21_PI2 - s21_atan(1 / x);
  } else if (x < -1) {
    result = (-S21_PI2) - s21_atan(1 / x);
  } else if (s21_fabs(x) > 0.999999) {
    if (x > 0) {
      result = S21_PI / 4;
    } else {
      result = -S21_PI / 4;
    }
  } else {
    long double advanced_x = x;
    int counter = 50;
    if (s21_fabs(advanced_x) > 0.999) {
      counter = 700000;
    } else if (s21_fabs(advanced_x) > 0.9799) {
      counter = 10000;
    } else if (s21_fabs(advanced_x) > 0.91) {
      counter = 1000;
    } else if (s21_fabs(advanced_x) > 0.8) {
      counter = 100;
    }
    if (-1 < x && x < 1) {
      for (register int i = 0; i < counter; i++) {
        result += s21_pow(-1, i) * s21_pow(x, 2 * i + 1) / (i * 2 + 1);
      }
    }
  }
  return result;
}