#include "../s21_math.h"
#include "s21_math_test.h"

START_TEST(s21_atan_test) {
  ck_assert_ldouble_eq_tol(atan(50), s21_atan(50), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(-1), s21_atan(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(1), s21_atan(1), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(0), s21_atan(0), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(-0.0), s21_atan(-0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(0.5), s21_atan(0.5), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(0.9999999), s21_atan(0.9999999), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(-0.9999999), s21_atan(-0.9999999), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(-0.5), s21_atan(-0.5), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(-INFINITY), s21_atan(-INFINITY), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(INFINITY), s21_atan(INFINITY), S21_EPS);
  ck_assert_double_nan(s21_atan(-(0.0f / 0.0f)));
  ck_assert_ldouble_eq_tol(atan(0.999999), s21_atan(0.999999), S21_EPS);
  for (double i = -200; i < 50; i += 5)
    ck_assert_ldouble_eq_tol(atan(i), s21_atan(i), S21_EPS);
  for (double i = -1; i <= 1; i += 0.1)
    ck_assert_ldouble_eq_tol(atan(i), s21_atan(i), S21_EPS);
}
END_TEST

Suite* atan_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_atan");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_atan_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_atan_tes() {
  int number_failed;
  Suite* s;
  SRunner* sr;

  s = atan_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  if (number_failed != 0) exit(EXIT_FAILURE);
  return EXIT_SUCCESS;
}
