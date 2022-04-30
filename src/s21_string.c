#include "s21_string.h"

// 1 function  ++
void *s21_memchr(const void *str, int c, s21_size_t n) {
    const unsigned char* copy_str;
    copy_str = str;
    s21_size_t index = 0;
    for (; index < n && *(copy_str+index) != c; index++);
    return c == *(copy_str+index) ? (unsigned char*) copy_str + index : S21_NULL;
}

// 2 fuction  ++
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char* copy_str1 = str1;
    const unsigned char* copy_str2 = str2;
    s21_size_t shift = 0;
    for(;shift < n && *(copy_str1 + shift) == *(copy_str2 + shift) && (*(copy_str1 + shift) || *(copy_str2 + shift)) != '\0'; shift++);
    return *(copy_str1 + shift) - *(copy_str2 + shift);
}

// 3 function ++
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    unsigned char* copy_dest = dest;
    const unsigned char* copy_src = src;
    s21_size_t index = 1;
    unsigned char* pointer = copy_dest;

    for (;(*pointer++ = *copy_src++) != '\0' && index < n; index++);
    return copy_dest;    
}

// 6 function  ++
char *s21_strcat(char *dest, const char *src) {
    s21_size_t lendest = s21_strlen(dest);
    s21_size_t shift = 0;

    while ((*(dest + lendest + shift++) = *src++) && (*src != '\0'));
    return dest;
}

// 7 function  ++
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    s21_size_t lendest = s21_strlen(dest);
    s21_size_t shift = 0;
    if (n == 0)
        return dest;
    while ((*(dest + lendest + shift++) = *src++) && (*src != '\0') && n-- && n != 0);
    return dest;
}

// 8 function  ++
char *s21_strchr(const char *str, int c) {
    int index = 0;
    while (str[index] && str[index] != c)
        index++;
    return c == str[index] ? (char*)str + index : S21_NULL;
}


// 9 function  ++
int s21_strcmp(const char* str1, const char* str2) {
    int shift = 0;
    for(; *(str1 + shift) == *(str2 + shift); shift++);
    return *(str1 + shift) - *(str2 + shift);
}

// 10 function ++
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    s21_size_t shift = 0;
    for(;shift < n && *(str1 + shift) == *(str2 + shift) && (*(str1 + shift) || *(str2 + shift)) != '\0'; shift++);
    return *(str1 + shift) - *(str2 + shift);
}

// 11 function  ++
char *s21_strcpy(char *dest, const char *src) {
    char* pointer = dest;
    while ((*pointer++ = *src++) != '\0');
    return dest;
}

// 15 function  ++
s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for(; str[len]; len++);
    return len;
} 

// 17 function  ++
char *s21_strrchr(const char *str, int c) {
    int k;
    int index = 0;
    while (str[index]) {
        if (str[index] == c)
            k = index;
        index++;
    }
    if (str[index] == '\0' && c == '\0')
        return (char*)str + index;
    return c == str[k] ? (char*)str + k : S21_NULL;
}

// 19 function  ++
char *s21_strstr(const char *haystack, const char *needle) {
    const char *temp, *c;
    temp = needle;
    while (*haystack) {
        c = haystack;
        while (*(haystack++) == *(needle++)) {
            if (!(*needle))
                return (char*)c;
            if ( !(*haystack) )
                return S21_NULL;
        }
        needle = temp;
    }
    return S21_NULL;
}

// 20 function  --
char *s21_strtok(char *str, char *delim) {
    static char *last = 0;
    if (str)
        last = str;
    if ((last == 0) || (*last == 0))
        return 0;
    char *c = last;
    while (s21_strchr(delim, *c))
        c++;
    if (*c == 0)
        return 0;
    char *start = c;
    while (*c && (s21_strchr(delim , *c) == 0))
        c++;
    if (*c == 0) {
        last = c;
        return start;
    }
    *c = 0;
    last = c+1;
    return start;
}
