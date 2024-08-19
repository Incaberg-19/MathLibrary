#include "../s21_math.h"
#include "s21_math_test.h"

START_TEST(s21_tan_test) {
  ck_assert_ldouble_eq_tol(tan(50), s21_tan(50), S21_EPS);
  ck_assert_ldouble_eq_tol(tan(-1), s21_tan(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(tan(1), s21_tan(1), S21_EPS);
  ck_assert_ldouble_eq_tol(tan(0), s21_tan(0), S21_EPS);
  ck_assert_ldouble_eq_tol(tan(-0.0), s21_tan(-0.0), S21_EPS);
  // ck_assert_double_nan(s21_tan(-50));
  ck_assert_ldouble_eq_tol(tan(0.5), s21_tan(0.5), S21_EPS);
  ck_assert_ldouble_eq_tol(tan(-0.5), s21_tan(-0.5), S21_EPS);
  ck_assert_double_nan(s21_tan(-INFINITY));
  // ck_assert_ldouble_eq_tol(tan(INFINITY) - s21_tan(INFINITY), S21_EPS);
  ck_assert_double_nan(s21_tan(-(0.0f / 0.0f)));
  ck_assert_double_eq_tol(tan(0.999999), s21_tan(0.999999), S21_EPS);
  for (double i = -200; i < 500; i += 0.07)
    ck_assert_double_eq_tol(tan(i), s21_tan(i), S21_EPS);
}
END_TEST

Suite* tan_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_tan");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_tan_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_tan_tes() {
  int number_failed;
  Suite* s;
  SRunner* sr;

  s = tan_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  if (number_failed != 0) exit(EXIT_FAILURE);
  return EXIT_SUCCESS;
}