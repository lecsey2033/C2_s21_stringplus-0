#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

char *strcat(char *dest, const char *src);
char *strchr(const char *str, int c);
int strcmp(const char *str1, const char *str2);
char *strcpy(char *dest, const char *src);
size_t strlen(const char *str);
char *strstr(const char *haystack, const char *needle);
char *strtok(char *str, char *delim);

#endif  //  SRC_S21_STRING_H_
