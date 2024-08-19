#include "../s21_math.h"
#include "s21_math_test.h"

START_TEST(s21_fmod_test) {
  ck_assert_double_nan(s21_fmod(NAN, 5.0));
  ck_assert_double_nan(s21_fmod(INFINITY, 5.0));
  ck_assert_double_nan(s21_fmod(5.0, NAN));
  ck_assert_double_nan(s21_fmod(5.0, 0.0));
  ck_assert_ldouble_eq_tol(fmod(4.25, INFINITY), s21_fmod(4.25, INFINITY),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(fmod(-0.0, 7.5), s21_fmod(-0.0, 7.5), S21_EPS);
  ck_assert_ldouble_eq_tol(fmod(4.25, -4.25), s21_fmod(4.25, -4.25), S21_EPS);
  ck_assert_ldouble_eq_tol(fmod(-4.25, 4.25), s21_fmod(-4.25, 4.25), S21_EPS);
  ck_assert_ldouble_eq_tol(fmod(-4.0, -2.0), s21_fmod(-4.0, -2.0), S21_EPS);
  for (double i = -100; i < 100; i += 0.4) {
    for (double j = -100; j < 100; j += 0.4)
      ck_assert_ldouble_eq_tol(fmod(i, j), s21_fmod(i, j), S21_EPS);
  }
}
END_TEST

Suite* fmod_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_fmod");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_fmod_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_fmod_tes() {
  int number_failed;
  Suite* s;
  SRunner* sr;

  s = fmod_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  if (number_failed != 0) exit(EXIT_FAILURE);
  return EXIT_SUCCESS;
}