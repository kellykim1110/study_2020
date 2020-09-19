#include <stdio.h>

// typedef 자료형에 별명 지정
int main() {
	int i = 1;
	typedef int 정수;
	typedef float 실수;

	정수 정수변수 = 3;
	실수 실수변수 = 3.33f;

	printf("정수변수 %d, 실수변수 %.2f\n", 정수변수, 실수변수);
	
	typedef struct GameInfo {
		char* name;
	} 게임정보;
	// struct GameInfo = 게임정보
	게임정보 game1;
	game1.name = "한글게임";
	
	printf("%s\n", game1.name);

	return 0;
}