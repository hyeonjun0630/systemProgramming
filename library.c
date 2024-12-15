#include "library.h"
#include <stdio.h>
#include <stdlib.h>

// ���ڿ� ���� ��� �Լ�
int string_length(const char* str) {
    int length = 0;
    while (*str++) {
        length++;
    }
    return length;
}

// ���� �Լ�
int multiply(int a, int b) {
    return a * b;
}

// ������ �Լ�
float divide(float a, float b) {
    if (b == 0) {
        fprintf(stderr, "Error: Division by zero.\n");
        exit(EXIT_FAILURE);
    }
    return a / b;
}
