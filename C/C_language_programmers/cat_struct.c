#include <stdio.h>
#include <time.h>

// 구조체 Struct
// printf("key1": %s\n",StructArr.key1);

/* 
구조체 포인터는 배열과 비슷
배열 구조로 된 구조체 StructArr

struct StructArr * StructPtr;
StructPtr = &StructArr;
printf("key1": %s\n",(*StructPtr).key1);
printf("key1": %s\n",StructPtr->key1);
*/

/*
구조체 안에 구조체
struct StructArr1{
char *key1;
int key2;

struct StructArr1 * SubStructArr;
}

struct StructArr2;


StructArr1.SubStructArr = &StructArr2;
printf("key1": %s\n",StructArr1.SubStructArr->key1);
*/

/*
5종류의 고양이가 존재
아무 키나 눌러서 랜덤으로 고양이 수집
5종류 고양이를 모두 수집해서 키우면 되는 게임
단, 같은 종류 고양이가 중복 수집이 발생 가능

고양이
이름, 나이, 성격, 키우기 난이도(레벨)
*/


/*
typedef struct {
	char * name;
	int age;
	char* character;
	int level;
} CAT;

// 현재까지 보유한 고양이
int collection[5] = { 0,0,0,0,0 };

// 전체 고양이 리스트
CAT cats[5];

// 고양이 정보 초기화
void initCats();

// 뽑힌 고양이 정보
void printCat(int selected);

// collection에 5종류의 고양이가 다 모아졌는지 확인
int checkCollection();


int main() {
	srand(time(NULL));

	// 초기화
	initCats();

	while (1) {
		printf( "\n\n두근두근~~어느 고양이의 간택(??)을 받을 수 있을까요???\n아무 키나 눌러서 확인해 보세요!!\n\n" );
		getchar();

		int selected = rand() % 5; // 0~4
		// 뽑힌 고양이 정보
		printCat(selected);
		
		// 뽑힌 고양이 처리
		collection[selected] = 1;

		checkCollection();
	}

	return 0;
}

// 고양이 정보 초기화
void initCats() {
	char * nameArr[] = { "랑이", "돼지", "시선", "강탈", "백호" };
	char* charArr[] = { "까탈", "황제성향", "펭하", "뀨" ,"관종" };
	int ageArr[] = { 12, 12, 3, 3, 4 };
	int levelArr[] = {5, 5, 3, 4, 2};

	for (int i = 0; i < 5; i++) {
		cats[i].name = nameArr[i];
		cats[i].age = ageArr[i];
		cats[i].character = charArr[i];
		cats[i].level = levelArr[i];
	}
}

// 뽑힌 고양이 정보
void printCat(int selected) {
	printf("\n\n===========당신은 이 고양이의 집사가 되었어요!!! ===========\n");
	printf("이름         : %s\n", cats[selected].name);
	printf("나이         : %d\n", cats[selected].age);
	printf("특징         : %s\n", cats[selected].character);
	printf("키우기 난이도:" );
	// 레벨은 별★로 표기
	for (int i = 0; i < cats[selected].level; i++) {
		printf("%s", "★");
	}
	printf("\n=================================================\n\n");
}

// collection에 5종류의 고양이가 다 모아졌는지 확인
int checkCollection() {
	// 1. 현재 보유한 고양이 목록도 확인
	// 2. 다 모았는지 여부 확인

	// 고양이 5종류 다 수집 여부
	int collectAll = 1;

	printf("\n\n====보유한 고양이 목록====\n\n");
	for(int i = 0; i < 5; i++) {
		// 현재 보유한 고양이의 종류가 없는게 있는지 여부
		// 빈 박스 or 고양이이름으로 출력
		if (collection[i] == 0) {
			printf("%10s","(빈 박스)");

			// 고양이 5종류 다 수집 X
			collectAll = 0;
		}
		else { 
			printf("%10s", cats[i].name);
		}
	}
	if (collectAll == 1){
		printf("\n축하합니다!!\n5종류의 고양이의 집사가 되었어요!!\n\n");
		exit(0);
	}
}

*/