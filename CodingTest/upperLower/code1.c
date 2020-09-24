// https://dojang.io/mod/page/view.php?id=379

#define _CRT_SECURE_NO_WARNINGS    // strtok ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>    // strtok �Լ��� ����� ��� ����

char* solution1(const char* s);
char* solution2(const char* s);

int main()
{
    char s1[] = "The Little Women";    
    
    printf("%s\n", solution1(s1));
    printf("%s\n", solution2(s1));

    return 0;

}

char* solution1(const char* s) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���.
    int len = strlen(s);
    char* answer = (char*)malloc(sizeof(char) * len);
    strcpy(answer, "");// �� ���ڿ��� ����� �ֱ�

    char* sArr[1000] = { NULL, };    // ũ�Ⱑ 1000�� ���ڿ� ������ �迭�� �����ϰ� NULL�� �ʱ�ȭ
    int i = 0;                     // ���ڿ� ������ �迭�� �ε����� ����� ����

    // ����: https://blockdmask.tistory.com/382
    char* ptr = strtok(s, " ");   // ���� ���ڿ��� �������� ���ڿ��� �ڸ�

    while (ptr != NULL)            // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
    {
        sArr[i] = ptr;             // ���ڿ��� �ڸ� �� �޸� �ּҸ� ���ڿ� ������ �迭�� ����
        i++;                       // �ε��� ����

        ptr = strtok(NULL, " ");   // ���� ���ڿ��� �߶� �����͸� ��ȯ
    }

    for (int j = 0; j < i; j++)
    {
        if (sArr[j] != NULL) {           // ���ڿ� ������ �迭�� ��Ұ� NULL�� �ƴ� ����
            //printf("%s\n", sArr[j]);   // ���ڿ� ������ �迭�� �ε����� �����Ͽ� �� ���ڿ� ���

            int len = strlen(sArr[j]);
            for (int k = 0; k < len; k++) {
                // ����: https://kkotkkio.tistory.com/16
                // �빮�ڷ� �� ¦����° ���ڴ� �ҹ��ڷ� ��ȯ
                if (sArr[j][k] >= 'A' && sArr[j][k] <= 'Z' && (k % 2 == 1)) {
                    sArr[j][k] += 32;
                }
                // �ҹ��ڷ� �� Ȧ����° ���ڴ� �빮�ڷ� ��ȯ
                else if (sArr[j][k] >= 'a' && sArr[j][k] <= 'z' && (k % 2 == 0)) {
                    sArr[j][k] -= 32;
                }
                else if (sArr[j][k] >= 'A' && sArr[j][k] <= 'Z' && (k % 2 == 0)) {
                    sArr[j][k] = sArr[j][k];
                }
                else if (sArr[j][k] >= 'a' && sArr[j][k] <= 'z' && (k % 2 == 1)) {
                    sArr[j][k]= sArr[j][k];
                }
            }
            //printf("%s\n", sArr[j]);
            strcat(answer, sArr[j]);
            strcat(answer, " ");

        }
    }
    answer[len] = '\0';
    return answer;
}


char* solution2(const char* s) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���.
    int len = strlen(s);
    printf("%d\n", len);
    char* answer = (char*)malloc(sizeof(char) * len);
    strcpy(answer, s);// answer�� s�� �����ϰ� ��ȯ

    int k = 0; // �� �ܾ �ε���
    for (int j = 0; j < len; j++)
    {
        if (s[j] == ' ') {
            k = 0;
        }
        else {
            // ����: https://kkotkkio.tistory.com/16
            // �빮�ڷ� �� ¦����° ���ڴ� �ҹ��ڷ� ��ȯ
            if (s[j] >= 'A' && s[j] <= 'Z' && (k % 2 == 1)) {
                answer[j] = s[j] + 32;
            }
            // �ҹ��ڷ� �� Ȧ����° ���ڴ� �빮�ڷ� ��ȯ
            else if (s[j] >= 'a' && s[j] <= 'z' && (k % 2 == 0)) {
                answer[j] = s[j] - 32;
            }
            // �빮�ڷ� �� Ȧ����° ���ڴ� �״��
            else if (s[j] >= 'A' && s[j] <= 'Z' && (k % 2 == 0)) {
                answer[j] = s[j];
            }
            // �ҹ��ڷ� �� ¦����° ���ڴ� �״��
            else if (s[j] >= 'a' && s[j] <= 'z' && (k % 2 == 1)) {
                answer[j] = s[j];
            }
            k++;
        }
        printf("%c", answer[j]);
    }
    answer[len] = '\0';
    for (int i = 0; i < len; i++) {
        printf("%c", answer[i]);
    }
    return answer;
}