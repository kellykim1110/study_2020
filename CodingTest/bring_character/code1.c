#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


char* solution(const char* s);

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int main(){
 
    const char* s1 = "abcde";
    const char* s2 = "qwer";
    
    printf("%s\n",solution(s1));
    printf("%s\n", solution(s2));
    return 0;
}

char* solution(const char* s) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    char* answer;
    int len = strlen(s);

    // ���ڿ��� ������ ¦���� ��  ��� �α���
    if (len % 2 == 0) {
        answer = (char*)malloc(2);

        answer[0] = s[(len / 2) - 1];
        answer[1] = s[len / 2];
        answer[2] = '\0';
    }
    // ���ڿ��� ������ Ȧ���� ��, ��� �ѱ���
    else {
        answer = (char*)malloc(1);
        answer[0] = s[len / 2];
        answer[1] = '\0';
    }

    return answer;
}