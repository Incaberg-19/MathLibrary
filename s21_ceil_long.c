#include "s21_math.h"
long double s21_ceil_long(long double x) {
  long double result = 0;
  if (S21_IS_NAN(x)) {
    result = S21_NAN;
  } else if (S21_IS_INF(x)) {
    result = x;
  } else {
    char arrive[100] = {0};
    sprintf(arrive, "%0.Lf", x);  // 0.Lf для того чтобы записывать в
                                  // массив только целую часть
    sscanf(arrive, "%Lf", &result);  // в result записываем содержимое массива
    if (result < x) {
      result++;
    }
    memset(arrive, 0, 100);  //обнуление массива
  }
  return result;
}