#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main() {
    //char dest[20] = "1235"/*, dest1[3]*/;
    char src[100] = "_ Gor_ shok   __  ";
    char trim_chars[10] = " _";
    //char src1[10] = "123";
    //int c;
    //scanf("%d", &c);
    printf("%s", s21_trim(src, trim_chars));
    //printf("%s\n", strcat(dest, src));
    return 0;
}


