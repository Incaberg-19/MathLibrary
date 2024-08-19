#include "s21_math.h"
long double s21_fmod(double x, double y) {
  int sign = 1, checking = 0;
  long double result = 0;
  if (S21_IS_INF(x) || y == 0) {
    result = -S21_NAN;
  } else if ((S21_IS_NAN(x)) || (S21_IS_NAN(y)) || (S21_IS_INF(x)) ||
             (y == 0.0)) {
    result = S21_NAN;
  } else if (y == S21_INF_POSITIVE || y == S21_INF_NEGATIVE) {
    result = x;
  } else if (s21_check_for_sign_zero(x) == 1) {
    result = S21_NEGATIVE_ZERO;
  } else if ((s21_fabs(x) == s21_fabs(y)) && x < 0) {
    result = S21_NEGATIVE_ZERO;
  } else {
    if (x < 0.0 && y < 0.0) checking = 1;
    if ((x > 0.0 && y < 0.0) || ((x < y) && x < 0 && y > 0)) {
      result = (long double)x -
               (long double)y * s21_ceil_long((long double)x / (long double)y);
    } else {
      result = (long double)x -
               (long double)y * s21_floor_long((long double)x / (long double)y);
    }
    if ((checking == 1 && result == 0) || (x < 0 && result == 0)) {
      sign = -1;
    }
  }
  return result * sign;
}