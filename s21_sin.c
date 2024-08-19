#include "s21_math.h"
long double s21_sin(double x) {
  long double advanced_x = 0;
  long double sum = 0;
  if (S21_IS_NAN(x)) {
    sum = S21_NAN;
  } else if (S21_IS_INF(x)) {
    sum = -S21_NAN;
  } else if (s21_check_for_sign_zero(x) == 1) {
    sum = S21_NEGATIVE_ZERO;
  } else {
    advanced_x =
        (long double)x - (2 * S21_PI) * s21_floor_long(x / (2 * S21_PI));
    long double znamenatel = 1.0;  //идёт как 1! 3! 5! 7! и тд
    for (register int i = 0, k = 0; i < 33; i++, k = k + 2) {
      if (i >= 1) {
        znamenatel =
            znamenatel * k *
            (k + 1);  //получение нового факториала с помощью предыдущего
      }
      sum += s21_pow(-1, i) * s21_pow(advanced_x, 2 * i + 1) /
             znamenatel;  //по формуле Тейлора
    }
  }
  return sum;
}