#include <stdio.h>
#include <time.h>

// 다차원 배열 Multidimensional Array
// int arr2[2][5] = {{1,2,3,4,5}, {1,2,3,4,5}};

/*
for (int i = 0; i< 2; i++){
	for(int j = 0; j < 5; j++){
		printf("2 차원 배열 <%d, %d>의 값 : %d\n", i, j, arr2[i][j]);
		}
		printf("\n");
	}
*/


/*
	동물카드 뒤집기 프로젝트
	뒤집힌 10마리의 서로 다른 동물카드가 각 동물당 2장씩 존재
	사용자로 부터 2개의 입력값을 받아서
	같은 동물을 찾으면 카드 뒤집기

	모든 동물 쌍을 찾으면 게임 종료

	총 실패 횟수 알려주기
	*/


int arrayAnimal[4][5];  // 총 20장의 동물 카드 배열하기
void initAnimalArray();

char *strAnimal[10]; // 10마리의 동물 이름의 주소를 가지고 올 수 있도록하기 위해 포인터로 지정
void animalName();

int getEmptyPosition(); // 좌표에서 빈공간 찾기
int conv_pos_x(int randPos); // x좌표
int conv_pos_y(int randPos); // y좌표
void shuffleAnimal();

// 동물 위치 출력
void printAnimals();
// 문제 출력(동물 카드 배열)
void printQuestion();
// 카드가 뒤집혔는지의 여부 확인
int checkAnimal[4][5];

// 카드가 모두 뒤집혔는지 여부 확인
int foundAllAnimals();



int main() {
	
	srand(time(NULL));

	// 초기 동물카드를 arrayAnimal에 맞게 배열하여 임의의 값을 넣어줌
	initAnimalArray(); 

	// 10마리의 동물의 이름 지정
	animalName();

	// 정해진 동물의 이름을 동물 카드 배열에 어떻게 집어넣을지를 결정
	shuffleAnimal();

	// 실패 횟수
	int failcnt = 0;

	while (1) {
		// 사용자가 선택한 수, 0~19
		int select1 = 0;
		int select2 = 0;

		// 동물 위치 출력
		printAnimals();
		// 문제 출력(동물 카드 배열)
		printQuestion();

		printf("뒤집을 카드 2개를 고르세요.\n");
		scanf_s("%d\n%d", &select1, &select2);
		if (select1 == select2) {
			continue;
		}

		// 좌표에 해당하는 카드를 뒤집어 보고 같은지 안같은지 확인
		// // 정수 좌표를 (x,y)로 변환
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		// // 카드가 이미 뒤집히지 않았는지 확인
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0)
			&& // // 두 동물이 같은 경우
			arrayAnimal[firstSelect_x][firstSelect_y] 
			== arrayAnimal[secondSelect_x][secondSelect_y]) {
			printf("\n\nBingo!! %s 발견\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		// // 두 동물이 다른 경우
		else {
			printf("\n\n땡!! 틀렸거나 이미 뒤집힌 카드입니다.\n\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failcnt++;
		}

		// 모든 동물을 다 찾은 경우
		if (foundAllAnimals() == 1) {
			printf("\n\n 축하합니다! 모든 동물을 다 맞추셨네요!! \n\n");
			printf("지금까지 총 %d번 실수하셨습니다.",failcnt);
			break;
		}
	}

	return 0;
}



void initAnimalArray() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			arrayAnimal[i][j] = -1;
		}
	}
}


void animalName() {
	strAnimal[0] = "기린";
	strAnimal[1] = "원숭이";
	strAnimal[2] = "토끼";
	strAnimal[3] = "사슴";
	strAnimal[4] = "강아지";
	strAnimal[5] = "고양이";
	strAnimal[6] = "호랑이";
	strAnimal[7] = "사자";
	strAnimal[8] = "물고기";
	strAnimal[9] = "다람쥐";
}

void shuffleAnimal() {
	for (int i = 0; i < 10; i++) { // 10마리 동물을
		for (int j = 0; j < 2; j++) { // 2번씩 불러
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;
		}
	}
}

// 좌표에서 빈공간 찾기
int getEmptyPosition() {
	while (1) {
		int randPos = rand() % 20; // 20개의 position 필요, 0~19
		// 좌표 자체가 4행 5열이므로 randPos의 숫자를 이용해 변경할 필요성 존재
		// 19 -> (3,4)
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);
		//printf("%d %d\n", x, y);

		if (arrayAnimal[x][y] == -1) {
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int randPos) {
	// 1행 당 5열
	// randPos = 5 * 행 + 열
	// 19 = 5 * 3 + 4
	return randPos / 5;
}

int conv_pos_y(int randPos) {
	// 1행 당 5열
	// randPos = 5 * 행 + 열
	// 19 = 5 * 3 + 4
	return randPos % 5;
}

// 동물 위치 출력
void printAnimals() {
	// 카드 배열의 동물을 출력
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n======================================\n\n");
}

// 문제 출력(동물 카드 배열)
void printQuestion() {
	// 0 ~ 19
	/*
					seq					checkAnimal
	□□□□□	0  1   2   3   4		 0 0 0 0 0
	□□□□□	5  6  토끼 8   9		 0 0 1 0 0
	□□□□□	10 11 12  토끼 14		 0 0 0 1 0
	□□□□□	15 16 17  18   19		 0 0 0 0 0
	*/
	int seq = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			// 카드를 뒤집어서 정답을 맞혔으면: '동물이름'
			if (checkAnimal[i][j] != 0){
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			// 카드를 뒤집지 못했으면(정답을 맞추지 X): 위치를 나타내는 숫자
			else {
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}


int foundAllAnimals() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (checkAnimal[i][j] == 0) {
				return 0;
			}
		}
	}
	return 1;
}

