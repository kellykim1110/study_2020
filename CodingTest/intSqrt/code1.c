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
    // n이 양의 정수의 제곱이어야 하므로
    // sqrt(n)이 양의 정수이어야 함
    if ((int)sqrt(n) == sqrt(n)) {
        answer = (sqrt(n) + 1) * (sqrt(n) + 1);
    }
    else {
        answer = -1;
    }
    return answer;
}