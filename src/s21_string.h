#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#define NULL ((void*)0)

typedef unsigned long s21_size_t;

char *s21_strcat(char *dest, const char *src); // 6
char *s21_strncat(char *dest, const char *src, s21_size_t n); // 7
char *s21_strchr(const char *str, int c); // 8
int s21_strcmp(const char* str1, const char* str2); // 9
int s21_strncmp(const char *str1, const char *str2, s21_size_t n); // 10
char *s21_strcpy(char *dest, const char *src); // 11
s21_size_t s21_strlen(const char *str); //15 
char *s21_strstr(const char *haystack, const char *needle); // 19
char *s21_strtok(char *str, char *delim); // 20

#endif  //  SRC_S21_STRING_H_
