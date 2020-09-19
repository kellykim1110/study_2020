
//Swap 함수
#include <stdio.h>

void swap1(int a, int b);
void swap2(int *a, int *b);

int main(){
	int a = 1;
	int b = 2;
	printf("swap함수 전: a = %d, b = %d\n", a, b);
	printf("swap함수 전: a주소 = %d, b주소 = %d\n", &a, &b);
	// swap함수 전: a주소 = 10221516, b주소 = 10221504

	// a와 b의 값을 바꾼다.
	swap1(a, b);
	printf("swap1함수: a = %d, b = %d\n", a, b);
	// a = 1, b = 2 변경되지 않음

	swap2(&a, &b);
	printf("swap2함수: a = %d, b = %d\n", a, b);
	// a = 2, b = 1 변경됨
}

void swap1(int a, int b){
	int temp = a;
	a= b;
	b = temp;
	printf("swap1함수 내: a = %d, b = %d\n", a, b);
	printf("swap1함수 내: a주소 = %d, b주소 = %d\n", &a, &b);
	// a = 2, b = 1
	//swap1함수 내: a주소 = 10221288, b주소 = 10221292
	// main공간의 a,b와 함수내의 a,b가 서로 다르다.
}

void swap2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("swap2함수 내: a = %d, b = %d\n", *a, *b);
	// a = 2, b = 1
}
