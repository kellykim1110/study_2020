#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int solution(int n);

int main() {
    printf("%d\n", solution(123));
    printf("%d\n", solution(123456));
    return 0;
}

int solution(int n) {
    int answer = 0;
    printf("answer: %d\n", answer);
    //  100,000,000 이하의 자연수
    for (int i = 1; i < 10; i++) {
        printf("%d\t%d\n", (int)pow(10, i), n - (int)pow(10, i) * (n / (int)pow(10, i)));
        answer += (n - answer - (int)pow(10, i) * (n / (int)pow(10, i)))/ pow(10, i-1);
        printf("answer = %d\n", answer);
        if (n == (n - (int)pow(10, i) * (n / (int)pow(10, i)))) {
            break;
        }
    }
    return answer;
}