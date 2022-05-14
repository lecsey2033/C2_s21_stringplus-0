#include <check.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "s21_string.h"


char string1[15] = "hello world\0";
char string2[15] = "1234567890";
char string3[0];
char cmp_str1[15] = "HELLO WORLD\0";
char cmp_str2[15] = "0987654321";
char cmp_str3[0];

START_TEST(s21_memchr_test) {
  ck_assert_ptr_eq(s21_memchr(string1, 'o', 10), memchr(string1, 'o', 10));
  ck_assert_ptr_eq(s21_memchr(string2, '7', 10), memchr(string2, '7', 10));
  ck_assert_ptr_eq(s21_memchr(string3, '7', 10), memchr(string3, '7', 10));
}
END_TEST

START_TEST(s21_memcmp_test) {
  ck_assert_int_eq(s21_memcmp(string1, cmp_str1, 1),
                   memcmp(string1, cmp_str1, 1));
  ck_assert_int_eq(s21_memcmp(string2, cmp_str2, 10),
                   memcmp(string2, cmp_str2, 10));
  ck_assert_int_eq(s21_memcmp(string3, cmp_str3, 0),
                   memcmp(string3, cmp_str3, 0));
}
END_TEST

START_TEST(s21_memcpy_test) {
  char dest1[100] = "Test_1_memcpy ";
  char dest2[100] = "Test_1_memcpy ";
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
}
END_TEST

START_TEST(s21_strcmp_test) {
  ck_assert_int_eq(s21_strcmp(string1, cmp_str1), strcmp(string1, cmp_str1));
  ck_assert_int_eq(s21_strcmp(string2, cmp_str2), strcmp(string2, cmp_str2));
  ck_assert_int_eq(s21_strcmp(string3, cmp_str3), strcmp(string3, cmp_str3));
  char *str1 = " ";
  char *str2 = "-";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
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
  for (int index = 0; index <= 133; index++) {
    char *tester = s21_strerror(index);
    ck_assert_str_eq(tester, strerror(index));
    free(tester);
  }
}
END_TEST

START_TEST(s21_strlen_test) {
  ck_assert_int_eq(s21_strlen(string1), strlen(string1));
  ck_assert_int_eq(s21_strlen(string2), strlen(string2));
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
}
END_TEST

START_TEST(s21_strspn_test) {
  char str_strspn1[10] = "elloH";
  char str_strspn2[10] = "210";
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
  char *temp;

  temp = s21_to_upper("test");
  ck_assert_str_eq(temp, "TEST");
  free(temp);

  temp = s21_to_upper("777test777");
  ck_assert_str_eq(temp, "777TEST777");
  free(temp);

  temp = s21_to_upper("!@#$");
  ck_assert_str_eq(temp, "!@#$");
  free(temp);

  temp = s21_to_upper(" ");
  ck_assert_str_eq(temp, " ");
  free(temp);
}
END_TEST

START_TEST(s21_to_lower_test) {
  char* temp = s21_to_lower(cmp_str1);
  ck_assert_str_eq(temp, "hello world\0");
  free(temp);

  temp = s21_to_lower("TEST");
  ck_assert_str_eq(temp, "test");
  free(temp);

  temp = s21_to_lower("777TEST777");
  ck_assert_str_eq(temp, "777test777");
  free(temp);

  temp = s21_to_lower("!@#$");
  ck_assert_str_eq(temp, "!@#$");
  free(temp);
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
  free(temp);

  char src2[50] = "team!";
  char str2[50] = "Dream";
  temp = s21_insert(src2, str2, 0);
  ck_assert_str_eq(temp, "Dreamteam!");
  free(temp);

  char src3[50] = "VR";
  char str3[50] = "erte";
  temp = s21_insert(src3, str3, 1);
  ck_assert_str_eq(temp, "VerteR");
  free(temp);

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
  free(temp);

  char src2[50] = " Dreamteam! ";
  char trim_chars2[50] = "";
  temp = s21_trim(src2, trim_chars2);
  ck_assert_str_eq(temp, "Dreamteam!");
  free(temp);

  char src3[50] = "DELETEtestDELETE";
  char trim_chars3[50] = "DELETE";
  temp = s21_trim(src3, trim_chars3);
  ck_assert_str_eq(temp, "test");
  free(temp);
}
END_TEST

START_TEST(s21_sprintf_test) {
  char *str1 = calloc(256, sizeof(char));
  char *str2 = calloc(256, sizeof(char));
  char *format = "xxx %14.3+f";
  double f = -77.123;
  int temp = s21_sprintf(str1, format, f);
  int temp2 = sprintf(str2, format, f);
  ck_assert_int_eq(temp, temp2);
  ck_assert_str_eq(str1, str2);
  free(str1);
  free(str2);

  char *str3 = calloc(256, sizeof(char));
  char *str4 = calloc(256, sizeof(char));
  char *format1 = "xxx %20.8+-ld";
  long f1 = 35;
  int temp3 = s21_sprintf(str3, format1, f1);
  int temp4 = sprintf(str4, format1, f1);
  ck_assert_int_eq(temp3, temp4);
  ck_assert_str_eq(str3, str4);
  free(str3);
  free(str4);

  char *str5 = calloc(256, sizeof(char));
  char *str6 = calloc(256, sizeof(char));
  char *format2 = "xxx %20.8+-u";
  unsigned int f2 = 35;
  int temp5 = s21_sprintf(str5, format2, f2);
  int temp6 = sprintf(str6, format2, f2);
  ck_assert_int_eq(temp5, temp6);
  ck_assert_str_eq(str5, str6);
  free(str5);
  free(str6);

  char *str7 = calloc(256, sizeof(char));
  char *str8 = calloc(256, sizeof(char));
  char *format3 = "xxx %%%d";
  int d = 10;
  int temp7 = s21_sprintf(str7, format3, d);
  int temp8 = sprintf(str8, format3, d);
  ck_assert_int_eq(temp7, temp8);
  ck_assert_str_eq(str7, str8);
  free(str7);
  free(str8);

  char *str9 = calloc(256, sizeof(char));
  char *str10 = calloc(256, sizeof(char));
  char *format4 = "xxx %12.4s";
  char *f3 = "verter is the best";
  int temp9 = s21_sprintf(str9, format4, f3);
  int temp10 = sprintf(str10, format4, f3);
  ck_assert_int_eq(temp9, temp10);
  ck_assert_str_eq(str9, str10);
  free(str9);
  free(str10);

  char *str11 = calloc(256, sizeof(char));
  char *str12 = calloc(256, sizeof(char));
  char *format5 = "xxx%cxxx";
  char f4 = 'v';
  int temp11 = s21_sprintf(str11, format5, f4);
  int temp12 = sprintf(str12, format5, f4);
  ck_assert_int_eq(temp11, temp12);
  ck_assert_str_eq(str11, str12);
  free(str11);
  free(str12);

  char *str13 = calloc(256, sizeof(char));
  char *str14 = calloc(256, sizeof(char));
  char *format6 = "xxx %hi";
  short f5 = 777;
  int temp13 = s21_sprintf(str13, format6, f5);
  int temp14 = sprintf(str14, format6, f5);
  ck_assert_int_eq(temp13, temp14);
  ck_assert_str_eq(str13, str14);
  free(str13);
  free(str14);

  char *str15 = calloc(256, sizeof(char));
  char *str16 = calloc(256, sizeof(char));
  char *format7 = "xxx %20.8+-hu";
  unsigned short f6 = 35;
  int temp15 = s21_sprintf(str15, format7, f6);
  int temp16 = sprintf(str16, format7, f6);
  ck_assert_int_eq(temp15, temp16);
  ck_assert_str_eq(str15, str16);
  free(str15);
  free(str16);

  char *str17 = calloc(256, sizeof(char));
  char *str18 = calloc(256, sizeof(char));
  char *format8 = "xxx %20.8+-lu";
  unsigned long f7 = 35;
  int temp17 = s21_sprintf(str17, format8, f7);
  int temp18 = sprintf(str18, format8, f7);
  ck_assert_int_eq(temp17, temp18);
  ck_assert_str_eq(str17, str18);
  free(str17);
  free(str18);
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
  // s21_sprintf
  TCase *s21_sprintfCase = tcase_create("s21_sprintfCase");
  suite_add_tcase(suite, s21_sprintfCase);
  tcase_add_test(s21_sprintfCase, s21_sprintf_test);

  // run all tests
  srunner_run_all(suite_runner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return (number_failed == 0) ? 0 : 1;
}
