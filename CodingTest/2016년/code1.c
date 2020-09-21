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

    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(3);

    // 매달 마지막 날짜
    int days[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

    // 1월 1일이 금요일
    // 7로 나누었을 때 가지는 요일
    char* day[7] = { "THU","FRI", "SAT", "SUN","MON","TUE","WED" };
    
    // a월 b일 까지의 전체 날짜
    int sum = 0;
    for (int i = 0; i < a - 1; i++) {
        sum += days[i];
    }
    sum += b;

    // 요일은 7개
    int date = sum % 7;
    
    answer = day[date];
    return answer;
}
