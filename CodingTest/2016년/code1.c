#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


char solution(int a, int b);

int main() {
    int a = 5;
    int b = 24;

    printf("%s", solution(a, b));

    return 0;
}

char solution(int a, int b) {

    // ������ ���� �޸𸮸� ���� �Ҵ����ּ���.
    char* answer = (char*)malloc(3);

    // �Ŵ� ������ ��¥
    int days[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

    // 1�� 1���� �ݿ���
    // 7�� �������� �� ������ ����
    char* day[7] = { "THU","FRI", "SAT", "SUN","MON","TUE","WED" };
    
    // a�� b�� ������ ��ü ��¥
    int sum = 0;
    for (int i = 0; i < a - 1; i++) {
        sum += days[i];
    }
    sum += b;

    // ������ 7��
    int date = sum % 7;
    
    answer = day[date];
    return answer;
}
