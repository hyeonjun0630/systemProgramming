# Prime Utility Library

## **설명**  
이번에 만들게된 라이브러리는 소수와 관련된 두 가지 기능을 가진 라이브러리입니다.
1. **소수 판별 (`is_prime`)**: 입력된 숫자가 소수인지 확인
2. **소수 목록 생성 (`generate_primes`)**: 지정된 범위 내의 모든 소수를 생성하여 반환
---
## **빌드 방법**

### **1. 정적 라이브러리 (`libcustom.a`)**  
1. 소스 코드를 컴파일합니다
   ```bash
   gcc -c library.c -o library.o
   ```
2. 정적 라이브러리를 생성합니다
   ```bash
   ar rcs libcustom.a library.o
   ```

### **2. 공유 라이브러리 (`libcustom.so`)**  
1. 위치 독립 코드(PIC)를 사용하여 소스 코드를 컴파일합니다
   ```bash
   gcc -fPIC -c library.c -o library.o
   ```
2. 공유 라이브러리를 생성합니다
   ```bash
   gcc -shared -o libcustom.so library.o
   ```

---

## **테스트 방법**

### **1. 정적 라이브러리 테스트**
1. 테스트 프로그램을 컴파일합니다
   ```bash
   gcc static_test.c -L. -lcustom -o static_test
   ```
2. 테스트 프로그램을 실행합니다
   ```bash
   ./static_test
   ```
<img width="569" alt="static" src="https://github.com/user-attachments/assets/d9eb3f26-e8d7-4a0e-b39c-bd328fb57a3e" />

### **2. 공유 라이브러리 테스트**
1. 공유 라이브러리 테스트 프로그램을 컴파일합니다
   ```bash
   gcc dynamic_test.c -ldl -o dynamic_test
   ```
2. 테스트 프로그램을 실행합니다
   ```bash
   ./dynamic_test
   ```
<img width="534" alt="dynamic" src="https://github.com/user-attachments/assets/3cfe8c09-afea-43c3-829e-beb85d613eaa" />

---

## **사용 예시**

### **정적 테스트 출력**
`static_test.c` 프로그램의 예제 출력은 다음과 같습니다:  
```plaintext
Enter a number between 1 and 50: 29
29 is a prime number.
Primes up to 50: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
```

### **동적 테스트 출력**
`dynamic_test.c` 프로그램의 예제 출력은 다음과 같습니다:  
```plaintext
Enter a number between 1 and 50: 25
25 is not a prime number.
Primes up to 50: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
```

---

## **라이브러리 함수 설명**

### **1. `bool is_prime(int num)`**
- **설명:** 입력된 숫자가 소수인지 확인합니다.  
- **입력:** 
  - `num`: 소수 여부를 확인할 정수.  
- **출력:** 
  - 소수이면 `true`, 아니면 `false`를 반환합니다.

### **2. `int *generate_primes(int limit, int *prime_count)`**
- **설명:** 지정된 범위 내의 모든 소수를 생성하여 동적 배열로 반환합니다.  
- **입력:**
  - `limit`: 소수를 생성할 범위의 상한값.
  - `prime_count`: 생성된 소수의 개수를 저장할 포인터.  
- **출력:**
  - 동적 배열로 소수 목록을 반환하며, 사용 후 반드시 `free`를 호출하여 메모리를 해제해야 합니다.
---
**이상입니다, 감사합니다!**
