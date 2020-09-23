#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int n);

int main() {
    printf("%s\n", solution(3));
    printf("%s\n", solution(4));

    return 0;
}


char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int i;
    char* answer = (char*)malloc((sizeof(char) * n * 3));

    strcpy(answer, "");

    for (i = 0; i < n; i++) {
        if (i % 2 == 0)
            // strcat(수정될 문자열, 수정될 문자열에 더해질 문자열)
            // strcat(s1,s2) == (s1 = s1+s2)
            strcat(answer, "수");
        else
            strcat(answer, "박");
    }

    return answer;
}
