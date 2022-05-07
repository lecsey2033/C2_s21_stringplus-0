#include <check.h>
#include <stdlib.h>
#include <string.h>
#include "s21_string.h"

char string1[15] = "Hello world\0";
char string2[15] = "1234567890";
char string3[0];
char cmp_str1[15] = "HELLO WORLD\0";
char cmp_str2[15] = "0987654321";
char cmp_str3[0];

START_TEST(s21_memchr_test) {
  // сравниваем между собой указатели
  ck_assert_ptr_eq(s21_memchr(string1, 'o', 10), memchr(string1, 'o', 10));
  ck_assert_ptr_eq(s21_memchr(string2, '7', 10), memchr(string2, '7', 10));
  ck_assert_ptr_eq(s21_memchr(string3, '7', 10), memchr(string3, '7', 10));
}
END_TEST

START_TEST(s21_memcmp_test) {
  // сравнивает между собой равен ли числовой результат
  ck_assert_int_eq(s21_memcmp(string1, cmp_str1, 10),
                   memcmp(string1, cmp_str1, 10));
  ck_assert_int_eq(s21_memcmp(string2, cmp_str2, 10),
                   memcmp(string2, cmp_str2, 10));
  ck_assert_int_eq(s21_memcmp(string3, cmp_str3, 10),
                   memcmp(string3, cmp_str3, 10));
}
END_TEST

START_TEST(s21_memcpy_test) {
  char dest1[100] = "Test_1_memcpy ";
  char dest2[100] = "Test_1_memcpy ";
  // сравнивает между собой строки
  s21_memcpy(dest1, string1, 11);
  memcpy(dest2, string1, 11);
  ck_assert_str_eq(dest1, dest2);

  char dest3[100] = "Test_2_memcpy ";
  char dest4[100] = "Test_2_memcpy ";
  s21_memcpy(dest3, string2, 10);
  memcpy(dest4, string2, 10);
  ck_assert_str_eq(dest3, dest4);

  char dest5[100] = "Test_3_memcpy ";
  char dest6[100] = "Test_3_memcpy ";
  char string1_1[10] = "\0";
  s21_memcpy(dest5, string1_1, 2);
  memcpy(dest6, string1_1, 2);
  ck_assert_str_eq(dest5, dest6);
}
END_TEST

START_TEST(s21_memmove_test) {
  char dest1[100] = "Test_1_memmove ";
  char dest2[100] = "Test_1_memmove ";

  s21_memmove(dest1, string1, 11);
  memmove(dest2, string1, 11);
  ck_assert_str_eq(dest1, dest2);

  char dest3[100] = "Test_2_memmove ";
  char dest4[100] = "Test_2_memmove ";
  s21_memmove(dest3, string2, 10);
  memmove(dest4, string2, 10);
  ck_assert_str_eq(dest3, dest4);

  char dest5[100] = "Test_3_memmove ";
  char dest6[100] = "Test_3_memmove ";
  s21_memmove(dest5, string3, 0);
  memmove(dest6, string3, 0);
  ck_assert_str_eq(dest5, dest6);
}
END_TEST

START_TEST(s21_memset_test) {
  ck_assert_str_eq(s21_memset(string1, 'H', 10), memset(string1, 'H', 10));
  ck_assert_str_eq(s21_memset(string2, '7', 10), memset(string2, '7', 10));
  ck_assert_str_eq(s21_memset(cmp_str2, '0', 10), memset(cmp_str2, '0', 10));
}
END_TEST

START_TEST(s21_strcat_test) {
  char dest1[100] = "Test_1_strcat ";
  char dest2[100] = "Test_1_strcat ";

  s21_strcat(dest1, string1);
  strcat(dest2, string1);
  ck_assert_str_eq(dest1, dest2);

  char dest3[100] = "Test_2_strcat ";
  char dest4[100] = "Test_2_strcat ";
  s21_strcat(dest3, string2);
  strcat(dest4, string2);
  ck_assert_str_eq(dest3, dest4);

  char dest5[100] = "Test_3_strcat ";
  char dest6[100] = "Test_3_strcat ";
  s21_strcat(dest5, string3);
  strcat(dest6, string3);
  ck_assert_str_eq(dest5, dest6);
}
END_TEST

START_TEST(s21_strncat_test) {
  char dest1[100] = "Test_1_strncat ";
  char dest2[100] = "Test_1_strncat ";

  s21_strncat(dest1, string1, 5);
  strncat(dest2, string1, 5);
  ck_assert_str_eq(dest1, dest2);

  char dest3[100] = "Test_2_strncat ";
  char dest4[100] = "Test_2_strncat ";
  s21_strncat(dest3, string2, 5);
  strncat(dest4, string2, 5);
  ck_assert_str_eq(dest3, dest4);

  char dest5[100] = "Test_3_strncat ";
  char dest6[100] = "Test_3_strncat ";
  s21_strncat(dest5, string3, 0);
  strncat(dest6, string3, 0);
  ck_assert_str_eq(dest5, dest6);
}
END_TEST

START_TEST(s21_strchr_test) {
  ck_assert_msg(s21_strchr(string1, 'w') == strchr(string1, 'w'),
                "s21_strchr 1");
  ck_assert_msg(s21_strchr(string2, '7') == strchr(string2, '7'),
                "s21_strchr 2");
  ck_assert_msg(s21_strchr(string3, 0) == strchr(string3, 0), "s21_strchr 3");
}
END_TEST

START_TEST(s21_strcmp_test) {
  ck_assert_int_eq(s21_strcmp(string1, cmp_str1), strcmp(string1, cmp_str1));
  ck_assert_int_eq(s21_strcmp(string2, cmp_str2), strcmp(string2, cmp_str2));
  ck_assert_int_eq(s21_strcmp(string3, cmp_str3), strcmp(string3, cmp_str3));
}
END_TEST

START_TEST(s21_strncmp_test) {
  ck_assert_int_eq(s21_strncmp(string1, cmp_str1, 5),
                   strncmp(string1, cmp_str1, 5));
  ck_assert_int_eq(s21_strncmp(string2, cmp_str2, 10),
                   strncmp(string2, cmp_str2, 10));
  ck_assert_int_eq(s21_strncmp(string3, cmp_str3, 0),
                   strncmp(string3, cmp_str3, 0));
}
END_TEST

START_TEST(s21_strcpy_test) {
  char dest1[100] = "Test_1_strcpy ";
  char dest2[100] = "Test_1_strcpy ";
  s21_strcpy(dest1, string1);
  strcpy(dest2, string1);
  ck_assert_str_eq(dest1, dest2);

  char dest3[100] = "Test_2_strcpy ";
  char dest4[100] = "Test_2_strcpy ";
  s21_strcpy(dest3, string2);
  strcpy(dest4, string2);
  ck_assert_str_eq(dest3, dest4);

  char dest5[100] = "Test_3_strcpy ";
  char dest6[100] = "Test_3_strcpy ";
  s21_strcpy(dest5, string3);
  strcpy(dest6, string3);
  ck_assert_str_eq(dest5, dest6);
}
END_TEST

START_TEST(s21_strncpy_test) {
  char dest1[100] = "Test_1_strncpy ";
  char dest2[100] = "Test_1_strncpy ";

  s21_strncpy(dest1, string1, 7);
  strncpy(dest2, string1, 7);
  ck_assert_str_eq(dest1, dest2);

  char dest3[100] = "Test_2_strncpy ";
  char dest4[100] = "Test_2_strncpy ";
  s21_strncpy(dest3, string2, 5);
  strncpy(dest4, string2, 5);
  ck_assert_str_eq(dest3, dest4);

  char dest5[100] = "Test_3_strncpy ";
  char dest6[100] = "Test_3_strncpy ";
  s21_strncpy(dest5, string3, 0);
  strncpy(dest6, string3, 0);
  ck_assert_str_eq(dest5, dest6);
}
END_TEST

START_TEST(s21_strcspn_test) {
  char string_cmp1[10] = "Hello";
  char string_cmp2[4] = "1234";
  ck_assert_int_eq(s21_strcspn(string1, string_cmp1),
                   strcspn(string1, string_cmp1));
  ck_assert_int_eq(s21_strcspn(string2, string_cmp2),
                   strcspn(string2, string_cmp2));
  ck_assert_int_eq(s21_strcspn(string3, cmp_str3), strcspn(string3, cmp_str3));
}
END_TEST

START_TEST(s21_strerror_test) {
  for (int index = -1; index <= 200; index++) {
    ck_assert_str_eq(s21_strerror(index), strerror(index));
  }
}
END_TEST

START_TEST(s21_strlen_test) {
  char string0[5] = "\0";
  ck_assert_int_eq(s21_strlen(string1), strlen(string1));
  ck_assert_int_eq(s21_strlen(string2), strlen(string2));
  ck_assert_int_eq(s21_strlen(string0), strlen(string0));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char str1[] = "abcdefghijklmnop", str2[] = "pksah", str3[] = "";
  ck_assert_msg(s21_strpbrk(string1, str1) == strpbrk(string1, str1),
                "s21_strpbrk 1");
  ck_assert_msg(s21_strpbrk(string1, str2) == strpbrk(string1, str2),
                "s21_strpbrk 2");
  ck_assert_msg(s21_strpbrk(string1, str3) == strpbrk(string1, str3),
                "s21_strpbrk 3");
}
END_TEST

START_TEST(s21_strrchr_test) {
  char str_strrchr[15] = "123123123";
  ck_assert_msg(s21_strrchr(string1, 'l') == strrchr(string1, 'l'),
                "s21_strrchr 1");
  ck_assert_msg(s21_strrchr(str_strrchr, '2') == strrchr(str_strrchr, '2'),
                "s21_strrchr 2");
  ck_assert_msg(s21_strrchr(string3, 0) == strrchr(string3, 0),
                "s21_strrchr 3");
}
END_TEST

START_TEST(s21_strspn_test) {
  char str_strspn1[5] = "elloH";
  char str_strspn2[5] = "210";
  ck_assert_int_eq(s21_strspn(string1, str_strspn1),
                   strspn(string1, str_strspn1));
  ck_assert_int_eq(s21_strspn(string2, str_strspn2),
                   strspn(string2, str_strspn2));
}
END_TEST

START_TEST(s21_strstr_test) {
  char str1[4] = "ell";
  char str2[4] = "345";
  char *result, *result2;

  result = s21_strstr(string1, str1);
  result2 = strstr(string1, str1);
  ck_assert_msg(result == result2, "s21_strstr 1");

  result = s21_strstr(string2, str2);
  result2 = strstr(string2, str2);
  ck_assert_msg(result == result2, "s21_strstr 2");
}
END_TEST

START_TEST(s21_strtok_test) {
  char str1_1[100] = "test1/test2/test3/test4";
  char str1[100] = "test1/test2/test3/test4";
  char delim1[4] = "/";
  char *result, *result2;

  result = s21_strtok(str1_1, delim1);
  result2 = strtok(str1, delim1);
  ck_assert_str_eq(result, result2);

  char str2_1[100] = "Aleksey - Ramil - Dima - Semen - Dylara";
  char str2[100] = "Aleksey - Ramil - Dima - Semen - Dylara";
  char delim2[10] = " - ";
  char *result3, *result4;

  result3 = s21_strtok(str2_1, delim2);
  result4 = strtok(str2, delim2);
  ck_assert_str_eq(result3, result4);

  char str3_1[100] = "Aleksey - Ramil - Dima - Semen - Dylara";
  char str3[100] = "Aleksey - Ramil - Dima - Semen - Dylara";
  char delim3[10] = " ";
  char *result5, *result6;

  result5 = s21_strtok(str3_1, delim3);
  result6 = strtok(str3, delim3);
  ck_assert_str_eq(result5, result6);
}
END_TEST

START_TEST(s21_to_upper_test) {
  char *temp = s21_to_upper(string1);
  ck_assert_str_eq(temp, cmp_str1);
  temp = s21_to_upper("test");
  ck_assert_str_eq(temp, "TEST");
  temp = s21_to_upper("777test777");
  ck_assert_str_eq(temp, "777TEST777");
  temp = s21_to_upper("!@#$");
  ck_assert_str_eq(temp, "!@#$");
  temp = s21_to_upper(" ");
  ck_assert_str_eq(temp, " ");
  free(temp);
}
END_TEST

START_TEST(s21_to_lower_test) {
  char* temp = s21_to_lower(cmp_str1);
  ck_assert_str_eq(temp, "hello world\0");
  temp = s21_to_lower("TEST");
  ck_assert_str_eq(temp, "test");
  temp = s21_to_lower("777TEST777");
  ck_assert_str_eq(temp, "777test777");
  temp = s21_to_lower("!@#$");
  ck_assert_str_eq(temp, "!@#$");
  temp = s21_to_lower(" ");
  ck_assert_str_eq(temp, " ");
  free(temp);
}
END_TEST

START_TEST(s21_insert_test) {
  char src1[50] = "Hello";
  char str1[50] = ", team!";
  char *temp = s21_insert(src1, str1, 5);
  ck_assert_str_eq(temp, "Hello, team!");

  char src2[50] = "team!";
  char str2[50] = "Dream";
  temp = s21_insert(src2, str2, 0);
  ck_assert_str_eq(temp, "Dreamteam!");

  char src3[50] = "VR";
  char str3[50] = "erte";
  temp = s21_insert(src3, str3, 1);
  ck_assert_str_eq(temp, "VerteR");

  char src4[50] = "";
  char str4[50] = " ";
  temp = s21_insert(src4, str4, 0);
  ck_assert_str_eq(temp, " ");
  free(temp);
}
END_TEST

START_TEST(s21_trim_test) {
    
  char src1[50] = "***Hello***";
  char trim_chars1[50] = "*";
  char *temp = s21_trim(src1, trim_chars1);
  ck_assert_str_eq(temp, "Hello");

  char src2[50] = " Dreamteam! ";
  char trim_chars2[50] = "";
  temp = s21_trim(src2, trim_chars2);
  ck_assert_str_eq(temp, "Dreamteam!");

  char src3[50] = "DELETEtestDELETE";
  char trim_chars3[50] = "DELETE";
  temp = s21_trim(src3, trim_chars3);
  ck_assert_str_eq(temp, "test");

  // char src3[50] = "";
  // char trim_chars3[50] = " ";
  // ck_assert_str_eq(s21_trim(src3, trim_chars3), "test");
  free(temp);
}
END_TEST

int main() {
  Suite *suite = suite_create("s21_suite_tests");
  SRunner *suite_runner = srunner_create(suite);
  // test 1
  TCase *s21_memchrCase = tcase_create("s21_memchrCase");
  suite_add_tcase(suite, s21_memchrCase);
  tcase_add_test(s21_memchrCase, s21_memchr_test);
  // test 2
  TCase *s21_memcmpCase = tcase_create("s21_memcmpCase");
  suite_add_tcase(suite, s21_memcmpCase);
  tcase_add_test(s21_memcmpCase, s21_memcmp_test);
  // test 3
  TCase *s21_memcpyCase = tcase_create("s21_memcpyCase");
  suite_add_tcase(suite, s21_memcpyCase);
  tcase_add_test(s21_memcpyCase, s21_memcpy_test);
  // test 4
  TCase *s21_memmoveCase = tcase_create("s21_memmoveCase");
  suite_add_tcase(suite, s21_memmoveCase);
  tcase_add_test(s21_memmoveCase, s21_memmove_test);
  // test 5
  TCase *s21_memsetCase = tcase_create("s21_memsetCase");
  suite_add_tcase(suite, s21_memsetCase);
  tcase_add_test(s21_memsetCase, s21_memset_test);
  // test 6
  TCase *s21_strcatCase = tcase_create("s21_strcatCase");
  suite_add_tcase(suite, s21_strcatCase);
  tcase_add_test(s21_strcatCase, s21_strcat_test);
  // test 7
  TCase *s21_strncatCase = tcase_create("s21_strncatCase");
  suite_add_tcase(suite, s21_strncatCase);
  tcase_add_test(s21_strncatCase, s21_strncat_test);
  // test 8
  TCase *s21_strchrCase = tcase_create("s21_strchrCase");
  suite_add_tcase(suite, s21_strchrCase);
  tcase_add_test(s21_strchrCase, s21_strchr_test);
  // test 9
  TCase *s21_strcmpCase = tcase_create("s21_strcmpCase");
  suite_add_tcase(suite, s21_strcmpCase);
  tcase_add_test(s21_strcmpCase, s21_strcmp_test);
  // test 10
  TCase *s21_strncmpCase = tcase_create("s21_strncmpCase");
  suite_add_tcase(suite, s21_strncmpCase);
  tcase_add_test(s21_strncmpCase, s21_strncmp_test);
  // test 11
  TCase *s21_strcpyCase = tcase_create("s21_strcpyCase");
  suite_add_tcase(suite, s21_strcpyCase);
  tcase_add_test(s21_strcpyCase, s21_strcpy_test);
  // test 12
  TCase *s21_strncpyCase = tcase_create("s21_strncpyCase");
  suite_add_tcase(suite, s21_strncpyCase);
  tcase_add_test(s21_strncpyCase, s21_strncpy_test);
  // test 13
  TCase *s21_strcspnCase = tcase_create("s21_strcspnCase");
  suite_add_tcase(suite, s21_strcspnCase);
  tcase_add_test(s21_strcspnCase, s21_strcspn_test);
  // test 14
  TCase *s21_strerrorCase = tcase_create("s21_strerrorCase");
  suite_add_tcase(suite, s21_strerrorCase);
  tcase_add_test(s21_strerrorCase, s21_strerror_test);
  // test 15
  TCase *s21_strlenCase = tcase_create("s21_strlenCase");
  suite_add_tcase(suite, s21_strlenCase);
  tcase_add_test(s21_strlenCase, s21_strlen_test);
  // test 16
  TCase *s21_strpbrkCase = tcase_create("s21_strpbrkCase");
  suite_add_tcase(suite, s21_strpbrkCase);
  tcase_add_test(s21_strpbrkCase, s21_strpbrk_test);
  // test 17
  TCase *s21_strrchrCase = tcase_create("s21_strrchrCase");
  suite_add_tcase(suite, s21_strrchrCase);
  tcase_add_test(s21_strrchrCase, s21_strrchr_test);
  // test 18
  TCase *s21_strspnCase = tcase_create("s21_strspnCase");
  suite_add_tcase(suite, s21_strspnCase);
  tcase_add_test(s21_strspnCase, s21_strspn_test);
  // test 19
  TCase *s21_strstrCase = tcase_create("s21_strstrCase");
  suite_add_tcase(suite, s21_strstrCase);
  tcase_add_test(s21_strstrCase, s21_strstr_test);
  // test 20
  TCase *s21_strtokCase = tcase_create("s21_strtokCase");
  suite_add_tcase(suite, s21_strtokCase);
  tcase_add_test(s21_strtokCase, s21_strtok_test);
  // bonus 1
  TCase *s21_to_upperCase = tcase_create("s21_to_upperCase");
  suite_add_tcase(suite, s21_to_upperCase);
  tcase_add_test(s21_to_upperCase, s21_to_upper_test);
  // bonus 2
  TCase *s21_to_lowerCase = tcase_create("s21_to_lowerCase");
  suite_add_tcase(suite, s21_to_lowerCase);
  tcase_add_test(s21_to_lowerCase, s21_to_lower_test);
  // bonus 3
  TCase *s21_insertCase = tcase_create("s21_insertCase");
  suite_add_tcase(suite, s21_insertCase);
  tcase_add_test(s21_insertCase, s21_insert_test);
  // bonus 4
  TCase *s21_trimCase = tcase_create("s21_trimCase");
  suite_add_tcase(suite, s21_trimCase);
  tcase_add_test(s21_trimCase, s21_trim_test);

  // run all tests
  srunner_run_all(suite_runner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return (number_failed == 0) ? 0 : 1;
}

