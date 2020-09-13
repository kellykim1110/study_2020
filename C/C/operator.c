// Arithmetic Operator 산술 연산자
#include <stdio.h>
int main() {
	int a, b;
	//A ssignment Operator 대입연산자
	// 우측의 값을 좌측에 대입하라
	a = 10;
	b = 3;
	printf("a + b = %d \n", a + b);
	printf("a - b = %d \n", a - b);
	printf("a * b = %d \n", a * b);
	printf("a / b = %d \n", a / b); 
	printf("a %% b = %d \n", a % b); //%를 텍스트로 표기하기 위해서는 큰 따옴표안에 %를 두개 써주어야 %이 하나로 출력됨. // %d, %x와 같이 인식될 수도 있으므로
	return 0;
}


// 산술 변환
/*
int main() {
	int a; //정수형 변수
	double b; //실수형 변수
	a = 10;
	b = 3;
	printf("산술 변환이란 자료형이 다른 두 변수를 연산할 때, 숫자가 큰 범위가 큰 자료형으로 자료형들이 바뀌는 것을 의미 \n");
	printf("a / b = %f \n", a / b);
	printf("a / b = %d \n", a / b); // 틀린 답으로 나온다. 정수형은 실수형보다 숫자 범위가 작다.
	printf("b / a = %f \n", b / a);
	return 0;
}
*/

/*
int main() {
	int a = 1, b = 1, c = 1, d = 1;
	a = a + 1;
	b += 1;
	printf("a = %d \nb = %d \n", a, b);
	// prefix
	// 1을 더한 후 결과 반환
	printf("c = %d\n", ++c);
	//postfix
	// 변수 반환 후 1 더하기
	printf("d = %d\n", d++);
	printf("d = %d\n", d);
	return 0;
}
*/

// 비트 연산자
/*
int main() {
	int a = 0xAF; // 10101111
	int b = 0xB5; // 10110101

	// a = 00000000 00000000 00000000 10101111
	printf("a & b = %x \n", a & b);
	printf("a | b = %x \n", a | b);
	printf("a ^ b = %x \n", a ^ b);
	// ~a = 11111111 11111111 11111111 01010000
	printf("~a = %x \n", ~a);
	// a << 2
	// 00000000 00000000 00000010 10111100
	printf("a << 2 = %x \n", a << 2);
	printf("b >> 3 = %x \n", b >> 3);
	return 0;
}
*/

// 컴퓨터가 음수를 표현하는 방법(2의 보수 2's Complement)
/* 
2의 보수 체계 하에서
어떤 수의 부호를 바꾸려면 먼저 비트를 반전시킨 뒤에 1을 더하기
*/
/*
int main() {
	// int는 -2147483648 ~ 2147483647까지 정수 데이터를 보관 가능
	int a = 2147483647;
	printf("정수형 범위를 넘어가면 \n");
	a++;
	printf("a = %d\n", a);
	printf("자료형의 최대 범위보다 큰 수를 대입하면 발생하는 문제를 오버플로우 Overflow라고 한다.")
	return 0;
}
*/
