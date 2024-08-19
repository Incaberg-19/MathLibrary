#include "../s21_math.h"
#include "s21_math_test.h"

START_TEST(s21_sqrt_test) {
  ck_assert_ldouble_eq_tol(sqrt(5), s21_sqrt(5), S21_EPS);
  ck_assert_ldouble_eq_tol(sqrt(4), s21_sqrt(4), S21_EPS);
  ck_assert_ldouble_eq_tol(sqrt(81), s21_sqrt(81), S21_EPS);
  ck_assert_ldouble_eq_tol(sqrt(0), s21_sqrt(0), S21_EPS);
  ck_assert_ldouble_eq_tol(sqrt(-0), s21_sqrt(-0), S21_EPS);
  ck_assert_ldouble_eq_tol(sqrt(1.21), s21_sqrt(1.21), S21_EPS);
  ck_assert_double_nan(s21_sqrt(-200));
  ck_assert_ldouble_eq_tol(sqrt(10000000000000), s21_sqrt(10000000000000),
                           S21_EPS);
  ck_assert_double_infinite(s21_sqrt(S21_INF_POSITIVE));
  ck_assert_double_infinite(s21_sqrt_long(INFINITY));
  ck_assert_ldouble_eq_tol(sqrt(0.0), s21_sqrt_long(0.0), S21_EPS);
  ck_assert_double_nan(s21_sqrt_long(-200));

  for (double i = 0.0; i < 500; i += 0.04)
    ck_assert_ldouble_eq_tol(sqrt(i), s21_sqrt(i), S21_EPS);
}
END_TEST

Suite* sqrt_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_sqrt");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_sqrt_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_sqrt_tes() {
  int number_failed;
  Suite* s;
  SRunner* sr;

  s = sqrt_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  if (number_failed != 0) exit(EXIT_FAILURE);
  return EXIT_SUCCESS;
}