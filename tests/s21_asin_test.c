#include "../s21_math.h"
#include "s21_math_test.h"

START_TEST(s21_asin_test) {
  ck_assert_double_nan(s21_asin(50));
  ck_assert_ldouble_eq_tol(asin(-1), s21_asin(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(asin(1), s21_asin(1), S21_EPS);
  ck_assert_ldouble_eq_tol(asin(0), s21_asin(0), S21_EPS);
  ck_assert_ldouble_eq_tol(asin(-0.0), s21_asin(-0.0), S21_EPS);
  ck_assert_double_nan(s21_asin(-50));
  ck_assert_ldouble_eq_tol(asin(0.5), s21_asin(0.5), S21_EPS);
  ck_assert_ldouble_eq_tol(asin(-0.5), s21_asin(-0.5), S21_EPS);
  ck_assert_double_nan(s21_asin(NAN));
  ck_assert_double_nan(s21_asin(INFINITY));
  ck_assert_double_nan(s21_asin(-(0.0f / 0.0f)));
  ck_assert_double_nan(s21_asin(S21_INF_POSITIVE));
  for (double i = -1; i < 1; i += 0.04)
    ck_assert_ldouble_eq_tol(asin(i), s21_asin(i), S21_EPS);
}
END_TEST

Suite* asin_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_asin");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_asin_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_asin_tes() {
  int number_failed;
  Suite* s;
  SRunner* sr;

  s = asin_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  if (number_failed != 0) exit(EXIT_FAILURE);
  return EXIT_SUCCESS;
}