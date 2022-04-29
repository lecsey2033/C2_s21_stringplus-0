#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main() {
  char dest[20] = "123"/*, dest1[3]*/;
  char src[10] = "12345";
  //char src1[10] = "123";
  printf("%s\n", s21_strcat(dest, src));
  //printf("%s\n", strcat(dest, src));
}
