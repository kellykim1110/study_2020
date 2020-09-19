#include <stdio.h>
#include <time.h>

// pointer

int level;
int arrayFish[6]; // 물고기 6마리
int * cursor; // cursor를 통해 물고기의 어항 위치에 찾아가 물높이를 변경(증가)시키는 역할

void initData();
void printFishes();
void descreaseWater(long elapsedTime);
int checkFishAlive();

int main() {
	/*
	물고기가 6마리가 있다.
	이들은 어항에 살고 있지만 사막에 있기 때문에 물이 빨리 증발된다.
	시간이 지날수록 물의 증발속도는 빨라진다.
	물이 다 증발하기 전에 어항에 물을 넣어서 물고기를 살려주자.

	단, 20초마다 한번씩 레벨업!!
	*/
	long starttime = 0; // 게임 시작 시간
	long totalElapsedTime = 0; // 총 경과 시간
	long prevElapsedTime = 0; // 직전 경과 시간 (최근에 물을 준 시간 간격)

	int num; // 몇 번 어항에 물을 줄 것인가? // 사용자 입력
	initData();

	cursor = arrayFish;

	starttime = clock();

	while (1) {
		printFishes(); // 현재 물고기의 어항 상태 표시
		// getchar();  // 임시로 사용자 입력 대기
		printf("몇 번 어항에 물을 주시겠어요? ");
		scanf_s("%d", &num);

		// 입력값 체크
		// 입력값이 1~6사이의 숫자가 아닐 때
		if (num < 1 || num > 6) {
			printf("입력값이 잘못되었습니다.\n");
			continue;
		}

		// 총 경과 시간
		totalElapsedTime = (clock() - starttime)/ CLOCKS_PER_SEC; //CLOCKS_PER_SEC초로 바꿔주는 단위
		printf("총 경과 시간: %ld 초 \n", totalElapsedTime);

		// 직전 물 준 시간
		// 총 경과 시간 - 마지막으로 물 준 시간
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("최근 경과 시간: %ld 초 \n", prevElapsedTime);
		
		// 어항의 물이 증발
		descreaseWater(prevElapsedTime);

		// 사용자가 입력한 어항에 물을 준다
		// 1. 어항의 물이 0이면 이미 물고기는 die... -> 물을 주지 않는다.
		if (cursor[num - 1] <= 0) {
			printf("%d 번 물고기는 이미 죽었어요ㅠㅠ  물을 주지 않습니다. \n", num);
		}
		// 2. 어향의 물이 0이 아닌 경우, 물을 준다. 100이 넘지 않는지 체크
		// 현재 어항의 물 + 1 <= 100
		else if (cursor[num - 1] + 1 <= 100) {
			// 물 주기
			printf("%d번 어항에 물을 줍니다.\n\n", num);
			cursor[num - 1] += 1;
		}
		// 레벌업을 할 건지 확인(20초마다 한번씩 레벨업!!)
		if (totalElapsedTime / 20 > level - 1) {
			level++;
			printf("*****축!레벨업!!*****\n\n기존 level.%d에서 level.%d로 레벨 업그레이드\n\n", level-1, level);

			// 최종 레벨: 5
			if (level == 5) {
				printf("\n\n축하합니다. 최종레벨을 달성하였습니다. \n게임을 종료합니다.\n");
				exit(0);
			}
		}
		// 모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0) {
			// 물고기가 모두 사망
			printf("모든 물고기가 DIE.....\n");
			exit(0);
		}
		else {
			// 최소 한마리의 물고기가 생존
			printf("물고기가 아직 살아있어요.\n");
		}
		// 10초 -> 15초 : prevElapsedTime = 5초 
		// -> 25초 : preveElasedTime = 10초 = 25초 - 15초
		// prevElapsedTime = totalElapsedTime - prevElapsedTime이므로
		// 기존의 prevElapsedTime을 prevElapsedTime = totalElapsedTime로 변경해 주어야 함
		prevElapsedTime = totalElapsedTime;

	}

	return 0;
}

void initData() {
	level = 1; //게임 레벨 1~5
	for (int i = 0; i < 6; i++) {
		arrayFish[i] = 100; // 어항의 물높이(0~100)
	}
}

void printFishes() {
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	// %3d번: 6byte차지 
	// %3d: 3byte 차지
	// 번: 2byte 차지
	//  : 1byte 차지
	for (int i = 0; i < 6; i++) {
		printf(" %4d ", arrayFish[i]);
		// " %4d ": 1+4+1 = 6byte차지 
	}
	printf("\n\n");
}

void descreaseWater(long elapsedTime) {
	for (int i = 0; i < 6; i++) {
		arrayFish[i] -= (level * 3 * (int)elapsedTime); //3은 난이도 조절을 위한 값
		if (arrayFish[i] < 0) {
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive() {
	// 어항의 물의 양을 통해 생존 여부 확인
	for (int i = 0; i < 6; i++) {
		if (arrayFish[i] > 0)
			return 1; // True
	}
	return 0; //False
}


/*
포인터 변수는 그 포인터가 가르치는 변수의 값을 직접 바꿀수 있다.

[철수]: 101호
[영희]: 201호
[민수]: 301호

// 각 문 앞에 '암호'가 걸려 있음
// 미션
1. 아파트의 각 집에 방문하여 문에 적힌 암호 확인

int 철수 = 1; // 암호
int 영희 = 2;
int 민수 = 3;

int *mission; // 포인터 변수
mission = &철수;

printf("철수네 주소: %d, 암호: %d \n", &철수, 철수);
printf("영희네 주소: %d, 암호: %d \n", &영희, 영희);

printf("mission이 방문하는 곳 주소: %d, 암호: %d\n", mission, *mission);
// mission = &철수, *mission = 철수

mission = &영희; //포인터 변수 전환
printf("mission이 방문하는 곳 주소: %d, 암호: %d\n", mission, *mission);
// mission = &영희, *mission = 영희

2. 각 암호에 3을 곱해라
mission = &철수;
*mission = *misson * 3;

printf("mission이 방문하는 곳 주소: %d, 암호: %d\n", mission, *mission);
// mission = &철수, *mission = 철수*3

3. mission의 암호에서 2를 빼라
int *spy = mission;

spy = &철수; // spy는 철수의 위치를 의미
*spy = *spy -2; // mission의 암호에서 -2를 한 값
printf("spy가 방문한 곳 주소: %d, 암호 %d\n", spy, *spy);
// spy = &철수, *spy = 철수*3 - 2

mission = &민수;
*mission = *misson * 3;
spy = &민수; // spy는 민수의 위치를 의미
*spy = *spy -2; // mission의 암호에서 -2를 한 값
printf("spy가 방문한 곳 주소: %d, 암호 %d\n", spy, *spy);
// spy = &민수, *spy = 민수*3 - 2

printf("철수네 주소: %d, 암호: %d \n", &철수, 철수);
printf("영희네 주소: %d, 암호: %d \n", &영희, 영희);
printf("민수네 주소: %d, 암호: %d \n", &민수, 민수);
// &name은 기존의 값과 동일
// 철수 = 3*철수 - 2
// 영희 = 3*영희
// 민수 = 3*민수 - 2

*/

/*
// 배열과 포인터의 관계

int arr[3] = {5, 10, 15};
int *ptr = arr;
for (int i = 0; i<3; i++){
	printf("배열 arr[%d] 의 값: %d\n", i, arr[i]);
	printf("포인터 ptr[%d] 의 값: %d\n", i, ptr[i]);
	// arr[i] = ptr[i] = 5 or 10 or 15
}

ptr[0] = 100;
ptr[1] = 200;
ptr[2] = 300;
for (int i = 0; i<3; i++){
	printf("배열 arr[%d] 의 값: %d\n", i, arr[i]);
	printf("포인터 ptr[%d] 의 값: %d\n", i, ptr[i]);
	// arr[i] = ptr[i] = 100 or 200 or 300
}

for (int i = 0; i<3; i++){
	printf("배열 arr[%d] 의 값: %d\n", i, arr[i]);
	printf("포인터 ptr[%d] 의 값: %d\n", i, *(arr + i));
	// arr[i] = *(arr + i)
	//*(arr + i)는 *(arr 배열의 첫번째 값의 주소(&arr[0])+ i)
}
*/

/*
특정 변수p에 대해 *&p는 아무것도 없는 것(p)과 같다.  
&는 주소이며
*는 그 주소의 값이기 때문에
*&는 서로 상쇄된다.
*/

