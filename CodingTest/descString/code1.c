#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //const char* s = "Zbcdefg";
    const char* s = "efgZbcd";
    int len = strlen(s);
    printf("efgZbcd\n%d\n", len);
    char* answer = (char*)malloc(sizeof(char) * len);
    
    // 문자열의 길이 = 1
    if (len == 1) {
        answer = s;
    }
    else {
        if (s[0] <= s[1]) {
            answer[0] = s[1];
            answer[1] = s[0];
        }
        else {
            answer[0] = s[0];
            answer[1] = s[1];
        }
        if (len >= 3) {
            for (int i = 2; i < len; i++) { // 새로 넣어질 값
                printf("%c\n", s[i]);
                
                // 새로 넣어진 값이 기존에 정렬된 값보다 작을 때
                if (s[i] <= answer[i - 1]) {
                    printf("새로 넣어진 값이 기존에 정렬된 값보다 작을 때\n");
                    answer[i] = s[i]; // 맨마지막에 넣기
                    printf("%s\n", answer);
                }

                // 최대값보다 클 때
                else if (s[i] >= answer[0]) {
                    printf("최대값보다 클 때\n");
                    for (int j = 0; j < i; j++) {
                        answer[i - j] = answer[i - j - 1];
                    }
                    answer[0] = s[i];
                    printf("%s\n", answer);
                }

                // 중간에 값이 끼어 있을 때
                else {
                    printf("중간에 값이 끼어 있을 때\n");
                    for (int j = 0; j < i-1; j++) {
                        if ((answer[j] >= s[i]) && (answer[j + 1] < s[i])) {
                            printf("%c 다음에 넣기\t%d\n", answer[j],j);
                            for (int k = 0; k <= i-(j + 1); k++) {
                                answer[i - k] = answer[i - k - 1];
                            }
                            printf("%c를 넣어보자\n", s[i]);
                            answer[j + 1] = s[i];
                            break;
                        }
                    }
                    printf("%s\n", answer);
                }
                
            }
        }
    }
    answer[len] = '\0';
    printf("%s\n", answer);
    return 0;
}
