#include "s21_math.h"
long double s21_cos(double x) {
  long double advanced_x = 0;
  long double sum = 0;
  if (S21_IS_NAN(x)) {
    sum = S21_NAN;
  } else if (S21_IS_INF(x)) {
    sum = -S21_NAN;
  } else {
    advanced_x =
        (long double)x - (2 * S21_PI) * s21_floor_long(x / (2 * S21_PI));
    long double znamenatel = 1.0;
    for (register int i = 0, k = -2; i < 33; i++, k = k + 4) {
      if (i >= 1) {
        znamenatel = znamenatel * i *
                     k;  //получение нового факториала с помощью предыдущего
      }
      sum += s21_pow(-1, i) * s21_pow(advanced_x, 2 * i) /
             znamenatel;  //по формуле Тейлора
    }
  }
  return sum;
}