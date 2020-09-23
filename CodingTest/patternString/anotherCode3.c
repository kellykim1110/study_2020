#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int n);

int main() {
    printf("%s\n", solution(3));
    printf("%s\n", solution(4));

    return 0;
}


char* solution(int n) {
    char* answer = (char*)malloc((sizeof(char) * 3) * n + 1);

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // https://www.geeksforgeeks.org/sprintf-in-c/
            // sprintf() 출력과 동시에 변수에 저장
            // sprintf(answer,이 뒤에는 printf와 동일)
            // answer에는 printf시 뽑히는 문자열이 저장됨
            sprintf(answer + i * 3, "수");
        }
        else {
            sprintf(answer + i * 3, "박");
        }
    }

    return answer;
}

