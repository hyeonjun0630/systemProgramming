#include "library.h"
#include <stdio.h>

int main() {
    char* str = "Hello, world!";
    int len = string_length(str);
    printf("Length of '%s': %d\n", str, len);

    int product = multiply(6, 7);
    printf("6 * 7 = %d\n", product);

    float quotient = divide(42, 6);
    printf("42 / 6 = %.2f\n", quotient);

    return 0;
}
