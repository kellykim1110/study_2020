/*변수 알아보기*/
#include <stdio.h>

int main() {
	int a;
	a = 10;
	printf("a의 값은 : %d \n", a);
	return 0;
}


/*변수 알아보기 2*/
/*
int main() {
	int a;
	a = 127;
	printf("a의 값은 %d 진수로 %o 입니다. \n", 8, a);
	printf("a의 값은 %d 진수로 %d 입니다. \n", 10, a);
	printf("a의 값은 %d 진수로 %x 입니다. \n", 16, a);
}
*/
/*변수 알아보기 3*/
/*
int main() {
	float a = 3.141592f; //f는 확실히 실수형인것을 표현하기 위해 덧붙힌 것
	double b = 3.141592;
	printf("a : %f \n", a);
	printf("b : %f \n", b);
	return 0;
}
*/


/*변수 선언시 주의할 점*/
/*
int main() {
	int a, A;
	//int 1hi; // 숫자가 앞에 위치할 수 없다.
	int hi123; // 숫자가 뒤에 위치하는 것은 괜찮음
	int 세종대왕만세; // 원래 변수는 오직 알파벳 숫자 언더바(_)로만 이루어져야 함 하지만 인식되었음(???)
	//int enum; // 예약어 사용 금지
	// int space bar; // 띄어쓰기 금지
	return 0;
}
*/
