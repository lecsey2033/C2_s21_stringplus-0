#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

typedef unsigned long s21_size_t;

char *s21_strcat(char *dest, const char *src);
int s21_strcmp(const char* str1, const char* str2);
char *s21_strcpy(char *dest, const char *src);
s21_size_t s21_strlen(const char *str); 

#endif  //  SRC_S21_STRING_H_
