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
    //최대값
    int max;
    //최소값
    int min;

    if (a <= b) {
        max = b;
        min = a;
    }
    else {
        max = a;
        min = b;
    }

    for (int i = min; i <= max; i++) {
        answer += i;
    }
    return answer;
}