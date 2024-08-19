#include "../s21_math.h"
#include "s21_math_test.h"

START_TEST(s21_cos_test) {
  // ck_assert_double_nan(s21_cos(50));
  ck_assert_ldouble_eq_tol(cos(-1), s21_cos(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(cos(1), s21_cos(1), S21_EPS);
  ck_assert_ldouble_eq_tol(cos(0), s21_cos(0), S21_EPS);
  ck_assert_ldouble_eq_tol(cos(-0), s21_cos(-0), S21_EPS);
  // ck_assert_double_nan(s21_cos(-50));
  ck_assert_double_nan(s21_cos(NAN));
  ck_assert_double_nan(s21_cos(INFINITY));
  ck_assert_double_nan(s21_cos(S21_INF_NEGATIVE));
  for (double i = -200.0; i < 200.0; i += 0.07)
    ck_assert_ldouble_eq_tol(cos(i), s21_cos(i), S21_EPS);
}
END_TEST

Suite* cos_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_cos");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_cos_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_cos_tes() {
  int number_failed;
  Suite* s;
  SRunner* sr;

  s = cos_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  if (number_failed != 0) exit(EXIT_FAILURE);
  return EXIT_SUCCESS;
}