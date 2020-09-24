// https://dojang.io/mod/page/view.php?id=379

#define _CRT_SECURE_NO_WARNINGS    // strtok 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>    // strtok 함수가 선언된 헤더 파일

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
    // return 값은 malloc 등 동적 할당을 사용해주세요.
    int len = strlen(s);
    char* answer = (char*)malloc(sizeof(char) * len);
    strcpy(answer, "");// 빈 문자열로 만들어 주기

    char* sArr[1000] = { NULL, };    // 크기가 1000인 문자열 포인터 배열을 선언하고 NULL로 초기화
    int i = 0;                     // 문자열 포인터 배열의 인덱스로 사용할 변수

    // 참조: https://blockdmask.tistory.com/382
    char* ptr = strtok(s, " ");   // 공백 문자열을 기준으로 문자열을 자름

    while (ptr != NULL)            // 자른 문자열이 나오지 않을 때까지 반복
    {
        sArr[i] = ptr;             // 문자열을 자른 뒤 메모리 주소를 문자열 포인터 배열에 저장
        i++;                       // 인덱스 증가

        ptr = strtok(NULL, " ");   // 다음 문자열을 잘라서 포인터를 반환
    }

    for (int j = 0; j < i; j++)
    {
        if (sArr[j] != NULL) {           // 문자열 포인터 배열의 요소가 NULL이 아닐 때만
            //printf("%s\n", sArr[j]);   // 문자열 포인터 배열에 인덱스로 접근하여 각 문자열 출력

            int len = strlen(sArr[j]);
            for (int k = 0; k < len; k++) {
                // 참조: https://kkotkkio.tistory.com/16
                // 대문자로 된 짝수번째 글자는 소문자로 변환
                if (sArr[j][k] >= 'A' && sArr[j][k] <= 'Z' && (k % 2 == 1)) {
                    sArr[j][k] += 32;
                }
                // 소문자로 된 홀수번째 글자는 대문자로 변환
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
    // return 값은 malloc 등 동적 할당을 사용해주세요.
    int len = strlen(s);
    printf("%d\n", len);
    char* answer = (char*)malloc(sizeof(char) * len);
    strcpy(answer, s);// answer을 s와 동일하게 변환

    int k = 0; // 각 단어별 인덱스
    for (int j = 0; j < len; j++)
    {
        if (s[j] == ' ') {
            k = 0;
        }
        else {
            // 참조: https://kkotkkio.tistory.com/16
            // 대문자로 된 짝수번째 글자는 소문자로 변환
            if (s[j] >= 'A' && s[j] <= 'Z' && (k % 2 == 1)) {
                answer[j] = s[j] + 32;
            }
            // 소문자로 된 홀수번째 글자는 대문자로 변환
            else if (s[j] >= 'a' && s[j] <= 'z' && (k % 2 == 0)) {
                answer[j] = s[j] - 32;
            }
            // 대문자로 된 홀수번째 글자는 그대로
            else if (s[j] >= 'A' && s[j] <= 'Z' && (k % 2 == 0)) {
                answer[j] = s[j];
            }
            // 소문자로 된 짝수번째 글자는 그대로
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