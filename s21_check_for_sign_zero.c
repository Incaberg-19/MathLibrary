#include "s21_math.h"
int s21_check_for_sign_zero(double x) {
  int result = 0;
  float_cast sign_for_negative_zero = {.f = x};
  if (sign_for_negative_zero.parts.sign == 1 && x == 0.0) {
    result = 1;
  }
  return result;
}