#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(long long n);

int main() {
    printf("%d\n", solution(121));
    printf("%d\n", solution(3));
    return 0;
}

long long solution(long long n) {
    long long answer = 0;
    // n�� ���� ������ �����̾�� �ϹǷ�
    // sqrt(n)�� ���� �����̾�� ��
    if ((int)sqrt(n) == sqrt(n)) {
        answer = (sqrt(n) + 1) * (sqrt(n) + 1);
    }
    else {
        answer = -1;
    }
    return answer;
}