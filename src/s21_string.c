#include <stdio.h>

// 6
// dest – указатель на массив в который будет добавлена строка.
// src – указатель на массив из которого будет скопирована строка.

char *strcat(char *dest, const char *src) {
  int i = 0;
  int j = 0;
  while (dest[i]) {
    i++;
  }
  while (src[j]) {
    dest[i+j] = src[j];
    j++;
  }
  dest[i+j] = '\0';
  return 0;
}

// 8
// str – указатель на строку, в которой будет осуществляться поиск.
// ch – код искомого символа.
// Функция strchr ищет первое вхождения символа, код которого указан
// в аргументе c, в строке, на которую указывает аргумент str

char *strchr(const char *str, int c) {
  int index = 0;
  while (str[index] != '\0') {
    if (str[index] == c)
      return &str[index];
    index++;
  }
  return NULL;
}

// 9
// Сравнивает строку, на которую указывает str1, со строкой, на которую указывает str2.
int strcmp(const char *str1, const char *str2) {
  int check1 = 0;
  int check2 = 0;
  while (*(str1+check1) && *(str2+check2) && *(str1+check1) == *(str2+check2)) {
    check1++;
    check2++;
  }
  return *(str1+check1) - *(str2+check2);
}

// 11
// Копирует строку, на которую указывает src, в dest.
char *strcpy(char *dest, const char *src) {
  int j = 0;
  while *src[j] != '\0') {
    dest[j] =*src[j];
    j++;
  }
  dest[j] = '\0';
  return 0;
}

// 15
// Вычисляет длину строки str, не включая завершающий нулевой символ.
size_t strlen(const char *str) {
  int check = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    check++;
  }
  return check;
}

// 19
// Находит первое вхождение всей строки needle 
// (не включая завершающий нулевой символ), которая появляется в строке haystack.
// haystack - стог сена, где ищем
// needle - игла
char *strstr(const char *haystack, const char *needle) {
  const char *temp, *c;
  temp = needle;
  while (*haystack) {
    c = haystack;
    while (*(haystack++) == *(needle++)) {
      if (!(*needle)) {
        return (char*)c;
      }
      if ( !(*haystack) ) {
        return NULL;
      }
    }
    needle = temp;
  }
  return NULL;
}

// 20
// Разбивает строку str на ряд токенов, разделенных delim.
char *strtok(char *str, char *delim) {
  static char *last = 0;
  if (str)
    last = str;
  if ((last == 0) || (*last == 0))
    return 0;
  char *c = last;
  while (strchr(delim, *c))
    ++c;
  if ( *c == 0 )
    return 0;
  char *start = c;
  while (*c && (strchr(delim , *c) == 0))
    ++c;
  if (*c == 0) {
    last = c;
    return start;
  }
  *c = 0;
  last = c+1;
  return start;
}

