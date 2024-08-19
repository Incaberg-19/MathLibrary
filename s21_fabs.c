#include "s21_math.h"
long double s21_fabs(double x) {
  int sign = 1;
  if (S21_IS_NAN(x)) {
    x = -S21_NAN;
  } else if (x < 0 || s21_check_for_sign_zero(x) == 1) {
    sign = -1;
  }
  return x * sign;
}
