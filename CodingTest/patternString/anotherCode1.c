//���ڿ� ���� ������ ���� ���⿡ ���� string.h �� ���� �Լ� ����
//��ó: https://studyc.tistory.com/12 

// ���ڿ� �� 
//�� ��� = strcmp(���ڿ�1, ���ڿ�2);

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
    char* add1 = "��";
    char* add2 = "��";
    int len = strlen(add1);

    // ������ ���� �޸𸮸� ���� �Ҵ����ּ���.
    char* answer = (char*)malloc(n * len);
    for (int i = 0; i < n; i++) {
        // strcpy(���ڿ��� ���� ������, ��� ���ڿ� ��);
        // strncpy(���ڿ��� ���� ������, ���� ���ڿ� ��, ���� ũ��);
        strcpy(&answer[i * len], i % 2 == 0 ? add1 : add2);
    }

    return answer;
}