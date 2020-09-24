#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* phone_number);

int main() {
    printf("%s\n", solution("01033334444"));
    printf("%s\n", solution("0244448888"));
    return 0;
}


// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* phone_number) {
    int len = strlen(phone_number);
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char) * len);
    strcpy(answer, phone_number);

    for (int i = 0; i < len - 4; i++) {
        answer[i] = '*';
    }

    return answer;
}