#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <arabic_to_roman.h>
#include <roman_to_arabic.h>
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1


START_TEST (to_arabic)
{
     int expected [] = {1, 2};
     char * test_value [] = {"I", "II"};
     int actual = roman_to_arabic(test_value[0]);
     ck_assert_msg(actual == expected[0],
                 "convert_roman_to_arabic(%s) expected %d but was %d", test_value[0], expected[0], actual);
     printf("convert_roman_to_arabic(%s) = %d\n", test_value[0], actual); 

     actual = roman_to_arabic(test_value[1]);
     ck_assert_msg(actual == expected[1],
                 "convert_roman_to_arabic(%s) expected %d but was %d", test_value[1], expected[1], actual);
     printf("convert_roman_to_arabic(%s) = %d\n", test_value[1], actual); 
}
END_TEST

START_TEST (to_roman)
{
}
END_TEST

Suite * roman_suite (void)
{
  Suite *s = suite_create ("Roman Numeral Unit Tests");

  TCase *tc_to_roman = tcase_create ("ArabicToRoman");
  tcase_add_test (tc_to_roman, to_roman);
  suite_add_tcase (s, tc_to_roman);

  TCase *tc_to_arabic = tcase_create ("RomanToArabic");
  tcase_add_test (tc_to_arabic, to_arabic);
  suite_add_tcase (s, tc_to_arabic);

  return s;
}

void srunner_set_fork_status (SRunner * sr, enum fork_status fstat);

int main(void)
{
  int number_tests_failed;
  Suite *s = roman_suite ();
  SRunner *sr = srunner_create (s);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all (sr, CK_NORMAL);
  number_tests_failed = srunner_ntests_failed (sr);
  srunner_free (sr);
  return (number_tests_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

