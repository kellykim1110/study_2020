#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int* solution(long long n);

int main() {
    printf("%p\n", solution(12345));
    printf("%p\n", solution(1230));
    return 0;
}

int* solution(long long n) {
    // ������ ���� �޸𸮸� ���� �Ҵ����ּ���.
    int* answer = (int*)malloc(sizeof(int) * 11);
    int i = 0;
    while (n) {
        answer[i] = n % 10;
        //printf("%d\n", answer[i]);
        n /= 10;
        i++;
    }
    return answer;
}