#include "s21_math.h"
long double s21_pow(double base, double exp) {
  long double result = 0;
  int sign = 1;
  if ((base == 0 && exp > 0) || ((size_t)base == 0 && exp == S21_INF_POSITIVE &&
                                 base != S21_INF_POSITIVE)) {
    result = 0;
    if (s21_check_for_sign_zero(base) == 1 && s21_abs(exp) % 2 != 0 &&
        s21_abs(exp) == s21_fabs(exp))
      sign = -1;
  } else if ((S21_IS_NAN(exp) && base == 1) ||
             (S21_IS_INF(exp) && (base == 1 || base == -1)) ||
             (S21_IS_INF(base) && exp == 0)) {
    result = 1;
  } else if ((S21_IS_NAN(exp) && s21_check_for_sign_zero(base) == 1) ||
             (S21_IS_NAN(exp) && base == S21_INF_NEGATIVE) ||
             (S21_IS_NAN(exp))) {
    result = S21_NAN;
  } else if (s21_check_for_sign_zero(base) == 1 && exp == S21_INF_POSITIVE) {
    result = 0;
  } else if ((base == S21_INF_NEGATIVE && exp != S21_INF_NEGATIVE) ||
             (base < 0 && exp == S21_INF_POSITIVE) ||
             (base == S21_INF_POSITIVE && exp == S21_INF_POSITIVE)) {
    result = S21_INF_POSITIVE;
    if (s21_abs(exp) % 2 != 0 && s21_abs(exp) == s21_fabs(exp)) {
      sign = -1;
    }
    if (exp < 0) result = 0;
  } else if (base == S21_INF_NEGATIVE && exp == S21_INF_NEGATIVE) {
    result = 0;
  } else if (exp == 1) {
    result = base;
  } else if (exp == -1) {
    result = (1.0 / base);
  } else if (base == 0 && exp < 0 && s21_check_for_sign_zero(base) != 1) {
    result = S21_INF_POSITIVE;
  } else if (s21_check_for_sign_zero(base) == 1 &&
             s21_check_for_sign_zero(exp) == 0) {
    if (s21_abs(exp) % 2 != 0 && s21_abs(exp) == s21_fabs(exp)) {
      sign = -1;
    }
    if (s21_abs(exp) != exp) {
      result = S21_INF_POSITIVE;
    }
  } else if (base < 0 && exp != s21_floor_long(exp) && !S21_IS_NAN(exp)) {
    result = -S21_NAN;
  } else {
    if (base < 0 && exp < 0) {
      base = s21_fabs_long(base);
      if (s21_abs(exp) % 2 != 0) {
        sign = -1;
      }
    }
    long long floor_exp = s21_abs(s21_ceil(exp)),
              tmp = floor_exp;  //достаём только целую часть степени
    result = 1.0;
    int binaryNumber[256] = {0},
        count_binary_num = 0;  // буфер для ноликов и единичек
    while (tmp > 0) {          // бинарный метод
      binaryNumber[count_binary_num++] += (tmp % 2);
      tmp /= 2;
    }
    while (--count_binary_num >= 0) {  // возведение в нолики и единички
      if (binaryNumber[count_binary_num]) {
        result *= base;
      }
      if (count_binary_num != 0) {
        result *= result;
      }
    }

    if (s21_fabs(s21_fabs(floor_exp) - s21_fabs(exp)) >
        S21_EPS) {  // если степень не равна целой степени
      long double advanced_x = s21_fabs_long(exp) - floor_exp,
                  result2 = s21_exp_long(advanced_x * s21_log(base));
      (exp < 0) ? result = (1 / (result * result2))
                : (result = result * result2);
    } else if (exp < 0) {
      result = 1 / result;
    }
  }
  return result * sign;
}