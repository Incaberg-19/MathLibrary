#include "s21_math.h"
long double s21_sqrt(double x) {
  long double y = 1;
  if (x < 0) {
    y = -S21_NAN;
  } else if (x == 0) {
    y = x;
  } else if (x == S21_INF_POSITIVE) {
    y = S21_INF_POSITIVE;
  } else {
    for (int i = 0; i != 100; ++i) {
      y = (y + x / y) / 2;
    }
  }
  return y;
}
