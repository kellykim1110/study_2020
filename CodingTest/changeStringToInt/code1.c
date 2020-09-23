#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solution(const char* s);

int main() {
    printf("%d\n", solution("1234"));
    printf("%d\n", solution("+1234"));
    printf("%d\n", solution("-1234"));
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int len = strlen(s);
    // 부호가 음수일 때,
    if (s[0] == '-') {
        for (int i = 0; i < (len - 1); i++) {
            // 숫자로 써진 문자일 경우
            // '0'은 48, '1'은 49, ... , 'n'은 n+48
            int num = s[len - 1 - i]-48;
            answer -=  num * pow(10.0,(float)i);
        }
    }
    // 부호에 + 기호가 있을 때
    else if (s[0] == '+') {
        for (int i = 0; i < (len - 1); i++) {
            int num = s[len - 1 - i] - 48;
            answer += num * pow(10, i);
        }
    }
    // 부호가 없이 숫자로 구성되어 있을 때
    else {
        for (int i = 0; i < len; i++) {
            int num = s[len - 1 - i] - 48;
            answer += num * pow(10, i);
        }
    }

    return answer;
}