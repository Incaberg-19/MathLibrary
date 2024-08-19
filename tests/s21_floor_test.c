#include "../s21_math.h"
#include "s21_math_test.h"

START_TEST(s21_floor_test) {
  ck_assert_double_nan(s21_floor(-(0.0f / 0.0f)));
  ck_assert_ldouble_eq_tol(floor(0.999999), s21_floor(0.999999), S21_EPS);
  ck_assert_double_infinite(s21_floor(INFINITY));
  ck_assert_double_infinite(s21_floor_long(INFINITY));
  ck_assert_double_nan(s21_floor_long(NAN));
  for (double i = -200; i < 200; i += 0.07)
    ck_assert_ldouble_eq_tol(floor(i), s21_floor(i), S21_EPS);
}
END_TEST

Suite* floor_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_floor");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_floor_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_floor_tes() {
  int number_failed;
  Suite* s;
  SRunner* sr;

  s = floor_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  if (number_failed != 0) exit(EXIT_FAILURE);
  return EXIT_SUCCESS;
}