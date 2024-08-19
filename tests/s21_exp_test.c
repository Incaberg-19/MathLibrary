#include "../s21_math.h"
#include "s21_math_test.h"

START_TEST(s21_exp_test) {
  // ck_assert_double_nan(s21_exp(50));
  ck_assert_ldouble_eq_tol(exp(-1), s21_exp(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(1), s21_exp(1), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(0), s21_exp(0), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(-0), s21_exp(-0), S21_EPS);
  // ck_assert_double_nan(s21_exp(-50));
  ck_assert_double_nan(s21_exp(NAN));
  ck_assert_double_infinite(s21_exp(INFINITY));
  ck_assert_double_infinite(s21_exp_long(INFINITY));
  ck_assert_ldouble_eq_tol(exp(S21_INF_NEGATIVE), s21_exp(S21_INF_NEGATIVE),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(exp(-0.0), s21_exp(-0.0), S21_EPS);
  for (double i = 0.0; i < 20.0; i += 0.07)
    ck_assert_ldouble_eq_tol(exp(i), s21_exp(i), S21_EPS);
}
END_TEST

Suite* exp_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_exp");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_exp_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_exp_tes() {
  int number_failed;
  Suite* s;
  SRunner* sr;

  s = exp_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  if (number_failed != 0) exit(EXIT_FAILURE);
  return EXIT_SUCCESS;
}