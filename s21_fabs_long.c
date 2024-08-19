#include "s21_math.h"
long double s21_fabs_long(long double x) {
  if (x < 0 || s21_check_for_sign_zero(x) == 1) return -x;
  return x;
}