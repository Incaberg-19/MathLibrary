#include "../s21_math.h"
#include "s21_math_test.h"

START_TEST(s21_log_test) {
  // ck_assert_double_nan(s21_log(50));
  // ck_assert_ldouble_eq_tol(log(-1), s21_log(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(log(1), s21_log(1), S21_EPS);
  ck_assert_double_infinite(s21_log(0));
  ck_assert_double_infinite(s21_log(-0));
  ck_assert_double_nan(s21_log(-50));
  ck_assert_double_nan(s21_log(NAN));
  ck_assert_double_infinite(s21_log(INFINITY));
  ck_assert_double_nan(s21_log(S21_INF_NEGATIVE));
  for (double i = 0.04; i < 200.0; i += 0.07)
    ck_assert_ldouble_eq_tol(log(i), s21_log(i), S21_EPS);
}
END_TEST

Suite* log_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_log");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_log_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_log_tes() {
  int number_failed;
  Suite* s;
  SRunner* sr;

  s = log_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  if (number_failed != 0) exit(EXIT_FAILURE);
  return EXIT_SUCCESS;
}