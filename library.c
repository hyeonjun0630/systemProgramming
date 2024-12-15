#include "library.h"
#include <stdlib.h>
#include <stdbool.h>

// 소수 판별 함수
bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// 범위 내 소수 목록 생성 함수
int* generate_primes(int limit, int* prime_count) {
    if (limit < 2) {
        *prime_count = 0;
        return NULL;
    }

    int* primes = malloc(sizeof(int) * (limit / 2)); // 메모리 할당
    if (!primes) {
        *prime_count = 0;
        return NULL;
    }

    *prime_count = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            primes[*prime_count] = i;
            (*prime_count)++;
        }
    }
    return primes;
}
