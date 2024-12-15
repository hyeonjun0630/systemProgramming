#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dlfcn.h>

int main() {
    void *handle;
    bool (*is_prime)(int);
    int *(*generate_primes)(int, int *);
    char *error;

    // 공유 라이브러리 로드
    handle = dlopen("./libcustom.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    // 함수 로드
    is_prime = dlsym(handle, "is_prime");
    generate_primes = dlsym(handle, "generate_primes");

    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        dlclose(handle);
        exit(EXIT_FAILURE);
    }

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

    // 라이브러리 닫기
    dlclose(handle);
    return 0;
}
