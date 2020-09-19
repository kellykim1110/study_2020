#include <stdio.h>
#include <time.h>

// functioin

// void : 아무것도 없다. 자료형으로 쓰임.
// void function(void parameter) void {return output}
/*
함수의 종류
전달값 유무
반환값 유무
*/

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main() {
	/* 
	문이 5개가 있고
	각 문마다 점점 어려운 수식 퀴즈 출제(랜덤)
	맞히면 통과, 틀리면 실패
	*/

	srand(time(NULL));
	int count = 0;
	int answer = -1;
	for (int i = 1; i <= 5; i++) {
		// 숫자 두개 for Question
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		// 문제
		showQuestion(i, num1, num2);
		//정답
		scanf_s("%d", &answer);
		if (answer == -1) {
			printf("프로그램을 종료합니다.\n");
			exit(0); // 프로그램 바로 종료
		}
		else if (answer == num1 * num2) {
			// 성공
			success();
			count++;
		}
		else {
			// 실패
			fail();
		}
	}
	printf("\n\n 당신은 5개의 비밀번호 중 %d개를 맞쳤습니다.\n\n", count);

	return 0;
}

int getRandomNumber(int level) {
	return rand() % (level * 7) + 1;
}

void showQuestion(int level, int num1, int num2) {
	printf("\n\n\n----- %d 번째 비밀번호 -------\n", level);
	printf("\n\t%d X %d = ?\n\n", num1, num2);
	printf("=================================\n");
	printf("\n 비밀번호를 입력하세요 (종료: -1) >> ");
}

void success() {
	printf(" >> 정답입니다.\n");
}

void fail() {
	printf("  >> 틀렸습니다. 아쉽게 됬네요. 다음에 도전하세요.\n");
}
