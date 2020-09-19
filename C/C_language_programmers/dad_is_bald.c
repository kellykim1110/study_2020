#include <stdio.h>
#include <time.h>

// array
int main() {
	printf("\n\n=====아빠는 대머리=====\n\n");
	int answer; // 사용자 입력값
	int treatment = rand() % 4; //발모제 선택(0~3)

	int cntShowBottle = 0; // 이번 게임에 보여줄 병의 개수
	int prevCntShowBottle = 0; // 앞 게임에 보여준 병의 개수
	// 서로 보여주는 병의 개수를 다르게 하여 정답률 향상(처음에 2개 -> 다음에 3개...)
	
	// 3 번의 발모제 투여 시도
	for (int i = 1; i <= 3; i++) {
		int bottle[4] = { 0,0,0,0 }; // 4개의 병
		do {
			cntShowBottle = rand() % 2 + 2; // 보여줄 병의 개수(2개 or3개)
		} while (cntShowBottle == prevCntShowBottle);

		int isIncluded = 0; //보여줄 병 중에 발모제가 포함되었는지 여부
		printf(" > %d번째 시도", i);

		// 보여줄 병 종류를 선택
		for (int j = 0; j < cntShowBottle; j++) {
			int randBottle = rand() % 4; // 0~3 중 하나

			// 아직 선택되지 않는 병이면, 선택처리
			if (bottle[randBottle] == 0) {
				bottle[randBottle] = 1;
				if (randBottle == treatment) {
					isIncluded = 1;
				}
			}
			// 이미 선택된 병이면, 중복이므로 다시 선택
			else {
				j--;
			}
		}
		// 사용자에게 문제 표시
		for (int k = 0; k < 4; k++) {
			if (bottle[k] == 1) {
				printf(" %d", k + 1);
			}
			}
		printf("물약을 머리에 바릅니다.\n\n");
		if (isIncluded == 1) {
			printf(" >> 성공 ! 머리가 났어요!! \n");
		}
		else {
			printf(" >> 실패 ! 머리가 나지 않아요 ㅠㅠ\n ");
		}
		printf("\n 계속하려면 아무키나 누르세요~~~!!");
		getchar();
	}
	printf("정답은 몇번째 발모제 일까요? ");
	scanf_s("%d", &answer);

	if (answer == treatment + 1) {
		printf("\n >> 정답입니다~\n");
	}
	else {
		printf("\n >> 틀렸습니다, 정답은 %d입니다.\n", treatment + 1);
	}
	return 0;
}



/*
배열 값 설정하기

	int arr[] = {1, 2};
	arr[2] = {1, 2};와 같다.

	값은 반드시 초기화 해야 함
	int arr[<이부분은 변수를 이용함이 아닌 직접 상수를 입력>]

	만약
	int arr[10] = {1,2};만 한다면
	arr[10] = {1, 2, 0, 0, 0, 0, 0, 0, 0, 0};와 동일 
*/

/*
문자 vs 문자열

문자일 경우
char c = 'A';
printf("%c\n",c);는 A를 출력

문자열일 경우
char str[6] = "coding";
printf("%s\n",str);는 coding외의 다른 이상한 문자도 뽑힌다.
왜냐하면 문자열 끝에는 "끝"을 의미하는 NULL 문자 '\0'이 포함되어야 함
char str[7] = "coding";
printf("%s\n",str);이어야 coding이 출력

char str[10] = "coding";
printf("%s\n",str);은 coding을 출력
이유는 남은 자리에 '\0'를 삽입하므로 가능 
char arr[10] = c o d i n g \0 _ _ _ 이라 생각하면  된다.

char str[7] = "coding";
printf("%d\n",str); 이면 %d는 정수형을 뽑는 것이므로 각 배열위치의 값인 알파벳이 ASCII 코드 값으로 출력된다(null은 0으로 출력)
	- 아스키코드
	 for(int i = 0; i<128; i++){
		printf("아스키코드 정수 %d: %c \n", i, i);
		// 아스키코드 정수 104 : h
	}
char str[] = "coding";
printf("%s\n",str);  >> coding
printf("%d\n",sizeof(str));  >> 7

char str[] = "코딩";
printf("%s\n",str);  >> 코딩
printf("%d\n",sizeof(str));  >> 5

char 크기 1byte
영어는 1byte  >> 6*1 + 1 = 7  
한글은 2 byte >> 2*2 + 1 = 5
*/

