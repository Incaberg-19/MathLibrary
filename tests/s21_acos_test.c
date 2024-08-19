#include "../s21_math.h"
#include "s21_math_test.h"

START_TEST(s21_acos_test) {
  ck_assert_double_nan(s21_acos(50));
  ck_assert_ldouble_eq_tol(acos(-1), s21_acos(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(acos(1), s21_acos(1), S21_EPS);
  ck_assert_ldouble_eq_tol(acos(0), s21_acos(0), S21_EPS);
  ck_assert_ldouble_eq_tol(acos(-0), s21_acos(-0), S21_EPS);
  ck_assert_double_nan(s21_acos(-50));
  ck_assert_ldouble_eq_tol(acos(0.5), s21_acos(0.5), S21_EPS);
  ck_assert_ldouble_eq_tol(acos(-0.5), s21_acos(-0.5), S21_EPS);
  ck_assert_double_nan(s21_acos(NAN));
  ck_assert_double_nan(s21_acos(INFINITY));
  ck_assert_double_nan(s21_acos(S21_INF_NEGATIVE));
  for (double i = -1; i < 1; i += 0.04)
    ck_assert_ldouble_eq_tol(acos(i), s21_acos(i), S21_EPS);
}
END_TEST

Suite* acos_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_acos");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_acos_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_acos_tes() {
  int number_failed;
  Suite* s;
  SRunner* sr;

  s = acos_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  if (number_failed != 0) exit(EXIT_FAILURE);
  return EXIT_SUCCESS;
}