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
    // ������ ���� �޸𸮸� ���� �Ҵ����ּ���.
    int i;
    char* answer = (char*)malloc((sizeof(char) * n * 3));

    strcpy(answer, "");

    for (i = 0; i < n; i++) {
        if (i % 2 == 0)
            // strcat(������ ���ڿ�, ������ ���ڿ��� ������ ���ڿ�)
            // strcat(s1,s2) == (s1 = s1+s2)
            strcat(answer, "��");
        else
            strcat(answer, "��");
    }

    return answer;
}
