#include "s21_string.h"

// 6 function
char *s21_strcat(char *dest, const char *src) {
    s21_size_t lendest = s21_strlen(dest);
    s21_size_t shift = 0;

    while ((*(dest + lendest + shift++) = *src++) && (*src != '\0'));
    return dest;
}

// 9 function
int s21_strcmp(const char* str1, const char* str2) {
    int shift = 0;

    for(; *(str1+shift) == *(str2+shift); shift++);
    return *(str1+shift)-*(str2+shift);
}

// 11 function
char *s21_strcpy(char *dest, const char *src) {
    char* pointer = dest;

    while ((*pointer++ = *src++) != '\0');
    return dest;
}

// 15 function
s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;

    for(; str[len]; len++);
    return len;
} 

