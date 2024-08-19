#include "s21_math.h"
long double s21_tan(double x) {
  long double result = 0;
  if (S21_IS_NAN(x)) {
    result = S21_NAN;
  } else if (S21_IS_INF(x)) {
    result = -S21_NAN;
  } else if (s21_check_for_sign_zero(x) == 1) {
    result = S21_NEGATIVE_ZERO;
  } else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}