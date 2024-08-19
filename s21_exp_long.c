#include "s21_math.h"
long double s21_exp_long(long double x) {
  long double series = 1;
  long double add_value = 1, i = 1;
  for (; s21_fabs_long(add_value) > 1.0E-20L;) {
    add_value *= x / i;
    i++;
    series += add_value;
    if (series > S21_LDBL_MAX) {
      series = S21_INF_POSITIVE;
      break;
    }
  }
  return series;
}