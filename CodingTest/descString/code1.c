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
    
    // ���ڿ��� ���� = 1
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
            for (int i = 2; i < len; i++) { // ���� �־��� ��
                printf("%c\n", s[i]);
                
                // ���� �־��� ���� ������ ���ĵ� ������ ���� ��
                if (s[i] <= answer[i - 1]) {
                    printf("���� �־��� ���� ������ ���ĵ� ������ ���� ��\n");
                    answer[i] = s[i]; // �Ǹ������� �ֱ�
                    printf("%s\n", answer);
                }

                // �ִ밪���� Ŭ ��
                else if (s[i] >= answer[0]) {
                    printf("�ִ밪���� Ŭ ��\n");
                    for (int j = 0; j < i; j++) {
                        answer[i - j] = answer[i - j - 1];
                    }
                    answer[0] = s[i];
                    printf("%s\n", answer);
                }

                // �߰��� ���� ���� ���� ��
                else {
                    printf("�߰��� ���� ���� ���� ��\n");
                    for (int j = 0; j < i-1; j++) {
                        if ((answer[j] >= s[i]) && (answer[j + 1] < s[i])) {
                            printf("%c ������ �ֱ�\t%d\n", answer[j],j);
                            for (int k = 0; k <= i-(j + 1); k++) {
                                answer[i - k] = answer[i - k - 1];
                            }
                            printf("%c�� �־��\n", s[i]);
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
