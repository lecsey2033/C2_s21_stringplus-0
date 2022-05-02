#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#define S21_NULL ((void*)0)

#include <stdlib.h>

typedef unsigned long s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n); // 1
int s21_memcmp(const void *str1, const void *str2, s21_size_t n); // 2
void *s21_memcpy(void *dest, const void *src, s21_size_t n); // 3
void *s21_memmove(void *dest, const void *src, s21_size_t n); // 4
void *s21_memset(void *str, int c, s21_size_t n); // 5
char *s21_strcat(char *dest, const char *src); // 6
char *s21_strncat(char *dest, const char *src, s21_size_t n); // 7
char *s21_strchr(const char *str, int c); // 8
int s21_strcmp(const char* str1, const char* str2); // 9
int s21_strncmp(const char *str1, const char *str2, s21_size_t n); // 10
char *s21_strcpy(char *dest, const char *src); // 11
char *s21_strncpy(char *dest, const char *src, s21_size_t n); // 12
s21_size_t s21_strcspn(const char *str1, const char *str2); // 13
s21_size_t s21_strlen(const char *str); // 15
char *s21_strpbrk(const char *str1, const char *str2); // 16
char *s21_strrchr(const char *str, int c); // 17
s21_size_t s21_strspn(const char *str1, const char *str2); // 18
char *s21_strstr(const char *haystack, const char *needle); // 19
char *s21_strtok(char *str, char *delim); // 20

void *s21_to_upper(const char *str); // *1
void *s21_to_lower(const char *str); // *2

#endif  //  SRC_S21_STRING_H_
