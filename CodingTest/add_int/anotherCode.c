#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b);

int main() {
    printf("%lld\n", solution(6, 3));
    printf("%lld\n", solution(4, 9));
    printf("%lld\n", solution(5, 5));

    return 0;
}

long long solution(int a, int b) {
    long long answer = 0;
    
    //a는 무조건 작은 수, b는 무조건 큰수로 바꿔버리기
    if (a > b) {
        int temp = b;
        b = a;
        a = temp;
    }
    for (int i = a; i <= b; i++) {
        answer += i;
    }
    return answer;
}