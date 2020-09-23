#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int n);

int main() {
    printf("%s\n", solution(3));
    printf("%s\n", solution(4));

    return 0;
}


char* solution(int n) {
    char* answer = (char*)malloc((sizeof(char) * 3) * n + 1);

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // https://www.geeksforgeeks.org/sprintf-in-c/
            // sprintf() ��°� ���ÿ� ������ ����
            // sprintf(answer,�� �ڿ��� printf�� ����)
            // answer���� printf�� ������ ���ڿ��� �����
            sprintf(answer + i * 3, "��");
        }
        else {
            sprintf(answer + i * 3, "��");
        }
    }

    return answer;
}

