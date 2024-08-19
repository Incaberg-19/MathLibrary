#include "../s21_math.h"
#include "s21_math_test.h"

START_TEST(s21_abs_test) {
  ck_assert_int_eq(abs(5), s21_abs(5));
  ck_assert_int_eq(abs(-5), s21_abs(-5));
  ck_assert_int_eq(abs(0), s21_abs(0));
  ck_assert_int_eq(abs(-0), s21_abs(-0));
  ck_assert_int_eq(abs(-100000000), s21_abs(-100000000));
  for (int i = -10000; i < 10000; ++i) ck_assert_int_eq(abs(i), s21_abs(i));
}
END_TEST

Suite* abs_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_abs");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_abs_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_abs_tes() {
  int number_failed;
  Suite* s;
  SRunner* sr;

  s = abs_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  if (number_failed != 0) exit(EXIT_FAILURE);
  return EXIT_SUCCESS;
}

/*int main()
{
    int number_failed;
    Suite* s;
    SRunner* sr;

    s = abs_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}*/