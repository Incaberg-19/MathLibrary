#include "../s21_math.h"
#include "s21_math_test.h"

START_TEST(s21_pow_test) {
  ck_assert_ldouble_eq_tol(pow(5, 5), s21_pow(5, 5), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(5, -1), s21_pow(5, -1), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(5, -1.45), s21_pow(5, -1.45), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(0, 5), s21_pow(0, 5), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(-0, 5), s21_pow(-0, 5), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(-0, 0), s21_pow(-0, 0), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(-0, -0), s21_pow(-0, -0), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(0, 0), s21_pow(0, 0), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(0.45, 0), s21_pow(0.45, 0), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(-0.45, 0), s21_pow(-0.45, 0), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(123, 0), s21_pow(123, 0), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(0, 54), s21_pow(0, 54), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(-0.1, -5), s21_pow(-0.1, -5), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(-0.1, 7), s21_pow(-0.1, 7), S21_EPS);
  ck_assert_double_eq(pow(-0.1, 59), s21_pow(-0.1, 59));
  ck_assert_double_eq(pow(0, -5), s21_pow(0, -5));
  ck_assert_double_eq(pow(-0, -1), s21_pow(-0, -1));
  ck_assert_double_eq(pow(-0, 1), s21_pow(-0, 1));
  ck_assert_double_eq(pow(-0, 2), s21_pow(-0, 2));
  ck_assert_double_eq(pow(0, 2), s21_pow(0, 2));
  ck_assert_double_eq(pow(S21_INF_POSITIVE, S21_INF_POSITIVE),
                      s21_pow(S21_INF_POSITIVE, S21_INF_POSITIVE));
  ck_assert_double_eq(pow(S21_INF_POSITIVE, S21_INF_NEGATIVE),
                      s21_pow(S21_INF_POSITIVE, S21_INF_NEGATIVE));
  ck_assert_double_eq(pow(S21_INF_POSITIVE, S21_NEGATIVE_ZERO),
                      s21_pow(S21_INF_POSITIVE, S21_NEGATIVE_ZERO));
  ck_assert_double_eq(pow(S21_INF_NEGATIVE, S21_NEGATIVE_ZERO),
                      s21_pow(S21_INF_NEGATIVE, S21_NEGATIVE_ZERO));
  ck_assert_double_eq(pow(S21_NEGATIVE_ZERO, S21_INF_NEGATIVE),
                      s21_pow(S21_NEGATIVE_ZERO, S21_INF_NEGATIVE));
  ck_assert_double_eq(pow(S21_NEGATIVE_ZERO, S21_INF_POSITIVE),
                      s21_pow(S21_NEGATIVE_ZERO, S21_INF_POSITIVE));
  ck_assert_double_eq(pow(-1, S21_INF_POSITIVE), s21_pow(-1, S21_INF_POSITIVE));
  ck_assert_double_eq(pow(-2, S21_INF_POSITIVE), s21_pow(-2, S21_INF_POSITIVE));
  ck_assert_double_eq(pow(S21_INF_NEGATIVE, S21_INF_POSITIVE),
                      s21_pow(S21_INF_NEGATIVE, S21_INF_POSITIVE));
  ck_assert_double_eq(pow(0, -5), s21_pow(0, -5));
  ck_assert_double_nan(s21_pow(-(0.0f / 0.0f), 4353));
  ck_assert_double_nan(s21_pow(-(0.0f / 0.0f), -4353));
  ck_assert_double_nan(s21_pow(546, -(0.0f / 0.0f)));
  ck_assert_double_nan(s21_pow(-546, -(0.0f / 0.0f)));
  ck_assert_double_nan(s21_pow(0, -(0.0f / 0.0f)));
  ck_assert_double_nan(s21_pow(-0, -(0.0f / 0.0f)));
  ck_assert_double_nan(s21_pow(-2.5, -2.5));
  ck_assert_ldouble_eq_tol(pow(-(0.0f / 0.0f), 0), s21_pow(-(0.0f / 0.0f), 0),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(pow(0, 0), s21_pow(0, 0), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(1, -(0.0f / 0.0f)), s21_pow(1, -(0.0f / 0.0f)),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(pow(-5, -5), s21_pow(-5, -5), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(5, -5), s21_pow(5, -5), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(5.5, 5), s21_pow(5.5, 5), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(5, 5.5), s21_pow(5, 5.5), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(5.5, 5.5), s21_pow(5.5, 5.5), S21_EPS);
  for (double i = 0.1; i < 10; i += 0.4) {
    for (double j = 0.1; j < 10; j += 0.4)
      ck_assert_double_eq_tol(pow(i, j), s21_pow(i, j), S21_EPS * 10);
  }
}
END_TEST

Suite* pow_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_pow");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_pow_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_pow_tes() {
  int number_failed;
  Suite* s;
  SRunner* sr;

  s = pow_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  if (number_failed != 0) exit(EXIT_FAILURE);
  return EXIT_SUCCESS;
}

/*int main()
{
    int number_failed;
    Suite* s;
    SRunner* sr;

    s = pow_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}*/
