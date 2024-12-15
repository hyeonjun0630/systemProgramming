#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdbool.h>

// 소수 판별 함수: 주어진 숫자가 소수인지 확인
bool is_prime(int num);

// 범위 내 소수 목록 생성: 소수를 동적 배열로 반환하고 개수를 prime_count에 저장
int* generate_primes(int limit, int* prime_count);

#endif // LIBRARY_H