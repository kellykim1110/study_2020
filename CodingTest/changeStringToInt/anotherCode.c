#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* s);

int main() {
    printf("%d\n", solution("1234"));
    printf("%d\n", solution("+1234"));
    printf("%d\n", solution("-1234"));
}


// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int solution(const char* s) {
    int answer = atoi(s);
    return answer;
}