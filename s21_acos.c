#include "s21_math.h"
long double s21_acos(double x) {
  long double result = 0;
  long double advanced_x = x;
  if (S21_IS_NAN(x) || S21_IS_INF(x)) {
    result = S21_NAN;
  } else if (x == 1) {
    result = 0;
  } else if (x == 0) {
    result = (S21_PI / 2);
  } else if (x == -1) {
    result = S21_PI;
  } else if (advanced_x > 0 && advanced_x < 1) {
    result =
        s21_atan((s21_sqrt_long(1 - (advanced_x * advanced_x)) / advanced_x));
  } else if (advanced_x > -1 && 0 > advanced_x) {
    result =
        S21_PI +
        s21_atan((s21_sqrt_long(1 - (advanced_x * advanced_x)) / advanced_x));
  } else {
    result = S21_NAN;
  }
  return result;
}