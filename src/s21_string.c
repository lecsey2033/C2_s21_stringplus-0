#include "s21_string.h"
#include <stdarg.h>
#include <stdlib.h>

// 1 function  ++
void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *copy_str;
  copy_str = str;
  s21_size_t index = 0;
  for (; index < n && *(copy_str + index) != c; index++) {
  }
  return c == *(copy_str + index) ? (unsigned char *)copy_str + index
                                  : S21_NULL;
}

// 2 fuction  ++
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *copy_str1 = str1;
  const unsigned char *copy_str2 = str2;
  s21_size_t shift = 0;
  for (; shift < n && *(copy_str1 + shift) == *(copy_str2 + shift) &&
         (*(copy_str1 + shift) || *(copy_str2 + shift)) != '\0';
       shift++) {
  }
  return *(copy_str1 + shift) - *(copy_str2 + shift);
}

// 3 function ++
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *copy_dest = dest;
  const unsigned char *copy_src = src;
  s21_size_t index = 1;
  unsigned char *pointer = copy_dest;

  for (; (*pointer++ = *copy_src++) != '\0' && index < n; index++) {
  }
  return copy_dest;
}

// 4 function ++
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *copy_dest = dest;
  const unsigned char *copy_src = src;
  s21_size_t index = 0;
  unsigned char *pointer = copy_dest;

  int size_arr = 0;
  for (; copy_src[size_arr] != '\0'; size_arr++) {
  }

  unsigned char temp_arr[size_arr];

  for (int i = 0; (temp_arr[i] = *copy_src++) != '\0'; i++) {
  }
  for (; index < n && (*pointer++ = temp_arr[index]) != '\0'; index++) {
  }
  return copy_dest;
}

// 5 function ++
void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *copy_str = str;
  s21_size_t check = 0;

  for (; check < n && *(copy_str + check) != '\0'; check++) {
    *(copy_str + check) = c;
  }
  return copy_str;
}

// 6 function  ++
char *s21_strcat(char *dest, const char *src) {
  s21_size_t lendest = s21_strlen(dest);
  s21_size_t shift = 0;

  while ((*(dest + lendest + shift++) = *src++) && (*src != '\0')) {
  }
  return dest;
}

// 7 function  ++
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t lendest = s21_strlen(dest);
  s21_size_t shift = 0;
  if (n == 0) return dest;
  while ((*(dest + lendest + shift++) = *src++) && (*src != '\0') && n-- &&
         n != 0) {}
  return dest;
}

// 8 function  ++
char *s21_strchr(const char *str, int c) {
  int index = 0;
  while (str[index] && str[index] != c) index++;
  return c == str[index] ? (char*)(str + index) : S21_NULL;
}

// 9 function  ++
int s21_strcmp(const char *str1, const char *str2) {
  int shift = 0;
  //    for(; *(str1 + shift) == *(str2 + shift); shift++);
  for (;
       *(str1 + shift) && *(str2 + shift) && *(str1 + shift) == *(str2 + shift);
       shift++) {
  }
  return *(str1 + shift) - *(str2 + shift);
}

// 10 function ++
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t shift = 0;
  for (; shift < n && *(str1 + shift) == *(str2 + shift) &&
         (*(str1 + shift) || *(str2 + shift)) != '\0';
       shift++) {
  }
  return *(str1 + shift) - *(str2 + shift);
}

// 11 function  ++
char *s21_strcpy(char *dest, const char *src) {
  char *pointer = dest;

  while ((*pointer++ = *src++) != '\0') {
  }
  return dest;
}

// 12 function  ++
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t check = 0;

  for (; check < n && *(src + check) != '\0'; check++) {
    *(dest + check) = *(src + check);
  }
  for (; check < n; check++) {
    *(dest + check) = '\0';
  }
  return dest;
}

// 13 function ++
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;

  for (; s21_strchr(str2, *(str1 + len)) == S21_NULL; len++) {
  }
  return len;
}

// 14 function ++
char *s21_strerror(int errnum) {
  char *arrerror[] = ARRERROR;
  char *resnum = calloc(70, sizeof(char));
  int max_errnum;

  if (arrerror[0][0] == 'U') {
    max_errnum = 106;
  } else {
    max_errnum = 133;
  }
  if (errnum >= 0 && errnum <= max_errnum) {
    s21_strcpy(resnum, arrerror[errnum]);
  } else {
    char num[15] = {0};
    if (errnum < 0) {
      num[0] = '-';
      errnum *= -1;
    }
    s21_strcpy(resnum, "Unknown error: ");
    int i;
    for (i = 13; errnum != 0; errnum /= 10, i--) {
      num[i] = errnum % 10 + '0';
    }
    if (num[0] == '-') {
      resnum[15] = '-';
    }
    s21_strcat(resnum, num + i + 1);
  }
  return resnum;
}

// 15 function  ++
s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;

  for (; str[len]; len++) {
  }
  return len;
}

// 16 function  ++
char *s21_strpbrk(const char *str1, const char *str2) {
  const char *check = S21_NULL;
  s21_size_t len_arr = s21_strlen(str1);
  s21_size_t len = s21_strcspn(str1, str2);
  if (len != len_arr) {
    check = &str1[len];
  }
  return (char*)check;
}

// 17 function  ++
char *s21_strrchr(const char *str, int c) {
  int k;
  int index = 0;

  while (str[index]) {
    if (str[index] == c) k = index;
    index++;
  }
  if (str[index] == '\0' && c == '\0') return (char*)(str + index);
  return c == str[k] ? (char*)(str + k) : S21_NULL;
}

// 18 function  ++
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t len = 0;

  for (; s21_strchr(str2, *(str1 + len)) != S21_NULL; len++) {
  }
  return len;
}

// 19 function  ++
char *s21_strstr(const char *haystack, const char *needle) {
  const char *temp, *c = S21_NULL;
  temp = needle;
  while (*haystack) {
    c = haystack;
    while (*(haystack++) == *(needle++)) {
      if (!(*needle)) return (char*)c;
      if (!(*haystack)) return S21_NULL;
    }
    needle = temp;
  }
  return S21_NULL;
}

// 20 function  ++

char *s21_strtok(char *str, const char *delim) {
  static char *buffer = S21_NULL;
  char *token = S21_NULL;
  // без данной проверки производится 1 деление текста
  if (str == S21_NULL) {
    str = buffer;
  }
  if (str != S21_NULL && delim != S21_NULL) {
    // index2 чтобы его каждый раз обнулять
    int index1 = 0, index2 = 0;
    while (str[index1] && str[index1] != delim[index2]) {
      index2 += 1;
      if (delim[index2] == '\0') {
        index1 += 1;
        index2 = 0;
      }
    }
    if (str[index1] == '\0') {
      str[index1] = '\0';
      buffer = S21_NULL;
    } else {
      str[index1] = '\0';
      buffer = &str[index1 + 1];
    }
    token = str;
  }
  return token;
}


// 1 bonus
void *s21_to_upper(const char *str) {
    s21_size_t len = s21_strlen(str);
    char *str1;
    str1 = malloc((len + 1) * sizeof(char));
    int i = 0;
    for (; i < (int)len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str1[i] = str[i] - 32;
        else
            str1[i] = str[i];
    }
    str1[i] = '\0';
    return len != 0 ? str1 : S21_NULL;
}

// 2 bonus
void *s21_to_lower(const char *str) {
    int len = s21_strlen(str);
    char *str1;
    str1 = malloc((len + 1) * sizeof(char));
    int i = 0;
    for (; i < (int)len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str1[i] = str[i] + 32;
        else
            str1[i] = str[i];
    }
    str1[i] = '\0';
    return len != 0 ? str1 : S21_NULL;
}

// 3 bonus
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    int oldStrLen = s21_strlen(src);
    int addedStrLen = s21_strlen(str);
    int newStrLen = addedStrLen + oldStrLen;
    char *newStr;
    newStr = malloc((newStrLen + 1) * sizeof(char));
    int index = 0, step = 0;
    for (; index < (int)start_index; index++)
        newStr[index] = src[index];
    for (; step < addedStrLen; step++)
        newStr[index + step] = str[step];
    for (; index + step < newStrLen; index++)
        newStr[index + step] = src[index];
    newStr[index + step] = '\0';
    return (newStrLen != 0 && (int)start_index <= oldStrLen) ?
    newStr : S21_NULL;
}

// 4 bonus
void *s21_trim(const char *src, const char *trim_chars) {
    int trimCharsLen;
    if (s21_strlen(trim_chars) == 0) {
        trim_chars = " ";
        trimCharsLen = 1;
    } else {
        trimCharsLen = s21_strlen(trim_chars);
    }
    int oldStrLen = s21_strlen(src);
    int indexBegin = 0, indexEnd = oldStrLen - 1;
    int flagStop = 1;
    while (flagStop == 1) {
        flagStop = 0;
        for (int index = 0; index < trimCharsLen; index++)
            if (trim_chars[index] == src[indexEnd])
                flagStop = 1;
        if (flagStop == 1)
            indexEnd--;
    }
    flagStop = 1;
    while (flagStop == 1) {
        flagStop = 0;
        for (int index = 0; index < trimCharsLen; index++)
            if (trim_chars[index] == src[indexBegin])
                flagStop = 1;
        if (flagStop == 1)
            indexBegin++;
    }
    int index = 0, newStrLen = indexEnd - indexBegin + 1;
    char *newStr;
    newStr = malloc((newStrLen + 1) * sizeof(char));
    for (; index < newStrLen; index++)
        newStr[index] = src[index + indexBegin];
    newStr[index] = '\0';
    return oldStrLen != 0 ? newStr : S21_NULL;
}

// struct SParameters {
//   char flag;
//   int width;
//   int acc;
//   char length;
//   char spec;
// } Parameters;

 int s21_sprintf(char *str, const char *format, ...) {
    char* check = str;
    int d;
    float f;
    char* arr;
    unsigned int u;

    va_list ptr;
    va_start(ptr, format);
    for (const char* c = format; *c; c++) {
      if (*c == '%') {
        ++c;
        if (*c == ' ') {
          c++;
        }
        switch (*c) {
          case 'c': *str++ = va_arg(ptr, int);
                    break;
          case 'd': d = va_arg(ptr, int);
                    itoa(d, str, 10);
                    for (; *str; str++) {
                    }
                    break;
          case 'i': d = va_arg(ptr, int);
                    itoa(d, str, 10);
                    for (; *str; str++) {
                    }
                    break;
          case 'f': f = va_arg(ptr, double);
                    itoa(f, str, 10);
                    for (; *str; str++) {
                    }
                    *str++ = '.';
                    f = 1000000 * (f - (int)f);
                    if (f < 0) {
                        f *= -1;
                    }
                    itoa(f, str, 10);
                    for (; *str; str++) {
                    }
                    break;
          case 's': arr = va_arg(ptr, char*);
                    for (; *arr; arr++, str++) {
                        *str = *arr;
                    }
                    break;
          case 'u': u = va_arg(ptr, unsigned int);
                    itoa_unsigned(u, str, 10);
                    for (; *str; str++) {
                    }
                    break;
          default: break;
        }
      } else {
        *str++ = *c;
      }
    }
     *str = '\0';
    va_end(ptr);

    int num_sym = 0;
    for (; *check; check++, num_sym++) {
    }
    return num_sym;
}

char *itoa(int number, char *destination, int base) {
  int count = 0;
  int ptr = 0;

  if (number < 0) {
      ptr = number;
      number *= -1;
  }
  do {
    int digit = number % base;
    destination[count++] = (digit > 9) ? digit - 10 +'A' : digit + '0';
  } while ((number /= base) != 0);
  if (ptr < 0) {
      destination[count] = '-';
      count++;
  }
  destination[count] = '\0';
  int i;
  for (i = 0; i < count / 2; ++i) {
    char symbol = destination[i];
    destination[i] = destination[count - i - 1];
    destination[count - i - 1] = symbol;
  }
  return destination;
}

char *itoa_unsigned(unsigned int number, char *destination, int base) {
  int count = 0;
  do {
    unsigned int digit = number % base;
    destination[count++] = (digit > 9) ? digit - 10 + 'A' : digit + '0';
  } while ((number /= base) != 0);
  destination[count] = '\0';
  int i;
  for (i = 0; i < count / 2; ++i) {
    char symbol = destination[i];
    destination[i] = destination[count - i - 1];
    destination[count - i - 1] = symbol;
  }
  return destination;
}

// char* set_params(const char *format) {
//     char return_arr[10];
//     switch (*format) {
//         case 'c': return_arr[0] = *format;
//                   break;
//         default: break;
//     }
//     return return_arr;
// }

