#include <stdio.h>
// 조건문 
// if else switch


int presentation(int classNum);
int rockscissorspaper();

int main() {
	// 5번 안에 숫자를 맞춰라.
	srand(time(NULL));
	int num = rand() % 100 + 1; // 1 ~ 100까지 숫자
	// printf("숫자: %d\n", num);
	int answer; // 정답
	int chance = 5; // 기회
	while (chance > 0) {
		printf("---숫자를 맞춰보세요.---\n\n");
		scanf_s("%d", &answer);
		if (answer > num) {
			printf(" DOWN ↓\n\n");
			printf("남은 기회 %d 번 \n", --chance);
		}
		else if (answer < num) {
			printf("UP ↑\n\n");
			printf("남은 기회 %d 번 \n", --chance);
		}
		else if (answer == num){
			printf("정답입니다!!!\n\n");
			break;
		}
	}
	if (chance == 0) {
		printf("기회를 다 사용하셨습니다. 정답은 %d였습니다.", num);
	}
	// presentation(23);
	// rockscissorspaper();
	return 0;
}



// if else
// break continue

int presentation(int classNum) {
	// 반에서 1-6번까지 발표
	for (int i = 1; i <= classNum; i++) {
		if (i > 6) {
			printf("이번 발표 후 나머지 학생들은 다음시간에 할게요.\n");
			break; // for문 탈출!!
		}
		else {
			printf("%d 번 학생, 발표 시작하세요.\n", i);
		}
	}
	printf("\n\tNext Class...\n\n");
	// 8번은 결석
	// 8번을 제외한 7번부터 13번까지 발표
	for (int i = 1; i <= 34; i++) {
		if (i >= 7 && i < 14) {
			if (i == 8) {
				printf("8번 학생은 결석이네요. 다음 번호로 넘어갈게요.\n");
				continue; // i에서 다음 조건에 만족했을 때 아래로 내려가지 않고 i+1번으로 넘어가서 실행 
			}
			printf("%d 번 학생, 발표 시작하세요.\n", i);
		}
	}
	return 0;
}

// switch case
int rockscissorspaper () {
	// 가위바위보
	srand(time(NULL));
	// 가위 0 바위 1 보 2
	int i = rand() % 3; // 0~2소환
	if (i == 0) {
		printf("가위\n");
	}
	else if(i==1){
		printf("바위\n");
	}
	else {
		printf("보\n");
	}
	// 위의 가위바위보를 switch로 바꾸면
	switch (i) {
	case 0: printf("가위\n"); break;
	case 1: printf("바위\n"); break; 
	case 2: printf("보\n"); break;
	default: printf("몰라요\n"); break;
	}
	return 0;
}