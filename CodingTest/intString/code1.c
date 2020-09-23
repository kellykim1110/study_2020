#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool solution(const char* s);

int main() {
    const char* s = "1234";
    //const char* s = "as2d";
    if (solution(s) == true) {
        printf("true");
    }
    else {
        printf("false");
    }

    return 0;
}


// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
bool solution(const char* s) {
    bool answer = true;
    int len = strlen(s);
    if ((len != 4) && (len != 6)) {
        answer = false;
    }
    else {
        for (int i = 0; i < len; i++) {
            if ((isdigit(s[i]) == false)) {
                answer = false;
            }
        }
    }
    return answer;
}