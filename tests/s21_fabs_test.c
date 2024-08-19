#include "../s21_math.h"
#include "s21_math_test.h"

START_TEST(s21_fabs_test) {
  ck_assert_double_eq(fabs(5.0), s21_fabs(5.0));
  ck_assert_double_eq(fabs(-5.0), s21_fabs(-5.0));
  ck_assert_double_eq(fabs(0.0), s21_fabs(0.0));
  ck_assert_double_eq(fabs(-0.0), s21_fabs(-0.0));
  ck_assert_double_eq(fabs(-100000000.0), s21_fabs(-100000000.0));
  ck_assert_double_nan(s21_fabs(NAN));
  ck_assert_double_nan(s21_fabs(-NAN));
  for (double i = -500.0; i < 500; i += 0.04)
    ck_assert_double_eq(fabs(i), s21_fabs(i));
}
END_TEST

Suite* fabs_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_fabs");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_fabs_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_fabs_tes() {
  int number_failed;
  Suite* s;
  SRunner* sr;

  s = fabs_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  if (number_failed != 0) exit(EXIT_FAILURE);
  return EXIT_SUCCESS;
}
