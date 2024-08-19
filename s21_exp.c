#include "s21_math.h"
long double s21_exp(double x) {
  long double series = 1;
  if (x < -14.509) {
    series = 0.0f;
  } else {
    long double add_value = 1, i = 1;
    for (; s21_fabs_long(add_value) > 0.000000001L;) {
      add_value *= (long double)x / i;
      i++;
      series += add_value;
      if (series > S21_LDBL_MAX) {
        series = S21_INF_POSITIVE;
        break;
      }
    }
  }
  return series;
}