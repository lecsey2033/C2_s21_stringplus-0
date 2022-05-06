#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main() {
    char str[70];
    char str1[70];
    char arr = 'J';
    //char* arr1 = "dfgfds";
    unsigned int d = 5294967280;
    int i;

    i = s21_sprintf(str, "ab%c %u cd", arr, d);
    printf("%s\n%d\n", str, i);
    i = sprintf(str1, "ab%c %u cd", arr, d);
    printf("%s\n%d", str1, i);
}



