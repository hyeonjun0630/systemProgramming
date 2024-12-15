#include "library.h"
#include <stdio.h>
#include <stdlib.h>

// ¹®ÀÚ¿­ ±æÀÌ °è»ê ÇÔ¼ö
int string_length(const char* str) {
    int length = 0;
    while (*str++) {
        length++;
    }
    return length;
}

// °ö¼À ÇÔ¼ö
int multiply(int a, int b) {
    return a * b;
}

// ³ª´°¼À ÇÔ¼ö
float divide(float a, float b) {
    if (b == 0) {
        fprintf(stderr, "Error: Division by zero.\n");
        exit(EXIT_FAILURE);
    }
    return a / b;
}
