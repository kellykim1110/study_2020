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
    char* answer = (char*)malloc((2*n)+1);
    char su[3] = { "��" };
    //printf("%d\t%s\n", strlen(su),su);
    char bac[3] = { "��" };
    //printf("%d\t%s\n", strlen(bac), bac);
    
   
    // 01 23 45 67 89 1011 ...
    // �� �� �� �� �� �� ...

    // ���� ��ȣ�� 2�� �������� ��
    // 0  1  2  3  4  5  ...
    // �� �� �� �� �� �� ...
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            answer[2 * i] = su[0];
            answer[2 * i + 1] = su[1];
            
        }
        else {
            answer[2 * i] = bac[0];
            answer[2 * i + 1] = bac[1];
        }
    }
    
    answer[2 * n] = '\0';
    return answer;
}