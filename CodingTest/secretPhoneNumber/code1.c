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


// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* phone_number) {
    int len = strlen(phone_number);
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    char* answer = (char*)malloc(sizeof(char) * len);
    strcpy(answer, phone_number);

    for (int i = 0; i < len - 4; i++) {
        answer[i] = '*';
    }

    return answer;
}