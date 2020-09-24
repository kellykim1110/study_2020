#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* s) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    char* answer = (char*)malloc(sizeof(char) * strlen(s) + 1);
    bool isOdd = true;

    strcpy(answer, s);

    for (int i = 0; i < strlen(s); ++i) {
        if (answer[i] == ' ') {
            isOdd = true;
            continue;
        }
         // �̷� ������ ��� ���� 
        answer[i] = isOdd ? toupper(answer[i]) : tolower(answer[i]);
        isOdd = !isOdd;
    }
    return answer;
}