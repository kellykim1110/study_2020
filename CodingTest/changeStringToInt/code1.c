#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solution(const char* s);

int main() {
    printf("%d\n", solution("1234"));
    printf("%d\n", solution("+1234"));
    printf("%d\n", solution("-1234"));
}

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int solution(const char* s) {
    int answer = 0;
    int len = strlen(s);
    // ��ȣ�� ������ ��,
    if (s[0] == '-') {
        for (int i = 0; i < (len - 1); i++) {
            // ���ڷ� ���� ������ ���
            // '0'�� 48, '1'�� 49, ... , 'n'�� n+48
            int num = s[len - 1 - i]-48;
            answer -=  num * pow(10.0,(float)i);
        }
    }
    // ��ȣ�� + ��ȣ�� ���� ��
    else if (s[0] == '+') {
        for (int i = 0; i < (len - 1); i++) {
            int num = s[len - 1 - i] - 48;
            answer += num * pow(10, i);
        }
    }
    // ��ȣ�� ���� ���ڷ� �����Ǿ� ���� ��
    else {
        for (int i = 0; i < len; i++) {
            int num = s[len - 1 - i] - 48;
            answer += num * pow(10, i);
        }
    }

    return answer;
}