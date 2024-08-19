#include "s21_math.h"
long double s21_log(double x) {
  long double y = 0;  //искомый y
  int ex_pow = 0;
  if (S21_IS_NAN(x)) {
    y = S21_NAN;
  } else if (x < 0) {
    y = S21_NAN;
  } else if (x == 1) {
    y = 0;
  } else if (x == 0) {
    y = S21_INF_NEGATIVE;
  } else if (x == S21_INF_POSITIVE) {
    y = S21_INF_POSITIVE;
  } else {
    long double advanced_x = x;
    double temp_y = 0;
    for (; advanced_x >= S21_E;
         advanced_x /= S21_E, ex_pow++) {  // пока x>=2.7  -> x/2.7
      continue;
    }
    for (int i = 0; i < 100; i++) {
      temp_y = y;
      y = temp_y + 2 * (advanced_x - s21_exp_long(temp_y)) /
                       (advanced_x + s21_exp_long(temp_y));
    }
  }
  return y + ex_pow;
}