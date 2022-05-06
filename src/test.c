#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main() {
    char str[70];
    char arr = 'J';
    int i;

    i = s21_sprintf(str, "ab%c cd", arr);
    printf("%s\n%d\n", str, i);
    i = sprintf(str, "ab%c cd", arr);
    printf("%s\n%d", str, i);
}



