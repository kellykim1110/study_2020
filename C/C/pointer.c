/*
포인터
: 메모리 상에 위치한 특정한 데이터의 (시작)주소값을 보관하는 변수

(포인터에 주소값이 저장되는 데이터의 형)* (포인터 명);
int* p;

단항 & 연산자를 통해 피연산자의 주소값을 불러온다.
&a
*/

/*
&연산자가 어떠한 데이터의 주소값을 얻어내는 연산자라면
거꾸로
*연산자는 주소값에서 해당 주소값에 대응하는 데이터를 가져오는 연산자
*/

/*
int* a : a is a pointer to a object of type int
int** a : a is a pointer to a pointer to a object of type int
int*** a : a is a pointer to a pointer to a pointer to object of type int
int**** a : a is a pointer to a pointer to a pointer to a pointer to object of type int
*/



/*
포인터의 타입은 
포인터에는 시작 주소만 들어가 있으므로 얼마나 메모리를 읽어야 하는지 알 수 없기 때문에 
타입type으로 읽어야 할 메모리 양을 알 수 있게 해줌 
*/

#include <stdio.h>
/*
int main() {
	int* p;
	int a, b;

	p = &a;

	printf("포인터p에 들어 있는 값: %p \n", p);
	printf("int 변수 a가 저장된 주소: %p \n", &a);
	printf("포인터p에 저장된 값과 변수a의 주소값이 동일하게 나온다.\n");

	a = 2;
	printf("a의 값: %d \n", a);
	printf("*p의 값: %d \n", *p);

	p = &b;
	*p = 4;

	printf("a : %d \n", a);
	printf("b : %d \n", b);

	return 0;
}
*/

