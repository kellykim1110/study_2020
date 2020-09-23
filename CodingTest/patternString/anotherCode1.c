//문자열 관련 내용을 많이 쓰기에 관련 string.h 에 관한 함수 내용
//출처: https://studyc.tistory.com/12 

// 문자열 비교 
//비교 결과 = strcmp(문자열1, 문자열2);

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int n);

int main() {
    printf("%s\n", solution(3));
    printf("%s\n", solution(4));

    return 0;
}

char* solution(int n) {
    char* add1 = "수";
    char* add2 = "박";
    int len = strlen(add1);

    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(n * len);
    for (int i = 0; i < n; i++) {
        // strcpy(문자열을 담을 변수명, 담길 문자열 값);
        // strncpy(문자열을 담을 변수명, 담을 문자열 값, 담을 크기);
        strcpy(&answer[i * len], i % 2 == 0 ? add1 : add2);
    }

    return answer;
}