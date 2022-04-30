#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main() {
  char dest[20] = "1235"/*, dest1[3]*/;
  char src[10] = "12345";
  //char src1[10] = "123";
    s21_size_t n;
    scanf("%ld", &n);
  printf("%d\n", s21_strncmp(dest, src, n));
  //printf("%s\n", strcat(dest, src));
}
