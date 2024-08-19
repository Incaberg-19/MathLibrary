#include "s21_math.h"
long double s21_asin(double x) {
  long double result = 0;
  long double advanced_x = x;
  if (S21_IS_NAN(x)) {
    result = x;
  } else if (S21_IS_INF(x)) {
    result = S21_NAN;
  } else if (s21_check_for_sign_zero(x) == 1) {
    result = S21_NEGATIVE_ZERO;
  } else if (x == 1) {
    result = S21_PI / 2;
  } else if (x == -1) {
    result = -(S21_PI / 2);
  } else if (advanced_x > -1 && advanced_x < 1) {
    result =
        s21_atan(advanced_x / (s21_sqrt_long(1 - (advanced_x * advanced_x))));
  } else {
    result = S21_NAN;
  }
  return result;
}