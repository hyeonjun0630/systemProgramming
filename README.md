# Custom Utility Library

## 기능
- 문자열 길이 계산 (`string_length`)
- 곱셈 (`multiply`)
- 나눗셈 (`divide`)

## 빌드 방법
1. 정적 라이브러리
gcc -c library.c -o library.o ar rcs libcustom.a library.o


2. 공유 라이브러리
gcc -fPIC -c library.c -o library.o gcc -shared -o libcustom.so library.o


## 테스트 방법
1. 정적 라이브러리 테스트:
gcc static_test.c -L. -lcustom -o static_test ./static_test


2. 공유 라이브러리 동적 테스트:
gcc dynamic_test.c -ldl -o dynamic_test ./dynamic_test
