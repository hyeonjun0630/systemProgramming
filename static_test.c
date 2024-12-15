#include "library.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // 사용자 입력을 통해 소수 판별
    int num;
    printf("Enter a number between 1 and 50: ");
    scanf("%d", &num);

    if (num < 1 || num > 50) {
        printf("Number out of range. Please enter a number between 1 and 50.\n");
    } else if (is_prime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    // 소수 목록 생성 테스트
    int limit = 50;
    int prime_count = 0;
    int *primes = generate_primes(limit, &prime_count);

    if (primes) {
        printf("Primes up to %d: ", limit);
        for (int i = 0; i < prime_count; i++) {
            printf("%d ", primes[i]);
        }
        printf("\n");
        free(primes); // 메모리 해제
    } else {
        printf("Failed to generate primes.\n");
    }

    return 0;
}
