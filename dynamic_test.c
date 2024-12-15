#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    void* handle;
    int (*string_length)(const char*);
    int (*multiply)(int, int);
    float (*divide)(float, float);
    char* error;

    // 라이브러리 로드
    handle = dlopen("./libcustom.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    // 함수 로드
    string_length = dlsym(handle, "string_length");
    multiply = dlsym(handle, "multiply");
    divide = dlsym(handle, "divide");

    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

    // 테스트
    printf("Length of 'Dynamic': %d\n", string_length("Dynamic"));
    printf("5 * 9 = %d\n", multiply(5, 9));
    printf("81 / 9 = %.2f\n", divide(81, 9));

    // 라이브러리 언로드
    dlclose(handle);

    return 0;
}
