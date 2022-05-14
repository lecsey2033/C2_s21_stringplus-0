#include "s21_string.h"

#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

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
  if (n != 1) {
    for (; shift < n && *(copy_str1 + shift) == *(copy_str2 + shift) &&
          (*(copy_str1 + shift) || *(copy_str2 + shift)) != '\0';
        shift++) {
    }
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
         n != 0) {
  }
  return dest;
}


// 8 function  ++
char *s21_strchr(const char *str, int c) {
  int index = 0;
  while (str[index] && str[index] != c) index++;
  return c == str[index] ? (char *)(str + index) : S21_NULL;
}

// 9 function  ++
int s21_strcmp(const char *str1, const char *str2) {
  int shift = 0;
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

s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for (; str[len]; len++) continue;

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
  return (char *)check;
}

char *s21_strrchr(const char *str, int c) {
    s21_size_t strlen = s21_strlen(str);
    char *res = S21_NULL;

    for (s21_size_t i = 0; i < strlen + 1; i++) {
        if (str[i] == c) {
            res = (char *)&str[i];
        }
    }

    return res;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t str1len = s21_strlen(str1);
    s21_size_t str2len = s21_strlen(str2);
    int is_continue = 0;
    s21_size_t res = 0;

    for (s21_size_t i = 0; i < str1len && is_continue == 0; i++) {
        int inner_res = 0;

        for (s21_size_t j = 0; j < str2len && inner_res == 0; j++) {
            if (str1[i] == str2[j]) {
                inner_res++;
            }
        }

        if (inner_res == 0) {
            is_continue++;
            res--;
        }

        res++;
    }

    return res;
}

// 19 function  ++
char *s21_strstr(const char *haystack, const char *needle) {
  const char *temp, *c = S21_NULL;
  temp = needle;
  while (*haystack) {
    c = haystack;
    while (*(haystack++) == *(needle++)) {
      if (!(*needle)) return (char *)c;
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
  if (str == S21_NULL) {
    str = buffer;
  }
  if (str != S21_NULL && delim != S21_NULL) {
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
  for (; index < (int)start_index; index++) newStr[index] = src[index];
  for (; step < addedStrLen; step++) newStr[index + step] = str[step];
  for (; index + step < newStrLen; index++) newStr[index + step] = src[index];
  newStr[index + step] = '\0';
  return (newStrLen != 0 && (int)start_index <= oldStrLen) ? newStr : S21_NULL;
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
      if (trim_chars[index] == src[indexEnd]) flagStop = 1;
    if (flagStop == 1) indexEnd--;
  }
  flagStop = 1;
  while (flagStop == 1) {
    flagStop = 0;
    for (int index = 0; index < trimCharsLen; index++)
      if (trim_chars[index] == src[indexBegin]) flagStop = 1;
    if (flagStop == 1) indexBegin++;
  }
  int index = 0, newStrLen = indexEnd - indexBegin + 1;
  char *newStr;
  newStr = malloc((newStrLen + 1) * sizeof(char));
  for (; index < newStrLen; index++) newStr[index] = src[index + indexBegin];
  newStr[index] = '\0';
  return oldStrLen != 0 ? newStr : S21_NULL;
}

// sprintf

struct SParameters {
  char flag1;
  char flag2;
  char flag3;
  int width;
  int acc;
  char length;
  char spec;
} Parameters;

void clear_pararms() {
  Parameters.flag1 = '\0';
  Parameters.flag2 = '\0';
  Parameters.flag3 = '\0';
  Parameters.width = -1;
  Parameters.acc = -1;
  Parameters.length = '\0';
  Parameters.spec = '\0';
}

char *s21_itoa(int number, int base) {
  int count = 0;
  int ptr = 0;
  char *destination = calloc(256, sizeof(char));
  if (number < 0) {
    ptr = number;
    number *= -1;
  }
  do {
    int digit = number % base;
    destination[count++] = (digit > 9) ? digit - 10 + 'A' : digit + '0';
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

char *s21_itoa_unsigned(unsigned int number, int base) {
  int count = 0;
  char *destination = calloc(256, sizeof(char));
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

char *dtoa(double _num) {
  char *num = calloc(256, sizeof(char));
  int cel = (int)_num;
  double ost = _num - cel;
  if (Parameters.acc == -1) {
    Parameters.acc = 6;
  }
  char *cel_str = s21_itoa(cel, 10);
  s21_strcat(cel_str, ".");
  char *ost_str = calloc(256, sizeof(char));
  for (int i = 0; i < Parameters.acc; i++) {
    int temp;
    ost = ost * 10;
    temp = ost;
    if (i == Parameters.acc - 1) {
      int round = ost * 10;
      if (round % 10 >= 5) {
        temp++;
      }
    }
    char* s = s21_itoa(temp % 10, 10);
    s21_strcat(ost_str, s);
    free(s);
  }
  s21_strcpy(num, cel_str);
  s21_strcat(num, ost_str);
  free(cel_str);
  free(ost_str);
  return num;
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list arguments;
  va_start(arguments, format);
  int result_length = 0;
  int j = 0;
  for (int i = 0; *(format + i) != '\0'; i++) {
    if (*(format + i) == '%') {
      if (*(format + i + 1) == '%') {
        s21_strncat(str, (format + j), i - j);
        s21_strcat(str, "%");
        int shift = 1;
        if ((s21_size_t)(i + shift) < s21_strlen(format)) {
          i += 1;
          j = i + 1;
        }
      } else {
        clear_pararms();
        s21_strncat(str, (format + j), i - j);
        int error = set_params(format, i, &j);
        if (error == 0) {
          create_string(str, &arguments);
        } else {
          j = s21_strlen(format);
        }
      }
    }
  }
  s21_strncat(str, (format + j), s21_strlen(format) - j);
  va_end(arguments);
  result_length = s21_strlen(str);
  return result_length;
}

void create_string(char *str, va_list *arguments) {
  char *substr;
  switch (Parameters.spec) {
    case 'c':
      substr = create_string_c(arguments);
      s21_strcat(str, substr);
      free(substr);
      break;
    case 'd':
      substr = create_string_d(arguments);
      s21_strcat(str, substr);
      free(substr);
      break;
    case 'i':
      substr = create_string_d(arguments);
      s21_strcat(str, substr);
      free(substr);
      break;
    case 'u':
      substr = create_string_u(arguments);
      s21_strcat(str, substr);
      free(substr);
      break;
    case 'f':
      substr = create_string_f(arguments);
      s21_strcat(str, substr);
      free(substr);
      break;
    case 's':
      substr = create_string_s(arguments);
      s21_strcat(str, substr);
      free(substr);
      break;
  }
}

char *create_string_s(va_list *arguments) {
  char *str;
  char *str1;
  switch (Parameters.length) {
    case 'l': {
      char *result = va_arg(*arguments, char *);
      str1 = acc_s(result);
      break;
    }
    default: {
      char *result = va_arg(*arguments, char *);
      str1 = acc_s(result);
      break;
    }
  }
  str = width_string(str1);
  free(str1);
  return str;
}

char *create_string_f(va_list *arguments) {
  char *str;
  double temp;
  switch (Parameters.length) {
    case 'l': {
      double result = (long)va_arg(*arguments, double);
      temp = result;
      break;
    }
    default: {
      double result = va_arg(*arguments, double);
      temp = result;
      break;
    }
  }
  char *digit = calloc(1, sizeof(char));
  if (temp < 0) {
    s21_strcpy(digit, "-");
    temp = temp * (-1);
  }
  char *numb = dtoa(temp);
  char *str1 = flags_int(numb, digit);
  str = width_string(str1);
  free(numb);
  free(digit);
  free(str1);
  return str;
}

char *create_string_d(va_list *arguments) {
  char *str;
  long temp;
  switch (Parameters.length) {
    case 'l': {
      long result = (long)va_arg(*arguments, int);
      temp = result;
      break;
    }
    case 'h': {
      short result = (short)va_arg(*arguments, int);
      temp = result;
      break;
    }
    default: {
      int result = va_arg(*arguments, int);
      temp = result;
      break;
    }
  }
  char *digit = calloc(2, sizeof(char));
  if (temp < 0) {
    s21_strcpy(digit, "-");
    temp = temp * (-1);
  }
  char *numb = s21_itoa(temp, 10);
  char *str1 = acc_int(numb);
  char *str2 = flags_int(str1, digit);
  str = width_string(str2);
  free(numb);
  free(digit);
  free(str1);
  free(str2);
  return str;
}

char *create_string_u(va_list *arguments) {
  char *str;
  long temp;
  switch (Parameters.length) {
    case 'l': {
      unsigned long result = (unsigned long)va_arg(*arguments, int);
      temp = result;
      break;
    }
    case 'h': {
      unsigned short result = (unsigned short)va_arg(*arguments, int);
      temp = result;
      break;
    }
    default: {
      unsigned int result = (unsigned int)va_arg(*arguments, int);
      temp = result;
      break;
    }
  }
  char *numb = s21_itoa_unsigned(temp, 10);
  char *str1 = acc_int(numb);
  str = width_string(str1);
  free(numb);
  free(str1);
  return str;
}

char *flags_int(char *str, char *digit) {
  char *res = calloc(s21_strlen(str) + 1, sizeof(char));
  if (s21_strncmp(digit, "-", 1) == 0) {
    s21_strcpy(res, "-");
    s21_strcat(res, str);
  } else {
    if (Parameters.flag2 == '+') {
      s21_strcpy(res, "+");
      s21_strcat(res, str);
    } else if (Parameters.flag3 == ' ') {
      s21_strcpy(res, " ");
      s21_strcat(res, str);
    } else {
      s21_strcpy(res, str);
    }
  }
  return res;
}

char *create_string_c(va_list *arguments) {
  char *str;
  char c;
  switch (Parameters.length) {
    case 'l': {
      wchar_t result = va_arg(*arguments, wchar_t);
      c = (char)result;
      break;
    }
    default: {
      c = va_arg(*arguments, int);
      break;
    }
  }
  char *buf = calloc(2, sizeof(char));
  buf[0] = c;
  buf[1] = '\0';
  str = width_string(buf);
  free(buf);
  return str;
}

char *acc_int(char *str) {
  int temp;
  int len = s21_strlen(str);
  if (Parameters.width <= len) {
    temp = len;
  } else {
    temp = Parameters.width;
  }
  char *ptr = calloc(temp, sizeof(char));
  if (Parameters.acc > len) {
    int j = 0;
    for (int i = 0; i < Parameters.acc; i++) {
      if (i < (Parameters.acc - len)) {
        ptr[i] = '0';
      } else {
        ptr[i] = str[j];
        j++;
      }
    }
  } else {
    s21_strcpy(ptr, str);
  }
  return ptr;
}

char *acc_s(char *str) {
  int len = s21_strlen(str);
  char *ptr = calloc(len, sizeof(char));
  if ((Parameters.acc < len) && (Parameters.acc != -1)) {
    s21_strncpy(ptr, str, Parameters.acc);
  } else {
    s21_strcpy(ptr, str);
  }
  return ptr;
}

char *width_string(char *str) {
  int temp;
  int len = s21_strlen(str);
  if (Parameters.width <= len) {
    temp = len;
  } else {
    temp = Parameters.width;
  }
  char *ptr = calloc(temp, sizeof(char));
  if (Parameters.width > len) {
    int j = 0;
    if (Parameters.flag1 == '-') {
      for (int i = 0; i < Parameters.width; i++) {
        if (i < len) {
          ptr[i] = str[j];
          j++;
        } else {
          ptr[i] = ' ';
        }
      }
    } else {
      for (int i = 0; i < Parameters.width; i++) {
        if (i < (Parameters.width - len)) {
          ptr[i] = ' ';
        } else {
          ptr[i] = str[j];
          j++;
        }
      }
    }
  } else {
    s21_strcpy(ptr, str);
  }
  return ptr;
}

int set_params(const char *format, int index, int *j) {
  int error = 0;
  int i = index + 1;
  char *params = calloc(s21_strlen(format), sizeof(char));
  error = get_param_string(format, params, i);
  *j = index + s21_strlen(params) + 2;
  if (error != 1) {
    Parameters.acc = get_acc(params);
    Parameters.width = get_width(params);
    Parameters.length = get_lenght(params);
    get_flag(params);
  }
  free(params);
  return error;
}

int get_param_string(const char *format, char *params, int index) {
  int error = 0;
  s21_size_t b = 0;
  b = s21_strcspn(format + index, "cdeEfgGosuxXpni");
  if (b != s21_strlen(format) - index) {
    Parameters.spec = *s21_strpbrk(format + index, "cdeEfgGosuxXpni");
    s21_strncpy(params, format + index, b);
    s21_strcat(params, "\0");
  } else {
    error = 1;
  }
  return error;
}

void get_flag(char *str) {
  if (s21_strrchr(str, '-') != S21_NULL) {
    Parameters.flag1 = '-';
  }
  if (s21_strrchr(str, '+') != S21_NULL) {
    Parameters.flag2 = '+';
  }
  if (s21_strrchr(str, ' ') != S21_NULL) {
    Parameters.flag3 = ' ';
  }
}

int get_width(char *str) {
  int result = 0;
  char *a = s21_strpbrk(str, "0123456789");
  if (a == S21_NULL) {
    result = -1;
  } else {
    for (int i = 0; *(a + i); i++) {
      int shift;
      if (*(a + i - 1) == '.') {
        shift = s21_strspn(a + i, "0123456789");
        if ((s21_size_t)(i + shift) < s21_strlen(a)) {
          i += shift;
        }
      } else {
        shift = s21_strspn(a + i, "0123456789");
        char *buf = calloc(s21_strlen(str), sizeof(char));
        if (shift > 0) {
          s21_strncpy(buf, a + i, shift);
          result = atoi(buf);
        }
        i += shift;
        free(buf);
      }
    }
  }
  return result;
}

int get_acc(char *str) {
  int result = -1;
  char *buf = calloc(s21_strlen(str), sizeof(char));
  if (s21_strrchr(str, '.')) {
    s21_strncpy(buf, s21_strrchr(str, '.') + 1,
                s21_strspn(s21_strrchr(str, '.') + 1, "0123456789"));
    result = atoi(buf);
  }
  free(buf);
  return result;
}

char get_lenght(char *str) {
  char c = 0;
  char *first = s21_strrchr(str, 'l');
  char *second = s21_strrchr(str, 'h');
  if (first != S21_NULL || second != S21_NULL) {
    if (first > second) {
      c = *first;
    } else {
      c = *second;
    }
  }
  return c;
}
